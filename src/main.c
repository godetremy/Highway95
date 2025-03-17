/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:28:54 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/16 19:53:46 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include "../includes/logs.h"

int    main(void)
{
	t_game    game;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
		return (log_error(SDL_GetError()));
	if (TTF_Init() != 0)
        return (log_error(TTF_GetError()));
	init_game(&game);
	while (game.running) {
		while (SDL_PollEvent(&(game.event))) {
			if (game.event.type == SDL_QUIT)
				game.running = 0;
			if (game.event.type == SDL_KEYDOWN)
				keydown_event(&game);
		}
		render(&game);
		game.frame++;
		SDL_Delay(16);
	}
	SDL_DestroyWindow(game.window);
	SDL_Quit();
}
