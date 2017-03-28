/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: craffate <craffate@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 10:54:39 by craffate          #+#    #+#             */
/*   Updated: 2017/03/17 10:57:55 by craffate         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	wordscounter(const char *s, const char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	while (s[j++])
		if (s[j] == c && s[j + 1] != c)
			i++;
	if (s[0] != '\0')
		i++;
	return (i);
}

static char			*elements(const char *s, const char c, unsigned int *i)
{
	char			*w;
	unsigned int	j;

	j = 0;
	if (!(w = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[*i] != c && s[*i])
	{
		w[j] = s[*i];
		j++;
		*i += 1;
	}
	w[j] = '\0';
	while (s[*i] == c && s[*i])
		*i += 1;
	return (w);
}

char				**ft_strsplit(char const *s, const char c)
{
	char			**arr;
	unsigned int	words;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	words = wordscounter(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] == c && s[i])
		i++;
	while (j < words && s[i])
	{
		arr[j] = elements(s, c, &i);
		j++;
	}
	arr[j] = NULL;
	return (arr);
}
