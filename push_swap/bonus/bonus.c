/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albrusso <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:21:58 by albrusso          #+#    #+#             */
/*   Updated: 2023/02/02 16:18:08 by albrusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushSwap.h"

void	ft_add_lst(t_value *a, t_value *b, int argc, char *argv[])
{
	int	i;

	i = 2;
	a->lst = ft_lstnew(ft_atoi(argv[1]));
	b->lst = NULL;
	while (i < argc)
	{
		ft_lstadd_back(&a->lst, ft_lstnew(ft_atoi(argv[i])));
		i++;
	}	
}

int	ft_read_rules(char *rules, t_value *a, t_value *b)
{
	while (1)
	{
		rules = get_next_line(0);
		if (rules == NULL || ft_strcmp(rules, "EOF\n") == 0)
		{
			free(rules);
			break ;
		}
		if (ft_execute_rules(rules, a, b) == 0)
		{
			free(rules);
			return (0);
		}
		free(rules);
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

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
	char	*rules;
	t_value	a;
	t_value	b;
	int		i;

	if (argc < 3)
		return (0);
	else
	{
		if (ft_check_num(argc, argv) == 0)
			return (write(1, "Errore\n", 7));
		else
		{
			ft_add_lst(&a, &b, argc, argv);
			ft_read_rules(rules, &a, &b);
			if (ft_isorder(&a.lst) == 0)
				write(1, "KO\n", 3);
			else
				write(1, "OK\n", 3);
		}
	}
	ft_free(a.lst);
	return (0);
}
