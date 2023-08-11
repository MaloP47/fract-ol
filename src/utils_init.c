/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 11:22:51 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/26 11:28:38 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	init_pos(t_fractol *f)
{
	f->pos.x = 0;
	f->pos.y = 0;
}

void	init_zoom(t_fractol *f)
{
	f->zoom.new_imag = 0;
	f->zoom.new_real = 0;
}

void	init_mlx_utils(t_fractol *f)
{
	f->utils.ptr = NULL;
	f->utils.wd = NULL;
}

void	img_struct_init(t_fractol *f)
{
	f->img.mlx_img = NULL;
	f->img.addr = NULL;
	f->img.bpp = 0;
	f->img.line_len = 0;
	f->img.endian = 0;
}
