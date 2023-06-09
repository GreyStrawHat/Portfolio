/*
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main(void) {
	ifstream inFile;
	ofstream outFile;
	string firstName;
	string lastName;
	string Department;
	double grossSalary;
	double bonus;
	double taxes;
	double netSalary;
	int distanceTraveled;
	int travelingTime;
	int coffeeSold;
	double coffeePrice;


	inFile.open("inData.txt");
	outFile.open("outData.txt");

	outFile << fixed << showpoint;
	outFile << setprecision(2);

	inFile >> firstName >> lastName >> Department >> grossSalary >> bonus >> taxes >> distanceTraveled >> travelingTime >> coffeeSold >> coffeePrice;
	outFile << "First Name: " << firstName << " " << lastName << ", " << "Department: " << Department << endl << "Monthly Gross Salary: $" << grossSalary << ", "
		<< "Monthly Bonus: " << bonus << "%, " << "Taxes: " << taxes << "%" << endl;

	bonus = bonus / 100;
	taxes = taxes / 100;
	netSalary = grossSalary * bonus;
	netSalary = (grossSalary + (grossSalary * bonus)) - ((grossSalary + (grossSalary * bonus)) * taxes);
	outFile << "Paycheck: $" << netSalary << endl << "Distance Traveled: " << distanceTraveled << " miles, " << "Traveling Time: " << travelingTime << " hours " <<
		endl << "Average Speed: " << distanceTraveled / travelingTime << " miles per hour" << endl << "Number of Coffee Cups Sold: " << coffeeSold << "," << " Cost: $" <<
		coffeePrice << " per cup" << endl << "Sales Amount = $" << coffeePrice * coffeeSold;
	inFile.close();
	outFile.close();
	return 0;

}
*/