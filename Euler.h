#ifndef EULER_H
#define EULER_H

#include <iostream>
#include <vector>
#include <cmath>
#include <functional>


class Euler {
    protected:
        // variables defined here are common for all methods (Explicit and Implicit)
        const std::function<std::vector<double>(std::vector<double>)> _func; // function to be solved
        std::vector<std::vector<double> > _result_vec; // result vector
        const std::vector<double> _y_0; // initial condition
        const double _dt; //timestep size
        const double _t_end; // ending time
        int _numberOfTimeSteps; // number of time steps

    public:
        //define constructor
        Euler(const std::vector<double>, const double, const double, const std::function<std::vector<double>(std::vector<double>)> );

        // Add virtual solve() method for each implementation
        virtual void solve() = 0;

        // Add method to print result matrix
        void print_result();

        // Add method to get result matrix
        std::vector<std::vector<double> > result() const;
        
        // Add method to test the result
        bool test(std::function <double(double)> f_analytical);

        // Declare the destructor as virtual
        virtual ~Euler() = default;

        // Add method to write the result vector to csv file
        void write_to_csv(std::string file_name);
};

#endif // EULER_Η