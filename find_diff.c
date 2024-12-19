#include <stdio.h>
#include <stdlib.h>

int isInArray(int *array, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (array[i] == num) {
            return 1;
        }
    }
    return 0;
}

void findDifference(int *nums1, int size1, int *nums2, int size2, int **result1, int *sizeResult1, int **result2, int *sizeResult2) {
    *result1 = (int *)malloc(size1 * sizeof(int));
    *result2 = (int *)malloc(size2 * sizeof(int));
    *sizeResult1 = 0;
    *sizeResult2 = 0;
    for (int i = 0; i < size1; i++) {
        if (!isInArray(nums2, size2, nums1[i])) {
            if (!isInArray(*result1, *sizeResult1, nums1[i])) {
                (*result1)[(*sizeResult1)++] = nums1[i];
            }
        }
    }
    for (int i = 0; i < size2; i++) {
        if (!isInArray(nums1, size1, nums2[i])) {
            if (!isInArray(*result2, *sizeResult2, nums2[i])) {
                (*result2)[(*sizeResult2)++] = nums2[i];
            }
        }
    }
}

int main() {
    int nums1[] = {1, 2, 3};
    int nums2[] = {2, 4, 6};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int *result1 = NULL, *result2 = NULL;
    int sizeResult1 = 0, sizeResult2 = 0;
    findDifference(nums1, size1, nums2, size2, &result1, &sizeResult1, &result2, &sizeResult2);
    printf("[[");
    for (int i = 0; i < sizeResult1; i++) {
        printf("%d", result1[i]);
        if (i < sizeResult1 - 1) {
            printf(", ");
        }
    }
    printf("], [");
    for (int i = 0; i < sizeResult2; i++) {
        printf("%d", result2[i]);
        if (i < sizeResult2 - 1) {
            printf(", ");
        }
    }
    printf("]]\n");
    free(result1);
    free(result2);
    return 0;
}
