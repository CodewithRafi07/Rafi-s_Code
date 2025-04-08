#include <stdio.h>
#include <stdlib.h> // For malloc

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* result = (int*)malloc(2 * sizeof(int)); // Dynamically allocate memory
    if (!result) return NULL; // Check for allocation failure

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                *returnSize = 2;
                return result;
            }
        }
    }

    free(result); // Free memory before returning NULL
    *returnSize = 0;
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;

    int* result = twoSum(nums, 4, target, &returnSize);

    if (result) { // Check if result is not NULL before accessing it
        printf("Output: [%d, %d]\n", result[0], result[1]);
        free(result); // Free dynamically allocated memory
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
 