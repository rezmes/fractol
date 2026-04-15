*This project has been created as part of the 42 curriculum by mmesgari.*

# fract-ol

## Description

**fract-ol** is a small interactive fractal exploration program written in C using the **MiniLibX** graphical library.

The project focuses on rendering mathematical fractals in real time and letting the user explore them through zooming, movement, and color variation. It introduces core ideas in complex numbers, iterative formulas, low-level pixel drawing, event handling, and interactive graphics programming.

This implementation includes the mandatory fractals:
- **Mandelbrot**
- **Julia**

It also includes bonus features:
- **Burning Ship** fractal
- **Mouse-centered zoom**
- **View movement with arrow keys**
- **Color range shifting**

---

## Features

### Mandatory part
- Renders the **Mandelbrot set**
- Renders the **Julia set**
- Displays the fractal inside a graphical window
- Uses a MiniLibX image buffer for drawing
- Supports smooth window behavior
- Exits cleanly when pressing **ESC**
- Exits cleanly when clicking the window close button
- Accepts command-line parameters to select the fractal
- Displays a usage message and exits if parameters are invalid
- Uses multiple colors to represent iteration depth

### Bonus part
- Adds a third fractal: **Burning Ship**
- Zoom follows the actual mouse position
- Arrow keys move the current view
- Color palette can be shifted interactively

---

## Project structure

Example project layout:

```txt
.
├── Makefile
├── README.md
├── fractol.h
├── main.c
├── render.c
├── utils.c
└── minilibx-linux/
```
## Compilation

### To compile the project, run:
```bash
`make`
```
### Useful Makefile rules:
```bash
make clean
make fclean
make re
```
The executable generated is:

```bash
./fractol
```
## Usage
### Mandelbrot
```bash
./fractol mandelbrot
```
### Julia
```bash
./fractol julia <x> <y>
```

## Example:

```bash
./fractol julia -0.8 0.156
```
### Burning Ship
```bash
./fractol burning_ship
```
If no valid argument is provided, the program prints a usage message and exits properly.

## Controls
* General controls
* Mouse wheel: zoom in / zoom out
* ESC: quit the program
* Window close button: quit the program
## Bonus controls
* Left arrow: move left
* Right arrow: move right
* Up arrow: move up
* Down arrow: move down
* C: shift colors forward
* X: shift colors backward
---
## Technical overview

Each pixel of the window is mapped to a point in the complex plane.

For each point, the program applies an iterative formula:

* **Mandelbrot** starts from z = 0 and uses the current pixel as the complex constant c
* **Julia** starts from the current pixel as z and uses the command-line parameters as the constant c
* **Burning Ship** applies a variation using absolute values before each iteration step

The number of iterations before divergence determines the color of the pixel.

Rendering is done by writing directly into a MiniLibX image buffer and then pushing that image to the window.

## Bonus details
### Mouse-centered zoom

Zooming is centered on the current mouse position so that the point under the cursor remains visually stable during zoom.

## View movement

The visible region of the complex plane can be translated using the arrow keys.

## Color shifting

The color palette can be adjusted interactively in order to explore different visual ranges without changing the fractal formula itself.

## Error handling

The program handles the following cases safely:

* missing arguments
* invalid fractal name
* invalid Julia parameters
* clean exit on keyboard or window close event

If initialization fails, the program exits without leaving allocated graphical resources behind.

## MiniLibX and dependencies

This project uses the Linux version of **MiniLibX**.

Typical required libraries on Linux include:

* X11
* Xext
* math library
* BSD compatibility library on some systems

Depending on the environment, the following development packages may be needed:

```bash
libx11-dev
libxext-dev
libbsd-dev
```
## Resources
### Fractals
* Mandelbrot set
* Julia set
* Burning Ship fractal
### Graphics and library
* MiniLibX documentation
* X11 documentation
### Mathematical background
* Complex numbers
* Escape-time fractal algorithms
* Iterative function systems

### AI usage disclosure

Artificial Intelligence was used as a learning and review aid during the development of this project.

It was used for:

* clarifying the mathematical mapping between screen coordinates and the complex plane
* behavior on different Linux environments

All code integration, debugging decisions, testing, and final validation remained under the author's control.

## Notes

This project was developed as part of the 42 curriculum and aims to balance:

* mathematical correctness
* interactive behavior
* clean resource management
* readable C code under project constraints

The goal is not only to render fractals, but also to build a reliable graphical program using low-level tools and event-driven design.