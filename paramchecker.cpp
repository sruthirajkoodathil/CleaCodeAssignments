bool ParamLimitOk(float param,float Lowlimit, float HighLimit);

bool ParamLimitOk(float param,float Lowlimit, float HighLimit)
{
  if ((param < Lowlimit) || (param > HighLimit)){
    return false;
  }
  return true;
}

bool vitalsAreOk(float* Param, int ParamCount) {
  int i = 0;
  static int count = 0; 
  static bool ret;
  
  for (i=0 ; (count <= ParamCount) && (ret);)
  {
   ret = ParamLimitOk(Param[i],Param[i+1],Param[i+2]);
   i = i+3;
   count++;
  }
  return ret;
}


