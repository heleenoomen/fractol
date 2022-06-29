#ifndef FR_USERINFO_H
# define FR_USERINFO_H

# define USAGE "\n\tUsage: ./fractol <fractal name> <optional parameters>\n\n\
\tspecify at least one parameter:\n\
\t fractal name: <Mandelbrot/Julia/Newton/M/J/N>\n\n\
\tthe following optional parameters may be used:\n\
\t  color: <natural/pink/green/rainbow>\n\
\t  for Julia only: <real axis coordinate> <imaginary axis coordinate>\n"

# define USAGE_NAME "\n\tPlease provide valid fractal name: Mandelbrot/Julia/Newton/M/J/N\n"

# define USAGE_COLOR "\n\tPlease provide valid color parameter: natural/pink/green/rainbow\n\
\tIf no color parameter is provided, 'natural' coloring algorithm will be used\n"

# define USAGE_JULIA "\n\tJulia fractal: use either two or zero coordinate parameters:\n\n\
\t ./fractol Julia <color> <real_coordinate> <imaginary_coordinate>\n\
\t ./fractol Julia <real_coordinate> <imaginary_coordinate>\n\
\t ./fractol Julia\n\n\
\tif no coordinates are provided, default coordinates {-0.79, 0.15} will be used\n"

# define WARNING_JULIA "\n\tWarning: specified coordinates are outside {2, 2} - input will yield empty fractal\n"

#endif