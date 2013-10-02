#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

void mergeRanges(int values[], int startIndex, int midPoint, int endIndex) {
  int i;
  int rangeSize;
  rangeSize = endIndex - startIndex;
  int* destination;
  destination = calloc(rangeSize, sizeof(values));
  int firstIndex = startIndex;
  int secondIndex = midPoint;
  int copyIndex = 0;
  while (firstIndex < midPoint && secondIndex < endIndex) {
    if(values[firstIndex] < values[secondIndex]) {
      destination[copyIndex] = values[firstIndex];
      ++firstIndex;
    } else {
      destination[copyIndex] = values[secondIndex];
      ++secondIndex;
    }
    ++copyIndex;
  }
  while (firstIndex < midPoint) {
    destination[copyIndex] = values[firstIndex];
    ++copyIndex;
    ++firstIndex;
  }
  while(secondIndex < endIndex){
    destination[copyIndex] = values[secondIndex];
    ++copyIndex;
    ++secondIndex;
  }
  for(i = 0; i < rangeSize; ++i){
    values[i+ startIndex] = destination[i];
  }
  free(destination);
}

void mergeSortRange(int values[], int startIndex, int endIndex) {
  int midPoint;
  int rangeSize;
  rangeSize = endIndex - startIndex;
  if (rangeSize >= 2) {
    midPoint = (startIndex + endIndex) / 2;
    mergeSortRange(values, startIndex, midPoint);
    mergeSortRange(values, midPoint, endIndex);
    mergeRanges(values, startIndex, midPoint, endIndex);
  }
}

void mergesort(int size, int values[]) {
  mergeSortRange(values, 0, size);
}
