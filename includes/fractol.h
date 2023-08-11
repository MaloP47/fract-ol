/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:31:04 by mpeulet           #+#    #+#             */
/*   Updated: 2023/07/27 09:03:07 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

/* *** includes *** */

# include "mlx.h"
# include "mlx_int.h"
# include "libft.h"

# include "messages.h"
# include "struct.h"

# include <complex.h>
# include <math.h>
# include <X11/X.h>

# include "purple_colors.h"
# include "rainbow_colors.h"
# include "y_to_o_colors.h"

/* *** define *** */

# define WIDTH 1920
# define HEIGHT 1080

# define ZOOM_IN 0.75
# define ZOOM_OUT 1.5

# define MOUSE_ZOOM 0.5
# define MOUSE_W_UP 4
# define MOUSE_W_DOWN 5

# define MOVE_DISTANCE 0.2
# define MOVE_UP 1
# define MOVE_DOWN 2
# define MOVE_LEFT 3
# define MOVE_RIGHT 4

# define MANDELBROT 1
# define JULIA 2
# define BURNING 3
# define LYAPUNOV 4

# define LIMIT 214748

/* *** SRC *** */
/* *** *** *** *** src/fractals *** *** *** *** */

int		burning_ship(t_fractol *f, double complex_real, double complex_imag);

double	random_double_real(void);
double	random_double_imag(void);
void	julia_random_values(t_fractol *f);
int		julia(t_fractol *f, double z_real, double z_imag);

int		lyapunov(t_fractol *f, double z_real, double z_imag);

int		mandelbrot(t_fractol *f, double complex_real, double complex_imag);
/*int	pow_mandelbrot(t_fractol *f, double complex_real, 
*double complex_imag, int p)*/
/*int	var_mandelbrot(t_fractol *f, double complex_real,
* double complex_imag)*/

/* *** *** *** *** ---- *** ---- *** *** *** *** */

/* *** close_program.c *** */

int		close_program(t_fractol *f);

/* *** colors.c *** */

void	white_to_purple_light(int *colorama);
void	white_to_purple_dark(int *colorama);
void	yellow_to_orange(int *colorama);
void	rainbow(int *colorama);
int		*init_colorama(t_fractol *f, int selection);

/* *** events.c *** */

void	print_controls(void);
int		keyboard_input_management(int keysym, t_fractol *f);
void	event_management(t_fractol *f);

/* *** extra_keyboard_actions.c *** */

void	change_fractal(t_fractol *f);
void	change_color(t_fractol *f);
void	change_julia_set(t_fractol *f);

/* *** full_default_init.c *** */

void	lyapunov_init(t_fractol *f);
void	julia_init(t_fractol *f, int starting_pos);
void	init_shape(t_fractol *f);
void	struct_init(t_fractol *f);
void	window_init(t_fractol *f);

/* *** movements_in_window.c *** */

void	zoom(t_fractol *f, double zoom);
void	move(t_fractol *f, double move, int direction);
int		mouse_event_management(int button, int x, int y, t_fractol *f);
int		keyboard_movements(int keysym, t_fractol *f);

/* *** parsing.c *** */

int		ok_f(t_fractol *f, char *av);
int		ok_j(t_fractol *f, char *av1, char *av2);
int		parsing_arg(t_fractol *f, int ac, char **av);
void	show_options(void);

/* *** render.c *** */

void	pix_put(t_ima *img, int x, int y, int color);
int		pix_calculate(t_fractol *f, double real, double imag);
void	render(t_fractol *f);

/* *** utils_init.c *** */

void	init_pos(t_fractol *f);
void	init_zoom(t_fractol *f);
void	init_mlx_utils(t_fractol *f);
void	img_struct_init(t_fractol *f);

#endif
