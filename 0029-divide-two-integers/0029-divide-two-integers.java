class Solution {
    public int divide(int dividend, int divisor) {

        // Special overflow case
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        // Determine whether result should be negative
        boolean negative = (dividend < 0) ^ (divisor < 0);

        // Convert to long before taking absolute value
        long a = Math.abs((long) dividend);
        long b = Math.abs((long) divisor);

        long quotient = 0;

        // Try subtracting divisor * powers of 2
        while (a >= b) {

            long temp = b;
            long multiple = 1;

            // Find largest power of 2 multiple that fits
            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            quotient += multiple;
        }

        // Apply sign
        if (negative) {
            quotient = -quotient;
        }

        return (int) quotient;
    }
}