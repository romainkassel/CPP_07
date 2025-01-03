/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:03:15 by rkassel           #+#    #+#             */
/*   Updated: 2024/12/09 04:03:25 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"

#define END "\033[0m"

// end colors

void	printArrEl( int arrEl )
{
	std::cout << arrEl;
	return ;
}

void	toUpper( char arrEl )
{
	arrEl = std::toupper(arrEl);
	std::cout << arrEl;
	return ;
}

void	appendToStr( std::string arrEl )
{
	arrEl.append(".test");
	std::cout << arrEl << std::endl;
	return ;
}

int	main( void )
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << MAGENTA;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "SPECIFIC FUNCTIONS PER TYPE" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//////////////////////////////////////
	
	int			a[5] = {1, 2, 3, 4, 5};
	char		b[19] = {"this is a sentence"};
	std::string	c[3] = {"sentence1", "sentence2", "sentence3"};

	//////////////////////////////////////

	std::cout << NORMAL << MAGENTA;
	std::cout << "INT -> void printArrEl( int arrEl )" << std::endl;
	std::cout << END;
	std::cout << std::endl;
	
	//test 1 - int array - int specific
	::iter( a, 5, printArrEl );
	std::cout << std::endl;

	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << NORMAL << MAGENTA;
	std::cout << "CHAR - > void toUpper( char arrEl )" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//test 2 - char array - arr specific
	::iter( b, 18, toUpper );
	std::cout << std::endl;

	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << NORMAL << MAGENTA;
	std::cout << "STRING - > void appendToStr( std::string arrEl )" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//test 3 - string array - string sp
	::iter( c, 3, appendToStr );

	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "TEMPLATE FUNCTION ALL TYPES" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << NORMAL << GREEN;
	std::cout << "INT -> void printArrElGeneric( T arrEl )" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//test 4 - int array - Generic
	::iter( a, 5, ::printArrElGeneric<int> );
	std::cout << std::endl;

	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << NORMAL << GREEN;
	std::cout << "CHAR - > void printArrElGeneric( T arrEl )" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//test 5 - char array - Generic
	::iter( b, 18, ::printArrElGeneric<char> );
	std::cout << std::endl;

	std::cout << std::endl;

	//////////////////////////////////////

	std::cout << NORMAL << GREEN;
	std::cout << "string -> void printArrElGeneric( T arrEl )" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	//test 6 - string array - Generic
	::iter( c, 3, ::printArrElGeneric<std::string> );

	std::cout << std::endl;
	std::cout << std::endl;

	return (0);
}
