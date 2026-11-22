/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:44:51 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 20:10:26 by amandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	count_clues(char *clues)
{
	int	count;

	count = 0;
	while (*clues)
	{
		if (*clues == ' ')
		{
			clues++;
			continue ;
		}
		if (*clues < '1' || *clues > '9')
			return (-1);
		if (*(clues + 1) >= '0' && *(clues + 1) <= '9')
			return (-1);
		count++;
		clues++;
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
