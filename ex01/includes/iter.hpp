/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/09 04:00:44 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ITER_H__
#define __ITER_H__

#include <iostream>

template< typename T >
void	printArrElGeneric( T arrEl )
{
	std::cout << arrEl;
	return ;
}

template< typename T, typename U >
void    iter( T* arr, int length, U f )
{
    for (int i = 0; i < length; i++)
        (f)(arr[i]);
    return ;
}

#endif