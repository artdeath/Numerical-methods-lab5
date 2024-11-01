#ifndef LAB5_H
#define LAB5_H

#include <iostream>
#include <vector>

class Quadrature {

private:

	double left; double right;

	double h; 

	std::vector<double> weight; 

	std::vector<double> node; 


public:

	Quadrature(double L, double R, std::initializer_list<double> W, std::initializer_list<double> N);

	Quadrature();

	Quadrature(const Quadrature& Object);

	void set_segment(double L, double R);

	void set_method(std::initializer_list<double> W, std::initializer_list<double> N);

	double x(int i, int k);

	double f(double x);

	double calculate(int n);

	~Quadrature();

};

#endif#pragma once 
