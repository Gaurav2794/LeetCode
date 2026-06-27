char* maximumOddBinaryNumber(char* s) {
    int n = strlen(s);
    int ones = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1')
            ones++;
    }
    int k = 0;
    for (int i = 0; i < ones - 1; i++)
        s[k++] = '1';
    while (k < n - 1)
        s[k++] = '0';
    s[n - 1] = '1';
    return s;
}