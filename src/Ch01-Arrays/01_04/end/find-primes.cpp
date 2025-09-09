#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num)
{
    if (num < 2)
        return false;

    for (int i = 2; i < num; i++) // TODO: Bruteforce method, it could be optimized
    {
        if (num % i == 0)
            return false;
    }

    return true;
}

void findPrimes(const int arr[], size_t size, std::vector<int> &primes)
{
    for (size_t i = 0; i < size; i++)
    {
        int e = arr[i];
        if (isPrime(e))
        {
            primes.push_back(e);
        }
    }
}

int main()
{
    int numbers[]{4, 7, 12, 3, 9, 17, 29};

    size_t size = sizeof(numbers) / sizeof(numbers[0]);
    vector<int> primes;

    findPrimes(numbers, size, primes);

    if (primes.empty())
    {
        cout << "No prime numbers found in the array.";
    }
    else
    {
        cout << "The prime numbers in the array are:";
        for (int prime : primes)
        {
            cout << " " << prime;
        }
        cout << endl;
    }
    return 0;
}
