#define max(x, y) (x > y) ? (x) : (y)

int maxSubArray(int* nums, int numsSize){
    int sum = 0, max_sum = nums[0];
    short i = 0;
    while(i < numsSize) {
        sum += nums[i++];
        max_sum = max(sum, max_sum);
        sum = max(0, sum);
    }
    return max_sum;
}
