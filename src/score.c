/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 20:14:15 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/16 20:22:14 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <stdlib.h>
#include <string.h>

void	draw_score(t_game *game)
{
	char *tmp;
	char *score;

	tmp = ft_itoa(game->score);
	score = ft_strjoin("*", tmp);
	write_str(score, game, 410, 0);
	free(tmp);
	free(score);
}