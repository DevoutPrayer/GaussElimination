#include <iostream>
#include "GaussElimination.h"

int main()
{
	GaussElimination* gauss = new GaussElimination;
	double A[2][2], x[2], b[2];
	A[0][0] = 0.007;
	A[0][1] = -0.8;
	A[1][0] = -0.1;
	A[1][1] = 10;

	b[0] = 0.7;
	b[1] = 10;

	gauss->inputMatrix((double*)A, b, 2);
	gauss->run(x);

	std::cout << "[" << x[0] << "," << x[1] << "]"<<std::endl;
	delete gauss;
	return 0;
}