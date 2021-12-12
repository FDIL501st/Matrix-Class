#include "Matrix.h"

using  mtx::Matrix;

//Definations of each method in class

Matrix::Matrix() : rows(0), columns(0) {
    data = 0;
    
    //Initialzed with no rows and no columns and data pointer ponting to null
    //This means that no memory allocated in heap right now
}

Matrix::Matrix(int r, int c) : rows(r), columns(c) {
    try 
    {
        data = new double* [r];
    }
    catch (const bad_alloc& e)
    {
        cerr << e.what() << ": Unable to allocate rows in heap." << endl;
        rows = 0;
        //Make rows to 0 as unable to allocate the memory
    }

    for (int i = 0; i < rows; i++)
    {
        try
        {
            data[i] = new double[c];
        }
        catch(const bad_alloc& e)
        {
            cerr << e.what() << ": Unable to allocate row " << i <<" in heap." << endl;
            columns = 0;
            //Make columns to 0 as unable to allocate all the columns

            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
                data[i] = 0;
            }
            break;
            //Then free allocation of each row and make each row have 0 column
            //This is to ensure uniformity of the matrix if at any point a row was unable to be allocated in heap
        }
    }
    //if allocation failed, won't terminate, just will send the message the exception occured

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

Matrix& Matrix::operator=(const Matrix& source)
{
    //First check we are not trying to assign itself
    if (this != &source)
    {
        destroy();
        copy(source);
    }
    return *this;
}

void Matrix::copy(const Matrix& source)
{
    //First directly copy rows and columns
    rows = source.rows;
    columns = source.columns;

    //Now need to check if the matrix we try to copy is empty
    if (!source.data)
    {
        data = 0;
        return;
    }
    
    //Making it here means there is a matrix to actually copy
    // So now we reserve the memory needed
    data = new double* [rows];
    if (data == 0)
    {
        cerr << "Heap was not granted, data points to null." << endl;
        rows = 0;
        columns = 0;
        return;
    }

    // i indexes each row
    for (int i = 0; i < rows; i++)
    {
        data[i] = new double [columns];
        if (data[i] == 0)
        {
            cerr << "Heap was not granted, row " << i << " points to null." << endl;
            columns = 0;
            for (int i = 0; i < rows; i++)
            {
                delete[] data[i];
                data[i] = 0;
            }
            //Loop above to ensure informity of matrix in case a row fails to get memory
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

void Matrix::check_boundry_rows(int i)
{
    
    //if i indexes before first row of matrix
    if (i < 0)
    {
        string error_msg("Attempted to access row ");
        error_msg += to_string(i) + ".\n";
        error_msg += "Index can't be less than 0.\n";

        throw out_of_range(error_msg);
    }

    //if i indexes past last row of matrix
    
    if (i >= rows)
    {
        string error_msg("Attempted to access row ");
        error_msg += to_string(i) + ".\n";
        error_msg += "Number of rows in matrix is ";
        error_msg += to_string(rows) + ".\n";
        error_msg += "Row index must be less than number of rows in matrix(i<";
        error_msg += to_string(rows) + ").\n";

        throw out_of_range(error_msg);
    }

    //Reaching here means 0<= i < rows, 
}

void Matrix::check_boundry_columns(int j)
{
    
    //if i indexes before first row of matrix
    if (j < 0)
    {
        string error_msg("Attempted to access column ");
        error_msg += to_string(j) + ".\n";
        error_msg += "Index can't be less than 0.\n";

        throw out_of_range(error_msg);
    }

    //if j indexes past last row of matrix
    
    else if (j >= columns)
    {
        string error_msg("Attempted to access column ");
        error_msg += to_string(j) + ".\n";
        error_msg += "Number of column in matrix is ";
        error_msg += to_string(columns) + ".\n";
        error_msg += "Column index must be less than number of columns in matrix(j<";
        error_msg += to_string(columns) + ").\n";

        throw out_of_range(error_msg);
    }

    //Reaching here means 0<= j < columns, 
}

double& Matrix::at(int i, int j)
{
    check_boundry_rows(i);
    check_boundry_columns(j);
    return data[i][j];
    
}

double* const Matrix::at(int i)
{
    check_boundry_rows(i);
    return data[i];
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