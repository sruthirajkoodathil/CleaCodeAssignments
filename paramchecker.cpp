#include "paramchecker.h"

bool ParamLimitOk(float param,float Lowlimit, float HighLimit);
bool ParamLimitOk(float param,float Lowlimit, float HighLimit)
{
  if ((param < Lowlimit) || (param > HighLimit)){
    return false;
  }
  return true;
}

bool vitalsAreOk(struct Param* Vitals,int TotalVitals) {
  int i = 0;
  static bool status;
  
  for (i=0 ; (i <= TotalVitals) && (status);i++)
  {
     status = ParamLimitOk(Vitals->vital,Vitals->lowerlimit,Vitals->upperlimit);
     Vitals++;
  }
  return status;
}


