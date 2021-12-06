#include "Matrix.h"

using  mtx::Matrix;

//Definations of each method in class

Matrix::Matrix() : rows(0), columns(0) {
    data = 0;
    
    //Initialzed with no rows and no columns and data pointer ponting to null
    //This means that no memory allocated in heap right now
}

Matrix::Matrix(int r, int c) : rows(r), columns(c) {
    data = new double* [r];
    if (data == 0)
    {
        cout << "Heap was not granted, data points to null." << endl;
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double[c];
        if (data[i] == 0)
        {
            cout << "Heap was not granted, row " << i << " points to null." << endl;
            return;
        }
    }
        
    //Initialized with r # of rows and c # of columns,
    // data pointing to an array of r double*  in heap,
    // each double* points to an array of c doubles also in heap
    
    //Essentially just made a r x c matrix stored in heap
}

Matrix::~Matrix()
{
    destroy();
}

Matrix::Matrix(const Matrix& source)
{
    copy(source);
}

void Matrix::copy(const Matrix& source)
{
    //First directly copy rows and columns
    rows = source.rows;
    columns = source.columns;

    //Now need to deepcopy the matrix, first need to make it
    data = 0;

    //Now need to check if the matrix we try to copy is empty
    if (!source.data)
        return;
    
    //Making it here means there is a matrix to actually copy
    // So now we reserve the memory needed
    data = new double* [rows];
    if (data == 0)
    {
        cout << "Heap was not granted, data points to null." << endl;
        return;
    }

    // i indexes each row
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double [columns];
        if (data[i] == 0)
        {
            cout << "Heap was not granted, row " << i << " points to null." << endl;
            return;
        }
        
        //Having reserved the row, now need to fill it up
        //  j indexes each column
        for (int j = 0; j < columns; j++)
        {
            data[i][j] = source.data[i][j];
        }
    }
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

double* Matrix::at(int i, int j)
{
    return &(data[i][j]);
    //No out of bounds check yet
}

void Matrix::print() const
{   
    // i indexes row
    for (int i = 0; i < rows; i++)
    {
        // j indexes column
        for (int j = 0; j < columns; j++)
            cout << '\t' << data[i][j];
        
        cout << endl;
    }
    //Result is printing each row in a seperate line, each number seperated by a tab
    
}