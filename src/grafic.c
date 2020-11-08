/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grafic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gordey <gordey@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 18:00:43 by gordey            #+#    #+#             */
/*   Updated: 2020/11/05 18:00:45 by gordey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	mlxInit(t_mlx *mlx)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIN_WID, WIN_HIG, "RTv1");
	mlx->size_line = WIN_WID;
	mlx->bit_pp = 32;
	mlx->endian = 0;
	mlx->img_ptr = mlx_new_image(mlx, WIN_WID, WIN_HIG);
	mlx->img_data = (int *)mlx_get_data_addr(mlx->img_ptr, &mlx->bit_pp, &mlx->size_line, &mlx->endian);
}


void	grafic(t_data *data, t_mlx *mlx)
{
	mlxInit(mlx);
	draw(&(mlx->img_data), *(data->p_object));
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
	mlx_hook(mlx->win, 2, 0, buttons_press, data);
	mlx_hook(mlx->win, 17, (1L << 17), close_window, data);
	mlx_loop(mlx->ptr);
}