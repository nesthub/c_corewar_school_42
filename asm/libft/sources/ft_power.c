/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abary <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:13:54 by abary             #+#    #+#             */
/*   Updated: 2016/02/01 13:00:24 by abary            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_power(int nbr, int power)
{
	if (power < 0 || nbr == 0)
		return (0);
	if (power == 0)
		return (1);
	else
		return ((nbr) * ft_power(nbr, power - 1));
}