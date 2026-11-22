/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:44:51 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 21:47:21 by amandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_clues(char *raw_clues)
{
	int	count;

	count = 0;
	while (*raw_clues)
	{
		if (*raw_clues == ' ')
		{
			raw_clues++;
			continue ;
		}
		if (*raw_clues < '1' || *raw_clues > '9')
			return (-1);
		if (*(raw_clues + 1) >= '0' && *(raw_clues + 1) <= '9')
			return (-1);
		count++;
		raw_clues++;
	}
	return (count);
}

int	fill_clues(int **clues, char *raw_clues, int n)
{
	int	side;
	int	i;

	side = 0;
	while (side < 4)
	{
		i = 0;
		while (i < n)
		{
			while (*raw_clues == ' ')
				raw_clues++;
			clues[side][i] = *raw_clues - '0';
			if (clues[side][i] > n)
				return (0);
			raw_clues++;
			i++;
		}
		side++;
	}
	return (1);
}

int	check_row(int **grid, int row, int n, int direction)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	if (direction == -1)
		i = n - 1;
	while (1)
	{
		if (direction == 1 && i >= n)
			break ;
		if (direction == -1 && i == -1)
			break ;
		if (grid[row][i] > max)
		{
			max = grid[row][i];
			seen++;
		}
		i = i + direction;
	}
	return (seen);
}

int	check_col(int **grid, int col, int n, int direction)
{
	int	i;
	int	max;
	int	seen;

	i = 0;
	max = 0;
	seen = 0;
	if (direction == -1)
		i = n - 1;
	while (1)
	{
		if (direction == 1 && i >= n)
			break ;
		if (direction == -1 && i == -1)
			break ;
		if (grid[i][col] > max)
		{
			max = grid[i][col];
			seen++;
		}
		i = i + direction;
	}
	return (seen);
}

int	check_clues(int **grid, int **clues, int row, int col)
{
	int	n;

	n = clues[4][0];
	if (col == n - 1)
	{
		if (check_row(grid, row, n, 1) != clues[2][row])
			return (0);
		if (check_row(grid, row, n, -1) != clues[3][row])
			return (0);
	}
	if (row == n - 1)
	{
		if (check_col(grid, col, n, 1) != clues[0][col])
			return (0);
		if (check_col(grid, col, n, -1) != clues[1][col])
			return (0);
	}
	return (1);
}

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
