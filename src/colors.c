/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:06:46 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/26 14:30:37 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	white_to_purple_light(int *colorama)
{
	colorama[0] = COLOR0;
	colorama[1] = COLOR1;
	colorama[2] = COLOR2;
	colorama[3] = COLOR3;
	colorama[4] = COLOR4;
	colorama[5] = COLOR5;
	colorama[6] = COLOR6;
	colorama[7] = COLOR7;
	colorama[8] = COLOR8;
	colorama[9] = COLOR9;
}

void	white_to_purple_dark(int *colorama)
{
	colorama[0] = COLOR23;
	colorama[1] = COLOR22;
	colorama[2] = COLOR21;
	colorama[3] = COLOR20;
	colorama[4] = COLOR19;
	colorama[5] = COLOR18;
	colorama[6] = COLOR17;
	colorama[7] = COLOR16;
	colorama[8] = COLOR15;
	colorama[9] = COLOR14;
}

void	yellow_to_orange(int *colorama)
{
	colorama[0] = YO_0;
	colorama[1] = YO_1;
	colorama[2] = YO_2;
	colorama[3] = YO_3;
	colorama[4] = YO_4;
	colorama[5] = YO_5;
	colorama[6] = YO_6;
	colorama[7] = YO_7;
	colorama[8] = YO_8;
	colorama[9] = YO_9;
}

void	rainbow(int *colorama)
{
	colorama[0] = RC0;
	colorama[1] = RC1;
	colorama[2] = RC2;
	colorama[3] = RC3;
	colorama[4] = RC4;
	colorama[5] = RC5;
	colorama[6] = RC6;
	colorama[7] = RC7;
	colorama[8] = RC8;
	colorama[9] = RC9;
}

int	*init_colorama(t_fractol *f, int selection)
{
	int	*colorama;

	colorama = calloc(sizeof(int), COLORS);
	if (!colorama)
	{
		close_program(f);
		return (NULL);
	}
	if (selection == 1)
		white_to_purple_light(colorama);
	else if (selection == 2)
		white_to_purple_dark(colorama);
	else if (selection == 3)
		yellow_to_orange(colorama);
	else if (selection == 4)
		rainbow(colorama);
	return (colorama);
}
