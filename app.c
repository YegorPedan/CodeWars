#include <stdio.h>
#include <stdlib.h>

int findMinimumIndex(int *array, int array_length) {
    int result = *array;
    int result_index = 0;

    for (int i = 1; i < array_length; i++) {
        if (*(array+ i) < result) {
            result = array[i];
            result_index = i;
        }
    }
    return result_index;
}

int queue_time(const int *customers, int customers_length, int n)
{
    int* resultTime = calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        resultTime[i] = 0;
    }


    for(int i = 0; i < customers_length; i++) {
        int index = findMinimumIndex(resultTime, n);
        resultTime[index] += customers[i];
    }

    int result = 0;
    for (int i = 0; i < n; i++) {
        if (resultTime[i] > result) {
            result = resultTime[i];
        }
    }
    return result;

}

int main() {
    int customers[] = {5, 2, 3, 4, 5};
    int customers_length = 5;
    int n = 3;
    int result = queue_time(customers, customers_length, n);
    printf("%d", result);
    return 0;
}