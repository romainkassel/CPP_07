/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/09 09:00:37 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <cmath>
#include <exception>

template <typename T>
class Array {

private:

    int _size;
    T*  _array;

public:

    Array( void );
    Array( unsigned int n );
    Array( Array const & src );
    ~Array( void);

    Array& operator=( Array const & rhs );
    
    T&  operator[]( int index );

    int size( void ) const;

    class   IndexOutOfBoundsException : public std::exception {
        
        public: 

            virtual const char *what() const throw()
            {
                return ("Array index out of bound");
            }
    };

    T*  getArray( void ) const;
    
};

template <typename T>
std::ostream    &operator<<( std::ostream & o, Array<T> const & rhs );

#include "Array.tpp"

#endif