/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 02:26:49 by mario             #+#    #+#             */
/*   Updated: 2024/08/01 07:11:17 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void    fill_image_space(t_config *config)
{
    config->images.person = "./textures/bird_dark.xpm"; 
	config->images.eat = "./textures/eat_dark.xpm"; 
	config->images.flood = "./textures/flood.xpm"; 
	config->images.wall = "./textures/obs.xpm"; 
	config->images.meta = "./textures/meta.xpm";
}

int ft_strcmp(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s1[i] == s2[i] && s1[i])
        i++;
    return (s1[i] - s2[i]);
}
int close_window(void *param)
{
    t_config *config = (t_config *)param;
    mlx_destroy_window(config->server_lib, config->window);
    exit(0);
}

int close_event_window(int key, void *param)
{
    if (key == 'q' || key == 'Q')
    {
        t_config *config = (t_config *)param;
        mlx_destroy_window(config->server_lib, config->window);
        exit(0);
    }
    return (0);
}

void full_free(t_config *config)
{
    mlx_destroy_display(config->server_lib);
	free(config->server_lib);
}

