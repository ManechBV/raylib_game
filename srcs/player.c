/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 05:57:30 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/12 06:13:46 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "game.h"

t_player	*init_player(float x, float y)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos_x = x;
	player->pos_y = y;
	player->hitbox = (Rectangle) {0.0f, 0.0f, 20.0f, 20.0f};
	return (player);
}

void	destroy_player(t_player *player)
{
	free(player);
}

void	draw_player(t_player *player)
{
	player->hitbox.x = player->pos_x - (player->hitbox.width / 2);
	player->hitbox.y = player->pos_y - (player->hitbox.height / 2);
	DrawRectangleRec(player->hitbox, BLUE);
}
