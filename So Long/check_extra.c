/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 02:13:20 by mario             #+#    #+#             */
/*   Updated: 2024/08/04 04:14:22 by mario            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./so_long.h"

static char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

int	check_extension(char *str)
{
	char	*extension;

	if (!str)
		return (0);
	extension = ft_strrchr(str, '.') + 1;
	if (ft_strcmp(extension, "ber") == 0)
		return (1);
	return (0);
}

static int	get_digit_count(int number)
{
	int	count;

	count = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		count++;
	while (number != 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static void	fill_str(char *str, int *number, int *count)
{
	while (*number != 0)
	{
		str[--*count] = (*number % 10) + '0';
		*number /= 10;
	}
}

char	*ft_itoa(int number)
{
	int		count;
	char	*str;
	int		is_negative;

	count = get_digit_count(number);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[count] = '\0';
	is_negative = 0;
	if (number < 0)
	{
		is_negative = 1;
		number = -number;
	}
	if (number == 0)
	{
		str[0] = '0';
		return (str);
	}
	fill_str(str, &number, &count);
	if (is_negative)
		str[0] = '-';
	return (str);
}
