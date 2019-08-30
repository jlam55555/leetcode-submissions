int maxArea(int* height, int heightSize){
    
    # two pointer method
    int *start = height, *end = height + heightSize - 1, maxVol = 0, vol;
    
    while(start != end) {
        vol = (end - start) * (*start < *end ? *start : *end);
        maxVol = vol > maxVol ? vol : maxVol;
        
        if(*start > *end)
            end--;
        else
            start++;
    }
    
    return maxVol;
}
