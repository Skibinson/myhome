from fastapi import FastAPI
import logging
from fastapi.middleware.cors import CORSMiddleware
from datetime import datetime
from .models import SensorData

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger(__name__)


app = FastAPI(title="MyHome", description="testing")

app.add_middleware(
    CORSMiddleware,
    allow_origins=["*"],  # в проде заменить на конкретные адреса
    allow_credentials=True,
    allow_methods=["*"],
    allow_headers=["*"],
)

received_data = [] # Хранилище данных (временно без БД

@app.get("/")
async def root():
    return {"message" : "Hello, antoha!"}

@app.get("/health")
async def health():
    return {"status" : "not Healthy"}

@app.post("/api/reading")
async def receive_reading(data: SensorData):
    logger.info(f"Received data from {data.device_id}")
    logger.info(f"Temperature: {data.readings.temperature}")

    entry = {
        "device_id": data.device_id,
        "timestamp": datetime.now().isoformat(),
        "readings": data.readings.dict(),
    }

    received_data.append(entry)

    if (len(received_data) > 100):
        received_data.pop(0)

    return {"status": "success", "message": "Data received", "received": entry}

@app.get("/api/reading")
async def get_readings(limit: int = 10):
    return received_data[-limit:]

