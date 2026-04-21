Project Objective
In this project, we aimed to simulate the trajectory of a projectile using physics formulas, and then display this trajectory as an image.
The main objective was to understand how theoretical calculations can be turned into something visual using a C++ program. It also helps practice working with functions, files, and arrays.
Description
This program simulates the motion of a projectile and generates an image showing its trajectory. It can handle different types of motion, including rebounds with or without energy loss.
Prerequisites
To use this program, you need:
a C++ compiler (g++, clang, etc)
a terminal or an IDE (Code::Blocks, Visual Studio, VS Code, etc)
Installation
Download or clone the project files
Compile the program with a command like:
Run the program
If there is a problem:
make sure all files are in the same folder
check that the .h file is correctly included


User Guide
When the program starts, it asks for:
the initial position (x0, z0)
the initial velocity
the launch angle
Then you choose a simulation mode:
simple launch
custom starting position
elastic rebounds
inelastic rebounds
At the end, an image is generated:
trajectoire.pgm
This image can be opened with any software that supports the PGM format.
How it works
The program first collects the user input, then it splits the velocity into two components:
horizontal (X axis)
vertical (Z axis)
Then, it calculates the position of the projectile at different moments in time.
Physical Model
The motion is based on the following equations:
x = x0 + vx0 × t
z = z0 + vz0 × t − 0.5 × g × t²
vz = vz0 − g × t
with g = 9.81 m/s².
The calculation is done step by step using a time increment.

Visualization
Each calculated point is converted into a pixel and displayed in an image.
The result is a black and white image where the trajectory appears in white. The generated file is called: trajectoire.pgm
Simulation Modes
The program offers several modes:
Launch from origin
The projectile starts from (0,0) and performs a single bounce.
Launch with initial position
The user chooses the starting height, but there is still only one launch.
Elastic rebounds
The projectile bounces without losing energy. The vertical velocity simply changes direction at each impact.
Inelastic rebounds
The projectile loses energy at each bounce. The bounces become smaller and smaller until it stops.
Code Organization
The project is divided into several files:
main.cpp: handles user input and program flow
biblio_fonctions.h: contains function declarations
biblio_fonctions.cpp: contains calculations and functions
Important Points
The motion is simulated using a time step
Real-world coordinates (meters) are converted into pixels
Some values are returned using references
The program ensures it stays within image boundaries


Results
Depending on the selected mode, the program can display:
the distance traveled
the velocity at impact
Possible Improvements
Some ideas to improve the project:
add air resistance
improve graphical display
add zoom or scaling
enhance user interaction
License
This project is for educational purposes. It can be used and modified freely.
Contributors
Project by: ENZO POINARD and JOACHIM BEAL
Conclusion
This project shows how physics formulas can be used in a program and visualized. Even with a simple model, it gives a good idea of how a simulation works
