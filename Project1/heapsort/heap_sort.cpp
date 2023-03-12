#include <bits/stdc++.h>
#include <sys/time.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main(){
    
    FILE *fd = fopen("testcase", "r");
    int *buffer = (int *)calloc(1000000, sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 1000000; j++)
        {
            fscanf(fd, "%d", &buffer[j]);
        }
        printf("Test %d ", i+1);
        struct timeval stop, start;
        gettimeofday(&start, NULL);
        heapsort(buffer, 1000000);
        gettimeofday(&stop, NULL);
        double s = (double)(stop.tv_usec - start.tv_usec) / 1000000 + (double)(stop.tv_sec - start.tv_sec);
        printf("took %fs\n", s);
    }
}
