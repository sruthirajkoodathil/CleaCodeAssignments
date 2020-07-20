bool HeartRateOk(float bpm) {
  if(bpm < 70 || bpm > 150) {
    return false;
  } 
  return true;
}
bool Spo2Ok(float spo2) {
  if(spo2 < 80) {
    return false;
  } 
  return true;
}

bool RespRateOk(float respRate) {
  if(respRate < 30 || respRate > 60) {
    return false;
  }
  return true;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  if(HeartRateOk(bpm) && Spo2Ok(spo2) && RespRateOk(respRate)){
    return true;
  } else {
    return false;
  }
}


