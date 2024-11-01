#include "lab5.h"

Quadrature::Quadrature() : left{ 0. }, right{ 1. }, h{ 1. }, weight{ 1. / 3., 4. / 3., 1. / 3. }, node{ -1., 0., 1. } {};

Quadrature::Quadrature(double L, double R, std::initializer_list<double> W, std::initializer_list<double> N) : left{ L }, right{ R } {

	if ((right - left) < std::numeric_limits<double>::epsilon()) {

		throw std::runtime_error("right value < left value");

	}

	if (W.size() != N.size()) {

		throw std::runtime_error("Number of nodes is not equal number of weights");

	}

	weight = std::vector<double>(W);

	node = std::vector<double>(N);

	h = 1.;

}

Quadrature::Quadrature(const Quadrature& Object) : left{ Object.left }, right{ Object.right }, h{ Object.h }, weight{ Object.weight }, node{ Object.node } {}

double Quadrature::x(int i, int k) {

	return (h * (node.at(i) + 1.) / 2.) + left + h * k;

}

double Quadrature::f(double x) {

	return 1. / (std::pow<double>(x, 2) - 4.);

}

void Quadrature::set_segment(double L, double R) {

	if ((R - L) < std::numeric_limits<double>::epsilon()) {

		throw std::runtime_error("right value < left value");

	}

	left = L;

	right = R;

}

void Quadrature::set_method(std::initializer_list<double> W, std::initializer_list<double> N) {

	if (W.size() != N.size()) {

		throw std::runtime_error("Number of nodes is not equal number of weights");

	}
	
	weight = std::vector<double>(W);

	node = std::vector<double>(N);

}

double Quadrature::calculate(int n) {

	if (n <= 0) {

		throw std::runtime_error("Bad N (<= 0)");

	}

	h = (right - left) / static_cast<double>(n);

	double result = 0.;

	for (int k = 0; k < n; k++) {

		for (int i = 0; i < weight.size(); i++) {

			result += h * weight.at(i) * f(x(i, k));

		}

	}

	result /= 2.;

	return result;

}

Quadrature::~Quadrature() {};