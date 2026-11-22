/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clues.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:44:51 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 20:12:23 by amandres         ###   ########.fr       */
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
