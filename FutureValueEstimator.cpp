#include <iostream>
#include <cmath> // pow(5,n) = 5^n
using namespace std;

double inputValidate(double);
char inputValidate(char);
double fV(double, double, double);

int main()
{
    double pv, // present value
            fv, // future value
            r, // interest rate 
            mn; // number of months

    char choice;        

    do
    {
        cout << "What is the present value?  ";
        pv = inputValidate(pv);

        cout << "What is the interest rate per annum?  ";

        r = inputValidate(r);

        cout << "Investment horizon (in months):  ";
        mn = inputValidate(mn);

        fv = fV(pv, r, mn);
        cout << "Future value of your investment is: $"
            << fixed << fv << '\n'
            << endl;
        
        cout << "Do you want to try again? (y/n): ";
        choice = inputValidate(choice);

        cout << endl;
                /* code */
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
    
}

/**************************************************************************
 * Validate functions to take only positive integers                      *
 **************************************************************************/
double inputValidate(double value)
{
    while(!(cin >> value) || value < 0)
    {
        cout << "Error! A value must be positive.";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return value;
}

/**************************************************************************
 * Validate functions to take only two letters 'y' or 'n'                 *
 **************************************************************************/
char inputValidate(char letter)
{
    cin >> letter;
    while(!(letter == 'y' ||
            letter == 'Y' ||
            letter == 'N' ||
            letter == 'n'))
        
    {
        cout << "Error! a character must be either y or n. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> letter;
    }
    return letter;
}

/**************************************************************************
 * Calculate the future value of the investment                           *
 **************************************************************************/
double fV(double pv, double r, double mn)
{
    r *= 0.01; // 5.55% = 0.055
    return pv * pow((1 + r/12), mn);
}
