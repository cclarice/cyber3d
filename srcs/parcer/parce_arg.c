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
/*   parce_arg.c                              cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/29 02:32:45  /  2021/07/29 02:47:58 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "parcer.h"

int	args_not_parced(t_cub *cub)
{
	if (!cub->path_n || !cub->path_s || !cub->path_w || !cub->path_e)
		return (TRUE);
	if (cub->colorf == 0xff000000 || cub->colorc == 0xff000000)
		return (TRUE);
	return (FALSE);
}

char	*skip(char *str, char chr)
{
	if (*str != chr)
		return (NULL);
	while (*str == chr)
		str++;
	return (str);
}

int	color(char *str, uint *color)
{
	int		ptr;
	int		temp;

	ptr = 2;
	if (!str)
		return (FALSE);
	while (ptr != -1)
	{
		temp = ft_atoi(str);
		if (temp < 0 || temp >= 256 || (temp == 0 && *str != '0'))
			return (FALSE);
		*color += temp << (8 * ptr--);
		while ((ptr != -1 && *str == ' ') || (*str >= '0' && *str <= '9'))
			str++;
		if (ptr != -1 && *str++ != ',')
			return (FALSE);
		while (ptr != -1 && *str == ' ')
			str++;
	}
	if (*str != '\n')
		return (FALSE);
	return (TRUE);
}

int	is_trash_in_map(char *str, char **ptr)
{
	while (*str == '\n')
		str++;
	*ptr = str;
	while (*str
		&& (*str == 'N' || *str == 'E' || *str == 'W' || *str == 'S'
		|| *str == '1' || *str == '0' || *str == ' '
		|| (*str == '\n' && str[1] != '\n'))
		|| (*str == '\n' && str[1] && str[1] == '\n' && str[2] == '\0'))
		str++;
	if (*str != 0)
		return (TRUE);
	return (FALSE);
}

/*
	NO ./path_to_the_north_texture
	SO ./path_to_the_south_texture
	WE ./path_to_the_west_texture
	EA ./path_to_the_east_texture
	F 220,100,0
	C 225,30,0
*/

int	parce_arg(t_cub *cub)
{
	char	*ptr;

	ptr = cub->cub;
	while (args_not_parced(cub))
	{
		if (*ptr && *ptr == 'N' && ptr[1] == 'O')
			cub->path_n = skip(&ptr[2], ' ');
		else if (*ptr && *ptr == 'S' && ptr[1] == 'O')
			cub->path_s = skip(&ptr[2], ' ');
		else if (*ptr && *ptr == 'W' && ptr[1] == 'E')
			cub->path_w = skip(&ptr[2], ' ');
		else if (*ptr && *ptr == 'E' && ptr[1] == 'A')
			cub->path_e = skip(&ptr[2], ' ');
		else if (*ptr && *ptr == 'F' && color(skip(&ptr[1], ' '), &cub->colorf))
			cub->colorf = cub->colorf & 0x00ffffff;
		else if (*ptr && *ptr == 'C' && color(skip(&ptr[1], ' '), &cub->colorc))
			cub->colorc = cub->colorc & 0x00ffffff;
		else if (*ptr != '\n')
			return (ERROR);
		while (*ptr && *ptr != '\n')
			ptr++;
		*ptr++ = '\0';
	}
	return (args_not_parced(cub) | is_trash_in_map(ptr, &cub->ptr));
}
