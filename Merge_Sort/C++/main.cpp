// g++ -std=c++20 main.cpp -o main && ./main
// g++ -std=c++20 main.cpp -o main.exe && main.exe  (I didn't check it for the Windows)

#include <iostream>
#include <ctime>

namespace OVDIIENKO_ANDRII
{
    template <typename T>
    void show(T *start, T *end)
    {
        std::cout << '[';
        for (T *temp = start; temp != end; temp++)
        {
            std::cout << *temp;
            if (temp + 1 != end)
                std::cout << ' ';
        }
        std::cout << ']';
    }

    template <typename T, typename Compare>
    void merge(T *start, T *end, T *middle, Compare compare)
    {
        T *temp = new T[end - start];
        T *del = temp;

        T *demo_start = start;
        T *demo_middle = middle;
        T *t = temp;

        while (demo_start < middle && demo_middle < end)
        {
            if (compare(*demo_start, *demo_middle))
                *t++ = *demo_start++;
            else
                *t++ = *demo_middle++;
        }

        while (demo_start < middle)
            *t++ = *demo_start++;
        while (demo_middle < end)
            *t++ = *demo_middle++;

        for (T *t = start; t - start < end - start; *t++ = *temp++)
        {
        }

        delete[] del;
        del = nullptr;
    }

    template <typename T, typename Compare>
    void merge_sort(T *start, T *end, Compare compare)
    {
        if (end == start || start + 1 == end)
            return;

        merge_sort(start, start + (end - start) / 2, compare);
        merge_sort(start + (end - start) / 2, end, compare);

        merge(start, end, start + (end - start) / 2, compare);
    }
};

int main()
{
    srand(time(nullptr));
    int *array = nullptr;

    array = new int[10];

    for (int *t = array; t - array != 10; t++)
    {
        *t = rand() % (10 + 10 + 1) - 10;
    }
    OVDIIENKO_ANDRII::show(array, array + 10);
    std::cout << '\n';

    OVDIIENKO_ANDRII::merge_sort(array, array + 10, [](int a, int b)
                                 { return a >= b; });

    OVDIIENKO_ANDRII::show(array, array + 10);

    delete[] array;
    array = nullptr;

    return 0;
}