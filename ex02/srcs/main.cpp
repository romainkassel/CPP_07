/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: debian <debian@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 06:54:59 by debian            #+#    #+#             */
/*   Updated: 2024/12/09 10:36:20 by debian           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750

void    testArrayCopyByAffectation();
void    testArrayCopyByConstructor();
void    testTip();

// start colors

#define BOLD "\033[1;"
#define NORMAL "\033[0;"

#define MAGENTA "35m"
#define GREEN "32m"

#define END "\033[0m"

// end colors

int main(int, char**)
{
    std::cout << std::endl;

    Array<int> numbers(MAX_VAL);

    // start custom
    std::cout << std::endl;
    // end custom

    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        // start custom
        delete [] tmp.getArray();
        // end custom
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
        // start custom
        /*std::cout << "numbers at index " << i << ": " << numbers[i] << std::endl;
        std::cout << "mirror at index " << i << ": " << mirror[i] << std::endl;
        std::cout << std::endl;*/
        // end custom
    }
    
    std::cout << std::endl;
    
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    // start custom
    std::cout << std::endl;
    // end custom

    // start custom
    try
    {
        int index = 749;
        // start custom
        std::cout << "[BEFORE] numbers at index " << index << ": " << numbers[index] << std::endl;
        std::cout << "[BEFORE] mirror at index " << index << ": " << mirror[index] << std::endl;
        std::cout << std::endl;
        // end custom
        numbers[749] = 0;
        mirror[749] = 0;
         // start custom
        std::cout << "[AFTER] numbers at index " << index << ": " << numbers[index] << std::endl;
        std::cout << "[AFTER] mirror at index " << index << ": " << mirror[index] << std::endl;
        // end custom
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    // end custom

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//

    // start custom
    delete [] numbers.getArray();
    // end custom

    testArrayCopyByAffectation();
    testArrayCopyByConstructor();
    std::cout << std::endl;
    testTip();

    std::cout << std::endl;

    return 0;
}

void    testArrayCopyByAffectation() {

    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test array copy by affectation" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    //////////////////////////////////////

	std::cout << NORMAL << GREEN;
	std::cout << "Creation of numbers1 array" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	// Creation of 1 array instance (one that will be copied)
    
	Array<int> numbers1(5);

	// Filling numbers1 array

    numbers1[0] = 54;
    numbers1[1] = 76;
    numbers1[2] = 21;
    numbers1[3] = 9;
    numbers1[4] = 456;

    // Display of numbers1 array
    
    std::cout << "numbers1 array: " << numbers1;

    //////////////////////////////////////

    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Creation of numbers2 array" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    // Creation of 1 array instance (copy)
	
    Array<int> numbers2(5);

   // Filling numbers2 array

    numbers2[0] = 0;
    numbers2[1] = 1;
    numbers2[2] = 2;
    numbers2[3] = 3;
    numbers2[4] = 4;

    // Display of numbers2 array
    
    std::cout << "numbers2 array: " << numbers2;

    //////////////////////////////////////

    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Display of numbers2 array after affectation (numbers2 = numbers1)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    std::cout << "numbers1 array: " << numbers1;
    std::cout << "numbers2 array BEFORE affectation: " << numbers2;
    numbers2 = numbers1;
    std::cout << "numbers2 array AFTER affectation: " << numbers2;

    //////////////////////////////////////

    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Modifying numbers1 array -> should NOT affect numbers2 array" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    // Updating numbers1 array

    numbers1[0] = 98;
    numbers1[1] = 43;
    numbers1[2] = 898;
    numbers1[3] = 1;
    numbers1[4] = 4347;

    // Display of numbers1 and numbers2 array after numbers1 update

    std::cout << "numbers1 array after update: " << numbers1;
    std::cout << "numbers2 array after update: " << numbers2;

    //////////////////////////////////////

    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Modifying numbers2 array -> should NOT affect numbers1 array" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    // Updating numbers2 array

    numbers2[0] = 987;
    numbers2[1] = 435;
    numbers2[2] = 657;
    numbers2[3] = 222;
    numbers2[4] = 999;

    // Display of numbers1 and numbers2 array after numbers1 update

    std::cout << "numbers1 array after update: " << numbers1;
    std::cout << "numbers2 array after update: " << numbers2;

    //////////////////////////////////////

    std::cout << std::endl;
    std::cout << NORMAL << GREEN;
	std::cout << "Creation of numbers3 array (empty)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	// Creation of 1 array instance (empty)
    
	Array<int> numbers3;

    // Display of numbers3 array
    
    std::cout << "numbers3 array: " << numbers3;
    std::cout << std::endl;

    //////////////////////////////////////

    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Display of numbers1 array after affectation (numbers1 = numbers3)" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    std::cout << "numbers3 array: " << numbers3 << std::endl;
    std::cout << "numbers1 array BEFORE affectation: " << numbers1;    
    numbers1 = numbers3;
    std::cout << "numbers1 array AFTER affectation: " << numbers1;
    std::cout << std::endl;

    //////////////////////////////////////

    std::cout << std::endl;
	std::cout << NORMAL << GREEN;
	std::cout << "Display of numbers3 array (numbers3 = numbers2)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    std::cout << "numbers2 array: " << numbers2;
    std::cout << "numbers3 array BEFORE affectation: " << numbers3 << std::endl;
    numbers3 = numbers2;
    std::cout << "numbers3 array AFTER affectation: " << numbers3;

    delete [] numbers2.getArray();
    delete [] numbers3.getArray();

    std::cout << std::endl;

    return ;
}

void    testCopyByConstructor(Array<int> numbers1);

void    testArrayCopyByConstructor() {

    std::cout << std::endl;
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test array copy by constructor" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;

    //////////////////////////////////////

	std::cout << NORMAL << GREEN;
	std::cout << "Creation of numbers1 array (filled)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	// Creation of 1 array instance (one that will be copied)
    
	Array<int> numbers1(5);

	// Filling numbers1 array

    numbers1[0] = 54;
    numbers1[1] = 76;
    numbers1[2] = 21;
    numbers1[3] = 9;
    numbers1[4] = 456;

    // Display of numbers1 array
    
    std::cout << "numbers1 array: " << numbers1;

    // Call to copy constructor
    
    testCopyByConstructor(numbers1);
    std::cout << std::endl;

    // Display of original numbers1 after copied numbers1 update

    std::cout << "original numbers1 array after update: " << numbers1;
    std::cout << std::endl;

    delete [] numbers1.getArray();

    //////////////////////////////////////

	std::cout << NORMAL << GREEN;
	std::cout << "Creation of numbers2 array (empty)" << std::endl;
	std::cout << END;
	std::cout << std::endl;

	// Creation of 1 array instance (one that will be copied)
    
	Array<int> numbers2;

    // Display of numbers2 array
    
    std::cout << "numbers2 array: " << numbers2;
    std::cout << std::endl;

    // Call to copy constructor
    
    testCopyByConstructor(numbers2);
    std::cout << std::endl;

    return ;
}

void    testCopyByConstructor(Array<int> numbers)
{
    std::cout << std::endl;
    
    //////////////////////////////////////

	std::cout << NORMAL << GREEN;
	std::cout << "Display of copied numbers array" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    // Display of numbers array
    
    std::cout << "copied numbers array: " << numbers;
    std::cout << std::endl;

    //////////////////////////////////////

    if (numbers.getArray())
    {
        std::cout << NORMAL << GREEN;
        std::cout << "Modifying copied numbers array -> should NOT affect original numbers1 array" << std::endl;
        std::cout << END;
        std::cout << std::endl;
    
        numbers[0] = 1;
        numbers[1] = 2;
        numbers[2] = 3;
        numbers[3] = 4;
        numbers[4] = 5;

        std::cout << "copied numbers array after update: " << numbers;

        delete [] numbers.getArray();
        
    }
    
    return ;
}

void    testTip()
{
	std::cout << std::endl;
	std::cout << BOLD << GREEN;
	std::cout << "**********************************************************************************************" << std::endl;
	std::cout << std::endl;
	std::cout << "Test TIP" << std::endl;
	std::cout << std::endl;
	std::cout << "VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV" << std::endl;
	std::cout << END;
	std::cout << std::endl;
    
    Array<int> a(1);
    std::cout << std::endl;
    std::cout << "*a.getArray() : " << *a.getArray() << std::endl;

    int * b = new int();
    std::cout << "*b : " << *b << std::endl;

    delete [] a.getArray();
    delete (b);

    /*Array<int> c(2);
    std::cout << std::endl;
    std::cout << "c.getArray()[1] : " << c.getArray()[1] << std::endl;

    int * d = new int[2];
    std::cout << "d[1] : " << d[1] << std::endl;

    delete [] c.getArray();
    delete [] d;*/

    std::cout << std::endl;

    return ;
}