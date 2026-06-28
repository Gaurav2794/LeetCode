char * addBinary(char * a, char * b){

    int i = strlen(a) - 1;
    int j = strlen(b) - 1;

    int size = (i > j ? i : j) + 3;
    char *ans = (char *)malloc(size);

    ans[size - 1] = '\0';

    int k = size - 2;
    int carry = 0;

    while(i >= 0 || j >= 0 || carry)
    {
        int sum = carry;

        if(i >= 0)
            sum += a[i--] - '0';

        if(j >= 0)
            sum += b[j--] - '0';

        ans[k--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    return ans + k + 1;
}