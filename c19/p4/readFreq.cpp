#include <stdio.h>
#include <cstdlib>
#include "readFreq.h"
#include "fstream"
void printSym(std::ostream & s, unsigned sym) {
  if (sym > 256 ) {
    s << "INV";
  }
  else if (sym == 256) {
    s << "EOF";
  }
  else if (isprint(sym)) {
    char c = sym;
    s << "'" << c << "'";
  }
  else {
    std::streamsize w = s.width(3);
    s << std::hex << sym << std::dec;
    s.width(w);
  }
}
uint64_t * readFrequencies(const char * fname) {
  //WRITE ME!
  std::ifstream input(fname);
  if (!input) {
    std::cerr << "error: can't open file" << std::endl;
    exit(1);
  }
  uint64_t *counts = new uint64_t[257];
  int ascii;
  std::fill_n(counts, 257, 0);
  while ((ascii=input.get()) != EOF) {
    ++counts[ascii];
  }
  counts[256] = 1;
  input.close();
  return counts;
}
