#include <stdio.h>
#include "dynamic_array.h"

void test_basic_operations();
void test_sorting();
void test_insertion();
void test_pop();
void test_custom_array_fill();

int main() {
    printf("=== Dynamic Array Test Suite ===\n");

    test_basic_operations();
    test_pop();
    test_insertion();
    test_sorting();
    test_custom_array_fill();

    printf("=== All tests completed ===\n");
    return 0;
}

void test_basic_operations() {
    printf("\n-- Testing Basic Operations --\n");

    arr *arr_1 = create_arr(3);
    append_arr(arr_1, 10);
    append_arr(arr_1, 20);
    append_arr(arr_1, 30);

    printf("arr_1 contents: ");
    print_arr(arr_1);

    int val = get_arr(arr_1, 2);
    printf("Value at index 2: %d\n", val); // 30

    printf("Length of arr_1: %d\n", len_arr(arr_1));

    free_arr(arr_1);
}

void test_pop() {
    printf("\n-- Testing Pop Operation --\n");

    arr *arr_2 = create_arr(5);
    append_arr(arr_2, 5);
    append_arr(arr_2, 15);
    append_arr(arr_2, 25);
    append_arr(arr_2, 35);
    append_arr(arr_2, 45);

    printf("Original array: ");
    print_arr(arr_2);

    while (len_arr(arr_2) > 0) {
        int popped = pop_arr(arr_2);
        printf("Popped: %d | New array: ", popped);
        print_arr(arr_2);
    }

    free_arr(arr_2);
}

void test_insertion() {
    printf("\n-- Testing Insertion --\n");

    arr *arr_3 = create_arr(5);

    insert_arr(arr_3, 0, 1);
    insert_arr(arr_3, 1, 2);
    insert_arr(arr_3, 1, 3);
    insert_arr(arr_3, 2, 4);
    insert_arr(arr_3, 0, 100);
    insert_arr(arr_3, 3, 200);

    printf("Array after insertions: ");
    print_arr(arr_3);

    free_arr(arr_3);
}

void test_sorting() {
    printf("\n-- Testing Sorting --\n");

    arr *arr_4 = create_arr(10);
    int data[] = {5, 3, 9, 1, 6, 8, 2, 7, 4, 0};
    for (int i = 0; i < 10; i++) {
        append_arr(arr_4, data[i]);
    }

    printf("Before sorting: ");
    print_arr(arr_4);

    sort_arr(arr_4);

    printf("After sorting:  ");
    print_arr(arr_4);

    free_arr(arr_4);
}

void test_custom_array_fill() {
    printf("\n-- Testing Custom Array Fill & Sort --\n");

    int arr_size = 20;
    arr *arr_5 = create_arr(arr_size);

    for (int i = 0; i < arr_size; i++) {
        append_arr(arr_5, (100 % (i + 1)) - (i / 3));
    }

    printf("Filled array:     ");
    print_arr(arr_5);

    sort_arr(arr_5);
    printf("Sorted array:     ");
    print_arr(arr_5);

    free_arr(arr_5);
}
