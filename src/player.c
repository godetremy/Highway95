/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgodet <rgodet@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:33:37 by rgodet            #+#    #+#             */
/*   Updated: 2025/03/17 14:41:12 by rgodet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game.h"

void  draw_player(t_game *game)
{
  	if (game->frame < game->last_collision_frame + 100 && game->frame % 8 > 4)
		return ;
	if (game->frame < 50)
		draw_str(player, game, -20 + game->frame / 2, 6 + (14 * game->road));
	else if (game->frame < game->last_collision_frame + 50)
		draw_str(player, game, (game->last_collision_frame - game->frame) / 2 + 5, 6 + (14 * game->road));
	else if (game->frame < game->last_collision_frame + 100)
		draw_str(player, game, (game->last_collision_frame - game->frame + 90)/2 * -1, 6 + (14 * game->road));
	else
		draw_str(player, game, 5, 6 + (14 * game->road));
}