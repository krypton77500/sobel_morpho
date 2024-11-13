/*
        ============================================================================
        Name        : sobel.c
        Author      : kdesnos
        Version     : 1.2
        Copyright   : CECILL-C
        Description :
        ============================================================================
*/

#include <math.h>
#include <stdlib.h>
#include <string.h>

#include "sobel.h"

// Sobel Filter
int i, j;

    for (j = 1; j < height - 1; j++) {
        for (i = 1; i < width - 1; i++) {
            int sum =
                input[(j - 1) * width + (i - 1)] + input[(j - 1) * width + i] +
                input[(j - 1) * width + (i + 1)] + input[j * width + (i - 1)] +
                input[j * width + i] + input[j * width + (i + 1)] +
                input[(j + 1) * width + (i - 1)] + input[(j + 1) * width + i] +
                input[(j + 1) * width + (i + 1)];
            output[j * width + i] = sum / 9;
        }
    }

  for (j = 0; j < height; j++) {
    output[j * width] = 0;
    output[(j + 1) * width - 1] = 0;
  }
}

