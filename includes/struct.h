/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 11:02:38 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/27 18:30:39 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

/*
* Struct: t_fractol
* This structure holds all necessary variables to draw and manage fractals.
* 
* Field: t_pos pos
* Holds the x and y positions in the window.
*
* Field: t_mlx_u utils
* Holds pointer and window mlx utilities.
* 
* Field: t_shape shape
* Holds the coordinates for shapes.
*
* Field: t_zoom zoom
* Holds variables to calculate zoom.
*
* Field: t_lya l
* Holds Lyapunov variables.
* 
* Field: int julia_options
* Holds initialization options for Julia sets.
*
* Field: int* colorama
* Holds a table of hardcoded colors.
*
* Field: int color_index
* Defines the starting color in the color table.
*
* Field: int max_iter
* Defines the limit of iterations while drawing.
*
* Field: int fractal
* Defines the type of fractal to be drawn (1 == Mandelbrot, 2 == Julia,...).
*
* Field: t_ima img
* Holds mlx_img information.
*/

/*
* Struct: t_ima
* Manages mlx image data.
* 
* Field: void* mlx_img
* Address of mlx image.
*
* Field: char* addr
* String containing each pixel.
* 
* Field: int bpp
* Bytes per pixel.
*
* Field: int line_len
* Length of *addr.
*
* Field: int endian
* Ensures system portability.
*/

typedef struct s_my_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}		t_ima;

typedef struct s_pos
{
	int		x;
	int		y;
}		t_pos;

typedef struct s_zoom
{
	double	new_real;
	double	new_imag;
}		t_zoom;

typedef struct s_utils
{
	void	*ptr;
	void	*wd;
}		t_mlx_u;

typedef struct s_complex
{
	double	cr;
	double	ci;
}		t_complex;

typedef struct s_shape
{
	double		min_real;
	double		max_real;
	double		min_imag;
	double		max_imag;
	t_complex	julia;
}		t_shape;

typedef struct s_lyapunov
{
	t_complex	a;
	t_complex	b;
	t_complex	t;
	double		lya;
	char		*sequence;
	int			seq_len;
	int			final;
}		t_lya;

typedef struct s_fractol
{
	t_pos	pos;
	t_mlx_u	utils;
	t_shape	shape;
	t_zoom	zoom;
	t_lya	l;		
	int		julia_options;
	int		*colorama;
	int		color_index;
	int		max_iter;
	int		fractal;
	t_ima	img;
}		t_fractol;

#endif