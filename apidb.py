import flask
from flask import jsonify, request
import sqlite3

app = flask.Flask(__name__)
#app.config["DEBUG"]=True

@app.route('/',methods=['GET'])
def home():
    return"<h1>Biblioteca online</h1><p>Prototipo di web API.</p>"

@app.route('/api/v1/resources/books/all',methods=['GET'])
def api_all():
    con = sqlite3.connect('apidb.db')
    cur = con.cursor()
    cur.execute(f"SELECT * FROM libri")
    rows = cur.fetchall()
    con.close()
    return jsonify(rows)

@app.route('/api/v1/resources/books', methods=['GET'])
def api_id():
    con = sqlite3.connect('apidb.db')
    cur = con.cursor()
    if 'id' in request.args:
        id = int(request.args['id'])
        cur.execute(f"SELECT * FROM libri WHERE id={id}")
        rows = cur.fetchall()

    if 'autore' in request.args :
        autore = request.args['autore']
        cur.execute(f"SELECT * FROM libri WHERE autore={autore}")
        rows = cur.fetchall()
        
    results = []

    con.close()
    for el in rows:
        results.append(el) 
    return jsonify(results)
app.run()