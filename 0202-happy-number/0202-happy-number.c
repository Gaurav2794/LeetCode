int sumOfSquares(int n) {
    int sum = 0, digit;

    while (n > 0) {
        digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }

    return sum;
}

int isHappy(int n) {
    int slow = n, fast = n;

    do {
        slow = sumOfSquares(slow);
        fast = sumOfSquares(sumOfSquares(fast));
    } while (slow != fast);

    return (slow == 1);
}