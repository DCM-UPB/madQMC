#include "NumericalUtilities.h"


bool AlmostEqualDouble(const double &arg1, const double &arg2)
{
   if ( (arg1<arg2+constants::EPS) && (arg1>arg2-constants::EPS) )
   {
      return 1;
   }
   else
   {
      return 0;
   }
}
