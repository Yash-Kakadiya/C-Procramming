#include <stdio.h>

int isInArray(int a[], int m)
{
    if (a[0] == -1) // reached end of array
        return 0;

    if (a[0] == m) // found element
        return 1;

    return isInArray(a + 1, m); // recursive call on next element
}

int main()
{
    int n, m;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n + 1];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    arr[n] = -1; // value marking end of array

    printf("Enter element to search: ");
    scanf("%d", &m);

    if (isInArray(arr, m))
        printf("%d is present in the array.\n", m);
    else
        printf("%d is NOT present in the array.\n", m);

    return 0;
}
