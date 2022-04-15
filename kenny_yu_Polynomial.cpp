#include "kenny_yu_Polynomial.h"
#include <iostream>
#include <string>
using namespace std;

Polynomial::~Polynomial() {
	
}
void Polynomial::enterTerms() {
	int currC;
	int currE;
  int amtOfTerms;
	cout << "Enter number of polynomial terms: ";
	cin >> amtOfTerms;

	for (int i = 0; i < amtOfTerms; i++) {
		cout << "\nEnter coefficient: ";
		cin >> currC;
		setCoefficient(currC);
		cout << "Enter exponent: ";
		cin >> currE;
		setExponent(currE);
	}
	cout << endl;
}
void Polynomial::setCoefficient(int coefficient) {
	coefficientNum.push_back(coefficient);
}
int Polynomial::getCoefficient(int index) const {
	return coefficientNum[index];
}
void Polynomial::setExponent(int exponent) {
	exponentNum.push_back(exponent);
}
int Polynomial::getExponent(int index) const {
	return exponentNum[index];
}
void Polynomial::printPolynomial() {
	string output = "";
  bool hasZeroExponent = false;

  // puts 0 degree number in beginning JUST THE NUMBER
  for (int i = 0; i < this->coefficientNum.size(); i++) {
    if (getExponent(i) == 0) {
      output += to_string(getCoefficient(i)); //5
      hasZeroExponent = true;
    }
  }
  // if there is no number before the first coefficient, then don't print a mathematical symbol, but if there is, have a plus 
	for (int i = 0; i < this->coefficientNum.size(); i++) {
    // if the coefficient is 0, dont print
    if (getCoefficient(i) == 0)
      continue;
    // whether or not first element should get a + / && -> whether last element gets a plus
    if ((i != 0 || hasZeroExponent) && getExponent(i) != 0) {
      output += ((getCoefficient(i) < 0) ? "" : "+");
      }
    // prevents printing the coefficient of the 0 exponent at the end
    if (getExponent(i) == 0)
      continue;
		if (getExponent(i) == 1) {
			output += to_string(getCoefficient(i)) + "x";
		} else {
			output += to_string(getCoefficient(i)) + "x^" + to_string(getExponent(i));
      }
	}
	cout << output; 
} 
Polynomial Polynomial::operator+(const Polynomial& rhs) const {
	Polynomial temp = *this;
  temp += rhs; //a + rhs(b) 
  return temp;
} // end function operator+
Polynomial Polynomial::operator-(const Polynomial& rhs) const {
	Polynomial temp = *this;
  temp -= rhs;
  return temp;
}
Polynomial& Polynomial::operator+=(const Polynomial& obj) {
	for (int i = 0; i < this->coefficientNum.size(); i++) {
    for (int j = 0; j < this->coefficientNum.size(); j++) {
		if (this->exponentNum[i] == obj.exponentNum[j])
			this->coefficientNum[i] += (obj.coefficientNum[i]);
	}
      }
	return *this;
}
Polynomial& Polynomial::operator-=(const Polynomial& obj) {
	for (int i = 0; i < this->coefficientNum.size(); i++) {
    for (int j = 0; j < this->coefficientNum.size(); j++) {
		if (this->exponentNum[i] == obj.exponentNum[j])
			this->coefficientNum[i] -= (obj.coefficientNum[i]);
	}
      }
	return *this;
}
const Polynomial& Polynomial::operator=(const Polynomial& rhs) { 
  this->coefficientNum = rhs.coefficientNum; // a + b is rhs
  this->exponentNum = rhs.exponentNum;
  return *this;
}
