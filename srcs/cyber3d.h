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
/*   cyber3d.h                                cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/28 21:04:31  /  2021/07/28 21:04:40 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYBER3D_H
# define CYBER3D_H
# define TRUE 1
# define FALSE 0
# define ERROR 1
# define OK 0

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "parcer/parcer.h"
# include "engine/engine.h"
# include "utils/utils.h"

typedef struct s_cub t_cub;
typedef unsigned int uint;

struct  s_cub
{
	char	*cub;
	char	**map;
	uint	map_x;
	uint	map_y;
	char	*path_n;
	char	*path_s;
	char	*path_w;
	char	*path_e;
	uint	colorf;
	uint	colorc;
};

#endif
