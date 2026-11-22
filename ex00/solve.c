/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 20:42:56 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 21:52:13 by amandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_valid(int **grid, int n, int row, int col);
int	check_clues(int **grid, int **clues, int row, int col);

int	fits(int **grid, int **clues, int row, int col)
{
	int	i;

	i = 0;
	while (i < clues[4][0])
	{
		if (i != col && grid[row][i] == grid[row][col])
			return (0);
		if (i != row && grid[i][col] == grid[row][col])
			return (0);
		i++;
	}
	return (check_clues(grid, clues, row, col));
}

int	solve(int **grid, int **clues, int row, int col)
{
	int	n;
	int	val;

	n = clues[4][0];
	if (col == n)
		return (solve(grid, clues, row + 1, 0));
	if (row == n)
		return (1);
	val = 1;
	while (val <= n)
	{
		grid[row][col] = val;
		if (fits(grid, clues, row, col) && solve(grid, clues, row, col + 1))
			return (1);
		val++;
	}
	grid[row][col] = 0;
	return (0);
}
