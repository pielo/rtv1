/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlanglet <mlanglet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/14 22:11:08 by mlanglet          #+#    #+#             */
/*   Updated: 2014/02/14 22:20:05 by mlanglet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static t_col           ft_hexa_to_rgb(int hex)
{
	t_col       rgb;


	rgb.r = ((hex >> 16) & 0xFF);
	rgb.g = ((hex >> 8) & 0xFF);
	rgb.b = ((hex) & 0xFF);
	return (rgb);
}

static int             ft_rgb_to_hexa(t_col rgb)
{
	int         hex;

	hex = ((rgb.r & 0xff) << 16) + ((rgb.g & 0xff) << 8) + (rgb.b & 0xFF);
	return (hex);
}


int		ft_define_color(int color, t_env e)
{
	t_col	color_temp;

	color_temp = ft_hexa_to_rgb(color);
	color_temp.r += e.light.color * e.lambert * 0.5;
	color_temp.g += e.light.color * e.lambert * 0.5;
	color_temp.b += e.light.color * e.lambert * 0.5;
	color_temp.r =  (color_temp.r > 255 ? 255 : color_temp.r);
	color_temp.g =  (color_temp.g > 255 ? 255 : color_temp.g);
	color_temp.b =  (color_temp.b > 255 ? 255 : color_temp.b);
	color_temp.r =  (color_temp.r < 0 ? 0 : color_temp.r);
	color_temp.g =  (color_temp.g < 0 ? 0 : color_temp.g);
	color_temp.b =  (color_temp.b < 0 ? 0 : color_temp.b);
	color = ft_rgb_to_hexa(color_temp);
	return (color);
}
