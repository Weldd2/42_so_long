/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:59:53 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/14 19:58:37 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static mlx_image_t	*load_single_image(mlx_t *mlx, const char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
		ft_error();
	image = mlx_texture_to_image(mlx, texture);
	mlx_delete_texture(texture);
	return (image);
}

static t_images	load_images(mlx_t *mlx)
{
	t_images	images;

	images.bloc0 = load_single_image(mlx, "assets/texture0.png");
	images.bloc1 = load_single_image(mlx, "assets/texture1.png");
	images.blocP = load_single_image(mlx, "assets/textureP.png");
	images.blocE = load_single_image(mlx, "assets/textureE.png");
	images.blocC = load_single_image(mlx, "assets/textureC.png");
	return (images);
}

static mlx_image_t	*get_image_by_tile(t_images *images, char tile)
{
	if (tile == '0')
		return (images->bloc0);
	if (tile == '1')
		return (images->bloc1);
	if (tile == 'E')
		return (images->blocE);
	if (tile == 'P')
		return (images->blocP);
	if (tile == 'C')
		return (images->blocC);
	return (NULL);
}

static void	draw_map_images(mlx_t *mlx, t_map map, t_images images)
{
	size_t		y;
	size_t		x;
	mlx_image_t	*image;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			image = get_image_by_tile(&images, '0');
			if (image)
				mlx_image_to_window(mlx, image, x * 32, y * 32);
			image = get_image_by_tile(&images, map.tiles[y][x]);
			if (image)
				mlx_image_to_window(mlx, image, x * 32, y * 32);
			x++;
		}
		y++;
	}
}

void	images_to_window(mlx_t *mlx, t_map map)
{
	t_images	images;

	images = load_images(mlx);
	draw_map_images(mlx, map, images);
}
