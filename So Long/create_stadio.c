/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stadio.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 01:46:14 by msalembe          #+#    #+#             */
/*   Updated: 2024/07/25 01:51:56 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

void	*load_image(t_config *config, char *path, int *width, int *height)
{
	return (mlx_xpm_file_to_image(config->server_lib, path, width,
									height));
}

void	show_image_window(char **mtr, int i, int *x, t_config *config, int controller_eff)
{
	while (mtr[i][*x] != '\0')
	{
			if (mtr[i][*x] == '1')
				mlx_put_image_to_window(config->server_lib, config->window,
										load_image(config, config->images.wall, &config->width, &config->height), config->alternate_x, config->alternate_y);
			if (mtr[i][*x] == '0')
					mlx_put_image_to_window(config->server_lib, config->window,
											load_image(config, config->images.flood, &config->width, &config->height), config->alternate_x, config->alternate_y);
			if (mtr[i][*x] == 'P')
					mlx_put_image_to_window(config->server_lib, config->window,
											load_image(config, config->images.person, &config->width, &config->height), config->alternate_x, config->alternate_y);
			if (mtr[i][*x] == 'C')
					mlx_put_image_to_window(config->server_lib, config->window,
											load_image(config, config->images.eat, &config->width, &config->height), config->alternate_x, config->alternate_y);
			if (mtr[i][*x] == 'E')
					mlx_put_image_to_window(config->server_lib, config->window,
											load_image(config, config->images.meta, &config->width, &config->height), config->alternate_x, config->alternate_y);
			*x += 1;
			config->alternate_x += config->width;
			if (controller_eff == 1)
				usleep(10000);
	}
}

void create_stadio(char **mtr, t_config *config, int controller_eff)
{
	int i;
	int x;

	config->alternate_y = 0;
	config->alternate_x = 0;
	config->width = 42;
	config->height = 42;
	i = 0;

	while (mtr[i] != NULL)
	{
		x = 0;
		show_image_window(mtr, i, &x, config, controller_eff);
		config->alternate_y += config->height;
		config->alternate_x = 0;
		i++;
	}
}
