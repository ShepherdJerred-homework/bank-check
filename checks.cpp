/*
Project: Checks
Author: Jerred Shepherd
Date: 12-1-15
Course: COMP 150

***********
Description
***********
Takes a double from 1 to 1 billion, outputs the same number in USD

Enter 0 as the amount to exit the program

***************
Sample Dialogue
***************
Amount? 123

One Hundred Twenty Three Dollars and No Cents

Amount? 2.345

Two Dollars and 35 Cents

Amount? 0.1

No Dollars and 10 Cents

Amount? 1.01

One Dollar and 1 Cent

Amount? 123456789.12

One Hundred Twenty Three Million Four Hundred Fifty Six Thousand Seven Hundred Eighty Nine Dollars and 12 Cents

Amount? 0

*/

#include <iostream>
#include <iomanip>
using namespace std;

void outputOnes(int number) {

	switch (number) {

	case 1:
		cout << "One";
		break;

	case 2:
		cout << "Two";
		break;

	case 3:
		cout << "Three";
		break;

	case 4:
		cout << "Four";
		break;

	case 5:
		cout << "Five";
		break;

	case 6:
		cout << "Six";
		break;

	case 7:
		cout << "Seven";
		break;

	case 8:
		cout << "Eight";
		break;

	case 9:
		cout << "Nine";
		break;

	}
}

void outputTens(int number) {

	if (number >= 10 && number <= 15 && number != 14) {

		switch (number) {

		case 10:
			cout << "Ten";
			break;

		case 11:
			cout << "Eleven";
			break;

		case 12:
			cout << "Tweleve";
			break;

		case 13:
			cout << "Thirteen";
			break;

		case 15:
			cout << "Fifteen";
			break;

		}

		return;

	}

	if (number >= 14 && number <= 19) {

		outputOnes(number - 10);
		cout << "teen";
		
		return;

	}

	if (number >= 20 && number <= 29) {

		if (number == 20) {

			cout << "Twenty";

		} else {

			cout << "Twenty ";
			outputOnes(number - 20);
		}

		return;

	}

	if (number >= 30 && number <= 39) {

		if (number == 30) {

			cout << "Thirty";

		} else {

			cout << "Thirty ";
			outputOnes(number - 30);
		}

		return;

	}

	if (number >= 40 && number <= 49) {

		if (number == 40) {

			cout << "Fourty";

		} else {

			cout << "Fourty ";
			outputOnes(number - 40);
		}

		return;

	}

	if (number >= 50 && number <= 59) {

		if (number == 50) {

			cout << "Fifty";

		} else {

			cout << "Fifty ";
			outputOnes(number - 50);
		}

		return;

	}

	if (number >= 60 && number <= 69) {

		if (number == 60) {

			cout << "Sixty";

		} else {

			cout << "Sixty ";
			outputOnes(number - 60);
		}

		return;

	}

	if (number >= 70 && number <= 79) {

		if (number == 70) {

			cout << "Seventy";

		} else {

			cout << "Seventy ";
			outputOnes(number - 70);
		}

		return;

	}

	if (number >= 80 && number <= 89) {

		if (number == 80) {

			cout << "Eighty";

		} else {

			cout << "Eighty ";
			outputOnes(number - 80);
		}

		return;

	}

	if (number >= 90 && number <= 99) {

		if (number == 90) {

			cout << "Ninety";

		} else {

			cout << "Ninety ";
			outputOnes(number - 90);
		}

		return;

	}

}

void outputHundreds(int number) {

	outputOnes(number);
	cout << " Hundred ";
	
}

void outputThousands(int number) {

	if (number >= 100) {

		outputHundreds(number / 100);
		number -= (number / 100) * 100;

	}

	if (number >= 10) {

		outputTens(number );

	} else {

		outputOnes(number);

	}

	cout << " Thousand ";

}

void outputMillions(int number) {

	if (number >= 100) {

		outputHundreds(number / 100);
		number -= (number / 100) * 100;

	}

	if (number >= 10) {

		outputTens(number);

	} else {

		outputOnes(number);

	}

	cout << " Million ";

}

void main() {

	double input;
	int buffer;
	int billions, millions, thousands, hundreds, tens, ones;

	float cents;

	cout.precision(2);

	do {
		
		do {

			cout << "Amount? ";
			cin >> input;
			cout << endl;

			if (input > 1000000000 || input < 0) {

				cout << "Enter a number from 0-1,000,000" << endl;
			}

		} while (input > 1000000000 || input < 0);

		if (input != 0) {

			buffer = input;

			cents = (input - buffer) * 100;

			billions = buffer / 1000000000;
			buffer -= (billions * 1000000000);

			millions = buffer / 1000000;
			buffer -= (millions * 1000000);

			thousands = buffer / 1000;
			buffer -= (thousands * 1000);

			hundreds = buffer / 100;
			buffer -= (hundreds * 100);

			if (buffer >= 10) {

				tens = buffer;
				ones = 0;

			} else {

				tens = buffer / 10;
				buffer -= (tens * 10);

				ones = buffer / 1;
				buffer -= (ones * 1);

			}

			if (billions == 1) {

				cout << "One Billion";

			}

			if (millions > 0) {

				outputMillions(millions);

			}

			if (thousands > 0) {

				outputThousands(thousands);

			}

			if (hundreds > 0) {

				outputHundreds(hundreds);

			}

			if (tens > 0) {

				outputTens(tens);

			}

			if (ones > 0) {

				outputOnes(ones);

			}

			if (input >= 1) {

				if (input >= 2) {

					cout << " Dollars";

				} else {

					cout << " Dollar";

				}

			} else {

				cout << "No Dollars and ";

			}

			if (cents > 0) {

				if (cents > 1) {

					if (input >= 1) {

						cout << " and " << cents << " Cents";

					} else {

						cout << cents << " Cents";

					}

				} else {

					if (input >= 1) {

						cout << " and " << 1 << " Cent";

					} else {

						cout << 1 << " Cent";

					}

				}


			} else {

				cout << " and No Cents";

			}

			cout << endl << endl;

		}
	
	} while (input != 0);

	system("pause");

}