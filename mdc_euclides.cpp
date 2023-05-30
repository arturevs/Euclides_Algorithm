#include <iostream>
#include <chrono>

unsigned int mdc_linear(unsigned int a,unsigned int b)
{
    int i = a;
    if(a < b) int i = b;
    while(i >= 0)
    {
        if(a % i == 0 && b % i == 0) return i;
        --i;
    }
    return 1;
}

unsigned int mdc_euclides(unsigned int a,unsigned int b)
{
    if(b == 0) return a;
    else return mdc_euclides(b, a % b);
}

int main()
{
    unsigned int a, b;
    std::cout << 
    "esse programa calculará o mdc de dois inteiros positivos a partir da implementação do algoritmo de euclides" << '\n';
    std::cout << "insira o primeiro número: ";
    std::cin >> a;
    std::cout << "insira o segundo número: ";
    std::cin >> b;
    // start counting time in microseconds
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::cout << "o mdc de " << a << " e " << b << " é " << mdc_euclides(a, b) << '\n';
    // int variable ending count of time
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    // calculate time difference
    auto duration = stop - start;
    // print time difference
    std::cout << "Tempo de compilação do algoritmo de Euclides: " << duration.count() << " nanosegundos" << '\n';
    start = std::chrono::high_resolution_clock::now();
    std::cout << "o mdc de " << a << " e " << b << " é " << mdc_linear(a, b) << '\n';
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    std::cout << "Tempo de compilação do algoritmo linear: " << duration.count() << " nanosegundos" << '\n';    
}