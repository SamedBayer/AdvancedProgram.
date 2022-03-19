#include <iostream>
#include <fstream>
#include <cassert>
#include "Euler.h"
#include "Explicit.h"
#include "Implicit.h"

// Define your function to be solved here
inline const std::vector<double> Dahlquist(std::vector<double> v) {
    std::vector<double> y_new = { 0.0 };
    y_new[0] = -1.0 * v[0];
    return y_new;
}
// Define your function's derivative to be solved here 
// in case you want to solve it with Implicit Euler
inline const std::vector<double> Diff_Dahlquist(std::vector<double> v) {
        std::vector<double> y_new{ 0.0 };
        y_new[0] = -1.0;
        return y_new;
}
// Define your function's analytical solution here for test
inline double Dahlquist_analytical(double time_value) {
    double result = std::exp(-1*time_value);
    return result;
}

int main() {

    std::cout<<"Your ODE Solver!"<<std::endl;
    std::cout<<"---------------------------"<<std::endl;
    std::cout<<"The ODE Solver solves with 2 different methods: "<<std::endl;
    while(true) {
        int solver_type;
        double dt ;
        double t_end ;
        double temp_initialValue ;
        std::cout<<"Please choose a method for solving the ODE:"<<std::endl;
        std::cout<<"Note: Dahlquist's test equation (lambda=-1) is being solved by default."<<std::endl;
        std::cout<<"Press 1 for Explicit Euler"<<std::endl;
        std::cout<<"Press 2 for Implicit Euler"<<std::endl;
        std::cout<<"Press 0 to exit"<<std::endl;
        std::cin>>solver_type;

    switch (solver_type){
        case 1: {
            std::cout<<"Give the time step value"<<std::endl;
            std::cin>>dt;
            assert(dt>0 && "Please give the positive time step value");
            std::cout<<"Give the end time"<<std::endl;
            std::cin>>t_end;
            assert(t_end>0 && "Please give the positive end time value");
            std::cout<<"Give the initial condition"<<std::endl;
            std::cin>>temp_initialValue;
            // inputs converted to constant to be used by classes
            const std::vector<double> y_0 = { temp_initialValue };

            Explicit Dahlquist_Explicit(y_0, dt, t_end, Dahlquist);
            Dahlquist_Explicit.solve();
            while (true){
                std::cout<<"Press 1 to print the result"<<std::endl;
                std::cout<<"Press 2 to test the result"<<std::endl;
                std::cout<<"Press 3 to write the result to file"<<std::endl;
                std::cout<<"Press 0 to exit the method"<<std::endl;
                int method_impl;
                std::cin>>method_impl;
                if(method_impl==1) {
                        std::cout<<"Printing the result:"<<std::endl;
                        Dahlquist_Explicit.print_result();
                    }
                else if(method_impl==2){
                        std::cout<<"Testing the method with given analytical solution:"<<std::endl;
                        Dahlquist_Explicit.test(Dahlquist_analytical);
                    }
                else if(method_impl==3){
                        std::string file_name;
                        std::cout<<"Set the name for your output file"<<std::endl;
                        std::cin>>file_name;
                        std::cout<<"Writing the result to the file:"<<std::endl;
                        Dahlquist_Explicit.write_to_csv(file_name);
                    }
                else if(method_impl==0){
                        std::cout<<"Exiting the Explicit Euler method!"<<std::endl;
                        break;
                    }
                else{
                        std::cout<<"Please enter a valid number!"<<std::endl;
                    }
                }
            break;
        }
        
        case 2:
        {
            std::cout<<"Give the time step value"<<std::endl;
            std::cin>>dt;
            assert(dt>0 && "Please give the positive time step value");
            std::cout<<"Give the end time"<<std::endl;
            std::cin>>t_end;
            assert(t_end>0 && "Please give the positive end time value");
            std::cout<<"Give the initial condition"<<std::endl;
            std::cin>>temp_initialValue;
            // inputs converted to constant to be used by classes
            const std::vector<double> y_0 = { temp_initialValue };

            Implicit Dahlquist_Implicit(y_0, dt, t_end, Dahlquist, Diff_Dahlquist);
            Dahlquist_Implicit.solve();
            while (true){
                std::cout<<"Press 1 to print the result"<<std::endl;
                std::cout<<"Press 2 to test the result"<<std::endl;
                std::cout<<"Press 3 to write the result to file"<<std::endl;
                std::cout<<"Press 0 to exit the method"<<std::endl;
                int method_impl;
                std::cin>>method_impl;
                if(method_impl==1) {
                        std::cout<<"Printing the result:"<<std::endl;
                        Dahlquist_Implicit.print_result();
                    }
                else if(method_impl==2){
                        std::cout<<"Testing the method with given analytical solution:"<<std::endl;
                        Dahlquist_Implicit.test(Dahlquist_analytical);
                    }
                else if(method_impl==3){
                        std::string file_name;
                        std::cout<<"Set the name for your output file"<<std::endl;
                        std::cin>>file_name;
                        std::cout<<"Writing the result to the file:"<<std::endl;
                        Dahlquist_Implicit.write_to_csv(file_name);
                    }
                else if(method_impl==0){
                        std::cout<<"Exiting the Implicit Euler method!"<<std::endl;
                        break;
                    }
                else{
                        std::cout<<"Please enter a valid number!"<<std::endl;
                    }
                }
            
            break;
        }
        case 0:
        {
            std::cout<<"Exiting the program!"<<std::endl;
            return 0;
        }

        default:
        {
            std::cout<<"Please enter a valid number!"<<std::endl;
            break;
        }
    }
    }


    return 0;
}