#include <bits/stdc++.h>
#include <sys/time.h>

void quicksort(int arr[], int l, int r) {
    int i = l, j = r;
    int temp;
    int pivot = arr[(l + r) / 2];

    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    if (l < j)
        quicksort(arr, l, j);
    if (i < r)
        quicksort(arr, i, r);
}

int main(){

    FILE *fd = fopen("./testcase", "r");
    int *buffer = (int *)calloc(1000000, sizeof(int));
    for (int i = 0; i<10; ++i)
    {
        for (int j = 0; j<1000000; ++j)
        {
            fscanf(fd, "%d", &buffer[j]);
        }
        printf("Test %d ", i+1);
        struct timeval stop, start;
        gettimeofday(&start, NULL);
        quicksort(buffer, 0, 999999);
        gettimeofday(&stop, NULL);
        double s = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
        printf(" took %fs\n", s);
    }
}
