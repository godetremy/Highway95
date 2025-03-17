/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   road.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:31:36 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 09:14:40 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <stdlib.h>

void draw_road(t_game *game)
{
	SDL_Rect	rect;
	int			i;
	int			shift;

	shift = game->frame % 6;
	SDL_SetRenderDrawColor(game->renderer, COLOR_LOW_R, COLOR_LOW_G, COLOR_LOW_B, 0);
	i = 0;
	while (i < 12)
	{
		rect = set_rect((8 * i) - shift * 1.5, 20, 6, 1);
		SDL_RenderFillRect(game->renderer, &rect);
		i++;
	}
	i = 0;
	while (i < 12)
	{
		rect = set_rect((8 * i) - shift * 1.5, 34, 6, 1);
		SDL_RenderFillRect(game->renderer, &rect);
		i++;
	}
}