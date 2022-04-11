import socket as sck
import sqlite3
import os.path
import threading

stations = {}   #dizionario in cui salvo sotto l'indice id_stazione il nome del fiume, la località e il livello di guardia

BASE_DIR = os.path.dirname(os.path.abspath(__file__))  #ricavo il percorso assoluto del db
db_path = os.path.join(BASE_DIR, "fiumi.db")

con = sqlite3.connect(db_path)          #mi connetto al db
cur = con.cursor()                      #creo il cursore
query = f"SELECT * FROM livelli"        #compongo la query
cur.execute(query)                      #eseguo la query
rows = cur.fetchall()                   #salvo una lista di tuple (una tupla per ogni riga del file)
con.close()                             #chiudo la connessione al db

for element in rows:                    #per ogni elemento della lista, cioè ogni riga del db
    if stations.get(element[0]) == None:        #se non esiste ancora un elemento nel dizionario con indice (element[0] che corrisponde ad un id_stazione)
        stations[element[0]] = []               #lo creo
    stations[element[0]].append(element[1])         #aggiungo le altre colonne della riga su qui sto lavorando all'interno del dizionario sotto l'indice dell'id_stazione a cui appartengono
    stations[element[0]].append(element[2])
    stations[element[0]].append(element[3])

s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)        #configuro il socket TCP
s.bind(('localhost', 80))       
s.listen()
threads = []                #creo una lista per i thread

def run(conn):          #funzione che gestisce il singolo thread e la sua comunicazione con il client
    while True:
        ack = "RECEIVED"                
        danger = "ACTIVATE_LIGHT"
        msg = conn.recv(4096).decode()          #ricevo il messaggio dal client
        tmp = msg.split(";")                    #lo splitto ottenendo così una lista con come primo parametro l'id_stazione, come secondo la misurazione e come terzo data e ora
        if float(tmp[1]) < stations[int(tmp[0])][2] * 0.3:      #se la misurazione è inferiore al 30% del livello di guardia
            conn.sendall(ack.encode())                          #mando messaggio di avvenuta ricezione
        if float(tmp[1]) >= stations[int(tmp[0])][2] * 0.3 and float(tmp[1]) < stations[int(tmp[0])][2] * 0.7:     #se la misurazione è tra il 30% e il 70% del livello di guardia
            conn.sendall(ack.encode())                                                                             #mando messaggio di avvenuta ricezione
            print(f"pericolo sul fiume: {stations[int(tmp[0])][0]} /{stations[int(tmp[0])][0]} / {tmp[2]}")                                     #stampo messaggio di pericolo con il nome del fiume(che ricavo dal dizionario), la sua località e la data e ora della misurazione
        if float(tmp[1]) >= stations[int(tmp[0])][2] * 0.7:                                                      #se la misurazione è maggiore al 70% del livello di guardia
            conn.sendall(danger.encode())                                                                           #mando il messaggio di attivare la luce di emergenza al client
            print(f"massimo pericolo sul fiume: {stations[int(tmp[0])][0]} / {stations[int(tmp[0])][1]} / {tmp[2]}")                             #stampo messaggio di pericolo con il nome del fiume(che ricavo dal dizionario), la sua località e la data e ora della misurazione

while True:
    conn, addr = s.accept()                             #accetto la connesione 
    t = threading.Thread(target=run, args=(conn,))   #creo un thread corrispondente alla connessione
    threads.append(t)                                   #aggiungo il thread alla lista dei thread
    t.start()                                           #starto il thread


s.close()           #chiudo il socket
for thread in threads:   #chiudo tutti i thread
    thread.join()