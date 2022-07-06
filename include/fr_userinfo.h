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

# define USER_INFO "\n\t\t\tVIEW\n\
\n\tZoom with mouse wheel\n\
\tUse arrow keys to move through picture\n\
\tAdd iterations:\tpress x\n\
\tDecrease iterations:\tpress z\n\
\tReset zoom and iterations:\tpress space\n\
\n\t\t\tCOLOR\n\
\tShift color: press numbers 0 - 9\n\
\tChange color scheme:\n\
\t\tpress b for bernstein\n\
\t\tpress r for rainbow\n\
\t\tpress p for psychedelic\n\
\n\t\t\tFRACTAL\n\
\tChange fractol:\n\
\t\tpress m for Mandelbrot set\n\
\t\tpress j for Julia set\n\
\t\tpress n for Newton fractal\n\
\tPrint current range:\tpress c\n\n\
\n\t\t\tMANDELBROT\n\
\tswitch to corresponding Julia set: right click on coordinates\n\
\n\t\t\tJULIA\n\
\tshift parameters for Julia:\n\
\t\tpress { to move up (imaginary axis)\n\
\t\tpress / to move down (imaginary axis)\n\
\t\tpress ; to move down (real axis)\n\
\t\tpress ' to move up (real axis)\n\
\tright click on any coordinates to generate Julia set\n\
\tpress i to print parameters of julia set\n\
\n\t\t\tPRINT INFO\n\
\tpress v to print current zoom\n\
\tpress c to print current range\n\
\tpress d to print current number of iterations\n\n"

#endif