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
/*   engine.c                                 cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/28 21:07:00  /  2021/07/28 21:07:13 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int temp(t_cub *cub)
{
	char **temp;

	temp = cub->map;
	printf("\e[1;32mcub:\n\e[0m%s\n", cub->cub);
	printf("\e[1;32mmap_x:\n\e[0m%u\n", cub->map_x);
	printf("\e[1;32mmap_y:\n\e[0m%u\n", cub->map_y);
	printf("\e[1;32mmap:\n\e[0m");
	while (cub->map && **cub->map != '\0')
	{
		printf("%s\e[1;33m$\e[0m", *cub->map);
		cub->map++;
	}
	cub->map = temp;
	if (!cub->map)
		printf("NULL\n");
	printf("\e[1;32mpath_n:\n\e[0m%s\n", cub->path_n);
	printf("\e[1;32mpath_s:\n\e[0m%s\n", cub->path_s);
	printf("\e[1;32mpath_w:\n\e[0m%s\n", cub->path_w);
	printf("\e[1;32mpath_e:\n\e[0m%s\n", cub->path_e);
	printf("\e[1;32mcolorf:\n\e[0m%x\n", cub->colorf);
	printf("\e[1;32mcolorc:\n\e[0m%x\n", cub->colorc);
	return (OK);
}

int	engine(t_cub *cub)
{
	temp(cub);
	return (OK);
}
