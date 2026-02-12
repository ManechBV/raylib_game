/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 04:28:15 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/12 16:39:11 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "game.h"

t_game	*init_game(int win_w, int win_h)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);

	game->map = generate_map(40, 40);
	if (!game->map)
	{
		write(2, "generate_map() failed.\n", 23);
		free(game);
		return (NULL);
	}

	game->player = init_player(50.0f, 50.0f);
	if (!game->player)
	{
		write(2, "init_player() failed.\n", 22);
		destroy_map(game->map);
		free(game);
		return (NULL);
	}

	game->win_w = win_w;
	game->win_h = win_h;
	game->scale = 32;

	return (game);
}

void	destroy_game(t_game *game)
{
	destroy_map(game->map);
	destroy_player(game->player);
	free(game);
}

void	draw_game(t_game *game)
{
	draw_map(game->map, game->scale, 0, 0);
	draw_player(game->player);
}
