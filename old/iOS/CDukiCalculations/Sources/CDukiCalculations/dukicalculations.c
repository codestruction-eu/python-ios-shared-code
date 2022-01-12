#include "dukicalculations.h"

#include <stdio.h>
#include <stdlib.h>

char * demo(bool boolean, long int integer, double floatingPoint, long long int integerArray[], size_t integerArrayCount) {

    char * result = calloc(100 + 1, sizeof(char));
    if (!result) {
        return "memory error";
    }

    result[100] = '\0';

    long long int integerArraySum = 0;
    for (int i = 0; i < integerArrayCount; i++) {
        integerArraySum += integerArray[i];
    }

    int cx = snprintf(result, 100,
                      "boolean: %s, integer: %ld, floatingPoint: %f, integerArray sum: %lld",
                      boolean ? "true" : "false",
                      integer,
                      floatingPoint,
                      integerArraySum);
    if (cx < 0 || cx >= 100) {
        free(result);
        return "snprintf error";
    }

    return result;
}
