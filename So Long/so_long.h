/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:59:50 by msalembe          #+#    #+#             */
/*   Updated: 2024/08/01 07:47:38 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"

# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
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
	int x;
	int y;
} t_point;

typedef struct s_images{
	char *person;
	char *eat;
	char *flood;
	char *wall;
	char *meta;
} t_images;

typedef struct s_config
{
	void	*window;
	void	*server_lib;
	char 	**map;
	int		alternate_x;
	int 	alternate_y;
	int 	width;
	int 	height;
	int		rows;
	int		cols;
	t_images images;
	
}			t_config;

enum e_move
{
	UP,
	DOWN,
	LEFT,
	RIGHT	
};

int			check_main(t_config config);
int			close_window(void *param);
int			count_items(char **mtr, char c);
int			close_event_window(int key, void *param);
int			check_line_num(char **mtr);
int			check_full_colum(char **mtr);
int			ft_printf(const char *format, ...);
int			check_full_end_column(char **mtr);
int 		count_mtr_lines(char **mtr);
int 		ft_strcmp(char *s1, char *s2);
int			check_full_line(char **mtr, int line);
int			ft_strlen(const char *str);
int			isValid(int **map, int x, int y, t_config *config, int **visited);
int    		check_extension(char *str);
int			calculate_width_window(char **mtr);
int			big_verification(t_config *config);
char		*ft_strdup(const char *s1);
char		**ft_split(char *str, char c);
char		**create_string_map(char *path);
void		full_free(t_config *config);
void 		final_status(int is_win, t_config *config);
void 		change_position(t_config *config, enum e_move move);
void		ft_calloc(char *tab);
void    	fill_image_space(t_config *config);
void		free_memory(t_config *config, int **map, int **visited);
void		free_matrix(char **matrix);
void		create_stadio(char **mtr, t_config *config, int controller_eff);
void		show_image_window(char **mtr, int i, int *x, t_config *config, int controller_eff);
void		*load_image(t_config *config, char *path, int *width, int *height);
t_point		find_player(char **mtr);

#endif
