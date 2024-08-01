/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_extra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 04:19:03 by mario             #+#    #+#             */
/*   Updated: 2024/08/01 05:16:54 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_memory(t_config *config, int **map, int **visited) {
    int i;

    i = -1;
    while (++i < config->rows) {
        free(map[i]);
        free(visited[i]);
    }
    free(map);
    free(visited);
}

int isValid(int **map, int x, int y, t_config *config, int **visited) {
    return (x >= 0 && x < config->rows && y >= 0 && y < config->cols && map[x][y] != '1' && !visited[x][y]);
}