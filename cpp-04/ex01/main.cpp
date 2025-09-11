/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:42:40 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 11:25:38 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "=== CREATING ARRAY OF ANIMALS (HALF DOGS, HALF CATS) ===" << std::endl;
	const int arraySize = 6;
	Animal* animals[arraySize];
	
	// Fill half with Dogs, half with Cats
	for (int i = 0; i < arraySize / 2; i++) {
		std::cout << "\nCreating Dog " << i << ":" << std::endl;
		animals[i] = new Dog();
	}
	
	for (int i = arraySize / 2; i < arraySize; i++) {
		std::cout << "\nCreating Cat " << i << ":" << std::endl;
		animals[i] = new Cat();
	}

	std::cout << "\n=== TESTING SOUNDS FROM ARRAY ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << animals[i]->getType() << " says: ";
		animals[i]->makeSound();
	}

	std::cout << "\n=== TESTING DEEP COPY ===" << std::endl;
	std::cout << "\nCreating original Dog:" << std::endl;
	Dog originalDog;
	
	std::cout << "\nCopying Dog using copy constructor:" << std::endl;
	Dog copiedDog(originalDog);
	
	std::cout << "\nCreating another Dog for assignment test:" << std::endl;
	Dog assignedDog;
	
	std::cout << "\nAssigning originalDog to assignedDog:" << std::endl;
	assignedDog = originalDog;
	
	std::cout << "\nTesting Cat deep copy:" << std::endl;
	std::cout << "\nCreating original Cat:" << std::endl;
	Cat originalCat;
	
	std::cout << "\nCopying Cat using copy constructor:" << std::endl;
	Cat copiedCat(originalCat);
	
	std::cout << "\nCreating another Cat for assignment test:" << std::endl;
	Cat assignedCat;
	
	std::cout << "\nAssigning originalCat to assignedCat:" << std::endl;
	assignedCat = originalCat;

	std::cout << "\n=== DELETING ARRAY ANIMALS (AS ANIMALS) ===" << std::endl;
	for (int i = 0; i < arraySize; i++) {
		std::cout << "\nDeleting Animal " << i << " (which is a " << animals[i]->getType() << "):" << std::endl;
		delete animals[i];
	}

	std::cout << "\n=== END OF PROGRAM (LOCAL OBJECTS WILL BE DESTROYED) ===" << std::endl;
	return 0;
}
