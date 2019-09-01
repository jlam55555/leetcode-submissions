// using divide-and-conquer
int majorityElement(int* nums, int numsSize){
    
    // if numsSize=1, majority element is first one
    // if numsSize=2, no majority element, just choose first one
    if(numsSize < 3)
        return nums[0];
    
    int majLeft, majRight, countDiff, i;
    
    majLeft = majorityElement(nums, numsSize/2);
    majRight = majorityElement(nums+numsSize/2, numsSize-numsSize/2);
    
    if(majLeft == majRight)
        return majLeft;
    else {
        for(countDiff = 0, i = 0; i < numsSize; i++) {
            if(nums[i] == majLeft)
                countDiff++;
            else if(nums[i] == majRight)
                countDiff--;
        }
        return countDiff > 0 ? majLeft : majRight;
    }
}
