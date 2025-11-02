#include <stdio.h>
#include <stdlib.h>

// ========== LEVEL 1 - BASIC LOOP LOGIC ==========

// Q1: Sum of 10 numbers
int sumOfTenNumbers()
{
    int sum = 0, num;
    printf("\n--- Q1: Sum of 10 Numbers ---\n");
    printf("Enter 10 numbers:\n");
    for (int i = 1; i <= 10; i++)
    {
        printf("Number %d: ", i);
        scanf("%d", &num);
        sum += num;
    }
    return sum;
}

// Q2: Find factorial of a given number
// Method 1: Iterative approach
int factorialIterative(int n)
{
    if (n < 0)
        return -1; // Error case
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }
    return fact;
}

// Method 2: Recursive approach
int factorialRecursive(int n)
{
    if (n < 0)
        return -1; // Error case
    if (n == 0 || n == 1)
        return 1;                         // Base case
    return n * factorialRecursive(n - 1); // Recursive case
}

// Q3: Print sum series 1 + 4 + 9 + 16 + ... + n^2
// Method 1: Iterative
int sumOfSquaresIterative(int n)
{
    int sum = 0;
    printf("Series: ");
    for (int i = 1; i <= n; i++)
    {
        sum += i * i;
        printf("%d", i * i);
        if (i < n)
            printf(" + ");
    }
    printf("\n");
    return sum;
}

// Method 2: Using formula (n(n+1)(2n+1))/6
int sumOfSquaresFormula(int n)
{
    return (n * (n + 1) * (2 * n + 1)) / 6;
}

// Q4: Print digits of a number in reverse order
void printDigitsReverse(int num)
{
    printf("Reversed digits: ");
    if (num == 0)
    {
        printf("0");
        return;
    }
    int isNegative = 0;
    if (num < 0)
    {
        isNegative = 1;
        num = -num;
    }
    while (num > 0)
    {
        printf("%d ", num % 10);
        num /= 10;
    }
    if (isNegative)
        printf("(original was negative)");
    printf("\n");
}

// Q5: Print sum of digits of a given number
// Method 1: Iterative
int sumOfDigitsIterative(int num)
{
    int sum = 0;
    if (num < 0)
        num = -num;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

// Method 2: Recursive
int sumOfDigitsRecursive(int num)
{
    if (num < 0)
        num = -num;
    if (num == 0)
        return 0;                                       // Base case
    return (num % 10) + sumOfDigitsRecursive(num / 10); // Recursive case
}

// Q6: Perform multiplication without using * operator
// Method 1: Using repeated addition
int multiplyUsingAddition(int a, int b)
{
    int result = 0;
    int isNegative = 0;

    if ((a < 0 && b > 0) || (a > 0 && b < 0))
    {
        isNegative = 1;
    }

    a = abs(a);
    b = abs(b);

    for (int i = 0; i < b; i++)
    {
        result += a;
    }

    return isNegative ? -result : result;
}

// Q7: Calculate x^y without using power operator
// Method 1: Iterative
int powerIterative(int x, int y)
{
    int result = 1;
    int isNegativePower = 0;

    if (y < 0)
    {
        isNegativePower = 1;
        y = -y;
    }

    for (int i = 0; i < y; i++)
    {
        result *= x;
    }

    if (isNegativePower && result != 0)
    {
        printf("Note: Negative power results in fraction\n");
        return 1;
    }

    return result;
}

// Method 2: Recursive
int powerRecursive(int x, int y)
{
    if (y == 0)
        return 1; // Base case
    if (y < 0)
    {
        printf("Note: Negative power results in fraction\n");
        return 1;
    }
    return x * powerRecursive(x, y - 1); // Recursive case
}

// Method 3: Fast exponentiation (divide and conquer)
int powerFast(int x, int y)
{
    if (y == 0)
        return 1; // Base case
    if (y < 0)
    {
        printf("Note: Negative power results in fraction\n");
        return 1;
    }

    int half = powerFast(x, y / 2);

    if (y % 2 == 0)
    {
        return half * half; // Even power: x^y = (x^(y/2))^2
    }
    else
    {
        return x * half * half; // Odd power: x^y = x * (x^(y/2))^2
    }
}

// ========== LEVEL 2 - LOOPS WITH CONDITIONAL LOGIC ==========

// Q8: Print numbers divisible by 2 between two numbers
void printDivisibleByTwo(int start, int end)
{
    printf("Numbers divisible by 2 between %d and %d:\n", start, end);
    int count = 0;
    for (int i = start; i <= end; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d ", i);
            count++;
        }
    }
    if (count == 0)
        printf("None");
    printf("\n");
}

// Q9: Find factors of a given number
// Method 1: Basic approach O(n)
void findFactorsBasic(int num)
{
    printf("Factors of %d: ", num);
    if (num < 0)
        num = -num;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
        }
    }
    printf("\n");
}

// Method 2: Optimized approach O(√n)
void findFactorsOptimized(int num)
{
    printf("Factors of %d: ", num);
    if (num < 0)
        num = -num;

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            printf("%d ", i);
            if (i != num / i)
            {
                printf("%d ", num / i);
            }
        }
    }
    printf("\n");
}

// Q10: Find the sum of all divisors of a number
// Method 1: Basic O(n)
int sumOfDivisorsBasic(int num)
{
    int sum = 0;
    if (num < 0)
        num = -num;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

// Method 2: Optimized O(√n)
int sumOfDivisorsOptimized(int num)
{
    int sum = 0;
    if (num < 0)
        num = -num;

    for (int i = 1; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
            if (i != num / i)
            {
                sum += num / i;
            }
        }
    }
    return sum;
}

// Q11: Find the GCD (Greatest Common Divisor) of two numbers
// Method 1: Euclidean algorithm (iterative)
int findGCDIterative(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (b != 0)
    {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Method 2: Euclidean algorithm (recursive)
int findGCDRecursive(int a, int b)
{
    a = abs(a);
    b = abs(b);

    if (b == 0)
        return a;                      // Base case
    return findGCDRecursive(b, a % b); // Recursive case
}

// Method 3: Subtraction method (slower but intuitive)
int findGCDSubtraction(int a, int b)
{
    a = abs(a);
    b = abs(b);

    while (a != b)
    {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

// Q12: Find the LCM (Least Common Multiple) of two numbers
int findLCM(int a, int b)
{
    a = abs(a);
    b = abs(b);

    // LCM(a,b) = (a * b) / GCD(a,b)
    int gcd = findGCDIterative(a, b);
    return (a * b) / gcd;
}

// Q13: Check whether a number is a Perfect Number
int isPerfectNumber(int num)
{
    if (num <= 0)
        return 0;

    int sum = 0;
    // Find sum of proper divisors (excluding the number itself)
    for (int i = 1; i < num; i++)
    {
        if (num % i == 0)
        {
            sum += i;
        }
    }
    return (sum == num);
}

// Q14: Check whether a number is a Harshad Number
int isHarshadNumber(int num)
{
    if (num <= 0)
        return 0;

    int original = num;
    int digitSum = 0;

    while (num > 0)
    {
        digitSum += num % 10;
        num /= 10;
    }

    return (original % digitSum == 0);
}

// Q15: Check whether a number is Prime or Not
// Method 1: Basic optimized approach
int isPrimeBasic(int num)
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;

    for (int i = 3; i * i <= num; i += 2)
    {
        if (num % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

// Method 2: Recursive approach
int isPrimeRecursive(int num, int divisor)
{
    if (num <= 1)
        return 0;
    if (num == 2)
        return 1;
    if (num % 2 == 0)
        return 0;

    if (divisor * divisor > num)
        return 1; // Base case
    if (num % divisor == 0)
        return 0; // Found divisor

    return isPrimeRecursive(num, divisor + 2); // Check next odd number
}

// Q16: Print the Fibonacci Series
// Method 1: Iterative
void printFibonacciIterative(int n)
{
    printf("Fibonacci series (Iterative) up to %d terms:\n", n);

    if (n <= 0)
    {
        printf("Invalid input\n");
        return;
    }

    int first = 0, second = 1, next;

    for (int i = 1; i <= n; i++)
    {
        if (i == 1)
        {
            printf("%lld ", first);
            continue;
        }
        if (i == 2)
        {
            printf("%lld ", second);
            continue;
        }
        next = first + second;
        first = second;
        second = next;
        printf("%lld ", next);
    }
    printf("\n");
}

// Method 2: Recursive (less efficient)
int fibonacciRecursive(int n)
{
    if (n <= 1)
        return n; // Base cases: fib(0)=0, fib(1)=1
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

void printFibonacciRecursive(int n)
{
    printf("Fibonacci series (Recursive) up to %d terms:\n", n);
    for (int i = 0; i < n; i++)
    {
        printf("%lld ", fibonacciRecursive(i));
    }
    printf("\n");
}

// Q17: Find the sum of series 1 - 2 + 3 - 4 + 5 - 6 + ... ± n
// Method 1: Iterative
int alternatingSumIterative(int n)
{
    int sum = 0;
    printf("Series: ");
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1)
        {
            sum += i;
            printf("+%d ", i);
        }
        else
        {
            sum -= i;
            printf("-%d ", i);
        }
    }
    printf("\n");
    return sum;
}

// Method 2: Using formula
int alternatingSumFormula(int n)
{
    // Pattern: if n is even, sum = -n/2
    //          if n is odd, sum = (n+1)/2
    if (n % 2 == 0)
    {
        return -n / 2;
    }
    else
    {
        return (n + 1) / 2;
    }
}

// Method 3: Recursive
int alternatingSumRecursive(int n)
{
    if (n == 0)
        return 0; // Base case
    if (n % 2 == 1)
    {
        return n + alternatingSumRecursive(n - 1); // Add odd
    }
    else
    {
        return -n + alternatingSumRecursive(n - 1); // Subtract even
    }
}

// ========== MAIN FUNCTION WITH MENU ==========

int main()
{
    int choice, num, num1, num2, n, method;

    while (1)
    {
        printf("\n========================================\n");
        printf("    LOOP PROBLEMS - SOLUTION MENU\n");
        printf("========================================\n");
        printf("LEVEL 1 - BASIC LOOP LOGIC\n");
        printf("1.  Sum of 10 numbers\n");
        printf("2.  Factorial (Iterative/Recursive)\n");
        printf("3.  Sum series 1+4+9+16+... (Iterative/Formula)\n");
        printf("4.  Print digits in reverse\n");
        printf("5.  Sum of digits (Iterative/Recursive)\n");
        printf("6.  Multiplication without * (3 methods)\n");
        printf("7.  Power x^y (Iterative/Recursive/Fast)\n");
        printf("\nLEVEL 2 - CONDITIONAL LOGIC\n");
        printf("8.  Numbers divisible by 2 in range\n");
        printf("9.  Find factors (Basic/Optimized)\n");
        printf("10. Sum of divisors (Basic/Optimized)\n");
        printf("11. GCD (3 methods)\n");
        printf("12. LCM\n");
        printf("13. Check Perfect Number\n");
        printf("14. Check Harshad Number\n");
        printf("15. Check Prime (Basic/Recursive)\n");
        printf("16. Fibonacci Series (3 methods)\n");
        printf("17. Alternating sum (3 methods)\n");
        printf("0.  Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Result: Sum = %d\n", sumOfTenNumbers());
            break;

        case 2:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("\nChoose method:\n1. Iterative\n2. Recursive\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printf("Factorial (Iterative) = %lld\n", factorialIterative(num));
            else
                printf("Factorial (Recursive) = %lld\n", factorialRecursive(num));
            break;

        case 3:
            printf("Enter n: ");
            scanf("%d", &n);
            printf("\nChoose method:\n1. Iterative\n2. Formula\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printf("Sum (Iterative) = %d\n", sumOfSquaresIterative(n));
            else
                printf("Sum (Formula) = %d\n", sumOfSquaresFormula(n));
            break;

        case 4:
            printf("Enter a number: ");
            scanf("%d", &num);
            printDigitsReverse(num);
            break;

        case 5:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("\nChoose method:\n1. Iterative\n2. Recursive\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printf("Sum of digits (Iterative) = %d\n", sumOfDigitsIterative(num));
            else
                printf("Sum of digits (Recursive) = %d\n", sumOfDigitsRecursive(num));
            break;

        case 6:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("%d × %d = %d\n", num1, num2, multiplyUsingAddition(num1, num2));
            break;

        case 7:
            printf("Enter base and exponent: ");
            scanf("%d %d", &num1, &num2);
            printf("\nChoose method:\n1. Iterative\n2. Recursive\n3. Fast (Divide & Conquer)\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printf("%d^%d = %lld\n", num1, num2, powerIterative(num1, num2));
            else if (method == 2)
                printf("%d^%d = %lld\n", num1, num2, powerRecursive(num1, num2));
            else
                printf("%d^%d = %lld\n", num1, num2, powerFast(num1, num2));
            break;

        case 8:
            printf("Enter start and end: ");
            scanf("%d %d", &num1, &num2);
            printDivisibleByTwo(num1, num2);
            break;

        case 9:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("\nChoose method:\n1. Basic O(n)\n2. Optimized O(√n)\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                findFactorsBasic(num);
            else
                findFactorsOptimized(num);
            break;

        case 10:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("\nChoose method:\n1. Basic O(n)\n2. Optimized O(√n)\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printf("Sum of divisors = %d\n", sumOfDivisorsBasic(num));
            else
                printf("Sum of divisors = %d\n", sumOfDivisorsOptimized(num));
            break;

        case 11:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("\nChoose method:\n1. Euclidean (Iterative)\n2. Euclidean (Recursive)\n3. Subtraction\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printf("GCD = %d\n", findGCDIterative(num1, num2));
            else if (method == 2)
                printf("GCD = %d\n", findGCDRecursive(num1, num2));
            else
                printf("GCD = %d\n", findGCDSubtraction(num1, num2));
            break;

        case 12:
            printf("Enter two numbers: ");
            scanf("%d %d", &num1, &num2);
            printf("LCM(%d, %d) = %d\n", num1, num2, findLCM(num1, num2));
            break;

        case 13:
            printf("Enter a number: ");
            scanf("%d", &num);
            if (isPerfectNumber(num))
                printf("%d is a Perfect Number\n", num);
            else
                printf("%d is NOT a Perfect Number\n", num);
            break;

        case 14:
            printf("Enter a number: ");
            scanf("%d", &num);
            if (isHarshadNumber(num))
                printf("%d is a Harshad Number\n", num);
            else
                printf("%d is NOT a Harshad Number\n", num);
            break;

        case 15:
            printf("Enter a number: ");
            scanf("%d", &num);
            printf("\nChoose method:\n1. Iterative\n2. Recursive\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
            {
                if (isPrimeBasic(num))
                    printf("%d is Prime\n", num);
                else
                    printf("%d is NOT Prime\n", num);
            }
            else
            {
                if (isPrimeRecursive(num, 3))
                    printf("%d is Prime\n", num);
                else
                    printf("%d is NOT Prime\n", num);
            }
            break;

        case 16:
            printf("Enter number of terms: ");
            scanf("%d", &n);
            printf("\nChoose method:\n1. Iterative\n2. Recursive\n3. Memoization (DP)\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printFibonacciIterative(n);
            else
                printFibonacciRecursive(n);
            break;

        case 17:
            printf("Enter n: ");
            scanf("%d", &n);
            printf("\nChoose method:\n1. Iterative\n2. Formula\n3. Recursive\nChoice: ");
            scanf("%d", &method);
            if (method == 1)
                printf("Sum = %d\n", alternatingSumIterative(n));
            else if (method == 2)
            {
                printf("Sum (Formula) = %d\n", alternatingSumFormula(n));
            }
            else
                printf("Sum (Recursive) = %d\n", alternatingSumRecursive(n));
            break;

        case 0:
            printf("Exiting program. Goodbye!\n");
            return 0;

        default:
            printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}