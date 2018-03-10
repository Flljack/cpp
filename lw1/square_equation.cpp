#include <cstdio>
#include <cmath>

int main()
{
    std::puts("Please enter a and b for 'ax^2 + bx +c = 0':");
    float a = 0;
    float b = 0;
    float c = 0;
    float D = 0;
    float x1, x2;
    std::scanf("%f %f %f", &a, &b, &c);
    D = b * b - 4 * a * c;
    x1 = (-b + std::sqrt(D)) / 2 * a;
    x2 = (-b - std::sqrt(D)) / 2 * a;
    std::printf("solution: %f %f", x1, x2);
}