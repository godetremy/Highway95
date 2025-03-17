/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 11:31:47 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 22:06:30 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

#define LOW_R 67
#define LOW_G 82
#define LOW_B 61

#define HIGH_R 199
#define HIGH_G 240
#define HIGH_B 216

#define life_off " @@@\n@   @\n@   @\n@   @\n @@@"
#define life_on " @@@\n@@@@@\n@@@@@\n@@@@@\n @@@"
#define player "     @@@@@@\n    @@@@@@@\n @@@ @@@@@ @@@@@@@\n@@@  @@@@@  @@@@@@@\n@@@  @@@@@  @ @   @\n@@@  @@@@@  @ @   @\n@@@ @@    @ @ @   @\n@@@@@@     @@@@@@@@\n@@@@@@@@@@@@@@@@@@@\n@@   @@@@@@@@@   @@\n@ @@@         @@@ @\n @@ @@@@@@@@@@@ @@\n  @@@@@@@@@@@@@@@"
#define car1 "    @@@@@@@\n @@@@     @@@@@@@\n@  @@     @@     @\n@  @@     @@     @\n@  @@     @@     @\n@  @ @@ @@ @     @\n@   @@@ @@@      @\n@                @\n@@    @ @        @\n@ @@@        @@@ @\n @@ @@@@@@@@@@ @@\n  @@@@@@@@@@@@@@"
#define car2 "    @@@@@@@\n  @@      @@@@@@\n @  @     @@    @@\n@ @ @     @@      @\n@ @ @     @@   @@ @\n@ @  @ @@@ @      @\n@   @@ @@@@       @\n@              @@ @\n@                 @\n@ @@@        @@@ @\n @@ @@@@@@@@@@ @@\n  @@@@@@@@@@@@@@"
#define car3 "  @@@@@@@@@@@\n @          @@@@@@\n@ @         @@    @\n@ @         @@     @\n@ @         @@     @\n@  @@ @@@ @@ @     @\n@ @@@ @@@ @@@      @\n@                  @\n@     @   @        @\n@ @@@         @@@ @\n @@ @@@@@@@@@@@ @@\n  @@@@@@@@@@@@@@@"
#define logo "@@@@@@@ @@@@@@@ @@@@@@@ @@@@    @@@@@@@ @@@@@@@ @@@@@@@\n@  @  @ @     @ @     @ @  @@@@ @ @ @ @ @     @ @  @  @\n@  @  @ @@   @@ @  @  @ @     @ @ @ @ @ @@@@  @ @  @  @\n@     @  @   @  @     @ @  @  @ @     @ @     @ @     @\n@  @  @ @@   @@ @@@@  @ @  @  @ @  @  @ @  @  @ @@@@  @\n@  @  @ @     @ @     @ @  @  @ @  @  @ @     @ @     @\n@@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@\n\n                    @@@@@@@ @@@@@@@\n                    @     @ @     @\n                    @  @  @ @  @@@@\n                    @     @ @     @\n                    @@@@  @ @@@@  @\n                    @     @ @     @\n                    @@@@@@@ @@@@@@@"
#define play "@@@@ @     @@@@@ @   @\n@  @ @     @   @ @   @\n@@@@ @     @   @ @@@@@\n@    @     @@@@@     @\n@    @@@@@ @   @ @@@@@"
#define exit_text "@@@@ @  @ @@@ @@@@@\n@    @  @  @    @\n@@@   @@   @    @\n@    @  @  @    @\n@@@@ @  @ @@@   @"
#define arrow "@\n@@\n@@@\n@@\n@"
#define game_over_text "@@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@\n@     @ @     @ @  @  @ @     @\n@  @@@@ @  @  @ @  @  @ @  @@@@\n@  @  @ @     @ @     @ @     @\n@  @  @ @  @  @ @ @ @ @ @  @@@@\n@     @ @  @  @ @ @ @ @ @     @\n@@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@\n\n@@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@\n@     @ @  @  @ @     @ @     @\n@  @  @ @  @  @ @  @@@@ @  @  @\n@  @  @ @  @  @ @     @ @    @@\n@  @  @ @  @  @ @  @@@@ @  @  @\n@     @ @    @@ @     @ @  @  @\n@@@@@@@ @@@@@@  @@@@@@@ @@@@@@@"
#define retry "@@@@ @@@@ @@@@@ @@@@ @  @\n@  @ @      @   @  @ @  @\n@@@@ @@@    @   @@@@ @@@@\n@ @  @      @   @ @     @\n@  @ @@@@   @   @  @ @@@"
#define pause_text "@@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@\n@     @ @     @ @  @  @ @     @ @     @\n@  @  @ @  @  @ @  @  @ @  @@ @ @  @@@@\n@     @ @     @ @  @  @ @@   @@ @     @\n@  @@@@ @  @  @ @  @  @ @ @@  @ @  @@@@\n@  @    @  @  @ @     @ @     @ @     @\n@@@@    @@@@@@@ @@@@@@@ @@@@@@@ @@@@@@@"
#define resume_text "@@@@ @@@@  @@@ @  @ @   @ @@@@\n@  @ @    @    @  @ @@ @@ @\n@@@@ @@@   @@  @  @ @ @ @ @@@\n@ @  @       @ @  @ @   @ @\n@  @ @@@@ @@@   @@  @   @ @@@@"

struct s_enemy {
	int		car_disposition;
	int		x;
	char		*car1_str;
	char		*car2_str;
	char		*car3_str;
};
typedef struct s_enemy t_enemy;

struct s_audio {
	Mix_Chunk	*bip;
	Mix_Chunk	*start;
	Mix_Chunk	*crash;
	Mix_Chunk	*game_over;
	Mix_Chunk	*score;
};
typedef struct s_audio t_audio;

struct s_game {
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	TTF_Font		*font;
	int				running;
	int				view;
	int				frame;
	int				menu_select;
	int				score;
	int				life;
	int				road;
	t_enemy			enemies[3];
	int				spawn_distance;
	t_audio			audio;
	int				last_collision_frame;
};
typedef struct s_game t_game;

char		*ft_itoa(int num);
char		*ft_strjoin(char const *s1, char const *s2);

SDL_Rect	set_rect(int x, int y, int w, int h);
void		set_pixel(SDL_Renderer *renderer, int x, int y);
void		draw_str(const char *content, t_game *game, int x, int y);
void		write_str(const char *content, t_game *game, int x, int y);
void		draw_score(t_game *game);
void		draw_player(t_game *game);

t_enemy		enemy_init(int spawn_distance);
void		init_game(t_game *game);
void		uninit_game(t_game *game);
void		restart_game(t_game *game);
void		keydown_event(t_game *game);
void		render(t_game *game);
void		draw_road(t_game *game);
void		draw_enemy(t_game *game, t_enemy *enemy);
void		check_collide(t_game *game);
void		get_bestscore(t_game *game);

void		view_menu(t_game *game);
void		view_game(t_game *game);
void		view_game_over(t_game *game);
void		view_pause(t_game *game);

#endif //GAME_H
