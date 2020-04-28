#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int *minus;
	int minusSize;
	int *plus;
	int plusSize;
	int *repetitions;
	int repetitionsSize;
	int zeros;
} sortedTable;

sortedTable sortAndSplit(int *table, int tableSize);

int main(){
	int testTable[] = {1, 2, 4, -4, 4, -5, -8, 40, -3, 4, -3, 12, 1};
	int testTableSize = 13;
	sortedTable myTable = sortAndSplit(testTable, testTableSize);
	for(int i = 0; i < myTable.plusSize; ++i){
		printf("%d\t", myTable.plus[i]);
	}
	printf("\n");
	for(int i = 0; i < myTable.minusSize; ++i){
		printf("%d\t", myTable.minus[i]);
	}
	printf("\n");
	for(int i = 0; i < myTable.repetitionsSize; ++i){
		printf("%d\t", myTable.repetitions[i]);
	}
	printf("\n");
	return 0;
}

int** threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
	int maxSize = 20000; //TODO
	int **result = (int**)malloc(maxSize * sizeof(int*));
	for(int i = 0; i < maxSize; ++i){
		result[i] = (int*)malloc(3 * sizeof(int));
	}
	int actualSize = 0;
	//sort and split table
	sortedTable functionTable = sortAndSplit(nums, numsSize);
	//handle "0 0 0" possibility
	if(functionTable.zeros > 2){
		for(int i = 0; i < 3; ++i){
			result[actualSize][i] = 0; 
		}
		actualSize++;
	}
	//handle 3 sums in repetitions
	for(int i = 0; i < functionTable.repetitionsSize; ++i){
		int temp = functionTable.repetitions[i];
		if(temp > 0){
			for(int j = 0; j < functionTable.minusSize; ++j){
				if(functionTable.minus[j] == -2 * temp){
					result[actualSize][0] = -2 * temp;
					result[actualSize][1] = temp;
					result[actualSize][2] = temp;
					actualSize++;
				}
			}
		}
		if(temp < 0){
			for(int j = 0; j < functionTable.plusSize; ++j){
				if(functionTable.plus[j] == -2 * temp){
					result[actualSize][0] = temp;
					result[actualSize][1] = temp;
					result[actualSize][2] = -2 * temp;
					actualSize++;					
				}
			}
		}
	}
	//handle three different 3 sum
	for(int i = 0; i < functionTable.minusSize; ++i){
		int tempMinus = functionTable.minus[i];
		for(int j = 0; j < functionTable.plusSize; ++j){
			int tempPlus = functionTable.plus[j];
			int difference = tempPlus + tempMinus;
			if(difference == 0){
				if(functionTable.zeros > 0){
					result[actualSize][0] = tempMinus;
					result[actualSize][1] = 0;
					result[actualSize][2] = tempPlus;
					actualSize++;
				}
			}
			if(difference > 0){
				for(int k = 0; k < i; ++k){
					if(functionTable.minus[k] == -difference){
					result[actualSize][0] = tempMinus;
					result[actualSize][1] = functionTable.minus[k];
					result[actualSize][2] = tempPlus;
					actualSize++;
					break;
					}
				}
			}
			if(difference < 0){
				for(int k = 0; k < j; ++k){
					if(functionTable.plus[k] == -difference){
					result[actualSize][0] = tempMinus;
					result[actualSize][1] = functionTable.plus[k];
					result[actualSize][2] = tempPlus;
					actualSize++;
					break;
					}
				}
			}
		}
	}


	for(int i = actualSize; i < maxSize; ++i){
		free(result[i]);
	}
	*returnSize = actualSize;
    *returnColumnSizes = (int*)malloc(actualSize * sizeof(int));
    for(int i = 0; i < actualSize; ++i){
		returnColumnSizes[0][i] = 3;
	}
	return result;
}

sortedTable sortAndSplit(int *table, int tableSize){
	sortedTable result;
	result.zeros = 0;
	result.minusSize = 0;
	result.plusSize = 0;
	result.repetitionsSize = 0;
	result.minus = (int*)malloc(tableSize * sizeof(int));
	result.plus = (int*)malloc(tableSize * sizeof(int));
	result.repetitions = (int*)malloc(tableSize / 2 * sizeof(int));
	for(int i = 0; i < tableSize; ++i){
		int temp = table[i];
		if(temp == 0){
			result.zeros += 1;
		}
		else if(temp > 0){
			int wasBeforeFlag = 0;
			int wasShiftedFlag = 0;
			for(int j = 0; j < result.plusSize; ++j){
				if(temp < result.plus[j]){
					for(int k = result.plusSize; k > j; --k){
						result.plus[k] = result.plus[k-1];
					}//move larger numbers
					result.plus[j] = temp;
					wasShiftedFlag = 1;
					break;
				}
				else if(temp == result.plus[j]){
					int wasAddedBefore = 0;
					for(int l = 0; l < result.repetitionsSize; ++ l){
						if(result.repetitions[l] == temp){
							wasAddedBefore = 1;			
						}
					}
					if(wasAddedBefore == 0){
						result.repetitions[result.repetitionsSize] = temp;
						result.repetitionsSize += 1;
					}
					wasBeforeFlag = 1;
					break;

				}
			}
			if(wasBeforeFlag == 0){
				if(wasShiftedFlag == 0){
					result.plus[result.plusSize] = temp;
				}
				result.plusSize += 1;
			}
		}
		else if(temp < 0){
			int wasBeforeFlag = 0;
			int wasShiftedFlag = 0;
			for(int j = 0; j < result.minusSize; ++j){
				if(temp > result.minus[j]){
					for(int k = result.minusSize; k > j; --k){
						result.minus[k] = result.minus[k-1];
					}//move larger numbers
					result.minus[j] = temp;
					wasShiftedFlag = 1;
					break;
				}
				else if(temp == result.minus[j]){
					int wasAddedBefore = 0;
					for(int l = 0; l < result.repetitionsSize; ++ l){
						if(result.repetitions[l] == temp){
							wasAddedBefore = 1;			
						}
					}
					if(wasAddedBefore == 0){
						result.repetitions[result.repetitionsSize] = temp;
						result.repetitionsSize += 1;
					}
					wasBeforeFlag = 1;
					break;

				}
			}
			if(wasBeforeFlag == 0){
				if(wasShiftedFlag == 0){
					result.minus[result.minusSize] = temp;
				}
				result.minusSize += 1;
			}
		}
	}
	result.plus = (int *)realloc(result.plus, result.plusSize * sizeof(int));
	result.minus = (int *)realloc(result.minus, result.minusSize * sizeof(int));
	result.repetitions = (int *) realloc(result.repetitions, result.repetitionsSize * sizeof(int));
	return result;
}
