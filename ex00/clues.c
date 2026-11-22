/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_clues.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:44:51 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 19:46:50 by amandres         ###   ########.fr       */
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
