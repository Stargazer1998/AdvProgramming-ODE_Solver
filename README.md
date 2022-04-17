# AdvancedProgramming_Bonus_ODE

## ODE SOLVER

This code is written by the Basak Kapusuzoglu and Safa Yilmaz for the compulsory  Advanced Programming course of TUM CSE Master Program.

### MOTIVATION

The purpose of the project is to implement a well known ODE solver to the C++ language. In the first sprint of the Project, Explicit Euler method was implemented. In the second sprint of the Project, Explicit Heun Method and Explicit Runge Kutta Method were implemented by using Object Oriented Programming. The code is divided into different files to enable the user to easily understand and use the code.

### HOW TO USE ?

1. First thing that user is required to do is to exact the provided .zip file. 

2. Second important thing that user has to do is to implement the right hand side of the ODE. This must be performed in **RHS.cpp** file. Inside this file function called **fun** is defined which returns **std::vector<std::vector<double>>**. Depending on the degree of the ODE, define the RHS function(s) as a column vector.

3. Inside the provided  file, a CMakeLists.tx is given for the user, to compile the code CMake Software is required. 

4. Open the termial where the CMakeLists is extracted, type the followings on the terminal
```
$ cmake .
$ make
$ ./ExplicitSolver

```

-Required parameters to solve the given equations are taken by the user during the run time. These parameters are as following:
1. End Time 
2. Time step
3. Initial Condition(s), depending on the nature of the ODE program firstly asks how many initial conditions are requried; then, initial conditions are taken by the user. 

-After defining the required parameters, program asks user to choose desired Explicit Method, available ones are as following:
1. Expilicit Euler
2. Expilicit Heun 
3. Expilicit Runge-Kutta

### CLASSES

![alt text](https://imgyukle.com/f/2022/01/13/occG1H.jpg)

#### ExpSolvers

The base class for the 3 different explicit ODE methods. It contains **virtual** Solve() function. 

#### Euler

First derived class from ExpSolvers. It overrides on the Solve function. To construct the class, intial condition(s) and time domain must be provided.

#### Heun

Second derived class from ExpSolvers. It override its on method on Solve function. It also needs initial condition(s) and time domain to construct the class. Different from **Euler** it needs **MatrixOperations.cpp** file to perform following operations:
 
- +operator takes two vectors as input and returns a vector which is summation of these two vectors.
- *operator takes a vector and a double as input and returns a vector which is multiplication of the vector with the double.
_In case user needs  any other operator overloading feature in its own program, these functions can be implemented on this file._ 

#### RungeKutta

Third derived class from ExpSolvers. Its requirements are the same as **Heun**, then implement its own explicit method.

### FUNCTIONS  

#### CreateTimeDomain.cpp

It is used to create the required time domain for the given equation. One can easily make some modifications on this file to implement any other method for the problem. With given end time and time increment, program checks if it is possible to reach the end time or not. If this is not the case following error will be created on the screen.  
```
Inputs are not compatible ! Using the given inputs, it is not possible to reach exatcly the desired end time !
```
#### GetSolution.cpp

Contains save_Sol and print_Sol functions in it. save_Sol function takes Solution and Solver name as input and saves the solution as .txt file with the explicit method name.
print_Sol function takes the Solution as an input and prints the elements.


#### RHS.cpp 

This is the only file that user must make some modifications

#### TestFunction.cpp 

This contains the function called Test_Exp, which takes the created time domain and explicit solver as an input and compares with the actual exponential function. If the maximum errror is found to be greater than 0.001 following error will be printed on the screen with the found error:
```
Desired trashold can not be achived with the given input :(
```
If the found error less than the 0.001 then following line will be printed with the found error:


```
Good news, you reached desired error trashold, it seems that you're going well !
```

Note that the test function provided in the code is specific to the example which is provided in the code. It cannot be used for other functions!

### An Example

**Dahlquist’s test equation** 

```math
\frac{dx}{dt} = - \lambda x  \qquad\qquad \lambda = 1  \qquad\text{and}\qquad x(0) = 1
```

- Go in to **RHS.cpp** file and modify function named **fun** as following:
```
std::vector<double> fun(const std::vector<double>& x){
    std::vector<double> y={-x[0]
                          };

    return y;
}
```

- The only required change is performed on the file. Now, explained steps in **HOW TO USE** file is implemeted.
1.Create CMake
```
stargazer@stargazer-VirtualBox:~/Desktop/ProjectFinal$ cmake .
-- The CXX compiler identification is GNU 10.3.0
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done
-- Generating done
-- Build files have been written to: /home/stargazer/Desktop/ProjectFinal
```
2. Compile the File 
```
stargazer@stargazer-VirtualBox:~/Desktop/ProjectFinal$ make 
Scanning dependencies of target ExplicitSolver
[ 10%] Building CXX object CMakeFiles/ExplicitSolver.dir/main.cpp.o
[ 20%] Building CXX object CMakeFiles/ExplicitSolver.dir/CreateTimeDomain.cpp.o
[ 30%] Building CXX object CMakeFiles/ExplicitSolver.dir/Euler.cpp.o
[ 40%] Building CXX object CMakeFiles/ExplicitSolver.dir/GetSolution.cpp.o
[ 50%] Building CXX object CMakeFiles/ExplicitSolver.dir/Heun.cpp.o
[ 60%] Building CXX object CMakeFiles/ExplicitSolver.dir/MatrixOperations.cpp.o
[ 70%] Building CXX object CMakeFiles/ExplicitSolver.dir/RHS.cpp.o
[ 80%] Building CXX object CMakeFiles/ExplicitSolver.dir/RungeKutta.cpp.o
[ 90%] Building CXX object CMakeFiles/ExplicitSolver.dir/TestFunction.cpp.o
[100%] Linking CXX executable ExplicitSolver
[100%] Built target ExplicitSolver
```

3. Run the code
```
stargazer@stargazer-VirtualBox:~/Desktop/ProjectFinal$ ./ExplicitSolver
```

4. Give the Required Parameters
```
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
       ~~~~~~~~~~  Welcome to Explicit Solver ~~~~~~~~~~ 
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
Have you already defined your RHS function in RHS.cpp file ?
If you have done so, there are a few more parameters you need to set:
*End Time
*Time Step
Enter the End Time:  20
Enter the time step:  0.01
Almost done! You need to define your initial condition(s) as well. In case you're working with higher order ODE initial conditions must be defined as array.Enter how many initial conditions your ODE need: 1
1. value: 1
Please tell which solver you want to use: 
 1) Euler 
 2) Heun 
 3) Runge Kutta 
1
Desired trashold can not be achived with the given input :(
It seems that there is a wrong with your time steps, try to deacrese it ! 
obtained error:0.0018471
```
With the given parameters, Euler could not get desired error trashold, one can check the values created file called Euler.txt in the same file. 


