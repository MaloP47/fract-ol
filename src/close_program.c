/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_program.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:58:37 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/26 15:16:28 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	close_program(t_fractol *f)
{
	if (f->img.mlx_img)
		mlx_destroy_image(f->utils.ptr, f->img.mlx_img);
	if (f->utils.wd)
		mlx_destroy_window(f->utils.ptr, f->utils.wd);
	if (f->utils.ptr)
		mlx_destroy_display(f->utils.ptr);
	if (f->utils.ptr)
		free(f->utils.ptr);
	if (f->colorama)
		free(f->colorama);
	exit(0);
}
