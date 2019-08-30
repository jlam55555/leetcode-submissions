/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    
    int i, j, **retVal;
    
    *returnSize = numRows;
    *returnColumnSizes = (int *) malloc(numRows * sizeof(int *));
    retVal = (int **) malloc(numRows * sizeof(int *));
    
    for(i = 0; i < numRows; i++) {
        (*returnColumnSizes)[i] = i+1;
        retVal[i] = (int *) malloc((i+1) * sizeof(int));
        for(j = 1; j < i; j++)
            retVal[i][j] = retVal[i-1][j-1] + retVal[i-1][j];
        retVal[i][0] = 1;
        retVal[i][i] = 1;
    }
    
    return retVal;
}
