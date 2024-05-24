/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_params.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ukireyeu < ukireyeu@student.42warsaw.pl    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:30:18 by ukireyeu          #+#    #+#             */
/*   Updated: 2024/05/23 12:21:12 by ukireyeu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

char	**split_params(char const *s, char c);
void	ft_free_words(char **words);
