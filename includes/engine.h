/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yichan <yichan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 20:31:41 by yichan            #+#    #+#             */
/*   Updated: 2024/03/31 23:07:00 by yichan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include <stdbool.h>
# include <math.h>

// # define RESET		"\033[0m"
// # define BLACK		"\033[0;30m"
// # define RED		"\033[0;31m"
// # define GREEN		"\033[0;32m"
// # define YELLOW		"\033[0;33m"
// # define PURPLE		"\033[0;34m"
// # define PINK		"\033[0;35m"
// # define SKY		"\033[0;36m"

// # define ON_RED 	"\033[41m"
// # define ON_PURPLE	"\033[44m"
// # define ON_PINK	"\033[45m"

# define A_VERY_VERY_BIG_NUMMER 1000000000000000000
# define BOUNDARY 1
// # define VECTORS t_vector tmp, t_vector dir, t_vector first

typedef struct s_vecstack	t_vecstack;
typedef struct s_vector		t_vector;
typedef struct s_data		t_data;
typedef struct s_texture	t_texture;
typedef struct s_player		t_player;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_img
{
	void	*ptr; //mlx_new_image
	char	*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_vecstack
{
	t_vector	tmp;
	t_vector	strich;
	t_vector	first_inter;
}	t_vecstack;

/* vector */
double		vec_dot(t_vector one, t_vector two);
t_vector	normalize_vec(t_vector vec);
t_vector	vector_add(t_vector first, t_vector second);
t_vector	vector_multpl(t_vector first, t_vector second);
t_vector	vector_substr(t_vector first, t_vector second);
t_vector	rotatevectorlol(t_vector vct, double angle); //do not rename!!!!!!!

/* raycasting */
void		ray_the_caster(t_data *data);
bool		is_wall(t_data *data, t_vector pos);
bool		ray_wall(t_data *data, t_vector pos);
double		horizontal_raycast(t_data *data, t_vector direction);
double		vertical_raycast(t_data *data, t_vector direction);
void		single_ray(t_data *data, t_vector direction);
t_vector	get_init_pos(t_player playa);
double		get_next_angle(t_vector ini, t_player playa, int ray);

/* raycasting edgecases */
int			end_condition(t_data *data, t_vector vector);
double		direction_check(t_data *data, t_vector direction, \
										double y, bool horiz);
double		ratio_is_actually_distance(t_data *data, double dist, \
										t_vector first, int cond);
t_vector	cond_horiz_zero(t_data *data, t_vecstack vec, \
								t_vector dir, double ratio);
t_vector	cond_vert_zero(t_data *data, t_vecstack vec, \
								t_vector dir, double ratio);
t_vector	dir_smoler_zero(t_vector direction, t_vector strich, bool horiz);

#endif
