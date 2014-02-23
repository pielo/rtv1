/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:59:56 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/14 22:20:21 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>

# define WIDTH 640
# define HEIGHT 480

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_col
{
	int			r;
	int			g;
	int			b;
}				t_col;

typedef struct	s_ray
{
	t_vec		origin;
	t_vec		dest;
}				t_ray;

typedef struct	s_sph
{
	t_vec		pos;
	double		radius;
	int			color;
}				t_sph;

typedef struct	s_lum
{
	t_vec		pos;
	double		color;
}				t_lum;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img_ptr;
	t_ray		camera;
	t_ray		ray;
	t_lum		light;
	t_vec		raylightdist;
	t_vec		raylightdir;
	double		normeraydist;
	t_vec		intensitylight;
	float		lambert;
	double		coef;
}				t_env;

void	ft_vector_normalize(t_vec *coord);
double	ft_vector_dot(t_vec orig, t_vec dest);
t_vec	ft_vector_cpy(t_vec vector);
t_vec	ft_vector_sub(t_vec first, t_vec sec);
t_vec	ft_vector_mul(t_vec first, t_vec sec);
int		ft_define_color(int color, t_env e);

#endif
