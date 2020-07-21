bool ParamLimitOk(float param1,float Lowlimit, float HighLimit);

bool ParamLimitOk(float param1,float Lowlimit, float HighLimit)
{
  if ((param1 < Lowlimit) || (param1 > HighLimit)){
    return false;
  }
  return true;
}

bool vitalsAreOk(float* Param, int ParamCount) {
  int i = 0;
  static int count = 0; 
  static bool ret;
  
  for (i=0 ; (count <= ParamCount) && (ret); )
  {
   ret = ParamLimitOk(Param[i++],Param[i++],Param[i++]);
   count++;
  }
  return ret;
}


