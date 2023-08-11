/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lyapunov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpeulet <mpeulet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 11:25:41 by mpeulet           #+#    #+#             */
/*   Updated: 2023/06/27 18:40:14 by mpeulet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
 * The function 'lyapunov' calculates the Lyapunov exponent for a 
 * specific complex number. The Lyapunov exponent is a measure of 
 * the rate of separation of infinitesimally close trajectories. 
 * This measure can be used to describe the chaotic behavior of 
 * dynamical systems.
 *
 * The calculation continues until the maximum iteration count is reached.
 *
 * The function takes three arguments. The first one, 'f', is a pointer 
 * to a t_fractol structure that holds the maximum iteration count and 
 * parameters for the Lyapunov calculation. The second and third 
 * arguments, 'zr' and 'zi', represent the real and imaginary parts of 
 * the complex number, respectively.
 *
 * In each iteration, the function forms a new number in the sequence 
 * based on a bifurcation formula. The bifurcation formula used depends 
 * on the current character in the sequence. If the character is 'A', 
 * one formula is used, and if it is 'B', another formula is used.
 *
 * The Lyapunov exponent is then updated by adding the logarithm of 
 * the magnitude of the newly formed number in the sequence.
 *
 * After all iterations, the Lyapunov exponent is normalized by dividing 
 * it by the total number of iterations and scaled by a factor of 100.
 *
 * The function will return the integer part of the Lyapunov exponent.
 */

int	lyapunov(t_fractol *f, double zr, double zi)
{
	int		result;

	result = 0;
	while (result < f->max_iter)
	{
		if (fabs(zr) > LIMIT || fabs(zi) > LIMIT)
			break ;
		if (f->l.sequence[result % f->l.seq_len] == 'A')
		{
			f->l.t.cr = zr * (f->l.a.cr - zr) - zi * (f->l.a.ci - zi);
			f->l.t.ci = zr * (f->l.a.ci - zi) + zi * (f->l.a.cr - zr);
		}
		else
		{
			f->l.t.cr = zr * (f->l.b.cr - zr) - zi * (f->l.b.ci - zi);
			f->l.t.ci = zr * (f->l.b.ci - zi) + zi * (f->l.b.cr - zr);
		}
		f->l.lya += log(sqrt(f->l.t.cr * f->l.t.cr + f->l.t.ci * f->l.t.ci));
		zr = f->l.t.cr;
		zi = f->l.t.ci;
		result++;
	}
	f->l.lya /= f->max_iter;
	f->l.final = (int)f->l.lya;
	return (abs(f->l.final));
}
