#include <iostream>
#include "Euler.h"
#include <fstream>

//construct Euler
Euler::Euler(std::vector<double> y_0, double dt, double t_end, std::function<std::vector<double>(std::vector<double>)> func)
:_y_0(y_0), _dt(dt), _t_end(t_end), _func(func)
{
    _numberOfTimeSteps = std::ceil(_t_end / _dt + 1);
    _result_vec.resize(_y_0.size(), std::vector<double>(_numberOfTimeSteps));
}

//print result matrix
void Euler::print_result() {
    std::cout << "[" << std::endl;
    for (const auto& row : _result_vec) {
        for (const auto& elem : row) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
}

//get result matrix
std::vector<std::vector<double> > Euler::result() const {
    return _result_vec;
}

//test result matrix
bool Euler::test(std::function <double(double)> f_analytical) {
    double tol{ 1e-2};
    std::vector<double > errors(_numberOfTimeSteps, 0.0);  
    float sum{ 0.0 };

    for (int j = 0; j < _numberOfTimeSteps; j++) {
        errors[j] = std::abs(_result_vec[0][j] - f_analytical(_dt * j));
        sum += errors[j];
    }

    double avg_error(sum / _numberOfTimeSteps); // average error

    if (avg_error > tol){
        std::cout << "ERROR is NOT under the tolerance limit" << std::endl;
        std::cout << "Restart the program and try with different step size" << std::endl;
        return false;
    }

    std::cout << "WORKING UNDER TOLERANCE LIMITATION"<< std::endl;
    return true;
}


//write result matrix
void Euler::write_to_csv(std::string a){

    std::string file_name = a + ".csv" ;
    std:: cout << file_name << "\n";
   // open file stream for output
   std::ofstream csv_file(file_name);

   // csv column headers
   csv_file << "time_step,values \n";

    for (int j = 0; j < _result_vec.size(); j++) {
        for( size_t i = 0; i < _result_vec[j].size(); i++ ){
        csv_file << _dt*i << ","<<_result_vec[j][i] << "\n";
         }
    }
   csv_file.close();
}


