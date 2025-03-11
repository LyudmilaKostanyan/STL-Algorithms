#include "stl_algorithms.h"

class Sum
{
public:
    void operator()(int value) { sum += value; }
    int getSum() const { return sum; }
private:
    int sum = 0;
};

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    std::cout << std::endl << "for_each()" << std::endl;
    std::cout << "Test 1: Functor:" << std::endl;
    Sum arr_sum = my_for_each(arr.begin(), arr.end(), Sum());
    std::cout << "Array sum: " << arr_sum.getSum() << std::endl;
    
    std::cout << "Test 2: Lambda function: ";
    std::cout << "Array elements after increment: ";
    my_for_each(arr.begin(), arr.end(), [](int value){
        value++;
        std::cout << value << " ";
    });
    std::cout << std::endl;

    std::cout << std::endl << "for_each_n()" << std::endl;
    std::cout << "Test 1: Functor" << std::endl;
    Sum arr_sum_n = my_for_each_n(arr.begin(), 3, Sum()).second;
    std::cout << "Array sum: " << arr_sum_n.getSum() << std::endl;

    std::cout << "Test 2: Lambda function\n";
    std::cout << "Array elements after increment: ";
    auto it = my_for_each_n(arr.begin(), 3, [](int value){
        value++;
        std::cout << value << " ";
    });
    std::cout << std::endl;
    std::cout << "Remaining elements: ";
    for (auto i = it.first; i != arr.end(); i++)
        std::cout << *i << " ";

    std::cout << std::endl << std::endl << "find()" << std::endl;
    std::cout << "Test 1: Find num in array: ";
    auto it_find = my_find(arr.begin(), arr.end(), 5);
    if (it_find != arr.end())
        std::cout << "Found" << std::endl;
    else
        std::cout << "Not found" << std::endl;
    return 0;
}