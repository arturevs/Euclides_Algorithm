#include <iostream>
#include <chrono>

unsigned int gdc_linear(unsigned int a,unsigned int b)
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

unsigned int gdc_euclides(unsigned int a,unsigned int b)
{
    if(b == 0) return a;
    else return gdc_euclides(b, a % b);
}

int main()
{
    unsigned int a, b;
    std::cout << 
    "This program will return the greatest common divisor between two integers." << '\n';
    std::cout << "input the first number: ";
    std::cin >> a;
    std::cout << "input the second number: ";
    std::cin >> b;
    // start counting time in microseconds
    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
    std::cout << "the gdc from " << a << " and " << b << " is " << gdc_euclides(a, b) << '\n';
    // int variable ending count of time
    std::chrono::high_resolution_clock::time_point stop = std::chrono::high_resolution_clock::now();
    // calculate time difference
    auto duration = stop - start;
    // print time difference
    std::cout << "Compilation time: " << duration.count() << " nanoseconds" << '\n';
    start = std::chrono::high_resolution_clock::now();
    std::cout << "the gdc from " << a << " and " << b << " is " << gdc_linear(a, b) << '\n';
    stop = std::chrono::high_resolution_clock::now();
    duration = stop - start;
    std::cout << "Compilation time: " << duration.count() << " nanoseconds" << '\n';    
}