//File to test methods of Matrix class
//Compilation will require both Matrix.cpp and Test.cpp to be compiled

#include "Matrix.h" //Matrix.h has cout and endl as part of it
using mtx::Matrix;

int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "Please provide 2 numbers." << endl
            << "Program will now end." << endl;
        return 0;
    }
#if 1

#if 1
    string str_r(argv[1]);
    string str_c(argv[2]);
    int r = stoi(str_r);
    int c = stoi(str_c);
    Matrix m1(r,c);
    m1.at(0,0) = 5.46;
    m1.at(1,2) = -4.67;
    //m1.at(-1,6) = 5;
    m1.print();
    //Test has shown that the contructor works and the print function works.
    //Also shows that the at() properly returns a reference to an entry 
    //  and can change that entry

    //Tested the out_of_range exceptions being thrown as well,
    //  they work for numbers larger than max row/column

    //bad_alloc exception in constructor also catches the exception and sets row or column to 0
    //However, because exception gets caught, program isn't terminated.
    //Just end up with no allocation of memory, thus matrix not made as requested.
#endif

#if 0
    Matrix m;
    m.print();
    //Test has shown default constructor also works!
#endif

    //Also currently no segmentation faults when program ends,
    // thus destroy() is also probably working fine
    // as it isn't accessing memory that it can't

    //Keyword is 'probably', no way to really tell that I'm not just getting lucky

#if 1
    Matrix m2(m1);
    m2.at(0,0) = 14.6;
    cout << endl;
    m2.print();
#endif
#if 1
    *(m2.at(0)+1) = 3;
    //*(m2.at(10)+1) = 3;
    //m2.at(1) = m2.at(0);
    //Test shown that was able to get a double* returned
    //Also shows that m2.at(1) can't be modified, however the dereferenced value can.
#endif
#if 1
    Matrix m3 = m2;
    m3.at(1,0) = -2.2;
    cout << endl;
    m1.print();
    cout << endl;
    m2.print();
    cout << endl;
    m3.print();

    //Test has shown that the = operator works fine for deepcopy of matrix objects.
    //Also that each matrix object is a seperate object
#endif
    //Tested the out_of_range exceptions, they work
#endif

#if 0

    string str("Hello");
    try
    {
        cout << str.at(10) << endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    cout << str.at(10) << endl;

    //Code showing how exception handling works
    // and how unhandled exceptions work
#endif

    return 1;


}