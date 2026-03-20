import requests
import time 

URL = "http://localhost:8000/api/reading"
DEVICE_ID = "kitchen_01"

data = {
        "device_id" : DEVICE_ID,

        }
