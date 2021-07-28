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
/*   parcer.c                                 cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/28 21:23:54  /  2021/07/28 21:23:58 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

int	parcer(t_cub *cub)
{
	if (parce_arg(cub))
		return (ERROR);
	if (parce_map(cub))
		return (ERROR);
	alloc_map();
	return (OK);
}
