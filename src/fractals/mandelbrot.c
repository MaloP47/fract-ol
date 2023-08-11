/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:28:10 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/23 13:02:57 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * The function 'mandelbrot' calculates the Mandelbrot sequence 
 * for a specific complex number. The calculation continues until
 * the sequence becomes unbounded or the maximum iteration count 
 * is reached.
 *
 * The function takes two arguments. The first one, 'complex_real', 
 * represents the real part of the complex number. The second one, 
 * 'complex_imag', represents the imaginary part of the complex number.
 *
 * In each iteration, the function forms a new number in the 
 * sequence by squaring the current number, adding the original 
 * complex number, and checking if the square of the magnitude of 
 * the result is greater than 4.
 *
 * If the square of the magnitude exceeds 4, the function breaks 
 * from the loop because the sequence will continue towards infinity 
 * (become unbounded). This indicates that the complex number is 
 * not part of the Mandelbrot set.
 *
 * The function will return the iteration count at which the sequence 
 * becomes unbounded or reaches the maximum iteration count.
 */

int	mandelbrot(t_fractol *f, double complex_real, double complex_imag)
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
		tmp = 2 * z_real * z_imag + complex_imag;
		z_real = z_real * z_real - z_imag * z_imag + complex_real;
		z_imag = tmp;
		result++;
	}
	return (result);
}

/* Extra shapes using forbiden complex.h functions */

/*int pow_mandelbrot(t_fractol *f, double complex_real,
		 double complex_imag, int p)
{
	int		result;
	double complex z;
	double complex c;

	z = 0;
	c = complex_real + complex_imag*I;
	result = 0;
	while (result < f->max_iter)
	{
		if (cabs(z) > 2.0)
			break ;
		z = cpow(z, p) + c;
		result++;
	}
	return (result);
}

int	var_mandelbrot(t_fractol *f, double complex_real, double complex_imag)
{
	int		result;
	double complex z;
	double complex c;

	z = 0;
	c = complex_real + complex_imag * I;
	result = 0;

	while (result < f->max_iter)
	{
		if (cabs(z) > 2.0)
			break;

		z = ccos(z / c); 

		result++;
	}
	return (result);
}*/