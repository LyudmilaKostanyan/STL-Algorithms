#include "stl_algorithms.h"

class Sum
{
public:
    void operator()(int value) { sum += value; }
    int getSum() const { return sum; }
private:
    int sum = 0;
};

bool isEven(int n) {
    return n % 2 == 0;
}

int main()
{
    std::vector<int> arr = {1, 2, 3, 4, 5};

    std::cout << std::endl << "for_each()" << std::endl;
    std::cout << "Test 1: Functor:" << std::endl;
    Sum arr_sum = mila::for_each(arr.begin(), arr.end(), Sum());
    std::cout << "Array sum: " << arr_sum.getSum() << std::endl;
    
    std::cout << "Test 2: Lambda function: ";
    std::cout << "Array elements after increment: ";
    mila::for_each(arr.begin(), arr.end(), [](int value){
        value++;
        std::cout << value << " ";
    });
    std::cout << std::endl;

    std::cout << std::endl << "for_each_n()" << std::endl;
    std::cout << "Test 1: Functor" << std::endl;
    Sum arr_sum_n = mila::for_each_n(arr.begin(), 3, Sum()).second;
    std::cout << "Array sum: " << arr_sum_n.getSum() << std::endl;

    std::cout << "Test 2: Lambda function\n";
    std::cout << "Array elements after increment: ";
    auto it = mila::for_each_n(arr.begin(), 3, [](int value){
        value++;
        std::cout << value << " ";
    });
    std::cout << std::endl;
    std::cout << "Remaining elements: ";
    for (auto i = it.first; i != arr.end(); i++)
        std::cout << *i << " ";

    std::cout << std::endl << std::endl << "find()" << std::endl;
    std::cout << "Test 1: Find 5 in array: ";
    auto it_find = mila::find(arr.begin(), arr.end(), 5);
    if (it_find != arr.end())
    std::cout << "Found" << std::endl;
    else
    std::cout << "Not found" << std::endl;
    
    std::cout << std::endl << std::endl << "find_if()" << std::endl;
    std::cout << "Test 1: Find first even num in array: ";
    std::cout << *(mila::find_if(arr.begin(), arr.end(), isEven)) << std::endl;
    std::cout << std::endl << std::endl << "find_if_not()" << std::endl;
    std::cout << "Test 1: Find first odd num in array: ";
    std::cout << *(mila::find_if_not(arr.begin(), arr.end(), isEven)) << std::endl;
    
    std::cout << std::endl << std::endl << "all_of(), any_of(), none_of()" << std::endl;
    std::cout << "Test 1: Check if all elements are even: ";
    std::cout << (mila::all_of(arr.begin(), arr.end(), isEven) == true ? "True" : "False") << std::endl;
    std::cout << "Test 2: Check if any element is even: ";
    std::cout << (mila::any_of(arr.begin(), arr.end(), isEven) == true ? "True" : "False") << std::endl;
    std::cout << "Test 3: Check if none of the elements are even: ";
    std::cout << (mila::none_of(arr.begin(), arr.end(), isEven) == true ? "True" : "False") << std::endl;

    return 0;
}