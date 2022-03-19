It is an optional 2 person project for Advanced Programming (IN1503) at TUM. 

# AdvProg_ODE_Solver

Idea contributed by Gerasimos Chourdakis <chourdak@in.tum.de> and Hasan Ashraf <ashraf@in.tum.de>. The projetc description can be found under ode-solver.md file.

It is implemented by Ceren Kartal <ceren.kartal@tum.de> and Samed Bayer <ge32cak@mytum.de>

## Overview

The goal of this project is to solve [ordinary differential equations](https://en.wikipedia.org/wiki/Ordinary_differential_equation) which is a classical application
in scientific computing and a basic component in every simulation software
package. In this project, [explicit Euler scheme](https://en.wikipedia.org/wiki/Euler_method) and [implicit Euler scheme](https://en.wikipedia.org/wiki/Backward_Euler_method)is implemented in C++. 

## How to use?

The user can choose Explicit or Implicit Euler ode solvers / schemes at runtime on the terminal. Additional parameters like time step value, inital values and end time should be also given in the same way. 
The code itself would find the approximate results and prints them on the console and also writes the results in a file. 

The user can define different ODE functions in the main.cpp and give them to the different schemes to be solved.

CMakeLists.txt helps to build the code and generate a make file. By running **make**, the user can create an executable file **ODESolver**.

## Functions and Classes

### main

Main function takes the type of the ODE and the additional parameters from the user. According to these parameters, it calls other functions with given parameters. 
Main function creates a class object according to the user input. It accesses different methods of the class.

### class Euler

It is an abstract base class, which all the schemes share. The purpose of this class is to set some rules what the child classes implement when they are inherited from this class. Also it has some other methods which are common for all the schemes (child classes). 
It has a getter method which gives the result. Also, it has abstract units of behaviors that can be shared by multiple child classes for printing, testing the result, and writing the results into a file.
It has a virtual solve() method, which enforces child classes to have body of this method.

### class Explicit

This class is child class of the Euler class. It has a solve() method solving ODE by using Explicit Euler numerical method. 
 
It uses another function which takes and returns **vector** data structure holding **double** data type. This function has the ODE that is wanted to be solved. It is taken from the users while constructing the object.

With Explicit Euler numerical method, it solves ODE with inital values step by step.

### class Implicit

This class is child class of the Euler class. This class has a solve() method solving ODE by using Implicit Euler numerical method. 

It uses another function which takes and returns **vector** data structure holding **double** data type. This function has the ODE that is wanted to be solved. It is taken from the users while constructing the object.

It uses another function which takes and returns **vector** data structure holding **double** data type. This function has the derivative of the ODE function that is wanted to be solved. It is taken from the users while constructing the object.

With Implicit Euler numerical method, it solves ODE with inital values step by step.

### How to include a new solver?

In order to include a new solver, a new subclass of the main class, class Euler in our project, must be added to code. The new subclass will access to the protected variables of the subclass. If other inputs, such as derivative of the function, are required, these variables must be defined within the subclass.

The subclass needs to include solve() method overriding the virtual method of the base class to solve the ODE.

### Dahlquist

This function contains the Dahlquist’s test equation:

<a href="https://www.codecogs.com/eqnedit.php?latex=\dot{x}&space;=&space;\lambda&space;x" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\dot{x}&space;=&space;\lambda&space;x" title="\dot{x} = \lambda x" /></a>


It takes initial condition as a **vector** data structure (One dimensional data structure and all of its elements are in **double** data type) and also returns **vector** compatibility. It is defined constant so that it will not be changed during runtime.

### Diff_Dahlquist

This function contains the derivative of the Dahlquist’s test equation. It takes the solution as a **vector** data structure and all of its elements are in **vector** data structure which stores **double** data type. It is given to the object if the implicit solver type is selected by the user.

### Dahlquist_analytical

This function contains the analytical solution of the Dahlquist’s test equation. It is used for unit test of the approximated results. It is given to the test method of the abstract base class if the approximated solution is wanted to be tested.

### test_Dahlquist

This function is for comparing the approximate values of the Dahlquist’s test equation estimated via explicit Euler method with the analytical solution of the Dahlquist’s test equation.

It takes approximate values as a **vector** data structure and all of its elements are in **vector** data structure which stores **double** data type. It also takes the step size, tolerance limit and end time as double arguments. 

According to these arguments, it finds the absolute values of approximate and exact results. 

If the average of the errors is less than the tolerance value given by main function, the function returns true as boolean data type. Otherwise, it returns false. Also, it prints result of the test on the console.


## Example

### Dahlquist

By using Dahlquist’s test equation below and initial values below, the approximate values are calculated:

<a href="https://www.codecogs.com/eqnedit.php?latex=\dot{x}&space;=&space;\lambda&space;x" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\dot{x}&space;=&space;\lambda&space;x" title="\dot{x} = \lambda x" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=x(0)=1" target="_blank"><img src="https://latex.codecogs.com/gif.latex?x(0)=1" title="x(0)=1" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=\lambda&space;=-1" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\lambda&space;=-1" title="\lambda =-1" /></a>



<a href="https://www.codecogs.com/eqnedit.php?latex=\begin{matrix}&space;dt=&space;0.1&space;\\&space;t(0)=0&space;\\&space;t(end)=&space;5&space;\end{matrix}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?\begin{matrix}&space;dt=&space;0.1&space;\\&space;t(0)=0&space;\\&space;t(end)=&space;5&space;\end{matrix}" title="\begin{matrix} dt= 0.1 \\ t(0)=0 \\ t(end)= 5 \end{matrix}" /></a>


Explicit_Euler function returns  calculated values below by using parameters above:
<pre>
[
1    0.9    0.81    0.729     0.6561   0.59049     0.531441     0.478297   0.430467    0.38742  0.348678   0.313811    0.28243     0.254187     0.228768    0.205891    0.185302    0.166772    0.150095    0.135085    0.121577    0.109419    0.0984771   0.0886294   0.0797664   0.0717898       0.0646108   0.0581497   0.0523348   0.0471013   0.0423912   0.038152    0.0343368   0.0309032   0.0278128   0.0250316   0.0225284   0.0202756   0.018248    0.0164232   0.0147809   0.0133028   0.0119725   0.0107753   0.00969774  0.00872796  0.00785517  0.00706965  0.00636269  0.00572642  0.00515378
]
</pre>

These approximate values are found under the tolerance limit by using the tolerance value in the unit test function. That means that approximate values are calculated correctly and our solver can solve first order ODEs. Tolerance value can be changed in main function and for this example, tolerance value used can be seen below:


<a href="https://www.codecogs.com/eqnedit.php?latex=tol&space;=&space;10^{-2}" target="_blank"><img src="https://latex.codecogs.com/gif.latex?tol&space;=&space;10^{-2}" title="tol = 10^{-2}" /></a>

