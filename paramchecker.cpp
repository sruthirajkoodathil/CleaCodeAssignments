bool LimitCheck(float param1,float Lowlimit, float HighLimit)
{
  if (param1 < Lowlimit) || (param1 > HighLimit){
    return false;
  }
  return true;
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  
  if (LimitCheck(bpm,70,150) && LimitCheck(spo2,70,100) && LimitCheck(respRate,30,60)){
    return true;
  }  
     return false;
}


