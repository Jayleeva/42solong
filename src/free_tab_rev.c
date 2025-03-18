/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tab_rev.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyglardo <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:59:58 by cyglardo          #+#    #+#             */
/*   Updated: 2025/03/18 15:18:39 by cyglardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft.h"

void	free_tab_rev(char **tab, int i)
{
	i--;
	while (i > 0)
	{
		free(tab[i]);
		tab[i] = NULL;
		i--;
	}
}
