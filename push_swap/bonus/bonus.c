/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:21:58 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/01 17:07:42 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
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
	char		*rules;

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
		{
			int	i;

			i = 2;
			a.lst = ft_lstnew(ft_atoi(argv[1]));
			b.lst = NULL;
			while (i < argc)
			{
				ft_lstadd_back(&a.lst, ft_lstnew(ft_atoi(argv[i])));
				i++;
			}
			while (1)
			{
				rules = get_next_line(0);
				if (rules == NULL || ft_strcmp(rules, "EOF\n") == 0)
				{
					free(rules);
					break ;
				}
				if (ft_execute_rules(rules, &a, &b) == 0)
				{
					free(rules);
					return (0);
				}
				free(rules);
			}
			if (ft_isorder(&a.lst) == 0)
				write(1, "KO\n", 3);
			else
				write(1, "OK\n", 3);
		}
	}
	ft_free(a.lst);
	return (0);
}