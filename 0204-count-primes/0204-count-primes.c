int countPrimes(int n) {
    if(n<=2){
        return 0;
    }
    bool prime[n];
    for(int i=0;i<n;i++){
        prime[i]=true;
    }
    prime[0]=false;
    prime[1]=true;
    for (int i = 2; i < n; i++) {
        if (prime[i]) {
            for (int j = i * 2; j < n; j += i)
                prime[j] = false;
        }
    }
    int count = 0;

    for (int i = 2; i < n; i++) {
        if (prime[i])
            count++;
    }

    return count;
    
}