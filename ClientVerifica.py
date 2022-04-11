import socket as sck
import datetime
from time import sleep
import random
s = sck.socket(sck.AF_INET, sck.SOCK_STREAM)   #configuro il socket in TCP
s.connect(('localhost',80))         #mi connetto al server

id_stazione = input("inserisci l'id_stazione: ")   #inserisco l'id della stazione che sto simulando
while True:
    mis = random.uniform(0.1,11)                #genero un numero casuale che simula la misurazione del livello del fiume
    print(f"misurazione: {mis}")
    msg = f"{id_stazione};{mis};{datetime.datetime.now()}"  #compongo il messaggio da mandare al server     "id_stazione:misurazione:data e ora"
    s.sendall(msg.encode())                                 #mando il messaggio al server
    res = s.recv(4096).decode()                             #mi aspetto la risposta dal server di avvenuta ricezione del messaggio
    print(res)                                               
    if res == "ACTIVATE_LIGHT":                             #se la risposta è la stringa 'ACTIVATE_LIGHT' "accendo la luce di emergenza" con una print
        print("luce di emergenza attivata")                 
    sleep(15)                                               #aspetto 15 secondi 
    
s.close()       #chiudo il socket