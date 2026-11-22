/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amandres <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:28:03 by amandres          #+#    #+#             */
/*   Updated: 2026/11/22 19:50:13 by amandres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
int		error(void);
int		count_clues(char *clues);

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
	ft_putchar('S');
	ft_putchar('k');
	ft_putchar('y');
	ft_putchar('s');
	ft_putchar('c');
	ft_putchar('r');
	ft_putchar('a');
	ft_putchar('p');
	ft_putchar('e');
	ft_putchar('r');
	ft_putchar('s');
	ft_putchar('\n');
	return (0);
}
