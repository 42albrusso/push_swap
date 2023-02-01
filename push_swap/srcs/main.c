/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:37:53 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/01 17:23:23 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

void	ft_main(t_value *a, t_value *b, char *argv[])
{
	int	i;

	i = 2;
	a->lst = ft_lstnew(ft_atoi(argv[1]));
	b->lst = NULL;
	while (i < a->ac)
	{
		ft_lstadd_back(&a->lst, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}
	if (a->ac == 4)
		ft_three_numbers(a, 0);
	if (a->ac == 6)
		ft_five_numbers(a, b);
	if (a->ac >= 7)
		ft_onehundred_numbers(a, b);
}

void	ft_free(t_stack *lst)
{
	t_stack	*temp;

	if (lst)
	{
		temp = lst->next;
		ft_free(temp);
	}
	free(lst);
}

int	main(int argc, char *argv[])
{
	t_value	a;
	t_value	b;

	a.ac = argc;
	b.ac = argc;
	if (argc < 3)
		return (0);
	else
	{
		if (ft_check_num(argc, argv) == 0)
		{
			write(1, "Errore\n", 7);
			return (0);
		}
		else
			ft_main(&a, &b, argv);
	}
	ft_free(a.lst);
	return (0);
}
