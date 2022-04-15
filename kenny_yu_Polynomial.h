#ifndef KENNY_YU_POLYNOMIAL_H
#define KENNY_YU_POLYNOMIAL_H
#include <iostream>
#include <vector>

static const int MAX = 50;

class Polynomial {
public:
	Polynomial() = default;
	~Polynomial();
	void setCoefficient(int);
	int getCoefficient(int) const;
	void setExponent(int);
	int getExponent(int) const;
	void enterTerms();
	void printPolynomial();
	Polynomial operator+(const Polynomial &rhs) const;
	Polynomial operator-(const Polynomial &rhs) const;
	Polynomial& operator+=(const Polynomial &obj);
	Polynomial& operator-=(const Polynomial &obj);
	const Polynomial& operator=(const Polynomial &rhs);
private:
	std::vector<int> coefficientNum;//change to vector
	std::vector<int> exponentNum;
};
#endif
