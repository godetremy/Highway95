/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collide.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:48:36 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/16 19:38:33 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void remove_life(t_game *game)
{
	game->life--;
	if (game->life == 0)
	{
		game->view = 2;
		game->menu_select = 0;
		Mix_PlayChannel(1, game->audio.game_over, 0);
	} else {
		Mix_PlayChannel(1, game->audio.crash, 0);
	}
}

static void	check_collision(t_enemy *enemy, t_game *game)
{
	if ((enemy->car_disposition == 0 && game->road == 0) ||
		(enemy->car_disposition == 1 && game->road == 1) ||
		(enemy->car_disposition == 2 && game->road == 2))
	{
		enemy->car_disposition = -1;
		remove_life(game);
	}
	if (enemy->car_disposition == 3 && (game->road == 0 || game->road == 1))
	{
		if (game->road == 0)
			enemy->car_disposition = 1;
		else
			enemy->car_disposition = 0;
		remove_life(game);
	}
	if (enemy->car_disposition == 4 && (game->road == 1 || game->road == 2))
	{
		if (game->road == 1)
			enemy->car_disposition = 2;
		else
			enemy->car_disposition = 1;
		remove_life(game);
	}
	if (enemy->car_disposition == 5 && (game->road == 0 || game->road == 2))
	{
		if (game->road == 0)
			enemy->car_disposition = 2;
		else
			enemy->car_disposition = 0;
		remove_life(game);
	}
}

void	check_collide(t_game *game)
{
	if (game->enemies[0].x > -10 && game->enemies[0].x < 24)
		check_collision(&(game->enemies[0]), game);
	if (game->enemies[1].x > -10 && game->enemies[1].x < 24)
		check_collision(&(game->enemies[1]), game);
	if (game->enemies[2].x > -10 && game->enemies[2].x < 24)
		check_collision(&(game->enemies[2]), game);
}
