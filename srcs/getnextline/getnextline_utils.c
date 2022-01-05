/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   getnextline_utils.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 09:05:16 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/08/02 14:30:26 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "getnextline.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	get_gnl_sizes(char **dst, char *src, size_t *dstsize, size_t *size)
{
	*dstsize = 0;
	if (*dst)
		*dstsize = ft_strlen(*dst);
	*size = *dstsize + ft_strlen(src);
}

char	*ft_gnl_strcat(char **dst, char *src)
{
	size_t	i;
	size_t	size;
	size_t	dstsize;
	char	*tmp;

	get_gnl_sizes(dst, src, &dstsize, &size);
	tmp = malloc(size + 1);
	if (!tmp)
		return (0);
	i = 0;
	while (i < dstsize)
	{
		*(tmp + i) = *((*dst) + i);
		i++;
	}
	while (i < size)
	{
		*(tmp + i) = *(src + i - dstsize);
		i++;
	}
	*(tmp + i) = 0;
	if (*dst)
		free(*dst);
	return (tmp);
}
