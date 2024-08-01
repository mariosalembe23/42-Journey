/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:58:54 by mario             #+#    #+#             */
/*   Updated: 2024/07/25 00:27:07 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static void    move_up(t_config *config, t_point index)
{
    if (config->map[index.x - 1][index.y] == 'E' && count_items(config->map, 'C') > 0)
        return ;
    if (config->map[index.x - 1][index.y] != '1')
    {
        if (config->map[index.x - 1][index.y] == 'E')
        {
            config->map[index.x][index.y] = '0';
            config->map[index.x - 1][index.y] = 'P';
            final_status(1, config);
        }
        config->map[index.x][index.y] = '0';
        config->map[index.x - 1][index.y] = 'P';
    }
}

static void    move_down(t_config *config, t_point index)
{
    
    if (config->map[index.x + 1][index.y] == 'E' && count_items(config->map, 'C') > 0)
        return ;
    if (config->map[index.x + 1][index.y] != '1')
    {
        if (config->map[index.x + 1][index.y] == 'E')
        {
            config->map[index.x][index.y] = '0';
            config->map[index.x + 1][index.y] = 'P';
            final_status(1, config);
        }
        config->map[index.x][index.y] = '0';
        config->map[index.x + 1][index.y] = 'P';
    }
    
}

static void    move_left(t_config *config, t_point index)
{
    
    if (config->map[index.x][index.y - 1] == 'E' && count_items(config->map, 'C') > 0)
        return ;
    if (config->map[index.x][index.y - 1] != '1')
    {
        if (config->map[index.x][index.y - 1] == 'E')
        {
            config->map[index.x][index.y] = '0';
            config->map[index.x][index.y - 1] = 'P';
            final_status(1, config);
        }
        config->map[index.x][index.y] = '0';
        config->map[index.x][index.y - 1] = 'P';
        config->images.person = "./textures/bird_left.xpm";
    }
    
}

static void    move_right(t_config *config, t_point index)
{
    
  if (config->map[index.x][index.y + 1] == 'E' && count_items(config->map, 'C') > 0)
        return ;
    if (config->map[index.x][index.y + 1] != '1')
    {
        if (config->map[index.x][index.y + 1] == 'E')
        {
            config->map[index.x][index.y] = '0';
            config->map[index.x][index.y + 1] = 'P';
            final_status(1, config);
        }
        config->map[index.x][index.y] = '0';
        config->map[index.x][index.y + 1] = 'P';
        config->images.person = "./textures/bird_dark.xpm";
    }
}

void change_position(t_config *config, enum e_move move)
{
    t_point position;
    
    position = find_player(config->map);
    
    if (move == UP)
        move_up(config, position);
    else if (move == DOWN)
        move_down(config, position);
    else if (move == LEFT)
        move_left(config, position);
    else if (move == RIGHT)
        move_right(config, position);
}