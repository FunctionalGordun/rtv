/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 18:30:05 by gordey            #+#    #+#             */
/*   Updated: 2020/11/08 17:09:41 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_raydata	creatRay(double max_len, t_coord point, t_coord direction)
{
	t_raydata	ray;

	ray.t_max = max_len;
	ray.point = point;
	ray.direction = direction;
	return (ray);
}


int	fixing_the_near_obj(t_raydata value, t_objectinfo *near, int type, int index)
{
	if ((near->t == -1 || value.t_near < near->t))
	{
		near->center = value.cent_obj;
		near->st_cent = value.st_cent;
		near->t = (value.t_near - 0.0001);
		near->type = type;
		near->index = index;
	}
	return (1);
}


void	draw(int **img_data, t_scene objs)
{
	int			x;
	int			y;
	t_raydata	ray;
	t_objectinfo	near;

	y = -1;
	objs.camera.roter = quatRoter(objs.camera);
	while (++y < WIN_HIG)
	{
		x = -1;
		while (++x < WIN_WID)
		{
			objs.camera.direct = getDirection(objs.camera, x, y);
			ray = creatRay(INFINITY, objs.camera.point, objs.camera.direct);
			if ((rayTrace(objs, ray, &near)))
				objs.pix_color = trace_to_light_src(near, objs);
			else
				color_change(&objs.pix_color, (t_color){0, 0, 0});
			put_color_to_img(img_data, x, y, objs.pix_color);
		}
	}
}
