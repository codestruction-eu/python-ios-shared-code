#include "MathFunctions.h"
#include <math.h>

#ifdef USE_MYMATH
#  include "mysqrt.h"
#endif

namespace mathfunctions {
double sqrt(double x)
{
#ifdef USE_MYMATH
  return detail::mysqrt(x);
#else
  return sqrt(x);
#endif
}
}
