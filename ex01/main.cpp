#include "Zombie.hpp"

int main(void)
{
    int N = 5;
    std::cout << "--- Creating a Zombie Horde of size " << N << " ---" << std::endl;
    Zombie* horde = zombieHorde(N, "Walker");

    if (horde)
    {
        for (int i = 0; i < N; i++)
        {
            std::cout << "[" << i << "] ";
            horde[i].announce();
        }
        std::cout << "\n--- Destroying the Zombie Horde ---" << std::endl;
        delete[] horde;
    }
    else
    {
        std::cout << "Invalid horde size." << std::endl;
    }

    std::cout << "\n--- Creating an invalid Zombie Horde of size 0 ---" << std::endl;
    Zombie* zeroHorde = zombieHorde(0, "Nobody");
    if (!zeroHorde)
        std::cout << "Horde creation failed as expected for N=0." << std::endl;

    return 0;
}
