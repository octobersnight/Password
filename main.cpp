/*
*   Khanh Pham - lab # 8
*
*   Using the String Class, design, develop, and test a password validation program that requests a
*   password from the user, and validates it based on the following criteria. The password must be at least 8
*   characters long, contain at least one number, and at least one upper case letter, and at least one lower
*   case letter. The user is limited to three (3) attempts and is then locked out (the program ends).
*/

#include <iostream>
#include <string>
#include "password.h"

using namespace std;

int main()
{
    int num_of_index = 0, attempts = 1;
    string pwInput, result;
    bool tof;

    get_User_Input(pwInput);            /* received user input */

    num_of_index = pwInput.length() + 1;

    /* testing or confirming

    //cout << num_of_index << endl;       // check for pwInput index plus 1

    for (int i = 0; i < num_of_index; i++)
    {
        cout << pwInput[i] << endl;
    }

    cout << get_check(pwInput);           // validate what is true or false
    */
    get_check(pwInput, result, tof);

    while(!tof == true || attempts < 3)
    {
        display_output(pwInput, result, attempts, tof);

        get_User_Input(pwInput);            /* prompt the user to create password again */

        get_check(pwInput, result, tof);

        attempts++;
    }

    display_output(pwInput, result, attempts, tof);

    return 0;
}
