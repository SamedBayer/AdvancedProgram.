#ifndef IMPLICIT_H
#define IMPLICIT_H

#include "Euler.h"
#include <cstdlib>

class Implicit : public Euler {
    private:
        const std::function<std::vector<double>(std::vector<double>)> _dfunc; // derivative of the function to be used in Newton's method
        std::vector<double> _y_temp; // y_temp generated to use in each step for previous step's outputs
    public:
        // Add constructor
        Implicit(const std::vector<double> y_0, const double dt, const double t_end, const std::function<std::vector<double>(std::vector<double>)> func, const std::function<std::vector<double>(std::vector<double>)> dfunc);
       
        // Override solve method
        void solve() override;

        // Add Newton's method
        std::vector<double> newton(); 
};

#endif // IMPLICIT_H