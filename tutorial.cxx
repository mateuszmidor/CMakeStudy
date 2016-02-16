#include <iostream>
#include <cstdlib>
#include "TutorialConfig.h"

#ifdef USE_MYMATH
    #include "MathFunctions.h"
#else
    #include <cmath>
#endif

using namespace std;

int main(int argc, const char* argv[])
{
//    cout << "CMake project" << endl;
//    cout << Tutorial_VERSION_MAJOR << "." << Tutorial_VERSION_MINOR << endl;
    
    if (argc != 2)
    {
        cout << "Please provide one argument: a number to sqrt.\n";
        return 1;
    }
    
    double input = atof(argv[1]); 
    
#ifdef USE_MYMATH
    double result = mysqrt(input);
    cout << "(use mymath) ";
#else
    double result = sqrt(input);
    cout << "(use cmath)" ;
#endif

    cout << result << endl;
    return 0;
}
