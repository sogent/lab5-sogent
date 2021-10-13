//
// Created by Sarah Ogent on 10/11/21.
//
#include <iostream>
#include <vector>
#include <stdexcept>
#include "calcFuelEconomy.h"
#include <exception>
#include <iomanip>

using namespace std;



int main() {
    double miles;
    double gallons;
    double MPG;
    char userInput1;
    char userInput;
    vector<double> userMiles;
    vector<double> userGallons;
    bool run = true;
    bool run1 = true;
    int i;


    cout << "Welcome! Let's calculate your vehicle\'s MPG!" << endl;
    while (run) {

        //get amount of miles from user
        miles = getMiles();
        userMiles.push_back(miles);

        //get amount of gallons from user
        gallons = getGallons();
        userGallons.push_back(gallons);


        while (run1) {
            try {

                cout << "Would you like to enter another tank of gas? (Y/N)" << endl;
                cin >> userInput1;
                userInput = toupper(userInput1);
                if (userInput == 'Y') {

                    break;

                } else if (userInput == 'N') {
                    MPG = getMPG(userMiles, userGallons);
                    cout<<endl;
                    cout << "Your vehicle has an average of " <<setprecision(1) << fixed << MPG << " MPG" << endl;
                    cout << "Come again soon!" << endl;
                    run1 = false;
                    run = false;

                } else { //IMPORTANT: did not include if(cin.fail()) because this is looking for a char
                     cin.clear();
                     cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Warning: input error detected");
                }
            } catch (runtime_error &excpObj) {
                cout << excpObj.what() << endl;
                cout << "Please try again" << endl;
                cout << endl;

            }

        }

    }

    return 0;
}