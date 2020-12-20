// Peter Truscinski
// SNHU CS 210
// 11/27/2020

// This program takes input about a deposit in a bank account
// and displays output with interest after monthly or without
// monthly deposits.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
   // Declare variables to store input
   float initInv, monDep, AnuInt, months, years;
   // Declare variables to store year end total amount, interest, and interest
   float totalAm, intAmt, yearTotInt;


   // Display form to user
   cout << "********************************\n";
   cout << "********** Data Input **********\n";
   cout << "Initial Investment Amount: \n";
   cout << "Monthly Deposit: \n";
   cout << "Annual Interest: \n";
   cout << "Number of years: \n";
   cout << "Press any key to continue . . .\n";

   // Pause for input 
   cin.get();

   // Get data from user
   cout << "********************************\n";
   cout << "********** Data Input **********\n";
   cout << "Initial Investment Amount: $";
   cin >> initInv;
   cout << "Monthly Deposit: $";
   cin >> monDep;
   cout << "Annual Interest: %";
   cin >> AnuInt;
   cout << "Number of years: ";
   cin >> years;
   months = years * 12;
   cout << "Press any key to continue . . .\n";

   // Pause for input 
   cin.get();
   
   // Set total amount to initial investment to be updated
   totalAm = initInv;

   // Display year data without monthly deposits
   cout << "\nBalance and Interest Without Additional Monthly Deposits\n";
   cout << "==============================================================\n";
   cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
   cout << "--------------------------------------------------------------\n";


   for (int i = 0; i < years; i++) {

       // Calculate yearly interest
       intAmt = (totalAm) * ((AnuInt / 100));

       // Calculate end of the year total
       totalAm = totalAm + intAmt;

       // Print results to table 
       cout << (i + 1) << "\t\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t\t$" << intAmt << "\n";

   }

   // Set total amount to initial investment 
   totalAm = initInv;
   

   //Display year data with monthly deposits
   cout << "\n\nBalance and Interest With Additional Monthly Deposits\n";
   cout << "==============================================================\n";
   cout << "Year\t\tYear End Balance\tYear End Earned Interest\n";
   cout << "--------------------------------------------------------------\n";

   for (int i = 0; i < years; i++) {

       // Set yearly interest to zero
       yearTotInt = 0;

       for (int j = 0; j < 12; j++) {

           // Calculate monthly interest
           intAmt = (totalAm + monDep) * ((AnuInt / 100) / 12);

           // Calculate month end interest
           yearTotInt = yearTotInt + intAmt;
            
           // Calculate month end total
           totalAm = totalAm + monDep + intAmt;

       }

       // Print results to table 
       cout << (i + 1) << "\t\t\t$" << fixed << setprecision(2) << totalAm << "\t\t\t\t$" << yearTotInt << "\n";


   }

   return 0;
}