int findMaxLength(int* nums, int numsSize) {
    int *first = (int *)malloc((2 * numsSize + 1) * sizeof(int));

    for (int i = 0; i < 2 * numsSize + 1; i++)
        first[i] = -2;

    int offset = numsSize;
    int sum = 0;
    int max = 0;

    first[offset] = -1;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 0)
            sum--;
        else
            sum++;

        if (first[sum + offset] != -2) {
            int len = i - first[sum + offset];
            if (len > max)
                max = len;
        } else {
            first[sum + offset] = i;
        }
    }

    free(first);
    return max;
}