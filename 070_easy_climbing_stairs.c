int climbStairs(int n){
    if(n < 3)
        return n;
    
    // fib
    int a = 1, b = 2, tmp, i;
    for(i = 0; i < n - 2; i++) {
        tmp = b;
        b += a;
        a = tmp;
    }
    
    return b;
}
