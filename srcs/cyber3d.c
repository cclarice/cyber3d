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
/*   cyber3d.c                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/29 02:44:39  /  2021/07/29 03:12:00 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "cyber3d.h"

int	freecub(t_cub *cub)
{
	uint	temp;

	temp = 0;
	if (cub->cub)
		free(cub->cub);
	if (cub->map)
	{
		if (*cub->map)
			free(*cub->map);
		free(cub->map);
	}
	return (TRUE);
}

int	nullcub(t_cub *cub)
{
	cub->cub = NULL;
	cub->map = NULL;
	cub->map_x = 0;
	cub->map_y = 0;
	cub->path_n = NULL;
	cub->path_s = NULL;
	cub->path_w = NULL;
	cub->path_e = NULL;
	cub->colorf = 0xff000000;
	cub->colorc = 0xff000000;
	cub->pla = -1;
	cub->plx = -1;
	cub->ply = -1;
	return (OK);
}

int main(int c, char *v[])
{
	t_cub	cub;

	nullcub(&cub);
	if (c != 2)
		return (error());
	cub.cub = readtostr(v[1]);
	if (!cub.cub)
		return (error());
	if (parcer(&cub) || engine(&cub))
		return (freecub(&cub) & error());
	freecub(&cub);
	return (OK);
}
