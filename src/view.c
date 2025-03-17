/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:14:35 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/16 20:26:47 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <stdlib.h>

void	view_menu(t_game *game)
{
	SDL_SetRenderDrawColor(game->renderer, COLOR_HIGH_R, COLOR_HIGH_G, COLOR_HIGH_B, 0);
	draw_str(logo, game, 14, 5);
	draw_str(play, game, 30, 25);
	draw_str(exit_text, game, 32, 35);
	draw_str(arrow, game, 25, 25 + (game->menu_select * 10));
}

void	view_game(t_game *game)
{
	SDL_Rect	rect;
	int			i;

	SDL_SetRenderDrawColor(game->renderer, COLOR_LOW_R, COLOR_LOW_G, COLOR_LOW_B, 0);
	rect = set_rect(0, 0, 84, 7);
	SDL_RenderFillRect(game->renderer, &rect);
	SDL_SetRenderDrawColor(game->renderer, COLOR_HIGH_R, COLOR_HIGH_G, COLOR_HIGH_B, 0);
	i = 0;
	while (i < 4)
	{
		if (game->life > i)
			draw_str(life_on, game, 4 + (6 * i), 1);
		else
			draw_str(life_off, game, 4 + (6 * i), 1);
		i++;
	}
	draw_score(game);
	draw_road(game);
	if (game->frame < 50)
		draw_str(player, game, -20 + game->frame / 2, 6 + (14 * game->road));
	else
		draw_str(player, game, 5, 6 + (14 * game->road));
	draw_enemy(game, &game->enemies[0]);
	draw_enemy(game, &game->enemies[1]);
	draw_enemy(game, &game->enemies[2]);
	check_collide(game);
}

void view_game_over(t_game *game)
{
	char *tmp;

	SDL_SetRenderDrawColor(game->renderer, COLOR_HIGH_R, COLOR_HIGH_G, COLOR_HIGH_B, 0);
	draw_str(game_over_text, game, 5, 5);
	draw_str(retry, game, 10, 25);
	draw_str(exit_text, game, 10, 35);
	draw_str(arrow, game, 5, 25 + (game->menu_select * 10));
	write_str("Score", game, 410, 20);
	tmp = ft_itoa(game->score);
	write_str(tmp, game, 410, 55);
	free(tmp);
	write_str("Best", game, 410, 100);
	write_str("0", game, 410, 135);
}