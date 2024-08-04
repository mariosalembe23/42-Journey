/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:32:54 by mario             #+#    #+#             */
/*   Updated: 2024/08/04 00:54:00 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	dfs(int **map, int x, int y, t_config *Node)
{
	int	i;
	int	directions[4][2];
	int	new_x;
	int	new_y;

	i = -1;
	directions[0][0] = -1;
	directions[0][1] = 0;
	directions[1][0] = 1;
	directions[1][1] = 0;
	directions[2][0] = 0;
	directions[2][1] = -1;
	directions[3][0] = 0;
	directions[3][1] = 1;
	Node->visited[x][y] = 1;
	while (++i < 4)
	{
		new_x = x + directions[i][0];
		new_y = y + directions[i][1];
		if (is_valid(map, new_x, new_y, Node))
		{
			dfs(map, new_x, new_y, Node);
		}
	}
}

static void	initialize_map_and_visited(t_config *Node, int ***map,
		int ***visited)
{
	int	x;
	int	y;

	x = -1;
	*map = (int **)malloc(Node->rows * sizeof(int *));
	*visited = (int **)malloc(Node->rows * sizeof(int *));
	while (++x < Node->rows)
	{
		(*map)[x] = (int *)malloc(Node->cols * sizeof(int));
		(*visited)[x] = (int *)malloc(Node->cols * sizeof(int));
		y = -1;
		while (++y < Node->cols)
		{
			(*visited)[x][y] = 0;
		}
	}
}

static void	find_start_position(t_config *Node, int **map, int *start_x,
		int *start_y)
{
	int	x;
	int	y;

	x = -1;
	*start_x = -1;
	*start_y = -1;
	while (++x < Node->rows)
	{
		y = -1;
		while (++y < Node->cols)
		{
			map[x][y] = Node->map[x][y];
			if (map[x][y] == 'P')
			{
				*start_x = x;
				*start_y = y;
			}
		}
	}
}

static int	check_validity(t_config *Node, int **map, int **visited)
{
	int	x;
	int	y;

	x = -1;
	while (++x < Node->rows)
	{
		y = -1;
		while (++y < Node->cols)
		{
			if ((map[x][y] == 'C' || map[x][y] == 'E') && !visited[x][y])
			{
				return (0);
			}
		}
	}
	return (1);
}

int	big_verification(t_config *Node)
{
	int	**map;
	int	start_x;
	int	start_y;

	initialize_map_and_visited(Node, &map, &Node->visited);
	find_start_position(Node, map, &start_x, &start_y);
	if (start_x == -1 || start_y == -1)
	{
		free_memory(Node, map, Node->visited);
		return (0);
	}
	dfs(map, start_x, start_y, Node);
	if (check_validity(Node, map, Node->visited))
		return (1);
	return (0);
	free_memory(Node, map, Node->visited);
}
