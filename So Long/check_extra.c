/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mario <mario@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 02:13:20 by mario             #+#    #+#             */
/*   Updated: 2024/07/25 02:30:06 by mario            ###   ########.fr       */
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

int    check_extension(char *str)
{
    char *extension;

    if (!str)
        return (0);
    extension = ft_strrchr(str, '.') + 1;
    if (ft_strcmp(extension, "ber") == 0)
        return (1);
    return (0);
}