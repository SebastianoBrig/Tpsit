import requests

print("random one")
r1 = requests.get(f"https://api.chucknorris.io/jokes/random")
print(r1.text)
r2 = requests.get("https://api.chucknorris.io/jokes/categories")
print(r2.text)
category = input("choose a category:  ")
r3 = requests.get(f"https://api.chucknorris.io/jokes/random?category={category}")
print(r3.text)
query = input("search: ")
r4 = requests.get(f"https://api.chucknorris.io/jokes/search?query={query}")
print(r4.text)