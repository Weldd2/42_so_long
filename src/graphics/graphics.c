/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:58:20 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/14 19:58:34 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	graph(t_map map)
{
	mlx_t	*mlx;

	mlx = mlx_init(map.width * 32, map.height * 32, "42Balls", true);
	if (!mlx)
		ft_error();
	images_to_window(mlx, map);
	mlx_loop(mlx);
}
