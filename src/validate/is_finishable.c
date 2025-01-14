/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_finishable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 18:47:42 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/14 18:56:22 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_ok	is_finishable(t_map *map)
{
	t_ok	is_ok;

	is_ok = bfs(map, map->p_y, map->p_x);
	return (is_ok);
}
