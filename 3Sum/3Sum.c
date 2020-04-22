#include <stdio.h>
#include <stdlib.h>

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes);

int main(){
	int testCase[] = {-1, 0, 1, 2, -1, -4, 5, -10, 6, 3, 2};
	int size = 11;
	int *returnedSize, *aaa;
	int **returned = threeSum(testCase, size, returnedSize, aaa);
	for(int i = 0; i < *returnedSize; ++i){
		printf("%d\t%d\t%d\n", returned[i][0], returned[i][1], returned[i][2]);
	}
	return 0;
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
	int maxSize = 10000;
	int **result = (int**)malloc(maxSize * sizeof(int*));
	for(int i = 0; i < maxSize; ++i){
		result[i] = (int*)malloc(3 * sizeof(int));
	}
	int actualSize = 0;
	int temp[3];
	for(int i = 0; i < numsSize-2; ++i){
		for(int j = i+1; j < numsSize-1; ++j){
			for(int k = j+1; k < numsSize; ++k){
				if(nums[i] + nums[j] + nums[k] == 0){ //triplet found
					int flag = 0;
					if(nums[i] <= nums[j] && nums[i] <= nums[k]){
						temp[0] = nums[i];
						if(nums[j] <= nums[k]){
							temp[1] = nums[j];
							temp[2] = nums[k];
						}
						else{
							temp[1] = nums[k];
							temp[2] = nums[j];
						}
					}
					else if(nums[j] <= nums[i] && nums[j] <= nums[k]){
						temp[0] = nums[j];
						if(nums[i] <= nums[k]){
							temp[1] = nums[i];
							temp[2] = nums[k];
						}
						else{
							temp[1] = nums[k];
							temp[2] = nums[i];
						}
					}
					else{
						temp[0] = nums[k];
						if(nums[i] <= nums[j]){
							temp[1] = nums[i];
							temp[2] = nums[j];
						}
						else{
							temp[1] = nums[j];
							temp[2] = nums[i];
						}
					}
					for(int l = 0; l < actualSize; ++l){
						if(temp[0] == result[l][0] && temp[1] == result[l][1] && temp[2] == result[l][2]){
							flag = 1;
						}
					}
					if(flag == 0){
						result[actualSize][0] = temp[0];
						result[actualSize][1] = temp[1];
						result[actualSize][2] = temp[2];
						actualSize++;

					}
				}
			}
		}
	}
	for(int i = actualSize; i < maxSize; ++i){
		free(result[i]);
	}
	*returnSize = actualSize;
	returnColumnSizes = (int**)malloc(1 * sizeof(int*));
    returnColumnSizes[0] = (int*)malloc(actualSize * sizeof(int));
	printf("Actual Size = %d\n", actualSize);
	for(int i = 0; i < actualSize; ++i){
		returnColumnSizes[0][i] = 3;
	}
	return result;
}
