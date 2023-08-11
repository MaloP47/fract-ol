/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_keyboard_actions.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 14:09:56 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/26 15:56:40 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	change_fractal(t_fractol *f)
{
	init_shape(f);
	init_zoom(f);
	f->fractal++;
	if (f->fractal == 4)
		f->max_iter = 10;
	if (f->fractal > 4)
	{
		f->max_iter = 100;
		f->fractal = 1;
	}
}

void	change_color(t_fractol *f)
{
	f->color_index++;
	free(f->colorama);
	f->colorama = init_colorama(f, f->color_index);
	if (!f->colorama)
		close_program(f);
	if (f->color_index > 3)
		f->color_index = 0;
}

void	change_julia_set(t_fractol *f)
{
	init_shape(f);
	init_zoom(f);
	f->julia_options++;
	if (f->julia_options > 4)
		f->julia_options = 1;
}
