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
#if 0
    int r = argv[1][0] - '0';
    int c = argv[2][0] - '0';
    Matrix m(r,c);
    double* num = m.at(0,0);
    *num = 5.46;
    num = m.at(1,2);
    *num = -4.67;
    m.print();
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
    return 1;
}