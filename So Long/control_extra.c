/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:19:03 by mario             #+#    #+#             */
/*   Updated: 2024/08/04 04:14:30 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_memory(t_config *Node, int **map, int **visited)
{
	int	i;

	i = -1;
	while (++i < Node->rows)
	{
		free(map[i]);
		free(visited[i]);
	}
	free(map);
	free(visited);
}

int	is_valid(int **map, int x, int y, t_config *Node)
{
	return (x >= 0 && x < Node->rows && y >= 0 && y < Node->cols
		&& map[x][y] != '1' && !Node->visited[x][y]);
}

int	check_line_num(char **mtr)
{
	int	i;
	int	len;

	i = 0;
	if (!*mtr || !mtr)
		return (0);
	len = ft_strlen(mtr[0]);
	while (i < count_mtr_lines(mtr) - 1)
	{
		if (ft_strlen(mtr[i]) != len)
			return (0);
		i++;
	}
	return (1);
}
