#include <iostream>

using namespace std;

struct timeType {
	int hr;
	double min;
	int sec;
};

struct tourType {
	string cityName;
	int distance;
	timeType travelTime;
};

void outputTourData(tourType param);

void outputTourData(tourType param) {
	cout << param.cityName;
	cout << param.distance;
	cout << param.travelTime.hr;
	cout << param.travelTime.min;
}

tourType inputTourData();

tourType inputTourData() {
	tourType tour;
	cin >> tour.cityName;
	cin >> tour.distance;
	cin >> tour.travelTime.hr;
	cin >> tour.travelTime.min;
	cin >> tour.travelTime.sec;

	return tour;
}

void referenceTourData(tourType& tour);

void referenceTourData(tourType& tour) {
	tourType tour;
	tour.cityName = "New York";
	tour.distance = '826';
	tour.travelTime.hr = 14;
	tour.travelTime.min = 46;
	tour.travelTime.sec = 32;
}

int main() {
	tourType destination;
	destination.cityName = "Chicago";
	destination.distance = 550;
	destination.travelTime.hr = 9;
	destination.travelTime.min = 30;

}