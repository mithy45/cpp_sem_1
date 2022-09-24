#include <iostream>
using namespace std;


int main(int argc, char const *argv[])
{
    int number;

    while (std::cin >> number) {
        int prime = 1;
        int loop = 2; 
        while (loop < number && prime == 1) {
            if((number % loop) == 0) {
                prime = 0;
            }
            loop++;
        }

        if (prime == 1 && number != 1)
            std::cout << number << " is a prime: True\n";
        else
            std::cout << number << " is a prime: False\n";
    }
    return 0;
}