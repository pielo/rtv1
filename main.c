/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 17:52:11 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/14 22:24:22 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int	key_hook(int keycode, t_env *e)
{
	(void)e;
	if (keycode == 65307)
		exit(0);
	return (0);
}

int				ft_inter_sphere(t_sph sphere, t_ray ray, double *coef)
{
	t_vec		dist;
	double		b;
	double		d;
	float		t0;
	float		t1;

	dist = ft_vector_cpy(sphere.pos);
	dist = ft_vector_sub(dist, ray.origin);
	b = ft_vector_dot(ray.dest, dist);
	d = b * b - ft_vector_dot(dist, dist) + sphere.radius * sphere.radius;
	if (d < 0)
		return (-1);
	t0 = b - sqrt(d);
	t1 = b + sqrt(d);
	if ((t0 > 0.1) && (t0 < *coef))
	{
		*coef = t0;
		return (0);
	}
	if ((t1 > 0.1) && (t1 < *coef))
	{
		*coef = t1;
		return (0);
	}
	return (-1);
}

int				main(void)
{
	t_env		e;
	t_sph		sphere;
	int			i;
	int			j;
	int			intersection;
	t_vec		impact;
	t_vec		distance;
	double		norme;
	float		temp;

	e.camera.origin.x = 0;
	e.camera.origin.y = 0;
	e.camera.origin.z = 0;
	e.ray.origin.x = e.camera.origin.x;
	e.ray.origin.y = e.camera.origin.y;
	e.ray.origin.z = e.camera.origin.z;
	e.camera.dest.z = -(WIDTH / (2 * tan(30 / 2)));

	sphere.pos.x = 0;
	sphere.pos.y = 0;
	sphere.pos.z = 100;
	sphere.radius = 20;

	e.light.pos.x = 200;
	e.light.pos.y = -150;
	e.light.pos.z = -50;
	e.light.color = 1;
	
	e.mlx = mlx_init();
	if (!e.mlx)
		return (1);
	e.win = mlx_new_window(e.mlx, WIDTH, HEIGHT, "Rtv1");
	mlx_key_hook(e.win, key_hook, &e);
	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			e.camera.dest.x = i - (WIDTH / 2);
			e.camera.dest.y = j - (HEIGHT / 2);
			e.ray.dest.x = e.camera.dest.x - e.camera.origin.x;
			e.ray.dest.y = e.camera.dest.y - e.camera.origin.y;
			e.ray.dest.z = e.camera.dest.z - e.camera.origin.z;
			ft_vector_normalize(&(e.ray.dest));
			e.coef = 20000;
			intersection = ft_inter_sphere(sphere, e.ray, &(e.coef));
			if (intersection == 0 && e.coef < 20000)
			{
				impact.x = e.ray.origin.x + e.ray.dest.x * e.coef;
				impact.y = e.ray.origin.y + e.ray.dest.y * e.coef;
				impact.z = e.ray.origin.z + e.ray.dest.z * e.coef;
	
				distance.x = impact.x - sphere.pos.x;
				distance.y = impact.y - sphere.pos.y;
				distance.z = impact.z - sphere.pos.z;
				ft_vector_normalize(&(distance));
				norme = ft_vector_dot(distance, distance);
				temp = norme * norme;
				temp = 1 / sqrt(temp);
				norme = temp * norme;
				sphere.color = 0xFF0000;
				if (norme != 0)
				{
					e.raylightdist.x = e.light.pos.x - impact.x;
					e.raylightdist.y = e.light.pos.y - impact.y;
					e.raylightdist.z = e.light.pos.z - impact.z;
					e.normeraydist = ft_vector_dot(e.raylightdist, e.raylightdist);
					if (e.normeraydist != 0)
					{
						e.raylightdir.x = e.raylightdist.x / norme;
						e.raylightdir.y = e.raylightdist.y / norme;
						e.raylightdir.z = e.raylightdist.z / norme;
					}
					e.intensitylight = ft_vector_mul(e.raylightdir, distance);
					e.lambert = (e.intensitylight.x * norme) + (e.intensitylight.y * norme) + (e.intensitylight.z * norme);
					sphere.color = ft_define_color(sphere.color, e);
					mlx_pixel_put(e.mlx, e.win, i, j, sphere.color);
				}
			}
			j++;
		}
		i++;
	}
	mlx_loop(e.mlx);
	return (0);
}
