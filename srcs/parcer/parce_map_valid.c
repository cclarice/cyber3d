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
/*   parce_map_valid.c                        cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/08/01 15:10:47  /  2021/08/01 15:13:16 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

int	parce_map_walls()
{
	int	xx;
	int	yy;

	yy = -1;
	while (++yy < x)
	{
		while (++xx < y)
		{
			
		}
	}
	return (OK);
}

int	parce_map_player()
{
	int	xx;
	int	yy;

	yy = -1;
	while (++yy < x)
	{
		while (++xx < y)
		{
			
		}
	}
	return (OK);
}

int	parce_map_valid()
{
	if (parce_map_walls())
		return (ERROR);
	if (parce_map_player())
		return (ERROR);
}