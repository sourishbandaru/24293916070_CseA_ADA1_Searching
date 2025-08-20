#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Linear Search function
int linear_search(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) return i;
    }
    return -1;
}

int main() {
    FILE *fp;
    fp = fopen("linear_search_results.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    fprintf(fp, "size,time\n"); // CSV header
    printf(" size\t time (seconds)\n");
    printf("--------------------------\n");

    for (int n = 1000; n <= 100000; n += 5000) {
        int *arr = malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) arr[i] = i;

        int target = n - 1; // Worst case (last element)

        clock_t start = clock();
        linear_search(arr, n, target);
        clock_t end = clock();

        double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

        // Write to file
        fprintf(fp, "%d,%f\n", n, time_taken);

        // Print to console
        printf("%6d\t %f\n", n, time_taken);

        free(arr);
    }

    fclose(fp);
    printf("\nResults written to linear_search_results.txt\n");
    return 0;
}