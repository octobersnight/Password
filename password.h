#ifndef PASSWORD_H_INCLUDED
#define PASSWORD_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

void get_User_Input(string& pwInput)
{
    cout << "-----------------------------------------------------------" << endl;
    cout << "Enter a password that contains: \n"
         << "\t -At least eight (8) characters. \n"
         << "\t -At least one number. \n"
         << "\t -At least one upper case letter. \n"
         << "\t -At least one lower case letter. \n" << endl;
    cout << "Password: ";
    cin >> pwInput;
    cout << "" << endl;
}


bool get_check(string& character, string& result, bool& tof)
{
    bool upperCase = false,
            lowerCase = false,
            digitNum = false;

    for (int k = 0; k < character[k]; k++)
    {
        if (isupper(character[k]))
        {
            upperCase = true;
        }
        else if (islower(character[k]))
        {
            lowerCase = true;
        }
        else if (isdigit(character[k]))
        {
            digitNum = true;
        }
    }


    /* combination of scenario of user password is created if its not met
        the requirements */
    if (upperCase && lowerCase && digitNum)
    {
        tof = true;
        return tof;
    }
    else if (!upperCase && lowerCase && digitNum)
    {
        result = "\tIt does not contain an upper case letter.\n";
        //return false;
    }
    else if (upperCase && !lowerCase && digitNum)
    {
        result = "\tIt does not contain an lower case letter.\n";
        //return false;
    }
    else if (upperCase && lowerCase && !digitNum)
    {
        result = "\tIt does not contain a number.\n";
        //return false;
    }
    else if (!upperCase && lowerCase && !digitNum)
    {
        result = "\tIt does not contain an upper case letter\n"
                "\tor a number.\n";
        //return false;
    }
}

void display_output(string pwInput, string result, int attempts, bool tof)
{

    if (tof == true)
    {
        cout << "\tCongrats! You have created your password. \n" << endl;
        exit(1);
    }
    else if (attempts < 3)
    {
        cout << "\t" << pwInput << " is not a valid password. "<< endl;
        cout << result << endl;
        cout << "\tThis is your attempt: " << attempts << "\n" << endl;
    }
    else
    {
        cout << "\t" << pwInput << " is not a valid password. "<< endl;
        cout << result << "\n" <<endl;
        cout << "\n>>>>> \t That was the third attempt. This seesion hase been locked. <<<<< \n" << endl;
        exit(1);
    }


}

#endif // PASSWORD_H_INCLUDED
