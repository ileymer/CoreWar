/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljerk <ljerk@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:50:59 by ljerk             #+#    #+#             */
/*   Updated: 2020/08/19 17:27:46 by ljerk            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	app_line(char **mas_str, char **line)
{
	int		len;
	char	*fd_str;

	len = 0;
	while ((*mas_str)[len] != '\0' && (*mas_str)[len] != '\n')
		len++;
	if ((*mas_str)[len] == '\n')
	{
		*line = ft_strsub(*mas_str, 0, len);
		fd_str = ft_strdup(&((*mas_str)[len + 1]));
		free(*mas_str);
		*mas_str = fd_str;
		if ((*mas_str)[0] == '\0')
			ft_strdel(mas_str);
	}
	else
	{
		*line = ft_strdup(*mas_str);
		ft_strdel(mas_str);
	}
	return (1);
}

static	int	out(char **mas_str, char **line, int rd_len, int fd)
{
	if (rd_len < 0)
		return (-1);
	else if (rd_len == 0 && mas_str[fd] == NULL)
		return (0);
	else
		return (app_line(&mas_str[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	int			rd_len;
	static char	*mas_str[200];
	char		buff[BUFF_SIZE + 1];
	char		*fd_str;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((rd_len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[rd_len] = '\0';
		if (mas_str[fd] == NULL)
			mas_str[fd] = ft_strdup(buff);
		else
		{
			fd_str = ft_strjoin(mas_str[fd], buff);
			free(mas_str[fd]);
			mas_str[fd] = fd_str;
		}
		if (ft_strchr(mas_str[fd], '\n'))
			break ;
	}
	return (out(mas_str, line, rd_len, fd));
}
