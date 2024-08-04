/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 02:26:49 by mario             #+#    #+#             */
/*   Updated: 2024/08/04 03:56:45 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	fill_image_space(t_config *Node)
{
	Node->img.person = "./textures/bird_dark.xpm";
	Node->img.eat = "./textures/eat_dark.xpm";
	Node->img.flood = "./textures/flood.xpm";
	Node->img.wall = "./textures/obs.xpm";
	Node->img.meta = "./textures/meta.xpm";
	Node->img.back = "./textures/fundo.xpm";
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
		i++;
	return (s1[i] - s2[i]);
}

int	close_window(void *param)
{
	t_config	*node;

	node = (t_config *)param;
	mlx_destroy_window(node->init, node->win);
	exit(0);
}

int	close_event_window(int key, void *param)
{
	t_config	*node;

	if (key == 'q' || key == 'Q')
	{
		node = (t_config *)param;
		mlx_destroy_window(node->init, node->win);
		exit(0);
	}
	return (0);
}

void	full_free(t_config *Node)
{
	mlx_destroy_display(Node->init);
	free(Node->init);
}
