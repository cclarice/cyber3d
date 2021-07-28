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
/*   readtostr.c                              cclarice@student.21-school.ru   */
/*                                                                            */
/*   Created/Updated: 2021/07/28 20:10:10  /  2021/07/28 20:19:53 @cclarice   */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		get_len(const char *filepath)
{
	int		ret;
	int		fd;
	char	buffer;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (fd);
	ret = 0;
	while (read(fd, &buffer, 1) == 1)
		ret++;
	close(fd);
	return (ret);
}

char	*readtostr(const char *filepath)
{
	char		*ret;
	const int	len = get_len(filepath);
	int			fd;

	if (len == -1 || !filepath)
		return (NULL);
	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * len + 1);
	ret[len] = '\0';
	if (read(fd, ret, len) == -1)
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
