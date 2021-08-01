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
/*   Created/Updated: 2021/07/29 02:57:04  /  2021/07/29 02:57:13 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

int temp(t_cub *cub)
{
	int y;

	y = 0;
	printf("\e[1;32mcub:\n\e[0m%s\n", cub->cub);
	printf("\e[1;32mmap_x:\n\e[0m%u\n", cub->map_x);
	printf("\e[1;32mmap_y:\n\e[0m%u\n", cub->map_y);
	printf("\e[1;32mmap:\n\e[0m");
	while (y != cub->map_y)
		printf("%.*s\e[1;33m$\e[0m\n", cub->map_x, *cub->map + y++ * cub->map_x);
	if (!cub->map)
		printf("NULL\n");
	printf("\e[1;32mpath_n:\n\e[0m%s\n", cub->path_n);
	printf("\e[1;32mpath_s:\n\e[0m%s\n", cub->path_s);
	printf("\e[1;32mpath_w:\n\e[0m%s\n", cub->path_w);
	printf("\e[1;32mpath_e:\n\e[0m%s\n", cub->path_e);
	printf("\e[1;32mcolorf:\n\e[0m%x\n", cub->colorf);
	printf("\e[1;32mcolorc:\n\e[0m%x\n", cub->colorc);

	printf("\e[1;32mplx:\n\e[0m%x\n", cub->plx);
	printf("\e[1;32mply:\n\e[0m%x\n", cub->ply);
	printf("\e[1;32mpla:\n\e[0m%x\n", cub->pla);
	return (OK);
}

int	engine(t_cub *cub)
{
	temp(cub);
	return (OK);
}
