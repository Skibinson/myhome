import requests
import time 
import random
URL = "http://localhost:8000/api/reading"
DEVICE_ID = "kitchen_01"

while True:
    data = {
        "device_id" : DEVICE_ID,
        "readings" :
        {
        "temperature" : random.uniform(-30, 30),
        "motion" : random.choice([True, False]),
        "leak" : random.choice([True, False])
        }
        }

    response = requests.post(URL, json=data)
    print(f"Sent: {data}, Response: {response.status_code}")
    time.sleep(5)