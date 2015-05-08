#include "NumericalUtilities.h"


bool AlmostEqualDouble(const double &arg1, const double &arg2)
{
   if ( (arg1<arg2+cnst::EPS) && (arg1>arg2-cnst::EPS) )
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
