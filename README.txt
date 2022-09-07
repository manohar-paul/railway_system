// Paul Manohar Pusuluri
//  
// README.txt

The project is made with the MakeFile Build tool.

Here every .h file is the header file and does not have implementation in it unless it is a template class where there are many templates and share a common body for a method. In this case I have written the body also in the header for some of them which are described by the above behaviour.
Every .cpp file gives the implementation and static constants of the class.

So the following are the commands

For running the application tests
1. mingw32-make.exe apptest

For running the unit tests
2. mingw32-make.exe unittest

For running the application
2. mingw32-make.exe run

Note: ``mingw32-make`` might not work for you and in that case try ``make`` inplace of it

THE PROJECT STRUCTURE:


|
|
|___ bin (this directory includes all the .exe output files)
    |
    |__ main.exe
    |__ test.exe
    |
|___ include (this directory includes all the .h files)
    |
    |__ Booking.h
    |__ Gender.h
    |
    .
    .
    .
|___ src (this directory includes all the .cpp files which does not contain main function)
    |
    |__ Booking.cpp
    |__ Gender.cpp
    |
    .
    .
    .
|___ test (this directory includes all the .cpp files which does contain main functions for tests)
    |
    |__ ApplicationTest.cpp 
    |__ UnitTest.cpp
    |
|___ application (this directory includes all a cpp file which does contain main functions for running the application)
    |
    |__ Application.cpp
