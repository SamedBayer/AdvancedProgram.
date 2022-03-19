#include <iostream>
#include <string>

#include "Explicit.h"

// TODO: Implement constructor and describe()

Explicit::Explicit(const std::vector<double> y_0, const double dt, const double t_end, const std::function<std::vector<double>(std::vector<double>)> func)
        : Euler(y_0, dt, t_end, func)
{
    std::cout << "Constructed the Explicit Method!" << std::endl;
}

inline void Explicit::solve() {

    // initializing y output vector with initial condition
    // only the first column changed
    // we iterate over number of columns, which is equal to the size of initial condition vector given
    for (int j = 0; j < _y_0.size(); j++) {
        _result_vec[j][0] = _y_0[j];
    }


    for (int j = 1; j < _numberOfTimeSteps; j++) {

        std::vector<double> y_temp; // y_temp generated to use in each step for previous step's outputs
        // in the following loop, we fill y_temp vector with the previous step's values
        for (int d = 0; d < _y_0.size(); d++) {
            y_temp.push_back(_result_vec[d][j - 1]);
        }
        // in the following for loop, we iterate over rows of the vector to calculate each rows' approximation with previous step's value
        for (int k = 0; k < _y_0.size(); k++) {
            _result_vec[k][j] = y_temp[k] + _dt * _func(y_temp)[k];
        }
    }
}