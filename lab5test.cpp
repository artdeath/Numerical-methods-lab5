#include "lab5.h"
#include <iostream>

int main() {

	const double I = -std::log(3) / 4;

	try {

		std::initializer_list<double> weight = { 1. / 3., 4. / 3., 1. / 3. }; //Parabola

		std::initializer_list<double> node = { -1., 0., 1. };

		Quadrature lab(0., 1., weight, node);

		for (int i = 1; i < 64; i *= 2) {

			double h1 = lab.calculate(i);

			double h2 = lab.calculate(2 * i);

			std::cout << 1./static_cast<double>(i) << '\t' << I - h1 << '\t' << (I - h1) / (I - h2) << "\t\t";

			double K = std::fabs(1. + (h2 - h1) / (I - h2));

			double temp = (h2 - h1) / (K - 1);

			std::cout << temp << '\t' << h2 + temp << '\t' << I - h2 - temp << '\t' << std::log2(K) << std::endl;

		}

		weight = { 1., 1. }; //Gauss-2

		node = { -1. / std::sqrt(3.), 1. / std::sqrt(3.) };

		lab.set_method(weight, node);

		for (int i = 1; i < 64; i *= 2) {

			double h1 = lab.calculate(i);

			double h2 = lab.calculate(2 * i);

			std::cout << 1./ static_cast<double>(i) << '\t' << I - h1 << '\t' << (I - h1) / (I - h2) << "\t\t";

			double K = std::fabs(1. + (h2 - h1) / (I - h2));

			double temp = (h2 - h1) / (K - 1);

			std::cout << temp << '\t' << h2 + temp << '\t' << I - h2 - temp << '\t' << std::log2(K) << std::endl;

		}

		lab.~Quadrature();

	}
	catch (const std::exception& e) {

		std::cerr << "Error: " << e.what();

	}

	return 0;

}
