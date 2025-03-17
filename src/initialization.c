/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:34:06 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 09:34:24 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/logs.h"

void	init_audio(t_game *game)
{
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
		exit(log_error(Mix_GetError()));
	game->audio.bip = Mix_LoadWAV("ressources/bip.wav");
	game->audio.start = Mix_LoadWAV("ressources/start.wav");
	game->audio.crash = Mix_LoadWAV("ressources/crash.wav");
	game->audio.game_over = Mix_LoadWAV("ressources/game_over.wav");
	game->audio.score = Mix_LoadWAV("ressources/score.wav");
}

void	init_game(t_game *game)
{
	game->window = SDL_CreateWindow("Highway95", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, 420, 240, 0);
	if (!game->window)
		exit(log_error("Window creation failed"));
	game->renderer = SDL_CreateRenderer(game->window, -1,
			SDL_RENDERER_ACCELERATED);
	if (!game->renderer)
		exit(log_error("Renderer creation failed"));
	game->font = TTF_OpenFont("ressources/ark.ttf", 40);
	if (!game->font)
		exit(log_error("Font loading failed"));
	init_audio(game);
	game->running = 1;
	game->frame = 0;
	game->view = 0;
	game->menu_select = 0;
	log_success("Initialization done");
}

void	restart_game(t_game *game)
{
	game->life = 4;
	game->road = 1;
	game->score = 0;
	game->spawn_distance = 84 * 1.5;
	game->enemies[0] = enemy_init(game->spawn_distance);
	game->enemies[1] = enemy_init(game->spawn_distance * 2);
	game->enemies[2] = enemy_init(game->spawn_distance * 3);
	game->frame = 0;
	game->last_collision_frame = -1000;
}

void	uninit_game(t_game *game)
{
    SDL_DestroyRenderer(game->renderer);
    SDL_DestroyWindow(game->window);
    TTF_CloseFont(game->font);
    Mix_FreeChunk(game->audio.bip);
    Mix_FreeChunk(game->audio.start);
    Mix_FreeChunk(game->audio.crash);
    Mix_FreeChunk(game->audio.game_over);
    Mix_FreeChunk(game->audio.score);
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}