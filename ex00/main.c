/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:28:03 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 21:40:43 by amandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		error(void);
int		count_clues(char *clues);
int		run(char *clues, int n);

int	main(int argc, char *argv[])
{
	int	nb_clues;
	int	n;

	nb_clues = 0;
	n = 0;
	if (argc != 2)
		return (error());
	nb_clues = count_clues(argv[1]);
	n = nb_clues / 4;
	if (n < 1 || n > 9)
		return (error());
	if (!run(argv[1], n))
		return (error());
	return (0);
}
