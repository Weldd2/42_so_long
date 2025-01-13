/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:48:57 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/13 23:57:29 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*gnl_and_trim(int fd)
{
	char	*line;
	char	*trimmed_line;

	line = gnl_get_next_line(fd);
	if (line == NULL)
		return (NULL);
	trimmed_line = str_strtrim(line, "\n ");
	mem_free(line);
	return (trimmed_line);
}

static int	init_map_tiles(int fd, t_map *map)
{
	char	*line;
	size_t	index;

	index = 0;
	map->tiles = NULL;
	while (true)
	{
		line = gnl_and_trim(fd);
		if (line == NULL)
			break ;
		if (line[0] == '\0')
		{
			mem_free(line);
			continue ;
		}
		map->tiles = mem_realloc(map->tiles, (index + 1) * sizeof(char *));
		map->tiles[index] = line;
		mem_mgc_add_block(map->tiles[index], mem_free);
		index++;
	}
	mem_mgc_add_block(map->tiles, mem_free);
	return (index);
}

t_map	copy_map(t_map original)
{
	t_map	cpy;
	char	**tiles;
	size_t	y;

	cpy.c_count = original.c_count;
	cpy.e_count = original.e_count;
	cpy.p_count = original.p_count;
	cpy.height = original.height;
	cpy.width = original.width;
	cpy.p_x = original.p_x;
	cpy.p_y = original.p_y;
	tiles = mem_malloc(sizeof(char *) * original.height);
	y = 0;
	while (y < cpy.height)
	{
		tiles[y] = mem_malloc(original.width);
		str_strlcpy(tiles[y], original.tiles[y], original.width + 1);
		mem_mgc_add_block(tiles[y], mem_free);
		y++;
	}
	cpy.tiles = tiles;
	mem_mgc_add_block(tiles, mem_free);
	return (cpy);
}

void	init_map(int fd, t_map *map)
{
	size_t	index;

	index = init_map_tiles(fd, map);
	map->height = index;
	map->width = str_strlen(map->tiles[0]);
	map->p_x = 0;
	map->p_y = 0;
	map->c_count = 0;
	map->p_count = 0;
	map->e_count = 0;
}
