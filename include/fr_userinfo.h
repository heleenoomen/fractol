#ifndef FR_USER_INFO_H
# define FR_USER_INFO_H

# define USAGE "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
\tspecify at least one parameter:\n\
\t fractal name: <Mandelbrot/Julia/Newton/M/J/N>\n\n\
\tthe following optional parameters may be used:\n\
\t  color: <bernstein/rainbow/psychedelic/be/ra/ps/b/r/p>\n\
\t  for Julia only: <real axis coordinate> <imaginary axis coordinate>\n"

# define USAGE_NAME "\n\tPlease provide valid fractal name: Mandelbrot/Julia/Newton/M/J/N\n"

# define USAGE_COLOR "\n\tPlease provide valid color parameter: bernstein/rainbow/psychedelic/be/ra/ps/b/r/p\n\
\tIf no color parameter is provided, 'bernstein' coloring algorithm will be used\n"

# define USAGE_JULIA "\n\tJulia usage:\n\n\
\t ./fractol Julia <color> <real_coordinate> <imaginary_coordinate>\n\
\t ./fractol Julia <real_coordinate> <imaginary_coordinate>\n\
\t ./fractol Julia\n\n\
\tNB provide either zero or two valid coordinates for Julia set\n\
\tCoordinates should be representable as a double, e.g.:\n\n\
\t\t./fractol Julia 0.15 -1.17\n\
\t\t./fractol Julia rainboow 0.1534 -2.17\n\n\
\tIf no coordinates are provided, default coordinates {-0.79, 0.15} will be used\n"

# define INFO_NEWTON "\n\tNewton fractal for f(x) = x^3 - 1, coloring based on number of iterations\n"

# define INFO_JULIA "\n\tJulia set for parameters {%f, %f}\n", fr->j_re, fr->j_im

# define INFO_MANDELBROT "\n\tMandelbrot set\n"

# define USER_INFO "\n\tZoom with mouse wheel\n\
\tUse arrow keys to move through picture\n\
\tAdd iterations:\tpress x\n\
\tDecrease iterations:\tpress z\n\
\tReset zoom and iterations:\tpress space\n\
\tShift color: press numbers 0 - 9\n\
\tChange color scheme:\n\
\t\tpress b for bernstein\n\
\t\tpress r for rainbow\n\
\t\tpress p for psychedelic\n\
\tChange fractol:\n\
\t\tpress m for Mandelbrot set\n\
\t\tpress j for Julia set\n\
\t\tpress n for Newton fractal\n\
\tPrint current range:\tpress c\n\n\
\tJulia:\n\
\t\tchange to Mandelbrot:\tpress m\n\
\t\tshift coordinates:\n\
\t\t\tpress { to move up (imaginary axis)\n\
\t\t\tpress / to move down (imaginary axis)\n\
\t\t\tpress ; to move down (real axis)\n\
\t\t\tpress ' to move up (real axis)\n\
\t\t\tright click to generate julia set of the coordinates clicked on\n\
\t\t\tpress i to print parameters of julia set\n\
\tMandelbrot:\n\
\t\tswitch to corresponding Julia set: right click on coordinates\n"


#endif