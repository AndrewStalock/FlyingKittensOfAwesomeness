#include <stdlib.h>
#include <stdio.h>
#include "array_merge.h"

int* array_merge(int num_arrays, int* sizes, int** values) {
  int* countArr;
  int max = 0;
  int totalSize = 0;
  int* totalArr;
  int i = 0;
  int j = 0;
  int k = 0;
  int m = 0;
  int finalSize = 0;
  int* finalArr;

  for(i = 0; i < num_arrays; ++i) {
    totalSize += sizes[i];
  }

  totalArr = calloc(totalSize, sizeof(values));

  
    for(j= 0; j < num_arrays; ++j){
      for(k = 0; k < sizes[j]; ++k){
	totalArr[m] = values[j][k];
	++m;
        if(values[j][k] > max) {
          max = values[j][k];
        }
      }
    }

  countArr = calloc(max+1, sizeof(values));

  for(i = 0; i < totalSize; ++i) {
    if(countArr[totalArr[i]] == 0) {
      countArr[totalArr[i]] = 1;
      ++finalSize;
    }
  }

  finalArr = calloc(finalSize+1, sizeof(values));
  finalArr[0] = finalSize;
  int duh = 1;
  for(i = 0; i <= max; ++i){
    if(countArr[i] == 1){
      finalArr[duh] = i;
      ++duh;
    }
  }
  free(countArr);
  free(totalArr);
 
  return finalArr;
  
}
