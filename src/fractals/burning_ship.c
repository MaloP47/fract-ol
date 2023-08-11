/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:21:24 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/23 11:23:52 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * The function 'burning_ship' calculates the Burning Ship sequence 
 * for a specific complex number, in a similar way to how the 
 * 'mandelbrot' function operates. However, the difference is that 
 * the 'burning_ship' function applies the absolute value to the 
 * real and imaginary parts of the current number in the sequence 
 * during each iteration.
 *
 * The calculation continues until the sequence becomes unbounded 
 * or reaches a maximum iteration count.
 *
 * The function takes two arguments, 'complex_real' and 'complex_imag', 
 * which represent the real and imaginary parts of the complex number.
 *
 * In each iteration, the function forms a new number in the sequence 
 * by squaring the current number, adding the original complex number, 
 * applying the absolute value to the real and imaginary parts of the 
 * current number, and checking if the square of the magnitude of the 
 * result is greater than 4.
 *
 * If the square of the magnitude exceeds 4, the function breaks from 
 * the loop as this indicates that the complex number is not part of 
 * the Burning Ship set, since the sequence will continue towards 
 * infinity (become unbounded).
 *
 * The function will return the iteration count at which the sequence 
 * becomes unbounded or reaches the maximum iteration count.
 */

int	burning_ship(t_fractol *f, double complex_real, double complex_imag)
{
	int		result;
	double	z_real;
	double	z_imag;
	double	tmp;

	z_real = 0;
	z_imag = 0;
	result = 0;
	while (result < f->max_iter)
	{
		if ((z_real * z_real + z_imag * z_imag) > 4.0)
			break ;
		z_real = fabs(z_real);
		z_imag = fabs(z_imag);
		tmp = 2 * z_real * z_imag + complex_imag;
		z_real = z_real * z_real - z_imag * z_imag + complex_real;
		z_imag = tmp;
		result++;
	}
	return (result);
}
