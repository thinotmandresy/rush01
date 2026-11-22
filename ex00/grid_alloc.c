/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:33:13 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 19:36:46 by amandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_grid(int **grid, int rows)
{
	int	i;

	i = 0;
	if (!grid)
		return ;
	while (i < rows)
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}

int	**alloc_grid(int rows, int cols)
{
	int	**grid;
	int	i;
	int	j;

	i = 0;
	j = 0;
	grid = malloc(rows * sizeof(int*));
	if (!grid)
		return (0);
	while (i < rows)
	{
		grid[i] = malloc(cols * sizeof(int));
		if (!grid[i])
		{
			free_grid(grid, i);
			return (0);
		}
		j = 0;
		while (j < cols)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
	return (grid);
}
