/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 21:28:09 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/14 21:36:18 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		ft_vector_normalize(t_vec *coord)
{
	double	id;

	id = 1 / sqrt((coord->x * coord->x) + (coord->y * coord->y)
			+ (coord->z * coord->z));
	coord->x = coord->x * id;
	coord->y = coord->y * id;
	coord->z = coord->z * id;
}

double		ft_vector_dot(t_vec orig, t_vec dest)
{
	return ((orig.x * dest.x) + (orig.y * dest.y) + (orig.z * dest.z));
}

t_vec		ft_vector_cpy(t_vec vector)
{
	t_vec	new;

	new.x = vector.x;
	new.y = vector.y;
	new.z = vector.z;
	return (new);
}

t_vec		ft_vector_sub(t_vec first, t_vec sec)
{
	t_vec	new;

	new.x = first.x - sec.x;
	new.y = first.y - sec.y;
	new.z = first.z - sec.z;
	return (new);
}

t_vec		ft_vector_mul(t_vec first, t_vec sec)
{
	t_vec	new;

	new.x = first.x * sec.x;
	new.y = first.y * sec.y;
	new.z = first.z * sec.z;
	return (new);
}
