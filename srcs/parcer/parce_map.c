/* ************************************************************************** */
/*                                                                            */
/*       ::::::    ::::::   :::  ::::::::  ::::::::   :::  ::::::    :::::::  */
/*     :+:   :+: :+:   :+: :+: :+:   :+:  :+:    :+: :+: :+:   :+: :+:    :+: */
/*    +:+       +:+       +:+ +:+   +:+  +:+    +:+     +:+       +:+    +:+  */
/*   +#+       +:+       +#+ +:+   +#+  +:+    +#+ +:+ +#+       +#+:+:+#+:   */
/*  +#+       +#+       +#+   +#+#+#+# #+#+#+#+   +#+ +#+       +#+           */
/* #+#   #+# #+#   #+# #+#            #+#    #+# #+# #+#   #+# #+#    #+#     */
/*  ######    ######  ############## ###    ### ###   ######    #######       */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/*   parce_map.c                              cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/29 03:57:45  /  2021/07/29 03:57:54 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

int	get_map_sizes(char *str, uint *x, uint *y)
{
	uint cx;

	while (*str)
	{
		cx = 0;
		while (*str != '\n')
		{
			str++;
			cx++;
		}
		if (cx > *x)
			*x = cx;
		*y = *y + 1;
		str++;
	}
	return (OK);
}

char	**alloc_map(uint x, uint y)
{
	char	**map;
	uint	tmp;

	map = (char **)malloc(sizeof(char *) * y);
	if (!map)
		return (NULL);
	*map = (char *)malloc(sizeof(char *) * y * x);
	if (!*map)
		return (NULL);
	tmp = 1;
	while (tmp < y)
		map[tmp] = *map + x * tmp++;
	tmp = 0;
	while (tmp < y * x)
		map[0][tmp++] = ' ';
	return (map);
}

void	writetomap(char **map, char *str, uint x, uint y)
{
	char	*ptr;
	uint	i;
	uint	d;

	ptr = *map;
	d = 0;
	while (d < y)
	{
		i = 0;
		while (i < x)
		{
			if (*str != '\n')
			{
				*ptr = *str;
				*str++;
			}
			i++;
			*ptr++;
		}
		d++;
		if (*str != '\0')
			str++;
	}
}

int	is_not_valid_map(t_cub *cub, char **map, uint x, uint y)
{
	int xx;
	int yy;

	yy = 0;
	while (yy < y)
	{
		xx = 0;
		while (xx < x)
		{
			if ((map[yy][xx] != '1' || map[yy][xx] != ' ')
					&& ((xx == 0 || xx == x - 1 || yy == 0 || yy == y - 1)
					|| map[yy][xx + 1] == ' ' || map[yy + 1][xx] == ' '
					|| map[yy][xx - 1] == ' ' || map[yy - 1][xx] == ' '))
					return (TRUE);
			if (map[yy][xx] >= 'A' && map[yy][xx] <= 'Z')
			{
				if (cub->plx != -1)
					return (TRUE);
				cub->plx = xx;
				cub->ply = yy;
			}
			xx++;
		}
		yy++;
	}
	return (FALSE);
	//int	ptr;
//
	//ptr = 0;
	//while (ptr < x * y)
	//{
	//	if ((map[0][ptr] != '1' && map[0][ptr] != ' '
	//		&& (ptr < x || ptr >= x * (y - 1) || (ptr + 1) % x <= 1))
	//		|| (map[0][ptr] >= 'A' && map[0][ptr] <= 'Z' && cub->pla != -1))
	//		return (TRUE);
	//	if (map[0][ptr] >= 'A' && map[0][ptr] <= 'Z')
	//	{
	//		cub->plx = ptr % x;
	//		cub->ply = ptr / x;
	//	}
	//	if (map[0][ptr] == 'N')
	//		cub->pla = P * 0;
	//	if (map[0][ptr] == 'E')
	//		cub->pla = P * 0.5;
	//	if (map[0][ptr] == 'S')
	//		cub->pla = P * 1;	
	//	if (map[0][ptr] == 'W')
	//		cub->pla = P * 1.5;
	//	ptr++;
	//	printf("%c", *map[ptr]);
	//	if (!(ptr % x))
	//		printf("\n");
	//}
	//return (FALSE);
}

int	parce_map(t_cub *cub)
{
	get_map_sizes(cub->ptr, &cub->map_x, &cub->map_y);
	cub->map = alloc_map(cub->map_x, cub->map_y);
	if (!cub->map)
		return (ERROR);
	writetomap(cub->map, cub->ptr, cub->map_x, cub->map_y);
	if (is_not_valid_map(cub, cub->map, cub->map_x, cub->map_y))
		return (ERROR);
	return (OK);
}
