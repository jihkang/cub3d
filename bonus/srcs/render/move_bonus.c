/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:57:59 by pjang             #+#    #+#             */
/*   Updated: 2023/03/07 14:53:08 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	valid_pos(char c)
{
	if (c == '1')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (1);
}

void	move_add(t_game *game, double vec[2])
{
	int		x;
	int		y;
	t_ray	*ray;
	t_map	*map;

	ray = &game->ray;
	map = &game->map;
	x = (int)(ray->pos[X] + vec[X] + 0.1);
	y = (int)(ray->pos[Y] + vec[Y] + 0.1);
	if (!(x >= 0 && x < map->width && y >= 0 && y < map->height))
		return ;
	if (valid_pos(map->maze[x][y]))
	{
		ray->pos[X] += vec[X];
		ray->pos[Y] += vec[Y];
	}
}

void	move_sub(t_game *game, double vec[2])
{
	int		x;
	int		y;
	t_ray	*ray;
	t_map	*map;

	ray = &game->ray;
	map = &game->map;
	x = (int)(ray->pos[X] - vec[X] - 0.1);
	y = (int)(ray->pos[Y] - vec[Y] - 0.1);
	if (!(x >= 0 && x < map->width && y >= 0 && y < map->height))
		return ;
	if (valid_pos(map->maze[x][y]))
	{
		ray->pos[X] -= vec[X];
		ray->pos[Y] -= vec[Y];
	}
}

void	move_ccw(t_game *game)
{
	double	old_dir[2];
	double	old_plane[2];
	double	time;
	double	rad;
	t_ray	*ray;

	ray = &game->ray;
	time = 0.1;
	rad = time * 3.0;
	old_dir[X] = ray->dir[X];
	ray->dir[X] = (ray->dir[X] * cos(rad) - ray->dir[Y] * sin(rad));
	ray->dir[Y] = (old_dir[X] * sin(rad) + ray->dir[Y] * cos(rad));
	old_plane[X] = ray->plane[X];
	ray->plane[X] = (ray->plane[X] * cos(rad) - ray->plane[Y] * sin(rad));
	ray->plane[Y] = (old_plane[X] * sin(rad) + ray->plane[Y] * cos(rad));
}

void	move_cw(t_game *game)
{
	double	old_dir[2];
	double	old_plane[2];
	double	time;
	double	rad;
	t_ray	*ray;

	ray = &game->ray;
	time = 0.1;
	rad = time * 3.0;
	old_dir[X] = ray->dir[X];
	ray->dir[X] = (ray->dir[X] * cos(-rad) - ray->dir[Y] * sin(-rad));
	ray->dir[Y] = (old_dir[X] * sin(-rad) + ray->dir[Y] * cos(-rad));
	old_plane[X] = ray->plane[X];
	ray->plane[X] = (ray->plane[X] * cos(-rad) - ray->plane[Y] * sin(-rad));
	ray->plane[Y] = (old_plane[X] * sin(-rad) + ray->plane[Y] * cos(-rad));
}
