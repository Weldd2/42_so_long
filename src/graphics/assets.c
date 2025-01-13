/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antoinemura <antoinemura@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:59:53 by antoinemura       #+#    #+#             */
/*   Updated: 2025/01/14 00:08:58 by antoinemura      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_assets(void)
{
	mlx_delete_texture(assets('C'));
	mlx_delete_texture(assets('1'));
	mlx_delete_texture(assets('P'));
	mlx_delete_texture(assets('E'));
	mlx_delete_texture(assets('0'));
}

mlx_texture_t	*assets(char c)
{
	static mlx_texture_t	*brique = NULL;
	static mlx_texture_t	*echelle = NULL;
	static mlx_texture_t	*fleur = NULL;
	static mlx_texture_t	*tnt = NULL;
	static mlx_texture_t	*planche = NULL;
	
	if (brique == NULL)
	{
		brique = mlx_load_png("./assets/brique.png");
		echelle = mlx_load_png("./assets/echelle.png");
		fleur = mlx_load_png("./assets/fleur.png");
		tnt = mlx_load_png("./assets/tnt.png");
		planche = mlx_load_png("./assets/planche.png");
	}
	if (c == '1')
		return (brique);
	if (c == 'C')
		return (fleur);
	if (c == 'P')
		return (tnt);
	if (c == 'E')
		return (echelle);
	if (c == '0')
		return (planche);
	return (NULL);
}

