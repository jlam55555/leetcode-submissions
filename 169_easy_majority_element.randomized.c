// using randomization method
int majorityElement(int* nums, int numsSize){
    
    int cand, count, i;
    
    srand(time(0));
    
    do {
        for(i = 0, count = 0, cand = nums[rand() % numsSize]; i < numsSize; i++)
            if(nums[i] == cand)
                count++;
    } while(count <= numsSize/2);
    
    return cand;
}
