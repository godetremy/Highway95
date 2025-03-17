/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:07:38 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 09:34:11 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

static void	menu_keydown_event(t_game *game)
{
	if (game->event.key.keysym.sym == SDLK_UP && game->menu_select == 1)
	{
		game->menu_select = 0;
		Mix_PlayChannel(2, game->audio.bip, 0);
	}
	else if (game->event.key.keysym.sym == SDLK_DOWN
		&& game->menu_select == 0)
	{
		game->menu_select = 1;
		Mix_PlayChannel(2, game->audio.bip, 0);
	}
	else if (game->event.key.keysym.sym == SDLK_RETURN)
	{
		if (game->menu_select == 0)
		{
			restart_game(game);
			game->view = 1;
			Mix_PlayChannel(1, game->audio.start, 0);
		}
		else if (game->menu_select == 1)
			game->running = 0;
	}
}

void	keydown_event(t_game *game)
{
	if (game->view == 0 || game->view == 2)
		menu_keydown_event(game);
	else if (game->view == 1)
	{
		if (game->event.key.keysym.sym == SDLK_UP)
		{
			if (game->road > 0)
				game->road--;
		}
		else if (game->event.key.keysym.sym == SDLK_DOWN)
		{
			if (game->road < 2)
				game->road++;
		}
	}
}
