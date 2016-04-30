#include<cstdlib>
#include<math.h>
#include"function.h"
#include"search.h"

int search(Function<int, int> * f, int low, int high) {
  int mid;
  int midval;
  while (low <= high) {
    mid = (low + high) / 2;
    midval = f->invoke(mid);
    if (midval == 0) {
      return mid;
    }
    else if (midval < 0) {
      low = mid + 1;
    }
    else {
      high = mid - 1;
    }
  }
  return mid;
}


int binarySearchForZero(Function<int, int> * f, int low, int high) {
  if (f->invoke(low) > 0) {
    return low;
  }
  else if (f->invoke(high) < 0) {
    return high - 1;
  }
  else {
    return search(f, low, high);
  }
}






    
