/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:59:50 by msalembe          #+#    #+#             */
/*   Updated: 2024/08/04 03:56:11 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define SIZE 4024
# define PERSON "./textures/bird_dark.xpm"
# define PERSON_LEFT "./textures/bird_left.xpm"
# define EAT "./textures/eat_dark.xpm"
# define FLOOD "./textures/flood.xpm"
# define WALL "./textures/obs.xpm"
# define META "./textures/meta.xpm"

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_images
{
	char		*person;
	char		*eat;
	char		*flood;
	char		*wall;
	char		*meta;
	char		*back;
}				t_images;

typedef struct s_config
{
	void		*win;
	void		*init;
	char		**map;
	int			**visited;
	int			alternate_x;
	int			alternate_y;
	int			width;
	int			height;
	int			rows;
	int			cols;
	int			controller_eff;
	int			moves_int;
	t_images	img;

}				t_config;

enum			e_move
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

int				check_main(t_config Node);
int				close_window(void *param);
int				count_items(char **mtr, char c);
int				close_event_window(int key, void *param);
int				check_line_num(char **mtr);
int				check_full_colum(char **mtr);
int				ft_printf(const char *format, ...);
int				check_full_end_column(char **mtr);
int				count_mtr_lines(char **mtr);
int				ft_strcmp(char *s1, char *s2);
int				check_full_line(char **mtr, int line);
int				ft_strlen(const char *str);
int				is_valid(int **map, int x, int y, t_config *Node);
int				check_extension(char *str);
int				calculate_width_window(char **mtr);
int				big_verification(t_config *Node);
char			*ft_itoa(int number);
char			*ft_strdup(const char *s1);
char			**ft_split(char *str, char c);
char			**create_string_map(char *path);
void			full_free(t_config *Node);
void			final_status(int is_win, t_config *Node);
void			change_position(t_config *Node, enum e_move move);
void			ft_calloc(char *tab);
void			fill_image_space(t_config *Node);
void			free_memory(t_config *Node, int **map, int **visited);
void			free_matrix(char **matrix);
void			create_stadio(char **mtr, t_config *Node);
void			show_image_window(char **mtr, int i, int *x, t_config *Node);
void			*load_image(t_config *Node, char *path);
t_point			find_player(char **mtr);

#endif
