/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 03:37:36 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/12 05:55:19 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "raylib.h"
#include "game.h"

int main(void)
{
	t_game	*game;

	game = init_game(1280, 720);
	if (!game)
	{
		write(2, "init_game() failed.\n", 20);
		return (-1);
	}

	InitWindow(game->win_w, game->win_h, "game");
	SetTargetFPS(60);

	while (!WindowShouldClose())
	{
		BeginDrawing();
		ClearBackground(DARKGRAY);

		draw_game(game);

		EndDrawing();
	}

	CloseWindow();

	destroy_game(game);

	return 0;
}
