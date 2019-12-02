/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 14:50:40 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/27 12:54:23 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	size_t	j;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (len_dst >= size)
		return (len_src + size);
	j = len_dst;
	i = 0;
	while (j < size - 1 && src[i])
		dst[j++] = src[i++];
	dst[j] = '\0';
	return (len_dst + len_src);
}

char	*ft_strndup(const char *src)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	str = malloc(sizeof(*src) * (len + 1));
	if (str != NULL)
	{
		while (src[i] && src[i] != '\n')
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}