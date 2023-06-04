#include <iostream>

void merge_sort(int* arr, int size) 
{
    if (size < 2) {
        return;
    }
    int middle = size / 2;
    int* left_arr = new int[middle];
    int* right_arr = new int[size - middle];

    for (int i = 0; i < middle; i++) 
    {
        left_arr[i] = arr[i];
    }
    for (int i = middle; i < size; i++) 
    {
        right_arr[i - middle] = arr[i];
    }
  
    merge_sort(left_arr, middle);
    merge_sort(right_arr, size - middle);
    
    int i = 0, j = 0, k = 0;
    while (i < middle && j < size - middle) 
    {
        if (left_arr[i] < right_arr[j]) 
        {
            arr[k++] = left_arr[i++];
        }
        else {
            arr[k++] = right_arr[j++];
        }
    }
    while (i < middle) 
    {
        arr[k++] = left_arr[i++];
    }
    while (j < size - middle) 
    {
        arr[k++] = right_arr[j++];
    }
    delete[] left_arr;
    delete[] right_arr;
}

void arrPrint(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    };
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    system("chcp 1251");
    int arr[]{24, 66, 20, 79, 30, 16, 19, 62, 94, 59, 0, 7, 59, 90, 84, 60, 95, 62};
    int size = 0;
    size = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Исходный массив: ";
    arrPrint(arr, size);
    merge_sort(arr, size);
    std::cout << "Отсортированный массив: ";
    arrPrint(arr, size);
    return 0;
}

