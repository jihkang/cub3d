/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 17:01:31 by pjang             #+#    #+#             */
/*   Updated: 2023/03/07 15:05:46 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_add2(t_game *game, double vec[2])
{
	int		x;
	int		y;
	t_ray	*ray;
	t_map	*map;

	ray = &game->ray;
	map = &game->map;
	x = (int)(ray->pos[X] + vec[X] - 0.1);
	y = (int)(ray->pos[Y] + vec[Y] - 0.1);
	if (!(x >= 0 && x < map->width && y >= 0 && y < map->height))
		return ;
	if (valid_pos(map->maze[x][y]))
	{
		ray->pos[X] += vec[X];
		ray->pos[Y] += vec[Y];
	}
}

void	move_sub2(t_game *game, double vec[2])
{
	int		x;
	int		y;
	t_ray	*ray;
	t_map	*map;

	ray = &game->ray;
	map = &game->map;
	x = (int)(ray->pos[X] - vec[X] + 0.1);
	y = (int)(ray->pos[Y] - vec[Y] + 0.1);
	if (!(x >= 0 && x < map->width && y >= 0 && y < map->height))
		return ;
	if (valid_pos(map->maze[x][y]))
	{
		ray->pos[X] -= vec[X];
		ray->pos[Y] -= vec[Y];
	}
}
