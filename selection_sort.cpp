#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        
        if (min_index != i) {
            std::swap(arr[i], arr[min_index]);
        }
    }
}

int main() {
    std::vector<int> numbers = {64, 25, 12, 22, 11};

    selectionSort(numbers);

    std::cout << "Sorted array: ";
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
