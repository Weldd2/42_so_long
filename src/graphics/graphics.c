/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:58:20 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/14 00:09:06 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_textures(t_map map, mlx_t *mlx)
{
	size_t		y;
	size_t		x;
	mlx_image_t	*img;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			img = mlx_texture_to_image(mlx, assets(map.tiles[y][x]));
			if (!img)
				ft_error();
			if (mlx_image_to_window(mlx, img, x * 32, y * 32) < 0)
				ft_error();
			x++;
		}
		y++;
	}
}

void	graph(t_map map)
{
	mlx_t*			mlx;

	mlx = mlx_init(WIDTH, HEIGHT, "42Balls", true);
	if (!mlx)
		ft_error();
	init_textures(map, mlx);
	free_assets();
	mlx_loop(mlx);
	if (map.c_count == 0)
		exit(EXIT_SUCCESS);
}
