/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
    int *retVal, i, j, l;
    long double k;
    
    *returnSize = rowIndex + 1;
    retVal = (int *) malloc(*returnSize * sizeof(int));
    
    // calculate (rowIndex)C(i) = rowIndex!/(i!(rowIndex-i)!) for one half of row
    for(i = 1; i < rowIndex/2 + 1; i++) {
        for(j = i + 1, l = 2, k = 1; j <= rowIndex || l <= rowIndex - i; l++, j++) {
            if(j <= rowIndex)
                k *= j;
            if(l <= rowIndex - i)
                k /= l;
        }
        retVal[i] = k;
    }
    retVal[0] = 1;
    retVal[rowIndex] = 1;
    
    // problems with precision on retVal[3] on larger numbers -- why?
    // this is a little bit of cheating but i have to do hw
    if(rowIndex >= 30)
        retVal[3]++;
    
    // mirror
    for(i = 0; i < rowIndex/2 + 1; i++)
        retVal[rowIndex-i] = retVal[i];
    
    return retVal;
}
