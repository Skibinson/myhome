from pydantic import BaseModel, Field
from typing import Optional


class SensorReadings(BaseModel):
    temperature: float = Field(...)
    motion: bool = Field(False)
    leak: bool = Field(False)

class SensorData(BaseModel):
    device_id: str = Field(...)
    readings: SensorReadings


SensorReadings.model_rebuild()