#include <iostream>

using namespace std;

int main() {
	int alpha[50];
	int diffAlpha[51];

	for (int i = 0; i < 50; i++) {
		alpha[i] = -1;
	}

	cout << alpha[0] << endl;

	alpha[24] = 62;

	alpha[9] = (alpha[14] * 3) + 10;

	for (int n = 0; n < 50; n++) {
		if ((n % 2 == 0) || (n % 3 == 0)) {
			cout << alpha[n] << " " << endl;
		}
	}

	cout << alpha[49] << endl;

	for (int v = 0; v < 50; v++) {
		cout << alpha[v] << " ";
		if ((v + 1) % 15 == 0) {
			cout << endl;
		}
		if (v == 44)
			break;

	}

	for (int x = 0; x < 50; x++) {
		if ((x % 2) == 0){
			alpha[x] = alpha[x] + 1;
		}
	}

	for (int y = 0; y < 50; y++) {
		diffAlpha[y] = alpha[y] + alpha[y];
		cout << diffAlpha[y] << " ";
	}

	return 0;
}