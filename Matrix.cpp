#include "Matrix.h"

using  mtx::Matrix;

//Definations of each method in class

Matrix::Matrix() : rows(0), columns(0) {
    data = 0;
    
    //Initialzed with no rows and no columns and data pointer ponting to null
    //This means that no memory allocated in heap right now
}

Matrix::Matrix(int r, int c) : rows(c), columns(c) {
    data = new double* [r];

    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[c];

        for (int j = 0; j < columns; j++)
            data[i][j] = 0.0;
    }

    //Initialized with r # of rows and c # of columns,
    // data pointing to an array of r double*  in heap,
    // each double* points to an array of c doubles also in heap
    //All the doubles are initialzed to 0.0

    //Essentially, made a r x c matrix where all the data is 0
}

Matrix::~Matrix()
{
    destroy();
}

void Matrix::destroy() 
{
    //First free each double* in array data points to

    for (int i = 0; i < rows; i++)
    {
        delete [] data[i];
        data[i] = 0;
    }

    //Now free data
    delete [] data;
    data = 0;
}