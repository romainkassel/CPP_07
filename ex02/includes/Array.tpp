/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 01:03:03 by debian            #+#    #+#             */
/*   Updated: 2024/12/09 10:28:01 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array( void ) : _size(0), _array(NULL)
{
    std::cout << "Default constructor (void) from Array called" << std::endl;
    return ;
}

template <typename T>
Array<T>::Array( unsigned int n ) : _size(n), _array(new T[n])
{
    std::cout << "Default constructor (unsigned int n) from Array called" << std::endl;
    *this->_array = 0;
    return ;
}

template <typename T>
Array<T>::Array( Array const & src ) : _size(src.size())
{
    if (src.getArray())
    {
        this->_array = new T[this->_size];
        for (int i = 0; i < this->_size; i++)
            this->_array[i] = src.getArray()[i];
    }
    else
        this->_array = NULL;
    return ;
}

template <typename T>
Array<T>::~Array( void )
{
    std::cout << "Destructor from Array called" << std::endl;
    return ;
}

template <typename T>
Array<T>& Array<T>::operator=( Array const & rhs )
{
    if (this->_array)
    {
        delete [] this->_array;
        this->_array = NULL;
    }
    this->_size = rhs.size();
    if (rhs.getArray())
    {
        this->_array = new T[this->_size];
        for (int i = 0; i < this->_size; i++)
            this->_array[i] = rhs.getArray()[i];
    }
    return (*this);
}

template <typename T>
T&  Array<T>::operator[]( int index )
{
    if (index >= this->size() || index < 0)
    {
        Array<T>::IndexOutOfBoundsException IndexOutOfBoundsException;
        throw IndexOutOfBoundsException;
    }
    return (this->_array[index]);
}

template <typename T>
int Array<T>::size( void ) const
{
    return (this->_size);
}

template <typename T>
T*  Array<T>::getArray( void ) const
{
    return (this->_array);
}

template <typename T>
std::ostream    &operator<<( std::ostream & o, Array<T> const & rhs )
{
    for (int i = 0; i < rhs.size(); i++)
    {
        std::cout << rhs.getArray()[i];
        if (i < (rhs.size() - 1))
            std::cout << ", ";
        else
            std::cout << std::endl;
    }
    return (o);
}
