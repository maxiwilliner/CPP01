#include "Zombie.hpp"

int main(void)
{
    std::cout << "--- Testing heap allocation (newZombie) ---" << std::endl;
    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;

    std::cout << "\n--- Testing stack allocation (randomChump) ---" << std::endl;
    randomChump("StackZombie");

    std::cout << "\n--- Returning from main ---" << std::endl;
    return 0;
}
