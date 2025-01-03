/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/08 23:33:04 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __WHATEVER_H__
#define __WHATEVER_H__

template< typename T >
void	swap( T & x, T & y )
{
	T	tmp;

	tmp = x;
	x = y;
	y = tmp;

	return ;
}

template< typename T >
T const & min( T const & x, T const & y )
{
	return (x < y ? x : y );
}

template< typename T >
T const & max( T const & x, T const & y )
{
	return (x > y ? x : y );
}

#endif