#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

#include "Implicit.h"

// TODO: Implement constructor and describe()

Implicit::Implicit(const std::vector<double> y_0, const double dt, const double t_end, const std::function<std::vector<double>(std::vector<double>)> func, const std::function<std::vector<double>(std::vector<double>)> dfunc)
        : Euler(y_0, dt, t_end, func), _dfunc(dfunc)
{   
    std::copy(_y_0.begin(), _y_0.end(), std::back_inserter(_y_temp));
    /*
    for(const auto& elem:_y_0){
        _y_temp.push_back(elem);
    }*/
    std::cout << "Constructed the Implicit Method!" << std::endl;
}

inline std::vector<double> Implicit::newton() {
    int N = _y_temp.size(); //size of vector y_temp
    std::vector<double> out_vec(N, 0); //output vector
    std::vector<double> y_temp2chg = _y_temp; //y_temp vector that will be changed in each iteration
    std::vector<double> err(N, 0); //error vector is defined with 0 as initial values
    int numberOfIterations = 0;
    double max_elm = 1;

    while ((numberOfIterations<=100) && (max_elm>1e-8)) {

        std::vector<double> df_return, f_return;

        for(int i = 0; i<N; i++){
            df_return.push_back(_dfunc(y_temp2chg)[i] * _dt - 1.0);
            f_return.push_back(_y_temp[i] + _dt * _func(y_temp2chg)[i] - y_temp2chg[i]);

            out_vec[i] = y_temp2chg[i] - (f_return[i]/df_return[i]);
            err[i] = std::abs(out_vec[i] - y_temp2chg[i]);
            y_temp2chg[i] = out_vec[i];
        }
        max_elm = *std::max_element(err.begin(), err.end());
        numberOfIterations++;
    }

    if (max_elm>1e-2){
        std::cout<< " Newton solver got stuck while finding the root, solution might be not correct " ;
    }
    return out_vec;
}


inline void Implicit::solve() {

    // initializing y output vector with initial condition
    // only the first column changed
    // we iterate over number of columns, which is equal to the size of initial condition vector given
    for (int j = 0; j < _y_0.size(); j++) {
        _result_vec[j][0] = _y_0[j];
    }

    for (int j = 1; j < _numberOfTimeSteps; j++) {

        // in the following loop, we fill y_temp vector with the previous step's values
        for (int d = 0; d < _y_0.size(); d++) {
            _y_temp[d] = _result_vec[d][j - 1];
        }
        std::vector<double> ynewton = Implicit::newton();

        // in the following for loop, we iterate over rows of the vector to calculate each rows' approximation with previous step's value
        for (int k = 0; k < _y_0.size(); k++) {
            _result_vec[k][j] = ynewton[k];
        }
    }
}