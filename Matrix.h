#include <iostream>
#include <stdexcept>
#include <string>

#ifndef MTX_MATRIX_H
#define MTX_MATRIX_H

using std::cout;
using std::cerr;
using std::endl;

using std::out_of_range;
using std::bad_alloc;
using std::bad_array_new_length;

using std::string;
using std::to_string;

namespace mtx 
{

class Matrix {
//This class only works with doubles
//Also the class is limited to uniform 2D arrays
//Constructors will only allocate memory in heap
public:    
    //Allocates a pointer pointing to null in heap. Makes size 0 array.
    Matrix();   

    //r = rows, c = columns
    Matrix(int r, int c); 
    //PROMISES:
    // Allocates memory in heap for rxc matrix 
    //     an array of r double*
    //     each double* points to an array of c doubles
    // If unable to allocate memory, will catch the bad_alloc exception and set rows or columns to 0
    //     Depends on which array allocation caught the array, won't set both to 0 unless both throws the exception

    
    //Copy Constructor
    Matrix(const Matrix& source);

    //Assignment operator overload
    Matrix& operator= (const Matrix& rhs);

    //Destroyer
    ~Matrix();


    //Allows to change the value of the double.
    double& at(int i, int j);

    //Allows to change the value of the double the pointer points at.
    //However, the double* returned can't have its referenced changed.
    // meaning that it can't be made to point to something else.
    //A check to ensure people don't try to make non-uniorm arrays.
    double* const at(int i);
    
    //This design desicion limits people trying to change an entire row
    //Will require a seperate function to do so, that checks for uniformity
    
    //Alternative to at(), lets people access using [] operator

    //A print function for the class to print the matrix
    void print() const;

private:
    //Pointer in stack to point to array of pointers in heap
    double** data; 
    // # of rows in matrix = # of pointers in array
    int rows;   
    // # of columns in matrix = # of doubles in array that pointers to point
    int columns;    

    //A helper method to free all memory in heap 
    void destroy(); 

    //A helper method to deepcopy another Matrix object
    void copy(const Matrix& source);

    //A method that throws an out_of_range exception if index is not within bounds of rows.
    //Does check if i is actually out of bounds or not.
    void check_boundry_rows(int i);

    //A method that throws an out_of_range exception if index is not within bounds of columns.
    //Does check if j is out of bounds or not.
    void check_boundry_columns(int j);
};


}

#endif

