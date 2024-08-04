/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:58:54 by mario             #+#    #+#             */
/*   Updated: 2024/08/04 04:04:31 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void	move_up(t_config *Node, t_point index)
{
	if (Node->map[index.x - 1][index.y] == 'E' && count_items(Node->map,
			'C') > 0)
		return ;
	if (Node->map[index.x - 1][index.y] != '1')
	{
		if (Node->map[index.x - 1][index.y] == 'E')
		{
			Node->map[index.x][index.y] = '0';
			Node->map[index.x - 1][index.y] = 'P';
			final_status(1, Node);
		}
		Node->map[index.x][index.y] = '0';
		Node->map[index.x - 1][index.y] = 'P';
		Node->moves_int++;
		mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
				Node->img.back), 82, 30);
		mlx_string_put(Node->init, Node->win, 84, 44, 0xffffffff,
			ft_itoa(Node->moves_int));
	}
}

static void	move_down(t_config *Node, t_point index)
{
	if (Node->map[index.x + 1][index.y] == 'E' && count_items(Node->map,
			'C') > 0)
		return ;
	if (Node->map[index.x + 1][index.y] != '1')
	{
		if (Node->map[index.x + 1][index.y] == 'E')
		{
			Node->map[index.x][index.y] = '0';
			Node->map[index.x + 1][index.y] = 'P';
			final_status(1, Node);
		}
		Node->map[index.x][index.y] = '0';
		Node->map[index.x + 1][index.y] = 'P';
		Node->moves_int++;
		mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
				Node->img.back), 82, 30);
		mlx_string_put(Node->init, Node->win, 84, 44, 0xffffffff,
			ft_itoa(Node->moves_int));
	}
}

static void	move_left(t_config *Node, t_point index)
{
	if (Node->map[index.x][index.y - 1] == 'E' && count_items(Node->map,
			'C') > 0)
		return ;
	if (Node->map[index.x][index.y - 1] != '1')
	{
		if (Node->map[index.x][index.y - 1] == 'E')
		{
			Node->map[index.x][index.y] = '0';
			Node->map[index.x][index.y - 1] = 'P';
			final_status(1, Node);
		}
		Node->map[index.x][index.y] = '0';
		Node->map[index.x][index.y - 1] = 'P';
		Node->img.person = "./textures/bird_left.xpm";
		Node->moves_int++;
		mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
				Node->img.back), 82, 30);
		mlx_string_put(Node->init, Node->win, 84, 44, 0xffffffff,
			ft_itoa(Node->moves_int));
	}
}

static void	move_right(t_config *Node, t_point index)
{
	if (Node->map[index.x][index.y + 1] == 'E' && count_items(Node->map,
			'C') > 0)
		return ;
	if (Node->map[index.x][index.y + 1] != '1')
	{
		if (Node->map[index.x][index.y + 1] == 'E')
		{
			Node->map[index.x][index.y] = '0';
			Node->map[index.x][index.y + 1] = 'P';
			final_status(1, Node);
		}
		Node->map[index.x][index.y] = '0';
		Node->map[index.x][index.y + 1] = 'P';
		Node->img.person = "./textures/bird_dark.xpm";
		Node->moves_int++;
		mlx_put_image_to_window(Node->init, Node->win, load_image(Node,
				Node->img.back), 82, 30);
		mlx_string_put(Node->init, Node->win, 84, 44, 0xffffffff,
			ft_itoa(Node->moves_int));
	}
}

void	change_position(t_config *Node, enum e_move move)
{
	t_point	position;

	position = find_player(Node->map);
	if (move == UP)
		move_up(Node, position);
	else if (move == DOWN)
		move_down(Node, position);
	else if (move == LEFT)
		move_left(Node, position);
	else if (move == RIGHT)
		move_right(Node, position);
}
