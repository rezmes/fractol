*This project has been created as part of the 42 curriculum by mmesgari@student.42.fr.*

# 🌀 fract-ol

## Description
**fract-ol** is a computer graphics project developed for the 42 curriculum. The primary goal of this project is to create a small 2D fractal renderer using the school's internal graphical library, **MiniLibX**. 

Through this project, we explore the mathematical beauty of complex numbers, the concept of infinite self-similarity, and the technical challenges of low-level graphical optimization in C. The program currently supports the **Mandelbrot** set and dynamically configurable **Julia** sets, featuring infinite mouse-centered zooming and smooth continuous coloring based on iteration counts.

## Instructions

### 1. Compilation
The project comes with a `Makefile`. To compile the project and generate the executable file, simply run:
```bash
make
```
This will compile the source files and create an executable named fractol at the root of the repository.

Other available make rules:

make clean: Removes all the object files (.o).

make fclean: Removes the object files and the fractol executable.

make re: Performs a full re-compilation (fclean followed by make).

2. Execution
Once compiled, you must run the fractol executable with specific parameters. Running it without parameters will display a help menu.

To view the Mandelbrot set:

```Bash
./fractol mandelbrot
```
(You can also simply use m instead of mandelbrot)

To view the Julia set:
The Julia set requires you to provide the Real (X) and Imaginary (Y) parts of the constant C to generate its shape.

```Bash
./fractol julia <X> <Y>
```
(You can also use j instead of julia)

Beautiful Julia examples to try:

```Bash
./fractol julia -0.8 0.156
./fractol julia -0.4 0.6
./fractol julia 0.285 0.01
```
3. Controls
Mouse Scroll: Zoom in and out. The zoom is mathematically centered precisely on the location of your mouse cursor.

ESC Key: Safely exit the program.

Window Close (X): Safely exit the program with zero memory leaks.

Resources
Classic References
Mandelbrot Set (Wikipedia)

Julia Set (Wikipedia)

42Docs - MiniLibX Documentation - Essential for understanding event hooks, memory image manipulation, and window management.

AI Usage Disclosure
Artificial Intelligence (LLM) was utilized during the development of this project strictly as an educational tutor and cognitive prosthetic, specifically for:

Mathematical Visualization: Breaking down the mapping algorithm between 2D screen coordinates (pixels) and the mathematical Complex Plane.