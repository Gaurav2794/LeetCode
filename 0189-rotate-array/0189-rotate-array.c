void rotate(int* nums, int numsSize, int k) {
    int temp[numsSize];
    k = k% numsSize;
    for(int i=0;i < numsSize ;i++){
        temp[(i+k) % numsSize]=nums[i];
    }
    for(int i = 0; i < numsSize; i++) {
        nums[i] = temp[i];
    }
}