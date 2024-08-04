/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:59:32 by msalembe          #+#    #+#             */
/*   Updated: 2024/08/04 04:06:20 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

t_config	g_node;

static void	print_map(char **mtr)
{
	int	i;
	int	x;

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

int	effect_move(int key, void *n)
{
	(void)n;
	if (key == 'w' || key == 'W' || key == 65362)
		change_position(&g_node, UP);
	else if (key == 's' || key == 'S' || key == 65364)
		change_position(&g_node, DOWN);
	else if (key == 'd' || key == 'D' || key == 65363)
		change_position(&g_node, RIGHT);
	else if (key == 'a' || key == 'A' || key == 65361)
		change_position(&g_node, LEFT);
	g_node.controller_eff = 0;
	create_stadio(g_node.map, &g_node);
	print_map(g_node.map);
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
	g_node.img.person = "./textures/bird_dark.xpm";
	if (!*g_node.map || !g_node.map)
	{
		perror("Impossible generate the map!");
		free_matrix(g_node.map);
	}
	print_map(g_node.map);
	g_node.init = mlx_init();
	if (!g_node.init)
	{
		perror("Error");
		free(g_node.init);
		exit(0);
	}
	g_node.win = mlx_new_window(g_node.init, ft_strlen(*g_node.map) * 42,
			calculate_width_window(g_node.map) * 42 + 84, "So Long");
	if (!g_node.init)
	{
		perror("Error");
		exit(0);
	}
	mlx_key_hook(g_node.win, close_event_window, &g_node);
	mlx_hook(g_node.win, 17, 0, close_window, &g_node);
	g_node.moves_int = 0;
	g_node.controller_eff = 1;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("\033[1;31mError\n\033[1;0m");
		return (0);
	}
	if (!check_extension(av[1]))
	{
		ft_printf("\033[1;31mError\n\033[1;0m");
		return (0);
	}
	fill_image_space(&g_node);
	g_node.map = create_string_map(av[1]);
	g_node.rows = count_mtr_lines(g_node.map);
	g_node.cols = ft_strlen(g_node.map[0]);
	if (!check_main(g_node) || !big_verification(&g_node))
	{
		ft_printf("\033[1;31mError\n\033[1;0m");
		return (0);
	}
	proccess_initial();
	mlx_hook(g_node.win, 2, 1L << 0, effect_move, NULL);
	create_stadio(g_node.map, &g_node);
	mlx_loop(g_node.init);
	full_free(&g_node);
	return (0);
}
