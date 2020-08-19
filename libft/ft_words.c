/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_words.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mannette <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:15:54 by mannette          #+#    #+#             */
/*   Updated: 2019/04/30 20:18:18 by mannette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_words(char const *s1, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] != c && s1[i] != '\0')
		{
			while (s1[i] != c && s1[i] != '\0')
			{
				i++;
			}
			count++;
		}
		while (s1[i] == c)
			i++;
	}
	return (count);
}