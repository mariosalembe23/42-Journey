/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:15:16 by msalembe          #+#    #+#             */
/*   Updated: 2024/07/25 02:10:07 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

int	calculate_width_window(char **mtr)
{
	int	i;

	i = -1;
	while (mtr[++i] != NULL)
		;
	return (i);
}

void	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	return ;
}

static int	rows_count(char const *s, char c)
{
	int		number_separator;
	char	*str;

	number_separator = 0;
	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			number_separator++;
		str++;
	}
	return (number_separator + 1);
}

static char	**fill_mtr(char **mtr, char const *str, char c, int rows)
{
	int	i;
	int	x;

	i = 0;
	while (i < rows)
	{
		while (*str == c)
			str++;
		x = 0;
		while (str[x] && str[x] != c)
			x++;
		mtr[i] = (char *)malloc((x + 1) * sizeof(char));
		if (!mtr[i])
			free_matrix(mtr);
		x = 0;
		while (*str && *str != c)
		{
			mtr[i][x++] = *str;
			str++;
		}
		mtr[i][x] = '\0';
		i++;
	}
	mtr[i] = NULL;
	return (mtr);
}

char	**ft_split(char *str, char c)
{
	char	**matriz;
	int		rows;

	rows = rows_count(str, c);
	matriz = (char **)malloc(sizeof(char *) * (rows + 1));
	if (!matriz)
		return (NULL);
	matriz = fill_mtr(matriz, str, c, rows);
	return (matriz);
}
