// A simple program that computes the square root of a number
#include <stdio.h>
#include "MathFunctions.h"
#include "TutorialConfig.h"

int main(int argc, char* argv[])
{
  if (argc < 2) {
    // report version
    printf("%s Version %d.%d\n", argv[0], Tutorial_VERSION_MAJOR, Tutorial_VERSION_MINOR);
    printf("Usage: %s number\n", argv[0]);
    return 1;
  }

  // convert input to double
  const double inputValue = std::stod(argv[1]);

  const double outputValue = mathfunctions::sqrt(inputValue);

  printf("The square root of %.0f is %.0f\n", inputValue, outputValue);
  return 0;
}
