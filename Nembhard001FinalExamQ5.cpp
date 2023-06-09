#include <iostream>
#include <fstream>

using namespace std;

int main() {
	int salesperson;
	int cars[10];
	int carsSold = 0;
	int totalCarsSold = 0;
	int maxCarsSold = 0;

	ifstream inFile("cars.dat");

	for (int i = 0; i < 10; i++) {
		salesperson = i + 1;
		inFile >> cars[i];
		totalCarsSold += cars[i];
		if (cars[i] > maxCarsSold) {
			maxCarsSold = cars[i];
			cout << "The current highest selling car salesperson is salesperson number " << salesperson << endl;
		}
		cout << "Total cars sold this month: " << totalCarsSold << endl;
	}

	return 0;
}