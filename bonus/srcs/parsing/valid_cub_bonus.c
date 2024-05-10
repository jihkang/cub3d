/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_cub_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:58:03 by pjang             #+#    #+#             */
/*   Updated: 2023/03/07 14:57:30 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	valid_path(char *str)
{
	int		ret;
	int		fd;
	int		flag;
	int		len;
	char	**temp;

	fd = -2;
	ret = 1;
	temp = ft_split(str, ' ');
	len = ft_strlen(temp[0]);
	flag = (!ft_strncmp("NO", temp[0], len) | !ft_strncmp("SO", temp[0], len) \
		| !ft_strncmp("WE", temp[0], len) | !ft_strncmp("EA", temp[0], len));
	if (flag && temp[1])
	{
		fd = open(temp[1], O_RDONLY);
		if (fd == -1)
			ret = 0;
		else
			close(fd);
	}
	else
		ret = 0;
	safety_dimention_free(&temp);
	return (ret);
}

int	valid_c(char *str, t_map *map)
{
	int			ret;

	ret = 1;
	while (*str)
	{
		if (!(*str == '0' || *str == '1' || *str == ' ' \
			|| *str == 'N' || *str == 'S' || *str == 'W' || *str == 'E'))
			ret = 0;
		if (*str == 'N' || *str == 'S' || *str == 'W' || *str == 'E')
			map->player++;
		if (map->player > 1)
			ret = 0;
		str++;
	}
	return (ret);
}

void	valid_str(char *str, t_valid *valid)
{
	char	**split;

	split = ft_split(str, ' ');
	if (!ft_strncmp("NO", split[0], ft_strlen(split[0])))
		valid->north = 1;
	if (!ft_strncmp("SO", split[0], ft_strlen(split[0])))
		valid->south = 1;
	if (!ft_strncmp("WE", split[0], ft_strlen(split[0])))
		valid->west = 1;
	if (!ft_strncmp("EA", split[0], ft_strlen(split[0])))
		valid->east = 1;
	if (!ft_strncmp("F", split[0], ft_strlen(split[0])))
		valid->floor = 1;
	if (!ft_strncmp("C", split[0], ft_strlen(split[0])))
		valid->ceil = 1;
	safety_dimention_free(&split);
}

int	valid_cub(char *str, t_map *map)
{
	if (valid_color(str))
	{
		valid_str(str, &map->valid);
		return (1);
	}
	if (valid_path(str))
	{
		valid_str(str, &map->valid);
		return (2);
	}
	if (valid_c(str, map))
		return (3);
	return (0);
}
