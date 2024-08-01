/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 15:44:01 by mario             #+#    #+#             */
/*   Updated: 2024/08/01 07:56:37 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int count_mtr_lines(char **mtr)
{
    int i;

    i = 0;
    if (!mtr || !*mtr)
        return (0);
    while (mtr[i] != NULL)
        i++;
    return (i);
}
t_point find_player(char **mtr)
{
    t_point index;

    index.x = 0;
    
    while (mtr[index.x] != NULL)
    {
        index.y = 0;
        while (mtr[index.x][index.y] != '\0')
        {
            if (mtr[index.x][index.y] == 'P')
                return (index);
            index.y++;
        }
         index.x++;
    }
    index.y = -1;
    index.x = -1;
    return (index);
}
int count_items(char **mtr, char c)
{
    int x;
    int y;
    int counter;
    
    counter = 0;
    x = -1;
    while (++x < count_mtr_lines(mtr) - 1)
    {
        y = -1;
        while (mtr[x][++y] != '\0')
            if (mtr[x][y] == c)
                counter++;
    }
    return (counter);
}

void final_status(int is_win, t_config *config)
{
   create_stadio(config->map, config, 0);
    if (is_win == 1)
    {
        config->images.person = "./textures/F.xpm"; 
	    config->images.eat = "./textures/F.xpm"; 
	    config->images.flood = "./textures/F.xpm"; 
	    config->images.wall = "./textures/F.xpm"; 
	    config->images.meta = "./textures/F.xpm"; 
    }
    else
    {
        config->images.person = "./textures/flood.xpm"; 
	    config->images.eat = "./textures/flood.xpm"; 
	    config->images.flood = "./textures/flood.xpm"; 
	    config->images.wall = "./textures/flood.xpm"; 
	    config->images.meta = "./textures/flood.xpm"; 
    }
    create_stadio(config->map, config, 1);
    usleep(10000);
    exit(0);
}