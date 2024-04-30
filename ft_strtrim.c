/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchalaou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 10:08:27 by tchalaou          #+#    #+#             */
/*   Updated: 2023/11/14 18:49:51 by tchalaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	char	*pstr;
	int		i;
	int		e;

	i = 0;
	e = ft_strlen(s1) - 1;
	while (ft_isset(s1[i], set))
		i++;
	while (ft_isset(s1[e], set))
		e--;
	if (i > e)
		return (ft_strdup(""));
	str = malloc(e - i + 2);
	if (!str)
		return (NULL);
	pstr = str;
	while (i <= e)
		*pstr++ = s1[i++];
	*pstr = 0;
	return (str);
}
