#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <limits.h>
#define SIZE 4096

using namespace std;
using namespace std::chrono;

void Rand_array(vector<char>* arr) //заполнение массива
{
    arr->clear();
    for (int i = 0; i < SIZE; i++)
        arr->push_back(32 + rand() % (128 - 32));
    for (int i = 0; i < SIZE; i++)
        cout << arr->at(i) << "";
    cout << endl;
}

int main()
{
    vector<char> main_array;
    Rand_array(&main_array);
    char key;

    auto start = high_resolution_clock::now();
    sort(main_array.begin(), main_array.end());
    auto end = high_resolution_clock::now();

    for (int i = 0; i < main_array.size(); i++)
        cout << main_array.at(i) << "";
    cout << "\nSTL sort time for array of " << SIZE << " elements: " << duration_cast<milliseconds>(end - start).count() << " msec\n";
    
    cout << "Input char: ";
    cin >> key;
    start = high_resolution_clock::now();
    bool result = binary_search(main_array.begin(), main_array.end(), key);
    end = high_resolution_clock::now();

    if (result)
        cout << "\nSTL binary search time for array of " << SIZE << " elements: " << duration_cast<milliseconds>(end - start).count() << " msec\n";
    else
        "Item isn't in array\n";
}
