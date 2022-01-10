#include "MathFunctions.h"
#include <math.h>

#ifdef USE_MYMATH
#  include "mysqrt.h"
#endif

double mathfunctions_sqrt(double x)
{
#ifdef USE_MYMATH
  return mysqrt(x);
#else
  return sqrt(x);
#endif
}
