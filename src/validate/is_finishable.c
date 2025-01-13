/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finishable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:47:42 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/13 19:49:51 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	reset_visited(t_map *map)
{
	size_t	y;
	size_t	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->tiles[y][x] == '2')
				map->tiles[y][x] = '0';
			x++;
		}
		y++;
	}
}

t_ok	bfs(t_map map, size_t x, size_t y, size_t c_count)
{
	char	tile;

	tile = map.tiles[y][x];
	if (x <= 0 || y <= 0 || x >= map.width || y >= map.height)
		return (E_ERR);
	if (tile == '1' || tile == '2')
		return (E_ERR);
	if (tile == 'E' && c_count == 0)
		return (E_OK);
	if (tile == 'C')
	{
		c_count--;
		reset_visited(&map);
	}
	if (tile != 'E')
		map.tiles[y][x] = '2';
	if (bfs(map, x + 1, y, c_count) == E_OK)
		return (E_OK);
	if (bfs(map, x - 1, y, c_count) == E_OK)
		return (E_OK);
	if (bfs(map, x, y + 1, c_count) == E_OK)
		return (E_OK);
	if (bfs(map, x, y - 1, c_count) == E_OK)
		return (E_OK);
	return (E_ERR);
}

t_ok	is_finishable(t_map map)
{
	return (bfs(map, map.p_x, map.p_y, map.c_count));
}
