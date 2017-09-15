#Introduction
CS 430 @ NAU
A simple PPM image converter program written in C.

This program uses a command line interface and allows users to convert to and from the binary and ascii
PPM formats (P3 and P6). By allowing the user to specify the input file, the output file, and the desired
format, the program is able to parse and convert any P3 or P6 file.

The program also features error handling for both the command line parameters and the PPM image format.

#Usage
Downloading the zip or using git clone. This includes a makefile which allows you to simply make the
project as long as you are in a UNIX environment.

Unpack the project, open your command line and navigate to the folder. Once in the folder, type make to
build the project.

Once the project is build type ./ppmrw 6 input.ppm output.ppm or ./ppmrw 3 input.ppm output.ppm

The project will run and convert the input and write out to the output file.

#Authors
Colter Hooker
ceh248@nau.edu
