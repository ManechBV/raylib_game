/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 04:40:39 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/12 05:32:09 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <time.h>

#include "raylib.h"
#include "game.h"

t_map	*generate_map(int w, int h)
{
	t_map	*map;
	int		tree_occ = 30; // one chance in X

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);

	map->w = w;
	map->h = h;

	// malloc lines
	map->tiles = malloc(sizeof(t_map_tile *) * h);
	if (!map->tiles)
	{
		free(map);
		return (NULL);
	}

	SetRandomSeed(time(NULL));
	// malloc each tile on every lines
	for (int y = 0; y < h; y++)
	{
		map->tiles[y] = malloc(sizeof(t_map_tile) * w);
		if (!map->tiles[y])
		{
			for (int i = y - 1; i >= 0; i--)
				free(map->tiles[i]);
			free(map->tiles);
			free(map);
			return (NULL);
		}

		// fill line with 0
		for (int x = 0; x < w; x++)
		{
			if (GetRandomValue(0, tree_occ) == 0)
				map->tiles[y][x].val = TREE;
			else
				map->tiles[y][x].val = EMPTY;
		}
	}
	return (map);
}

void	destroy_map(t_map *map)
{
	for (int y = map->h; y >= 0; y--)
		free(map->tiles[y]);
	free(map->tiles);
	free(map);
}

void	draw_map(t_map *map, int tile_size, int offset_x, int offset_y)
{
	enum e_tile_type	val;
	Color				col; 

	for (int y = 0; y < map->h; y++)
	{
		for (int x = 0; x < map->w; x++)
		{
			val = map->tiles[y][x].val;
			if (val == EMPTY)
				col = (Color){0, 255, 0, 255};
			else if (val == TREE)
				col = (Color){139, 69, 19, 255};

			DrawRectangle(
				(x * tile_size) + offset_x,
				(y * tile_size) + offset_y,
				tile_size - 1, tile_size - 1,
				col
			);
		}
	}
}
