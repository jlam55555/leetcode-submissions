int singleNumber(int* nums, int numsSize){
    int res = 0;
    
    while(numsSize--)
        res ^= *nums++;
    
    return res;
}
