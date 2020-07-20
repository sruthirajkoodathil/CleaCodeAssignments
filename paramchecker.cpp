void HeartRateOk(float bpm) {
  if(bpm < 70 || bpm > 150) {
    bpmOK =false;
  } 
  bpmOK = true;
}
void Spo2Ok(float spo2) {
  if(spo2 < 80) {
    spo2OK = false;
  } 
  spo2OK = true;
}

void RespRateOk(float respRate) {
  if(respRate < 30 || respRate > 60) {
    resOK = false;
  }
  resOK = true;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  HeartRateOk(bpm); 
  Spo2Ok(spo2); 
  RespRateOk(respRate);
  if (bpmOK && spo2OK && resOK)
  {
    return true;
  } 
    return false;
}


