/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:11:32 by mario             #+#    #+#             */
/*   Updated: 2024/08/01 06:04:07 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int check_line_num(char **mtr)
{
    int i;
    int len;

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
int check_full_line(char **mtr, int line)
{
    int i;

    i = 0;
    if (!*mtr || !mtr)
        return (0);
    while (mtr[line][i] != '\0')
    {
       if (mtr[line][i] != '1')
            return (0);
       i++;
    }
    return (1);
}

int check_full_colum(char **mtr)
{
    int i;

    i = 0;
     if (!*mtr || !mtr)
        return (0);
    while (i < count_mtr_lines(mtr) - 1)
    {
        if (mtr[i][0] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_full_end_column(char **mtr)
{
    int i;

    i = 0;
     if (!*mtr || !mtr)
        return (0);
    while (i < count_mtr_lines(mtr) - 1)
    {
        if (mtr[i][ft_strlen(mtr[i]) - 1] != '1')
            return (0);
        i++;
    }
    return (1);
}

int check_items(char **mtr)
{
    int x;
    int y;

    x = 0;
    while (x < count_mtr_lines(mtr) - 1)
    {
        y = 0;
        while (mtr[x][y] != '\0')
        {
            if (mtr[x][y] != '1' && mtr[x][y] != '0' && mtr[x][y] != 'E' && mtr[x][y] != 'C' && mtr[x][y] != 'P')
                return (0);
            y++;
        }
        x++;
    }
    return (1);
}

int check_main(t_config config)
{
    if (!check_line_num(config.map))
        return (0);
    if (!check_full_line(config.map, 0))
        return (0);
    if (!check_full_line(config.map, count_mtr_lines(config.map) - 1))
        return (0);
    if (!check_full_colum(config.map))
        return (0);
    if (!check_full_end_column(config.map))
        return (0);
    if (!check_items(config.map))
        return (0);
    if (count_items(config.map, 'P') == 0 || count_items(config.map, 'E') == 0 || count_items(config.map, 'E') == 0)
        return (0);
    if (count_items(config.map, 'P') > 1 || count_items(config.map, 'E') > 1)
        return (0);
    return (1);
}