/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:44:36 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 19:38:31 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

SDL_Rect	set_rect(int x, int y, int w, int h)
{
	SDL_Rect	rect;

	rect.x = x * 5;
	rect.y = y * 5;
	rect.w = w * 5;
	rect.h = h * 5;
	return (rect);
}

void	set_pixel(SDL_Renderer *renderer, int x, int y)
{
	SDL_Rect	rect;

	rect = set_rect(x, y, 1, 1);
	SDL_RenderFillRect(renderer, &rect);
}

void	draw_str(const char *content, t_game *game, int x, int y)
{
	int		i;
	int		base_x;

	i = 0;
	base_x = x;
	while (content[i] != '\0')
	{
		if (content[i] == '@')
		{
			set_pixel(game->renderer, x, y);
			x++;
		}
		else if (content[i] == '\n')
		{
			y++;
			x = base_x;
		}
		else
			x++;
		i++;
	}
}

void	write_str(const char *content, t_game *game, int x, int y)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;
	SDL_Rect	rect;

	surface = TTF_RenderText_Solid(game->font, content, (SDL_Color)
		{HIGH_R, HIGH_G, HIGH_B, 0});
	texture = SDL_CreateTextureFromSurface(game->renderer, surface);
	rect.x = x - surface->w;
	rect.y = y;
	rect.w = surface->w;
	rect.h = surface->h;
	SDL_RenderCopy(game->renderer, texture, NULL, &rect);
	SDL_FreeSurface(surface);
	SDL_DestroyTexture(texture);
}

void	render(t_game *game)
{
	SDL_Rect viewport = { 0, 0, 420, 240 };

	SDL_SetRenderDrawColor(game->renderer, LOW_R, LOW_G,
			LOW_B, 0);
	if (game->view == 1)
		SDL_SetRenderDrawColor(game->renderer, HIGH_R, HIGH_G,
		HIGH_B, 0);
	SDL_RenderClear(game->renderer);
	if (game->view == 0)
		view_menu(game);
	else if (game->view == 1)
		view_game(game);
	else if (game->view == 2)
		view_game_over(game);
	else if (game->view == 3)
		view_pause(game);
	if (game->last_collision_frame + 20 > game->frame && game->view == 1)
	{
		viewport.x = (rand() % 10) - 5;
		viewport.y = (rand() % 10) - 5;
	}
	SDL_RenderSetViewport(game->renderer, &viewport);
	SDL_RenderPresent(game->renderer);
}