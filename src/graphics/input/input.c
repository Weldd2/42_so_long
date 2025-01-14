/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 22:07:55 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/14 23:24:24 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	direction_keyhook(mlx_key_data_t keydata, void* param)
{
	t_images	*images;

	images = (t_images *)param;
	images->blocP->instances[0].z = 2;
	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
		mlx_close_window(param);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		images->blocP->instances[0].y -= 32;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		images->blocP->instances[0].x -= 32;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		images->blocP->instances[0].y += 32;
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		images->blocP->instances[0].x += 32;
}
	