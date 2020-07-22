bool ParamLimitOk(float param,float Lowlimit, float HighLimit);

struct limit{
float vital[3];
float lowlimit[3];
float upperlimit[3];
};

bool ParamLimitOk(float param,float Lowlimit, float HighLimit)
{
  if ((param < Lowlimit) || (param > HighLimit)){
    return false;
  }
  return true;
}

bool vitalsAreOk(struct limit* Param) {
  int i = 0;
  bool ret;
  
  for (i=0 ; (i <= 3) && (ret);i++)
  {
     ret = ParamLimitOk(Param.vital[i],Param.lowlimit[i],Param.upperlimit[i]);
  }
  return ret;
}


