//File to test methods of Matrix class
//Compilation will require both Matrix.cpp and Test.cpp to be compiled

#include <string>
#include "Matrix.h" //Matrix.h has cout and endl as part of it
using mtx::Matrix;
using std::string;
int main(int argc, char** argv)
{
    if (argc != 3)
    {
        cout << "Please provide 2 numbers." << endl
            << "Program will now end." << endl;
        return 0;
    }
#if 1
    int r = argv[1][0] - '0';
    int c = argv[2][0] - '0';
    Matrix m1(r,c);
    m1.at(0,0) = 5.46;
    m1.at(1,2) = -4.67;
    m1.print();
    //Test has shown that the contructor works and the print function works.
    //Also shows that the at() properly returns a reference to an entry 
    //  and can change that entry
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
    return 1;
}