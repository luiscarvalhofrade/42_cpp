/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luide-ca <luide-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 21:42:40 by luide-ca          #+#    #+#             */
/*   Updated: 2025/08/22 13:35:25 by luide-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    std::cout << "===============================================" << std::endl;
    std::cout << "    TESTING ABSTRACT CLASS AAnimal" << std::endl;
    std::cout << "===============================================" << std::endl;
    
    // Note: This line would cause a compilation error because AAnimal is abstract
    // AAnimal abstract; // ERROR: Cannot instantiate abstract class
    
    std::cout << "\n=== TEST 1: POLYMORPHISM WITH ABSTRACT BASE ===" << std::endl;
    std::cout << "Creating polymorphic pointers to abstract base class...\n" << std::endl;
    
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();
    
    std::cout << "\nTesting polymorphic behavior:" << std::endl;
    std::cout << "Dog type: " << dog->getType() << " | Sound: ";
    dog->makeSound();
    
    std::cout << "Cat type: " << cat->getType() << " | Sound: ";
    cat->makeSound();
    
    std::cout << "\nDeleting through base class pointers (virtual destructor test):" << std::endl;
    delete dog;
    delete cat;

    std::cout << "\n=== TEST 2: ARRAY OF ABSTRACT POINTERS ===" << std::endl;
    const int arraySize = 6;
    AAnimal* animals[arraySize];
    
    // Fill half with Dogs, half with Cats
    std::cout << "\nCreating array of abstract pointers..." << std::endl;
    for (int i = 0; i < arraySize / 2; i++) {
        std::cout << "Creating Dog " << i << ":" << std::endl;
        animals[i] = new Dog();
    }
    
    for (int i = arraySize / 2; i < arraySize; i++) {
        std::cout << "Creating Cat " << i << ":" << std::endl;
        animals[i] = new Cat();
    }

    std::cout << "\nTesting polymorphic calls through array:" << std::endl;
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Animal[" << i << "] (" << animals[i]->getType() << ") says: ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== TEST 3: DEEP COPY TESTING ===" << std::endl;
    std::cout << "Testing deep copy to ensure proper Brain allocation...\n" << std::endl;
    
    std::cout << "Creating original Dog with Brain:" << std::endl;
    Dog* originalDog = new Dog();
    
    std::cout << "\nCopying Dog using copy constructor:" << std::endl;
    Dog copiedDog(*originalDog);
    
    std::cout << "\nCreating another Dog for assignment test:" << std::endl;
    Dog assignedDog;
    
    std::cout << "\nTesting assignment operator:" << std::endl;
    assignedDog = *originalDog;
    
    std::cout << "\nDeleting original Dog (copied Dogs should remain valid):" << std::endl;
    delete originalDog;
    
    std::cout << "Copied dogs still exist and can make sounds:" << std::endl;
    std::cout << "Copied dog: ";
    copiedDog.makeSound();
    std::cout << "Assigned dog: ";
    assignedDog.makeSound();

    std::cout << "\n=== TEST 4: ABSTRACT CLASS THROUGH REFERENCES ===" << std::endl;
    std::cout << "Testing abstract base class references...\n" << std::endl;
    
    Dog realDog;
    Cat realCat;
    
    // References to abstract base class
    AAnimal& dogRef = realDog;
    AAnimal& catRef = realCat;
    
    std::cout << "Dog through reference - Type: " << dogRef.getType() << " | Sound: ";
    dogRef.makeSound();
    
    std::cout << "Cat through reference - Type: " << catRef.getType() << " | Sound: ";
    catRef.makeSound();

    std::cout << "\n=== TEST 5: MEMORY LEAK PREVENTION ===" << std::endl;
    std::cout << "Ensuring proper cleanup through virtual destructors...\n" << std::endl;
    
    for (int i = 0; i < arraySize; i++) {
        std::cout << "Deleting Animal[" << i << "] (" << animals[i]->getType() << "):" << std::endl;
        delete animals[i]; // Should call proper derived destructor due to virtual destructor
    }

    std::cout << "\n=== TEST 6: STRESS TEST WITH MORE OBJECTS ===" << std::endl;
    std::cout << "Creating and destroying multiple objects quickly...\n" << std::endl;
    
    const int stressSize = 4;
    for (int round = 0; round < 2; round++) {
        std::cout << "\nRound " << (round + 1) << ":" << std::endl;
        AAnimal* stressTest[stressSize];
        
        for (int i = 0; i < stressSize; i++) {
            if (i % 2 == 0) {
                stressTest[i] = new Dog();
            } else {
                stressTest[i] = new Cat();
            }
            stressTest[i]->makeSound();
        }
        
        for (int i = 0; i < stressSize; i++) {
            delete stressTest[i];
        }
    }

    std::cout << "\n===============================================" << std::endl;
    std::cout << "  END OF PROGRAM - LOCAL OBJECTS CLEANUP" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "(realDog, realCat, copiedDog, and assignedDog will be destroyed)" << std::endl;
    
    return 0;
}
