#include "polinom.h"
#include <stdlib.h>
#include <iostream>

//1237

using namespace std;
void main() {
	bool end_work = false;
	int answer;
	char answer_c;
	int size_polinom;
	while (end_work == false) {
		Polinom polinom_1, polinom_2;
		Polinom polinom_res;
		monom input_monom;
		double input;
		cout << "Enter size of the first polinom: ";
		cin >> size_polinom;
		for (int i = 0; i < size_polinom; i++) {
			cout << "Element " << i << ":  " << endl;
			cout << "	 Coefficient = ";
			cin >> input;
			input_monom.SetCoefficient(input);
			cout << "	 Degree = ";
			cin >> input;
			input_monom.SetDegree(input);
			polinom_1.AddElement(input_monom);
		}
		cout << endl;
		cout << "Enter size of the second polinom: ";
		cin >> size_polinom;
		for (int i = 0; i < size_polinom; i++) {
			cout << "Element " << i << ":  " << endl;;
			cout << "	Coefficient = ";
			cin >> input;
			input_monom.SetCoefficient(input);
			cout << "	Degree = ";
			cin >> input;
			input_monom.SetDegree(input);
			polinom_2.AddElement(input_monom);
		}

		bool correct_input = false;
		bool select_operation = false;
		bool correct_select_polinom = false;
		monom constanta_monom;
		while (select_operation == false) {
			correct_input = false;
			while (correct_input != true) {
				cout << endl;
				cout << "Select operation (+,-,*): ";
				cin >> answer_c;
				cout << endl;
				switch (answer_c) {
					case '+':
						polinom_res = polinom_1 + polinom_2;
						cout << "The sum: " << endl;
						for (int i = 0; i < polinom_res.GetLength(); i++) {
							cout << "Element " << i << " = " << polinom_res[i].GetCoefficient() << "|" << polinom_res[i].GetDegree() << endl;
						}
						correct_input = true;
						break;
					case '-':
						polinom_res = polinom_1 - polinom_2;
						cout << "The difference: " << endl;
						for (int i = 0; i < polinom_res.GetLength(); i++) {
							cout << "Element " << i << " = " << polinom_res[i].GetCoefficient() << "|" << polinom_res[i].GetDegree() << endl;
						}
						correct_input = true;
						break;
					case '*':
						while (correct_input != true) {
							cout << "Select type of multiply (0-polinom|1-const): ";
							cin >> answer;
							switch (answer) {
								case 0:
									correct_input = true;
									polinom_res = polinom_1 * polinom_2;
									cout << "The multiply: " << endl;
									for (int i = 0; i < polinom_res.GetLength(); i++) {
										cout << "Element " << i << " = " << polinom_res[i].GetCoefficient() << "|" << polinom_res[i].GetDegree() << endl;
									}
									break;
								case 1:
									correct_input = true;
									double constanta;
									cout << "Enter constant for multiply: ";
									cin >> constanta;
									constanta_monom = monom(constanta, 000);
									while (correct_select_polinom != true) {
										cout << "Select polinom (1|2): ";
										cin >> answer;
										switch (answer) {
											case 1:
												correct_select_polinom = true;
												polinom_res = polinom_1*constanta_monom;
												break;
											case 2:
												correct_select_polinom = true;
												polinom_res = polinom_2*constanta_monom;
												break;
											default:
												correct_select_polinom = false;
												cout << "Input error!" << endl;
										}
									}
									cout << "The multiply(const): " << endl;
									for (int i = 0; i < polinom_res.GetLength(); i++) {
										cout << "Element " << i << " = " << polinom_res[i].GetCoefficient() << "|" << polinom_res[i].GetDegree() << endl;
									}
									break;

								default:
									correct_input = false;
									cout << "Input error!"<<endl;
							}
							correct_input = true;
							break;
					default:
						cout << "Input error!" << endl;
						}
				}
				cout << "Continue selecting operation? (1-yes|0-no): ";
				cin >> answer;
				if (answer == 1) {
					select_operation = false;
				}
				else {
					select_operation = true;
				}
			}
		}
		cout << endl;
		cout << "Continue work? (1-yes|0-no): ";
		cin >> answer;
		if (answer == 0) {
			end_work = true;
		}
		else {
			end_work = false;
		}
	}
}