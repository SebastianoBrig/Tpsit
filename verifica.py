from flask import Flask, render_template, request,redirect,url_for,make_response
import sqlite3
import random
import string

from matplotlib.style import use
app = Flask(__name__)
tk= ""
for _ in range(0,20):
    c = random.choice(string.ascii_letters)
    tk = tk + c

def validate(username, password):
    completion = False
    con = sqlite3.connect('./socialnetwork.db')             #apro il db e ottengo tutti gli utenti e password
    cur = con.cursor()
    cur.execute("SELECT * FROM utenti")
    rows = cur.fetchall()                           
    for row in rows:                                #confronto quelli inseriti con tutti quelli memorizzati
        dbUser = row[0]
        dbPass = row[1]
        if dbUser==username:                            #se lo username corrisponde controllo la passowrd
            completion=check_password(dbPass, password)
    con.close()
    return completion                                   #ritorno un booleano in base al riscontro ottenuto

def check_password(hashed_password, user_password):
    return hashed_password == user_password

@app.route('/', methods=['GET', 'POST'])
def login():                                        
    error = None
    if request.method == 'POST':                    #quando viene cliccato il pulsante ottengo lo username e la password
        username = request.form['username']
        password = request.form['password']
        completion = validate(username, password)   # funzione che li confronta con quelli memorizzati nel db
        if completion ==False:
            error = 'Invalid Credentials. Please try again.' #se non ho riscontro stampo il messaggio di errore
        else:                                                
            cookie = request.cookies.get('username')        #ottengo il cookie dell'utente
            if cookie == None:                                      #se non ce l'ha ancora, ed è quindi il primo accesso che fa lo setto uguale al suo username
                resp = make_response(redirect(url_for('index')))
                resp.set_cookie('username',username)
            else:                                                               
                resp = make_response(redirect(url_for('index')))
            return resp
    return render_template('login.html', error=error)


@app.route(f'/index/{tk}', methods=['GET', 'POST'])
def index(): 
    user = request.cookies.get('username') #ottengo il nome dell'utente attraverso il cookie
    print(user)
    while True:                                                 
        con = sqlite3.connect('./socialnetwork.db')             #estraggo uno stato casuale fino a che non ne trovo uno diverso dal mio utente
        cur = con.cursor()
        q = f"SELECT username,stato FROM utenti"
        cur.execute(q)
        lista_stati = cur.fetchall()
        print(lista_stati)
        con.close()
        stato_rand = random.choice(lista_stati)
        print(stato_rand)
        if stato_rand[0] != user:
            break

    if request.method == 'POST':            #quando il pulsante viene cliccato ottengo il nuovo stato e lo inserisco nel db
        stato = request.form['stato']
        if len(stato) > 80:
            stato = stato[:80]
        con = sqlite3.connect('./socialnetwork.db')
        cur = con.cursor()
        q = f"UPDATE utenti SET stato = '{stato}' WHERE username='{user}'"
        cur.execute(q)
        cur.execute("commit")
        con.close()
    elif request.method == 'GET':
        return render_template('index.html', res = stato_rand)      
    return render_template("index.html", res = stato_rand)

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')