#include "IntArray.h"
#include <assert.h>
#include <ostream>

IntArray::IntArray(): data(NULL), numElements(0) {

}

IntArray::IntArray(int n): data(new int[n]), numElements(n) {

}

IntArray::IntArray(const IntArray & rhs): data(new int[rhs.numElements]), numElements(rhs.numElements) {
  for (int  i = 0; i < rhs.numElements; i++) {
    data[i] = rhs.data[i];
  }
}

IntArray::~IntArray() {
  delete [] data;
}

IntArray & IntArray::operator=(const IntArray & rhs) {
  if(this != &rhs) {
    int *temp = new int[rhs.numElements];
    for (int i = 0; i < rhs.numElements; i++) {
      temp[i] = rhs.data[i];
    }
    delete [] data;
    data = temp;
    numElements = rhs.numElements;
  }
  return *this;
}

const int & IntArray::operator[](int index) const {
  assert(index < numElements);
  int &ref = data[index];
  return ref;
}

int & IntArray::operator[](int index) {
 assert(index < numElements);
  int &ref = data[index];
  return ref;
}

int IntArray::size() const {
  return numElements;
}

bool IntArray::operator==(const IntArray & rhs) const {
  if (numElements == rhs.numElements) {
    for (int i = 0; i < numElements; i++) {
      if (data[i] != rhs.data[i]) {
	return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

bool IntArray::operator!=(const IntArray & rhs) const {
  if (numElements != rhs.numElements) {
    return true;
  } else {
    for (int i = 0; i < numElements; i++) {
      if (data[i] != rhs.data[i]) {
	return true;
      }
    } 
    return false;
  }
}

std::ostream & operator<<(std::ostream & s, const IntArray & rhs) {
  s << "{";
  for (int i = 0; i < rhs.size(); i++) {
    if (i != rhs.size() - 1) {
      s << rhs.operator[](i)<<", ";
    } else {
      s << rhs.operator[](i);
    }
  }
  s<<"}";
  return s;
}
