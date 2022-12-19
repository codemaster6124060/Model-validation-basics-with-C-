#include <iostream>
#include <cmath> // pow(5, n) = 5^n
#include <limits>

using namespace std;

// Function Prototypes
double pV(double, double, double);
double inputValidate(double);
char inputValidate(char);

int main()
{
    double pv, // Present value
           fv, // Future value
           r, // Annual interest rate
           mn; // Number of months

    char choice;

    do
    {
        cout << "What is the interest rate per annum? " ;
        r = inputValidate(r);

        cout << "What is the future value? " ;
        fv = inputValidate(fv);

        cout << "Investment horizon (in months): " ;
        mn = inputValidate(mn);

        pv = pV(fv, r, mn);
        cout << "Present value of your investment should be: "
                << '$' << fixed << pv << '\n' << endl;

        cout << "Do you want to try again? (y/n): ";
        choice = inputValidate(choice);

        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    return 0;
}

/**************************************************************************
 * Validate functions to take only positive integers                      *
 **************************************************************************/

double inputValidate(double num)
{
    while(!(cin >> num))
    {
        cout << "Error. An integer above 0 must be entered: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return num;
}

/**************************************************************************
 * Validate functions to take only two letters 'y' or 'n'                 *
 **************************************************************************/
char inputValidate(char letter)
{
    cin >> letter;

    while (!(letter == 'y' ||
            letter == 'Y' ||
            letter == 'N' ||
            letter == 'n'))
    {
        cout << "Error: a Y or an N must be entered: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cin >> letter;
    }

    return letter;
}

/**************************************************************************
 * Calculate the future value of the investment                           *
 **************************************************************************/

double pV(double fv, double r, double mn)
{
    r *= .01; // 3.33% .0333
    return  fv / pow((1 + r/12), mn);
}