/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils_bonus.c                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/19 14:50:40 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/30 17:50:54 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

char	*ft_strdup(const char *src)
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
		while (src[i])
		{
			str[i] = src[i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (str + i);
		i++;
	}
	if (c == '\0')
		return (str + i);
	return (0);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	unsigned int	max_len;
	unsigned int	i;
	char			*new_str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_str = malloc(sizeof(char));
		if ((new_str))
			new_str[0] = '\0';
		return (new_str);
	}
	max_len = 0;
	while (s[max_len + start] && max_len < len)
		max_len++;
	if (!(new_str = (char *)malloc((1 + max_len) * sizeof(char))))
		return (NULL);
	i = 0;
	while (i < max_len)
		new_str[i++] = s[start++];
	new_str[i] = '\0';
	return (new_str);
}
