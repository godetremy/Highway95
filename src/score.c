/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:14:15 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 15:52:48 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/logs.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	draw_score(t_game *game)
{
	char	*tmp;
	char	*score;

	tmp = ft_itoa(game->score);
	score = ft_strjoin("*", tmp);
	write_str(score, game, 410, 0);
	free(tmp);
	free(score);
}

void	get_bestscore(t_game *game)
{
	int		fd;
	int		bestscore;
	char	tmp[11];
	char	*bestscore_str;

	fd = open("ressources/bestscore", O_RDONLY | O_CREAT, 0644);
	if (fd == -1)
		return;
	tmp[read(fd, tmp, 10)] = '\0';
	bestscore = atoi(tmp);
	if (game->score > bestscore)
	{
		close(fd);
		fd = open("ressources/bestscore", O_WRONLY | O_TRUNC);
		if (fd == -1)
			return;
		bestscore_str = ft_itoa(game->score);
		write(fd, bestscore_str, strlen(bestscore_str));
		close(fd);
		write_str(bestscore_str, game, 410, 135);
		free(bestscore_str);
	}
	else
	{
		bestscore_str = ft_itoa(bestscore);
		write_str(bestscore_str, game, 410, 135);
		free(bestscore_str);
	}
}