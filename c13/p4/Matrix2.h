#ifndef __T_MATRIX_H___
#define __T_MATRIX_H___

#include <assert.h>
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

//YOUR CODE GOES HERE!
template<typename T>
class Matrix {
 private:
  int numRows;
  int numColumns;
  vector<vector<T> > rows;
 public:  
 Matrix():numRows(0), numColumns(0),rows(0,vector<T>(0)) {}
  
 Matrix(int r, int c) : numRows(r), numColumns(c), rows(r, vector<T>(c)) {}
  
 Matrix(const Matrix & rhs): numRows(rhs.numRows), numColumns(rhs.numColumns) ,rows(rhs.rows) {}
  
  ~Matrix() {}
  
  Matrix<T> & operator=(const Matrix<T> & rhs) {
    if (this != &rhs) {
      rows = rhs.rows;
      numRows = rhs.numRows;
      numColumns = rhs.numColumns;
    }
    return *this;    
  }
    
  int getRows() const {
    return numRows;
  }
  
  int getColumns() const {
    return numColumns;
  }

  const vector<T> & operator[](int index) const {
    assert(index < numRows);
    const vector<T> &ref = rows[index];
    return ref;
  }

  vector<T> & operator[](int index) {
    assert(index < numRows);
    vector<T> &ref = rows[index];
    return ref;
  } 
  
  bool operator==(const Matrix<T> & rhs) const {
    if (numRows == rhs.numRows && numColumns == rhs.numColumns) {          //check if the two matrix have same columns and rows
      for (int i = 0; i < numRows; i++) {
	if (rows[i] != rhs.rows[i]) {                                       //check if every row is the same
	  return false;
	}
      }
      return true;
    } 
    else {
      return false;
    }
  }
  
  Matrix<T> operator+(const Matrix<T> & rhs) {
    assert(numRows == rhs.numRows && numColumns == rhs.numColumns);
    Matrix<T> temp(rhs.numRows, numColumns);
    for (int i = 0; i < numRows; i++) {
      for (int j = 0; j < numColumns; j++) {
	temp[i][j] = rows[i][j] + rhs[i][j];
      }
    }
    return temp;
  }
};

template<typename T>
std::ostream & operator<<(std::ostream & s, const Matrix<T> & rhs) {
  s << "[ ";
  if (rhs.getRows() != 0 && rhs.getColumns() !=0) {
    for (int i = 0; i < rhs.getRows(); i++) {               //print each row
      s << "{";
      for (int j = 0; j < rhs.getColumns(); j++) {
	if (j != rhs.getColumns() - 1) {                    //if it is not the last element of row
	  s<< rhs[i][j]<<", ";
	} 
	else {
	  if (i != rhs.getRows() - 1) {                      
	    s<< rhs[i][j]<<"},"<<endl;
	  }
	  else {                                             //if it is the last element in the last row
	    s<<rhs[i][j]<<"} ]";
	  }
	}
      }
    }
  }
  else {
    s<< " ]";
  }    
  return s;  
}
#endif
