//
// Created by Sarah Ogent on 10/11/21.
//

#include "calcFuelEconomy.h"
#include <stdexcept>
#include <iostream>
#include <exception>
#include <string>
#include <vector>
using namespace std;

double getMiles() {
    double userMiles;
    bool run=true;

    while(run) {
        try {
            cout << "Enter the number of miles:" << endl;
            cin>>userMiles;

            if (userMiles<0) {
                throw runtime_error("Invalid entry, user mile input cannot be less than 0");
            } else if(cin.fail()) {
                cin.clear();

                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Warning: input error detected");

            } else {
                return userMiles;
                }


            }catch (runtime_error& expObj) {
            cout<<expObj.what()<<endl;
            cout << "Please try again" << endl;
            cout<<endl;
        }
    }
}


double getGallons(){
    double userGallons;
    bool run=true;

    while(run) {
        try {
            cout << "Enter the number of gallons of gas:" << endl;
            cin >> userGallons;

            if (userGallons < 0) {
                throw runtime_error("Invalid entry, user gallon amount cannot be less than 0");
            } else if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Warning: input error detected");

            } else{
                return userGallons;

            }

        } catch (runtime_error& excpObj) {
            cout<<excpObj.what()<<endl;
            cout<<"Please try again"<<endl;
            cout<<endl;
        }
    }
}

double getMPG(vector<double>& miles, vector<double>& gallons) {
    double milesSum = 0;
    double gallonsSum = 0;
    double totalMPG;
    int i;

    try {

        if (miles.empty() || gallons.empty()) {
            throw runtime_error("No values recorded, MPG is nan");

        }

        //milesSum
        for (i = 0; i < miles.size(); ++i) {
            milesSum = milesSum + miles.at(i);

        }

        //gallonsSum
        for (i = 0; i < gallons.size(); ++i) {
            gallonsSum = gallonsSum + gallons.at(i);

        }

       return totalMPG = milesSum / gallonsSum;


    } catch(runtime_error & excpObj) {
        cout<<excpObj.what()<<endl;
        cout<<"Please try again"<<endl;

    }
}


