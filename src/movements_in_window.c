/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_in_window.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 13:10:23 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/26 15:18:46 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	zoom(t_fractol *f, double zoom)
{
	f->zoom.new_real = f->shape.min_real - f->shape.max_real;
	f->zoom.new_imag = f->shape.max_imag - f->shape.min_imag;
	f->shape.max_real = f->shape.max_real
		+ (f->zoom.new_real - zoom * f->zoom.new_real) / 2;
	f->shape.min_real = f->shape.max_real + zoom * f->zoom.new_real;
	f->shape.min_imag = f->shape.min_imag
		+ (f->zoom.new_imag - zoom * f->zoom.new_imag) / 2;
	f->shape.max_imag = f->shape.min_imag + zoom * f->zoom.new_imag;
}

void	move(t_fractol *f, double move, int direction)
{
	f->zoom.new_real = f->shape.min_real - f->shape.max_real;
	f->zoom.new_imag = f->shape.max_imag - f->shape.min_imag;
	if (direction == MOVE_UP)
	{
		f->shape.min_imag += f->zoom.new_imag * move;
		f->shape.max_imag += f->zoom.new_imag * move;
	}
	else if (direction == MOVE_DOWN)
	{
		f->shape.min_imag -= f->zoom.new_imag * move;
		f->shape.max_imag -= f->zoom.new_imag * move;
	}	
	else if (direction == MOVE_LEFT)
	{
		f->shape.min_real += f->zoom.new_real * move;
		f->shape.max_real += f->zoom.new_real * move;
	}
	else if (direction == MOVE_RIGHT)
	{
		f->shape.min_real -= f->zoom.new_real * move;
		f->shape.max_real -= f->zoom.new_real * move;
	}
}

int	mouse_event_management(int button, int x, int y, t_fractol *f)
{
	if (button == MOUSE_W_UP)
	{
		if (f->fractal <= 3)
			f->max_iter += 5;
		zoom(f, MOUSE_ZOOM);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, (double)abs_value(x) / WIDTH, MOVE_LEFT);
		else if (x > 0)
			move(f, (double)x / WIDTH, MOVE_RIGHT);
		if (y < 0)
			move(f, (double)abs_value(y) / HEIGHT, MOVE_UP);
		else if (y > 0)
			move(f, (double)y / HEIGHT, MOVE_DOWN);
	}
	else if (button == MOUSE_W_DOWN)
	{
		if (f->fractal <= 3)
			f->max_iter -= 5;
		zoom(f, ZOOM_OUT);
	}
	render(f);
	return (0);
}

int	keyboard_movements(int keysym, t_fractol *f)
{
	if (keysym == XK_Up || keysym == XK_w)
		move(f, MOVE_DISTANCE, MOVE_UP);
	else if (keysym == XK_Down || keysym == XK_s)
		move(f, MOVE_DISTANCE, MOVE_DOWN);
	else if (keysym == XK_Left || keysym == XK_a)
		move(f, MOVE_DISTANCE, MOVE_LEFT);
	else if (keysym == XK_Right || keysym == XK_d)
		move(f, MOVE_DISTANCE, MOVE_RIGHT);
	render(f);
	return (0);
}
