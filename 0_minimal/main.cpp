#include <iostream>
#include "calculator.h"

using namespace std;

int main()
{
    calculator myCalc;
    cout << "Addition 5 + 6 = " << myCalc.Add(5, 6) << endl;
    cout << "Subtract 5 + 6 = " << myCalc.Subtract(5, 6) << endl;
    cout << "Multiply 5 + 6 = " << myCalc.Multiply(5, 6) << endl;

    return 0;
}