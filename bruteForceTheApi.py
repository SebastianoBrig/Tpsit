import requests

id = input("inserisci l'id: ")
r = requests.get(f"http://127.0.0.1:5000/api/v1/resources/books?id={id}")
print(r.json())
