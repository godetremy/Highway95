/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:28:57 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 18:00:07 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"
#include <stdlib.h>

static char	*randomize_texture()
{
	char	*texture;
	int	random;

	random = rand() % 3;
	if (random == 0)
		texture = car1;
	else if (random == 1)
		texture = car2;
	else
		texture = car3;
	return (texture);
}

t_enemy	enemy_init(int spawn_distance)
{
	t_enemy	enemy;

	enemy.car_disposition = rand() % 6;
	enemy.x = 84 + spawn_distance;
	enemy.car1_str = randomize_texture();
	enemy.car2_str = randomize_texture();
	enemy.car3_str = randomize_texture();
	return (enemy);
}

static void	relocate_enemy(t_game *game, t_enemy *enemy)
{
	int	spawn_distance;
	int	i;

	spawn_distance = 0;
	i = 0;
	while (i < 3)
	{
		if (game->enemies[i].x > spawn_distance)
			spawn_distance = game->enemies[i].x;
		i++;
	}
	if (game->spawn_distance > 45)
		game->spawn_distance -= 1;
	enemy->x = game->spawn_distance + spawn_distance;
	enemy->car_disposition = rand() % 6;
	enemy->car1_str = randomize_texture();
	enemy->car2_str = randomize_texture();
	enemy->car3_str = randomize_texture();
}

void	draw_enemy(t_game *game, t_enemy *enemy)
{
	if (enemy->car_disposition == 0 || enemy->car_disposition == 3
		|| enemy->car_disposition == 5)
		draw_str(enemy->car1_str, game, enemy->x, 7);
	if (enemy->car_disposition == 1 || enemy->car_disposition == 3
		|| enemy->car_disposition == 4)
		draw_str(enemy->car2_str, game, enemy->x, 7 + 14);
	if (enemy->car_disposition == 2 || enemy->car_disposition == 4
		|| enemy->car_disposition == 5)
		draw_str(enemy->car3_str, game, enemy->x, 7 + 14 * 2);
	enemy->x -= 1;
	if (enemy->x < -20)
	{
		if (enemy->car_disposition == 0 || enemy->car_disposition == 1
			|| enemy->car_disposition == 2)
			game->score++;
		else if (enemy->car_disposition >= 3)
			game->score += 2;
		if (enemy->car_disposition >= 0)
			Mix_PlayChannel(1, game->audio.score, 0);
		relocate_enemy(game, enemy);
	}
}
