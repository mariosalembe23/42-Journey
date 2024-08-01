/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:59:32 by msalembe          #+#    #+#             */
/*   Updated: 2024/08/01 07:31:16 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_config	config;

static void    print_map(char **mtr)
{
    int i;
    int x;

    i = 0;
    while (mtr[i] != NULL)
    {
        x = 0;
        while (mtr[i][x] != '\0')
        {
            if (mtr[i][x] == 'P')
                ft_printf("\033[1;34m%c\033[1;0m", mtr[i][x]);
            else if (mtr[i][x] == 'C')
                ft_printf("\033[1;32m%c\033[1;0m", mtr[i][x]);
            else if (mtr[i][x] == 'V')
                ft_printf("\033[1;31m%c\033[1;0m", mtr[i][x]);
            else if (mtr[i][x] == 'E')
                ft_printf("\033[1;35m%c\033[1;0m", mtr[i][x]);
            else
                ft_printf("%c", mtr[i][x]);
			x++;
        }
		ft_printf("\n");
		i++;
    }
}
int effect_move(int key, void *n)
{
	(void)n;
	if (key == 'w' || key == 'W' || key == 65362)
		change_position(&config, UP);
	else if (key == 's' || key == 'S' || key == 65364)
		change_position(&config, DOWN);
	else if (key == 'd' || key == 'D' || key == 65363)
		change_position(&config, RIGHT);
	else if (key == 'a' || key == 'A' || key == 65361)
		change_position(&config, LEFT);
	create_stadio(config.map, &config, 0);
	print_map(config.map);
	return (0);
}

char	**create_string_map(char *path)
{
	int		fd;
	char	initial_map[SIZE];
	char	c;
	int		read_size;
	int		counter;

	read_size = 0;
	counter = 0;
	ft_calloc(initial_map);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	while (counter <= SIZE)
	{
		read_size = read(fd, &c, 1);
		if (read_size == 0)
			break ;
		initial_map[counter] = c;
		counter++;
	}
	initial_map[counter] = '\0';
	close(fd);
	return (ft_split((ft_strdup(initial_map)), '\n'));
}

static void	proccess_initial(void)
{
	config.images.person = "./textures/bird_dark.xpm";
	if (!*config.map || !config.map)
	{
		perror("Impossible generate the map!");
		free_matrix(config.map);
	}
	print_map(config.map);
	config.server_lib = mlx_init();
	if (!config.server_lib)
	{
		perror("Error, impossible init then server mlx");
		free(config.server_lib);
		exit(0);
	}
	config.window = mlx_new_window(config.server_lib, ft_strlen(*config.map) * 42, calculate_width_window(config.map) * 42,
			"42 Game Solitary Bird");
	if (!config.server_lib)
	{
		perror("Error, impossible init then server mlx");
		exit(0);
	}
	mlx_key_hook(config.window, close_event_window, &config);
	mlx_hook(config.window, 17, 0, close_window, &config);
}


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("\033[1;31mError! Try <so_long> <map.ber>\n\033[1;0m");
		return (0);
	}
	if (!check_extension(av[1]))
	{
		ft_printf("\033[1;31mInvalid Extension, try .ber files/maps\n\033[1;0m");
		return (0);
	}
	fill_image_space(&config);
	config.map = create_string_map(av[1]);
	config.rows = count_mtr_lines(config.map);
	config.cols = ft_strlen(config.map[0]);
	if (!check_main(config) || !big_verification(&config))
	{
		ft_printf("\033[1;31mInvalid Map! Try other map\n\033[1;0m");
		return (0);
	}
	proccess_initial();
	mlx_key_hook(config.window, effect_move, NULL);
	create_stadio(config.map, &config, 1);
	mlx_loop(config.server_lib);
	full_free(&config);
	return (0);
}
