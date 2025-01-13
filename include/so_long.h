/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:38:50 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/13 20:02:14 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42.h"
# include "gnl.h"
# include "pf_printf.h"

typedef struct s_map
{
	char	**tiles;
	size_t	width;
	size_t	height;
	size_t	c_count;
	size_t	e_count;
	size_t	p_count;
	size_t	p_x;
	size_t	p_y;
}	t_map;

typedef enum e_errno
{
	E_GLOBAL,
	E_OPEN,
	E_ARGS,
	E_MAPEMPTY,
	E_MAPWIDTH,
	E_MAPEDGES,
	E_FINISHABLE,
	E_INVALID_CHAR,
	E_COLLECTIBLE,
	E_EXIT,
	E_PLAYER,
	E_NO_ERROR,
}	t_errno;

extern t_errno	g_eno;

typedef enum e_bloc
{
	E_PLANCHE = 0,
	E_BRIQUE = 1,
	E_FLEUR = 2,
	E_ECHELLE = 3,
	E_TNT = 4
}	t_bloc;

typedef enum e_ok
{
	E_OK = 0,
	E_ERR = 1
}	t_ok;

void	ft_error();
void	init_map(int fd, t_map *map);
t_ok	is_rectangular(t_map map);
t_ok	is_closed(t_map map);
t_ok	is_playable(t_map *map);
t_ok	is_finishable(t_map map);
t_ok	validate(t_map map);

#endif
