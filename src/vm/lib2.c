/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgeonosi <dgeonosi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:11:04 by dgeonosi          #+#    #+#             */
/*   Updated: 2021/02/21 18:42:01 by dgeonosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/vm.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	size_t i;
	size_t j;

	if (*to_find == '\0')
		return ((char *)str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (to_find[j] == str[i + j])
		{
			if (to_find[j + 1] == '\0')
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	res;

	res = 0;
	while (str[res])
		res++;
	return (res);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int		memory_belay(int place)
{
	if ((place) % (MEM_SIZE) < 0)
		return (((place) % (MEM_SIZE)) + (MEM_SIZE));
	else
		return (place % (MEM_SIZE));
}

int		get_value(t_dataall *inf, int place, int len)
{
	long int		i;
	unsigned char	a[5];
	int				res;

	a[0] = inf->map[memory_belay(place)];
	a[1] = inf->map[memory_belay(place + 1)];
	a[2] = inf->map[memory_belay(place + 2)];
	a[3] = inf->map[memory_belay(place + 3)];
	a[4] = '\0';
	i = -1;
	res = 0;
	while (++i < len)
		res = (res << 8) | a[i];
	return (res);
}
