/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stadio.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 01:46:14 by msalembe          #+#    #+#             */
/*   Updated: 2024/08/04 04:07:13 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	*load_image(t_config *Node, char *path)
{
	return (mlx_xpm_file_to_image(Node->init, path, &Node->width,
			&Node->height));
}

void	show_image_window(char **mtr, int i, int *x, t_config *Node)
{
	while (mtr[i][*x] != '\0')
	{
		if (mtr[i][*x] == '1')
			mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
					Node->img.wall), Node->alternate_x, Node->alternate_y);
		if (mtr[i][*x] == '0')
			mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
					Node->img.flood), Node->alternate_x, Node->alternate_y);
		if (mtr[i][*x] == 'P')
			mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
					Node->img.person), Node->alternate_x, Node->alternate_y);
		if (mtr[i][*x] == 'C')
			mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
					Node->img.eat), Node->alternate_x, Node->alternate_y);
		if (mtr[i][*x] == 'E')
			mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
					Node->img.meta), Node->alternate_x, Node->alternate_y);
		*x += 1;
		Node->alternate_x += Node->width;
		if (Node->controller_eff == 1)
			usleep(10000);
	}
}

void	create_stadio(char **mtr, t_config *Node)
{
	int	i;
	int	x;

	Node->alternate_y = 84;
	Node->alternate_x = 0;
	Node->width = 42;
	Node->height = 42;
	i = 0;
	while (mtr[i] != NULL)
	{
		x = 0;
		show_image_window(mtr, i, &x, Node);
		Node->alternate_y += Node->height;
		Node->alternate_x = 0;
		i++;
	}
	mlx_string_put(Node->init, Node->win, 42, 42, 0xffffffff, "Moves: ");
	mlx_string_put(Node->init, Node->win, 84, 44, 0xffffffff,
		ft_itoa(Node->moves_int));
}
