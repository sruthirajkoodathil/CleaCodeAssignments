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
  retun true;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  bpmOK = HeartRateOk(bpm); 
  spo2OK = Spo2Ok(spo2); 
  resOK = RespRateOk(respRate);
  if (bpmOK && spo2OK && resOK)
  {
    return true;
  } 
    return false;
}


