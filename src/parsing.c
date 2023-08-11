/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:54:56 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/27 16:39:03 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	ok_f(t_fractol *f, char *av)
{
	if (ft_strcmp(av, "mandelbrot") == 0)
	{
		f->julia_options = 1;
		f->fractal = MANDELBROT;
		return (1);
	}
	else if (ft_strcmp(av, "julia") == 0)
	{
		f->fractal = JULIA;
		f->julia_options = 1;
		return (1);
	}
	else if (ft_strcmp(av, "burning ship") == 0)
	{
		f->julia_options = 1;
		f->fractal = BURNING;
		return (1);
	}
	else if (ft_strcmp(av, "lyapunov") == 0)
	{
		f->julia_options = 1;
		f->fractal = LYAPUNOV;
		return (1);
	}
	return (0);
}

int	ok_j(t_fractol *f, char *av1, char *av2)
{
	if (strcmp(av1, "julia") == 0 && (ft_atoi(av2) >= 1 && ft_atoi(av2) <= 4))
	{
		f->fractal = JULIA;
		if (ft_atoi(av2) == 1)
			f->julia_options = 1;
		else if (ft_atoi(av2) == 2)
			f->julia_options = 2;
		if (ft_atoi(av2) == 3)
			f->julia_options = 3;
		if (ft_atoi(av2) == 4)
			f->julia_options = 4;
		return (1);
	}
	return (0);
}

int	parsing_arg(t_fractol *f, int ac, char **av)
{
	if (ac == 2 && ok_f(f, av[1]))
		return (1);
	if (ac == 3 && ok_j(f, av[1], av[2]))
		return (1);
	return (0);
}

void	show_options(void)
{
	ft_putstr_fd(PARAM_ERROR, 1);
	ft_putstr_fd(PARAM_EXAMPLE, 1);
	ft_putstr_fd(P_EX_LIST, 1);
	ft_putstr_fd(JULIA_OPTIONS, 1);
	ft_putstr_fd(JULIA_EXAMPLE, 1);
	ft_putstr_fd(ENJOY, 1);
}
