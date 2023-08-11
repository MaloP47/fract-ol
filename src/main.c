/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 10:41:02 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/27 16:44:17 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	main(int ac, char **av)
{
	t_fractol	fractol;

	if (parsing_arg(&fractol, ac, av))
	{
		print_controls();
		window_init(&fractol);
		render(&fractol);
		event_management(&fractol);
		mlx_loop(fractol.utils.ptr);
	}
	else
		show_options();
	return (0);
}
