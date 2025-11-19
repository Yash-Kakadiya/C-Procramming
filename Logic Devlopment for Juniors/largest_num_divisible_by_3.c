// WAP for given N digits, arrange them to form the largest number divisible by 3.

#include <stdio.h>

int main()
{
    int n, i, sum = 0;

    printf("Enter the number of digits: ");
    scanf("%d", &n);

    int digits[n];
    printf("Enter %d digits:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("Digit %d: ", i + 1);
        scanf("%d", &digits[i]);
        sum += digits[i];
    }

    // Sort digits in descending order
    int count_freq[10] = {0}; // Frequency array for digits 0-9

    // Count frequency of each digit
    for (i = 0; i < n; i++)
    {
        count_freq[digits[i]]++;
    }

    // Reconstruct array in descending order
    int idx = 0;
    for (i = 9; i >= 0; i--)
    {
        while (count_freq[i] > 0)
        {
            digits[idx++] = i;
            count_freq[i]--;
        }
    }

    int remainder = sum % 3;
    int count = n; // Number of digits to use

    if (remainder != 0)
    {
        // We need to remove some digits
        int removed = 0;

        // Try to remove smallest digit with remainder equal to sum%3
        for (i = n - 1; i >= 0 && !removed; i--)
        {
            if (digits[i] % 3 == remainder)
            {
                // Remove this digit by marking it as -1
                digits[i] = -1;
                count--;
                removed = 1;
            }
        }

        // If not found, try to remove two digits whose sum%3 == remainder
        if (!removed)
        {
            int needed = (3 - remainder) % 3;
            int removedCount = 0;

            for (i = n - 1; i >= 0 && removedCount < 2; i--)
            {
                if (digits[i] != -1 && digits[i] % 3 == needed)
                {
                    digits[i] = -1;
                    count--;
                    removedCount++;
                }
            }
        }
    }

    // Check if we have any valid digits left
    if (count == 0)
    {
        printf("Not possible to form a number divisible by 3\n");
        return 0;
    }

    // Check if all remaining digits are 0
    int allZeros = 1;
    for (i = 0; i < n; i++)
    {
        if (digits[i] != -1 && digits[i] != 0)
        {
            allZeros = 0;
            break;
        }
    }

    if (allZeros && count > 0)
    {
        printf("Largest number divisible by 3: 0\n");
        return 0;
    }

    // Print the largest number
    printf("Largest number divisible by 3: ");
    for (i = 0; i < n; i++)
    {
        if (digits[i] != -1)
        {
            printf("%d", digits[i]);
        }
    }
    printf("\n");

    return 0;
}