int digitproduct(int num){
    int product = 1;
    while(num > 0){
        product = product * (num%10);
        num = num /10;
    }
    return product;
}
int smallestNumber(int n, int t) {
    while(1){
        if(digitproduct(n)%t == 0)
            return n;
        n++;
    }
    
}