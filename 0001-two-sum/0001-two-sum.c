/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* Result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;
    
    for(int i=0;i<numsSize;i++){
        for(int j=i+1; j<numsSize; j++){
            if( (nums[i]+nums[j]) == target){
                Result[0] = i;
                Result[1] = j;
                return Result;
            }
        }
    }
    
    return NULL;
    
}