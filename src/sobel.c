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

void mean_filter(int width, int height, unsigned char *input, unsigned char *output) {
  int i, j;

  // Appliquer le filtre moyenneur
  for (j = 1; j < height - 1; j++) {
    for (i = 1; i < width - 1; i++) {
      int sum = 0;

      // Calculer la somme des pixels voisins dans une fenêtre 3x3
      for (int y = -1; y <= 1; y++) {
        for (int x = -1; x <= 1; x++) {
          sum += input[(j + y) * width + (i + x)];
        }
      }

      // Calculer la moyenne des pixels voisins et l'assigner à la sortie
      output[j * width + i] = sum / 9; // 9 car il y a 9 pixels dans la fenêtre 3x3
    }
  }

  // Remplir les bords gauche et droit avec des pixels noirs (0)
  for (j = 0; j < height; j++) {
    output[j * width] = 0;             // Bord gauche
    output[(j + 1) * width - 1] = 0;   // Bord droit
  }
}

