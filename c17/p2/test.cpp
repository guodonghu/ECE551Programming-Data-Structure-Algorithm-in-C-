#include <iostream>
#include "function.h"
#include "search.h"
#include <cstdlib>
#include <math.h>


class SinFunction : public Function<int, int> {
public:
  virtual int invoke(int arg) {
    return 10000000 * (sin(arg/100000.0) - 0.5);
  }
};

int main(void) {
  int low = 0;
  int high = 150000;
  Function<int, int> * f = new SinFunction;
  int ans = binarySearchForZero(f, low, high);
  std::cout << ans;
  delete f;
  return EXIT_SUCCESS;
}

