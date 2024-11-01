
#include <iostream>

using namespace std;

const int SIZE = 4; // Global variable for matrix size

class Matrix { //class for Matrix
private: //private portion of Class
  int data[SIZE][SIZE];  // 2D array for matrix data 

public: //public portion of class
  // 1. read input for matrix
  void readFromStdin() { //void function to read input (because no return needed)
      for (int i = 0; i < SIZE; i++) { //iterate through to size for rows
            for (int j = 0; j < SIZE; j++) { //iterate through to size for cols
                cout << "Enter value for coordinates [" << i << "][" << j << "]: ";
                cin >> data[i][j]; //set input to that part of matrix
            }
      }
  }

  // 2. Display a matrix
  void display() const { //void function to display matrix
      for (int i = 0; i < SIZE; i++) { //iterate through rows
            for (int j = 0; j < SIZE; j++) { //iterate through cols
                cout << data[i][j] << " "; //output specified coordinate
            }
            cout << "\n"; //output a new line
        }
    }

  // 3. Add two matrices (operator overloading for +)
  Matrix operator+(const Matrix& other) const { //class + operator overload
    Matrix result; //define a result matrix
        for (int i = 0; i < SIZE; i++) { //iterate through size for rows
            for (int j = 0; j < SIZE; j++) { //iterate through size for cols
                result.data[i][j] = data[i][j] + other.data[i][j]; //set result coord to sum of matrix 1 and matrix 2 
            }
        }
    return result; //return result matrix
  }

  // 4. Multiply two matrices (operator overloading for *)
  Matrix operator*(const Matrix& other) const { //class * operator overload
    Matrix result; //define a result matrix
        for (int i = 0; i < SIZE; i++) { //iterate through to size for rows
            for (int j = 0; j < SIZE; j++) { //iterate through to size for cols
                result.data[i][j] = 0; // Initialize to 0
                for (int k = 0; k < SIZE; k++) { //iterate through to size for k in order to properly multiply according to matrix multiplication formula
                    result.data[i][j] += data[i][k] * other.data[k][j]; //add matrix1[i][k]*matrix2[k][j] to result coordinates for all k vals
                }
            }
        }
    return result; //return result matrix
  }

  // 5. Compute the sum of matrix diagonal elements
  int sumOfDiagonals() const { //define a function to sum the diagonals
    int sum = 0; //declare sum as 0
    for (int i = 0; i < SIZE; i++) { //iterate through to size
        sum += data[i][i];// Sum of primary diagonal elements
        sum += data[i][SIZE - 1 - i]; // Sum of anti-diagonal elements
    }
    return sum; //return the sum
  }

  // 6. Swap matrix rows
  void swapRows(int row1, int row2) { //void function to swapRows, no return needed
    if (row1 >= 0 && row2 >= 0 && row1 < SIZE && row2 < SIZE) { //if the input is valid 
        for (int j = 0; j < SIZE; j++) { //iterate through to size
            std::swap(data[row1][j], data[row2][j]); //make a swap
            }
        } 
        else { //otherwise
            cout << "Invalid indices" << "\n"; //tell user indices are invalid
        }
    }
  };

int main() {
  // Example usage:
  Matrix mat1;
  cout << "Enter values for Matrix 1:" << endl;
  mat1.readFromStdin();
  cout << "Matrix 1:" << endl;
  mat1.display();

  Matrix mat2;
  cout << "Enter values for Matrix 2:" << endl;
  mat2.readFromStdin();
  cout << "Matrix 2:" << endl;
  mat2.display();

  Matrix sum = mat1 + mat2;
  cout << "Sum of matrices:" << endl;
  sum.display();

  Matrix product = mat1 * mat2;
  cout << "Product of matrices:" << endl;
  product.display();

  cout << "Sum of diagonals of Matrix 1: " << mat1.sumOfDiagonals() << endl;

  mat1.swapRows(0, 2);
  cout << "Matrix 1 after swapping rows:" << endl;
  mat1.display();

  return 0;
}
