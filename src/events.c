/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:17:26 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/27 18:25:35 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	print_controls(void)
{
	ft_putstr_fd(MOVES, 1);
	ft_putstr_fd(ZOOOM, 1);
	ft_putstr_fd(ITER, 1);
	ft_putstr_fd(JUL, 1);
	ft_putstr_fd(CH, 1);
	ft_putstr_fd(ESC, 1);
}

int	keyboard_input_management(int keysym, t_fractol *f)
{
	if (keysym == XK_x)
		change_fractal(f);
	else if (keysym == XK_c)
		change_color(f);
	else if (keysym == XK_r)
		julia_random_values(f);
	else if (keysym == XK_j)
		change_julia_set(f);
	else if (keysym == XK_space)
		f->max_iter += 5;
	else if (keysym == XK_b)
		f->max_iter -= 5;
	else if (keysym == XK_Escape)
		close_program(f);
	else if (!keyboard_movements(keysym, f))
		return (1);
	render(f);
	return (0);
}

void	event_management(t_fractol *f)
{
	mlx_key_hook(f->utils.wd, keyboard_input_management, f);
	mlx_hook(f->utils.wd, ButtonPress, ButtonPressMask,
		mouse_event_management, f);
	mlx_hook(f->utils.wd, DestroyNotify, NoEventMask, close_program, f);
}
