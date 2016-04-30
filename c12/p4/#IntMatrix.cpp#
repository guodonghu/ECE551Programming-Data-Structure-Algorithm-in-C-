#include "IntMatrix.h"

IntMatrix::IntMatrix(): numRows(0), numColumns(0), rows(NULL){
}

IntMatrix::IntMatrix(int r, int c): numRows(r), numColumns(c), rows(new IntArray *[r]) {
  for (int i = 0; i < r; i++) {
    rows[i] = new IntArray(c);
  }
}
IntMatrix::IntMatrix(const IntMatrix & rhs): numRows(rhs.numRows), numColumns(rhs.numColumns), rows(new IntArray *[rhs.numRows]){
  for (int i = 0; i < rhs.numRows; i++) {
    rows[i] = new IntArray(numColumns);
    *rows[i] = *rhs.rows[i];
  }    
}

IntMatrix::~IntMatrix() {
  for (int i = 0; i < numRows; i++) {
    delete rows[i];
  }
  delete []rows;
}

IntMatrix &IntMatrix::operator=(const IntMatrix & rhs) {
  if (this != &rhs) {
    IntArray **temp = new IntArray *[rhs.numRows];
    for (int i = 0; i < rhs.numRows; i++) {
      temp[i] = new IntArray(numColumns);
      *temp[i] = *rhs.rows[i];
    }
    for (int i = 0; i < numRows; i++) {
    delete rows[i];
  } 
    delete []rows;
    numRows = rhs.numRows;
    numColumns = rhs.numColumns;
    rows = temp;
    for (int i = 0; i < numRows; i++) {
      rows[i] = temp[i];
    }
  }
  return *this;
}

int IntMatrix::getRows() const {
  return numRows;
}

int IntMatrix::getColumns() const {
  return numColumns;
}

const IntArray & IntMatrix::operator[](int index) const {
  assert(index < numRows);
  IntArray &ref = *rows[index];
  return ref;
}
IntArray & IntMatrix::operator[](int index){
  assert(index < numRows);
  IntArray &ref = *rows[index];
  return ref;
}

bool IntMatrix::operator==(const IntMatrix & rhs) const {
  if (numRows == rhs.numRows && numColumns == rhs.numColumns) {
    for (int i = 0; i < numRows; i++) {
      if (*rows[i] != *rhs.rows[i]) {
	return false;
      }
    }
    return true;
  } else {
    return false;
  }
}

IntMatrix IntMatrix::operator+(const IntMatrix & rhs) const {
  assert(numRows == rhs.numRows && numColumns == rhs.numColumns);
  for (int i = 0; i < numRows; i++) {
    for (int j = 0; j < numColumns; j++) {
      rows[i]->operator[](j) = rows[i]->operator[](j) + rhs.rows[i]->operator[](j);
    }
  }
  return *this;
}
std::ostream & operator<<(std::ostream & s, const IntMatrix & rhs) {
  s << "[ ";
  if (rhs.getRows() != 0 && rhs.getColumns() !=0) {
    for (int i = 0; i < rhs.getRows(); i++) {
      if (i != rhs.getRows() - 1) {
	s<< rhs.operator[](i)<<",\n";
      } else {
	s<< rhs.operator[](i)<<" ]";
      }
    }
  } else {
    s<<" ]";
  }
  return s;  
}

