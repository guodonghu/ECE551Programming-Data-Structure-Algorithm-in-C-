#include "search.h"
#include "function.h"
#include <math.h>
#include <iostream>
class SinFunction : public Function<int, int> {
public:
  virtual int invoke(int arg) {
    return 10000000 * (sin(arg/100000.0) - 0.5);
  }
};

int main(void) {
  
  int answer = binarySearchForZero(f, low, high);
