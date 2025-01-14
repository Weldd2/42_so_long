/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amura <amura@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:58:20 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/14 23:15:38 by amura            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graph(t_map map)
{
	mlx_t		*mlx;
	t_images	images;

	mlx = mlx_init(map.width * 32, map.height * 32, "42Balls", true);
	mem_mgc_add_block((void *)mlx, (void *)(void *)mlx_terminate);
	if (!mlx)
		ft_error();
	images = images_to_window(mlx, map);
	mlx_key_hook(mlx, &direction_keyhook, &images);
	mlx_loop(mlx);
}
