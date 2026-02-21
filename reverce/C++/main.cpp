#include <iostream>
#include <ctime>

template <typename T>
void fill(T *start, T *end)
{
    for (T *temp = start; temp != end; temp++)
        *temp = rand() % 10;
}

template <typename T>
void print(T *start, T *end)
{
    std::cout << '[';
    for (T *temp = start; temp != end; temp++)
        std::cout << *temp << ' ';
    if (start != end && start + 1 != end)
        std::cout << '\b';
    std::cout << ']';
}

template <typename T>
void reverce(T *start, T *end)
{
    if (start == end || start + 1 == end)
        return;

    T *demo_start = start;
    T *demo_end = end;
    T *demo = new T;
    demo_end--;
    while (demo_end - demo_start > 0)
    {
        *demo = *demo_end;
        *demo_end = *demo_start;
        *demo_start = *demo;

        demo_end--;
        demo_start++;
    }
    delete demo;
    demo = nullptr;
}

int main()
{
    srand(time(nullptr));

    int *A = nullptr;
    const int N = 1000000000;
    A = new int[N];

    double start = double(), end = double();

    start = std::clock();
    fill(A, A + N);
    end = std::clock();
    std::cout << (end - start) / CLOCKS_PER_SEC << '\n';
    //  print(A, A + N);
    std::cout << '\n';

    start = std::clock();
    reverce(A, A + N);
    end = std::clock();
    std::cout << (end - start) / CLOCKS_PER_SEC << '\n';
    // print(A, A + N);
    std::cout << '\n';

    delete[] A;
    A = nullptr;

    return 0;
}