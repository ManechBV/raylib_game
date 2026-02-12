/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabenois <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 04:13:46 by mabenois          #+#    #+#             */
/*   Updated: 2026/02/12 06:13:42 by mabenois         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "raylib.h"

/* MAP DATA */

enum	e_tile_type
{
	EMPTY,
	TREE
};

typedef	struct	s_map_tile
{
	enum e_tile_type	val;
}	t_map_tile;

typedef struct	s_map
{
	int			w;
	int			h;
	t_map_tile	**tiles;
}	t_map;


/* PLAYER DATA */

typedef struct	s_player
{
	float		pos_x;
	float		pos_y;
	Rectangle	hitbox;
}	t_player;


/* GAME DATA */

typedef struct	s_game
{
	t_map		*map;
	t_player	*player;

	int			win_w;
	int			win_h;
	int			scale;
}	t_game;


/* FUNCTIONS */

// game.c
t_game	*init_game(int win_w, int win_h);
void	destroy_game(t_game *game);
void	draw_game(t_game *game);

// map.c
t_map	*generate_map(int w, int h);
void	destroy_map(t_map *map);
void	draw_map(t_map *map, int tile_size, int offset_x, int offset_y);

// player.c
t_player	*init_player(float x, float y);
void		destroy_player(t_player *player);
void		draw_player(t_player *player);

#endif
