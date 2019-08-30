int removeDuplicates(int* nums, int numsSize){
    
    if(numsSize < 2)
        return numsSize;
    
    int *i, *j;
    
    for(i = nums, j = nums + 1; j - nums < numsSize; j++)
        if(*i != *j)
            *++i = *j;
    
    return i - nums + 1;
}
