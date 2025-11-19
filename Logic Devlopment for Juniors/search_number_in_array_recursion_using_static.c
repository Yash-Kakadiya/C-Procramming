#include <stdio.h>

// Global variable to store array size
int n;

// Recursive function to check if element m is in array a[]
// Returns 1 if found, 0 if not found
int isInArray(int a[], int m)
{
    static int index = 0; // Static variable to track current position

    // Base case: reached end of array
    if (index >= n)
    {
        index = 0; // Reset for next call
        return 0;  // Element not found
    }

    // If element found at current index
    if (a[index] == m)
    {
        index = 0; // Reset for next call
        return 1;  // Element found
    }

    // Recursive case: check next element
    index++;
    return isInArray(a, m);
}

int main()
{
    int i, element, result;

    printf("Enter the number of elements in array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &element);

    result = isInArray(arr, element);

    if (result == 1)
    {
        printf("%d is present in the array.\n", element);
    }
    else
    {
        printf("%d is not present in the array.\n", element);
    }

    return 0;
}