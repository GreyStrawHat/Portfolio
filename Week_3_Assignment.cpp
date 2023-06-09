#include <iostream>
#include <string>
/*
using namespace std;

int main(void) {
    char service_code;
    int call_length;
    int account_number;
    string call_time;
    string service;
    double service_price;
    double r_oc_fee = 0;
    double p_oc_fee_a = 0;
    double p_oc_fee_b = 0;
    double total_charge = 0;

    cout << "Enter your account number.\n";
    cin >> account_number;
    cout << "Enter your service code.\n";
    cin >> service_code;
    cout << "Enter number of minutes the service was used.\n";
    cin >> call_length;
    cout << "Was the service used in the day or at night?\n";
    cin >> call_time;

    if (service_code == 'r' || service_code == 'R') {
        // Set the service name and price for Regular service
        service = "Regular";
        service_price = 10;

        // Calculate the overcharge fee if call length is greater than 50 minutes
        if (call_length > 50) {
            r_oc_fee = ((call_length - 50) * 0.2);
            total_charge = service_price + r_oc_fee;
        }
        else {
            // If call length is less than or equal to 50, the total charge is the service price only
            total_charge = service_price;
        }
    }
    else if (service_code == 'p' || service_code == 'P') {
        // Set the service name and price for Premium service
        service = "Premium";
        service_price = 25;

        if (call_time == "day") {
            // Calculate the overcharge fee if call length is greater than 75 minutes during the day
            if (call_length > 75) {
                p_oc_fee_a = ((call_length - 75) * 0.1);
                total_charge = service_price + p_oc_fee_a;
            }
            else {
                // If call length is less than or equal to 75 during the day, the total charge is the service price only
                total_charge = service_price;
            }
        }
        else if (call_time == "night") {
            // Calculate the overcharge fee if call length is greater than 100 minutes during the night
            if (call_length > 100) {
                p_oc_fee_b = ((call_length - 100) * 0.05);
                total_charge = service_price + p_oc_fee_b;
            }
            else {
                // If call length is less than or equal to 100 during the night, the total charge is the service price only
                total_charge = service_price;
            }
        }
    }
    else {
        // If service code is neither 'r' nor 'p', display an error message
        cout << "Error, please enter a valid service code.\n";
    }

    // Output the total charge only if it has been calculated and is not zero
    if (total_charge != 0) {
        cout << "Your Account Number is " << account_number << ".\nYou currently have the " << service << " service.\n" << "Your service time is " << call_length << " minutes.\n"
            << "Your amount due is $" << total_charge << " dollars." << endl;
    }
    return 0;
}
*/