/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 21:32:54 by mario             #+#    #+#             */
/*   Updated: 2024/07/31 23:45:04 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void dfs(int **map, int x, int y, t_config *config, int **visited) {
    int i;
    
    i = -1;
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    visited[x][y] = 1;

    while (++i < 4) {
        int newX = x + directions[i][0];
        int newY = y + directions[i][1];

        if (isValid(map, newX, newY, config, visited)) {
            dfs(map, newX, newY, config, visited);
        }
    }
}

static void initialize_map_and_visited(t_config *config, int ***map, int ***visited) {
    int x;
    int y;

    x = -1;
    *map = (int **)malloc(config->rows * sizeof(int *));
    *visited = (int **)malloc(config->rows * sizeof(int *));
    while (++x < config->rows) {
        (*map)[x] = (int *)malloc(config->cols * sizeof(int));
        (*visited)[x] = (int *)malloc(config->cols * sizeof(int));
        y = -1;
        while (++y < config->cols) {
            (*visited)[x][y] = 0;
        }
    }
}

static void find_start_position(t_config *config, int **map, int *startX, int *startY) {
    int x;
    int y;

    x = -1;
    *startX = -1;
    *startY = -1;
    while (++x < config->rows) {
        y = -1;
        while (++y < config->cols) {
            map[x][y] = config->map[x][y];
            if (map[x][y] == 'P') {
                *startX = x;
                *startY = y;
            }
        }
    }
}

static int check_validity(t_config *config, int **map, int **visited) {
    int x;
    int y;

    x = -1;
    while (++x < config->rows) {
        y = -1;
        while (++y < config->cols) {
            if ((map[x][y] == 'C' || map[x][y] == 'E') && !visited[x][y]) {
                return 0;
            }
        }
    }
    return 1;
}

int big_verification(t_config *config) {
    int **map;
    int **visited;
    int startX;
    int startY;

    initialize_map_and_visited(config, &map, &visited);
    find_start_position(config, map, &startX, &startY);

    if (startX == -1 || startY == -1) {
        free_memory(config, map, visited);
        return (0);
    }
    dfs(map, startX, startY, config, visited);
    if (check_validity(config, map, visited))
        return (1);
    return (0);
    free_memory(config, map, visited);
}

