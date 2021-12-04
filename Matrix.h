#ifndef MTX_MATRIX.H
#define MTX_MATRIX.H

namespace mtx 
{

class Matrix {
public:
    //This class only works with doubles
    //This essentially means most numbers, just not too large nor complex numbers

    //First need to figure out constructors of the class
    //Constructors will only allocate memory in heap and initlialize all values to 0
    
    //Default constructor, allocates a pointer pointing to null in heap
    Matrix();   

    //Constructor that provides dimensions of array
    Matrix(int r, int c); 

    //Because dealing with memory in heap, 
    //will need a destructor, 
    //copy constructor and 
    //assignment operator overload
    
    //Destroyer
    ~Matrix();
private:
    double** data;  //Pointer in stack to point to array of pointers in heap
    int rows;   // # of rows in matrix = # of pointers in array
    int columns;    // # of columns in matrix = # of doubles in array that pointers to point

    //A helper method to free all memory in heap 
    void destroy(); 
};

}

#endif

