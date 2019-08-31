char * convertToTitle(int n){

    char *res;
    // this calculation is not exact, and may be one
    // byte too long
    int i = log(n)/log(26) + 1;
    
    res = (char *) malloc((i + 1) * sizeof(char));
    
    res[i] = '\0';
    while(n) {
        res[--i] = --n % 26 + 'A';
        n /= 26;
    }
    
    return res + i;
}
