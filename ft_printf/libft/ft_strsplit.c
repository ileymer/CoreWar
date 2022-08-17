/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 20:20:38 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/12 19:21:47 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_countword(const char *s, char c)
{
	int	out;
	int	i;

	i = 0;
	out = 0;
	if (!s || !c)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i])
		{
			out++;
			while (s[i] != c && s[i])
				i++;
		}
		i++;
	}
	return (out);
}

static char		*ft_addstr(char const *s, int len)
{
	char	*str;
	char	*start;

	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str || !s)
		return (NULL);
	start = str;
	while (len--)
	{
		*str = *s;
		s++;
		str++;
	}
	*str = '\0';
	return (start);
}

static void		ft_word(char **out, const char *s, char c)
{
	int	i;
	int len;

	i = 0;
	len = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = 0;
			while (*s && *s != c)
			{
				len++;
				s++;
			}
			out[i] = ft_addstr(s - len, len);
			if (out[i] == NULL)
				ft_freestrarr(out);
			i++;
		}
		if (*s)
			s++;
	}
	out[i] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	char	**out;
	int		cw;

	cw = ft_countword(s, c);
	out = (char**)malloc(sizeof(char*) * cw + 1);
	if (!s || !c || !out)
	{
		free(out);
		return (NULL);
	}
	if (cw == 0)
	{
		out[0] = NULL;
		return (out);
	}
	ft_word(out, s, c);
	return (out);
}
