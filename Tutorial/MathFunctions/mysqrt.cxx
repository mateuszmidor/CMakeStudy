#include "MathFunctions.h"
#include "TutorialConfig.h"
#include "Table.h" // sqrtTable, this header is generated
#include <cmath>

double tablebasedSqrt(double val)
{
    unsigned index = static_cast<unsigned>(val);
    if (index >= sizeof(sqrtTable) / sizeof(sqrtTable[0]))
        return 0.0;
    else
        return sqrtTable[index];
}

double mysqrt(double val)
{
#if defined(HAVE_LOG) && defined(HAVE_EXP)
	return return exp(log(val) * 0.5);
#else
	#pragma message "sqrt function is table based (max input value: 100)"
    return tablebasedSqrt(val);
#endif
}

