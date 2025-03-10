#include "stl_algorithms.h"

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};
    my_for_each(arr.begin(), arr.end(), [](int value){
        value++;
        std::cout << value << std::endl;
    });

    return 0;
}