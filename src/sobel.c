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
void sobel(int width, int height, unsigned char *input, unsigned char *output) {
  int i, j;
  for (j = 1; j < height - 1; j++) {
    for (i = 1; i < width - 1; i++) {
      int gx = -input[(j - 1) * width + i + 1] - 2 * input[j * width + i - 1] -
               input[(j + 1) * width + i - 1] + input[(j - 1) * width + i + 1] +
               2 * input[j * width + i + 1] + input[(j + 1) * width + i + 1];
      int gy = -input[(j - 1) * width + i - 1] -
               2 * input[(j - 1) * width + i] - input[(j - 1) * width + i + 1] +
               input[(j + 1) * width + i - 1] + 2 * input[(j + 1) * width + i] +
               input[(j + 1) * width + i + 1];
      output[(j - 1) * width + i] = (gx * gx + gy * gy) / 8;
    }
  }
}

// Mean Filter
void mean_filter(int width, int height, unsigned char *input, unsigned char *output) {
  int i, j;
  for (j = 1; j < height - 1; j++) {
    for (i = 1; i < width - 1; i++) {
      int sum = 0;
      for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
          sum += input[(j + y) * width + (i + x)];
        }
      }
      output[j * width + i] = sum / 9;
    }
  }
  for (j = 0; j < height; j++) {
    output[j * width] = 0;
    output[(j + 1) * width - 1] = 0;
  }
}

