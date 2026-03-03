from pydantic import BaseModel, Field, ValidationError
from datetime import datetime


class SensorReadings(BaseModel):
    temperature: float = Field(..., ge=-40, lt=40)
    motion: bool = Field(...)
    leak: bool = Field(...)

class SensorData(BaseModel):
    device_id: str = Field(...)
    timestamp: str = Field(...)
    readings: SensorReadings

def test_valid_data():
    data = {
        "device_id": "dev1",
        "timestamp": "2026-03-02T14:30:00Z",
        "readings": {
            "temperature": 22.6,
            "motion": True,
            "leak": False
        },
    }

    try:
        sdata = SensorData(**data)
        print("Data is valid\n")
        print(f"Device: {sdata.device_id}")
        print(f"Datetime: {sdata.timestamp}")
        print(f"Readings: \n {sdata.readings}")
    except ValidationError as e:
        print("Validation error", e)

test_valid_data()
