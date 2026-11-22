/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:53:59 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 21:35:50 by amandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		**alloc_grid(int rows, int cols);
void	free_grid(int **grid, int rows);
int		fill_clues(int **clues, char *s, int n);
int		solve(int **grid, int **clues, int row, int col);
void	print_grid(int **grid, int n);

int	run(char *raw_clues, int n)
{
	int	**grid;
	int	**clues;
	int	is_ok;

	grid = alloc_grid(n, n);
	clues = alloc_grid(5, n);
	is_ok = 0;
	if (grid && clues)
	{
		clues[4][0] = n;
		if (fill_clues(clues, raw_clues, n) && solve(grid, clues, 0, 0))
		{
			print_grid(grid, n);
			is_ok = 1;
		}
	}
	free_grid(grid, n);
	free_grid(clues, 5);
	return (is_ok);
}
