#ifndef MTX_MATRIX_H
#define MTX_MATRIX_H

#include <iostream>
using std::cout;
using std::endl;

namespace mtx 
{

class Matrix {
//This class only works with doubles
//This essentially means most numbers, just not too large nor complex numbers
//Also the class is limited to 2D arrays

//Constructors will only allocate memory in heap
public:    
    //Default constructor, allocates a pointer pointing to null in heap. Makes size 0 array.
    Matrix();   

    //Constructor that provides dimensions of array
    Matrix(int r, int c); 
    
    //Copy Constructor
    Matrix(const Matrix& source);

    //Assignment operator overload
    Matrix& operator= (const Matrix& rhs);

    //Destroyer
    ~Matrix();

    //Returns a pointer to the double at i,j
    //Allows to change the value of the double
    double& at(int i, int j);

    //A print function for the class to print the matrix
    void print() const;

private:
    double** data;  //Pointer in stack to point to array of pointers in heap
    int rows;   // # of rows in matrix = # of pointers in array
    int columns;    // # of columns in matrix = # of doubles in array that pointers to point

    //A helper method to free all memory in heap 
    void destroy(); 

    //A helper method to deepcopy another Matrix object
    void copy(const Matrix& source);
};

}

#endif

