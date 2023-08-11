/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 10:03:08 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/26 15:18:24 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*Both following functions use the LCG (linear congruential generator) method */
/*they are designed to provide random number to initialize the Julia fractal  */
/*The Linear Congruential Generator (LCG) is a type of method for generating  */
/*sequences of pseudorandom numbers. The method is one of the oldest and      */
/*best-known pseudorandom number generator algorithms, mainly because of its  */
/*simplicity and speed of operation.  */

double	random_double_real(void)
{
	static unsigned long	seed = 123456789;
	double					random;

	seed = (1103515245 * seed + 12345) % 2147483648;
	random = ((double)seed) / 2147483648.0;
	random = random * 1.5 - 1.0;
	return (random);
}

double	random_double_imag(void)
{
	static unsigned long	seed = 123456789;
	double					random;

	seed = (1103515245 * seed + 12345) % 2147483648;
	random = ((double)seed) / 2147483648.0;
	return (random);
}

void	julia_random_values(t_fractol *f)
{
	f->shape.julia.cr = random_double_real();
	f->shape.julia.ci = random_double_imag();
}

/*
 * The function 'julia' calculates the Julia sequence for a 
 * specific complex number, in a similar way to how the 
 * 'mandelbrot' function operates. The difference is that 
 * in the 'julia' function, the original complex number
 * changes with each pixel, while the constant added during 
 * each iteration remains the same.
 *
 * The calculation continues until the sequence becomes unbounded 
 * or reaches a maximum iteration count.
 *
 * The function takes two arguments, 'z_real' and 'z_imag', 
 * which represent the real and imaginary parts of the complex 
 * number.
 *
 * In each iteration, the function forms a new number in the 
 * sequence by squaring the current number, adding a constant 
 * complex number, and checking if the square of the magnitude 
 * of the result is greater than 4.
 *
 * If the square of the magnitude exceeds 4, the function breaks 
 * from the loop as this indicates that the complex number is 
 * not part of the Julia set, since the sequence will continue 
 * towards infinity (become unbounded).
 *
 * The function will return the iteration count at which the 
 * sequence becomes unbounded or reaches the maximum iteration 
 * count.
 */

int	julia(t_fractol *f, double z_real, double z_imag)
{
	int		result;
	double	tmp;

	result = 0;
	while (result < f->max_iter)
	{
		if ((z_real * z_real + z_imag * z_imag) > 4.0)
			break ;
		tmp = 2 * z_real * z_imag + f->shape.julia.ci;
		z_real = z_real * z_real - z_imag * z_imag + f->shape.julia.cr;
		z_imag = tmp;
		result++;
	}
	return (result);
}
