#include <bits/stdc++.h>
using namespace std;

int swaps = 0;
int arr[100020];
int buf[100020];

void mergeSort(int L, int R) {
    if (L >= R)
        return;

    int mid = (L + R) / 2;
    mergeSort(L, mid);
    mergeSort(mid+1, R);

    int i = L;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= R) {
        if (arr[i] < arr[j]) {
            buf[k] = arr[i];
            i++;
        }
        else {
            buf[k] = arr[j];
            j++;
            swaps += (mid - i + 1);
        }
        k++;
    }

    while (i <= mid) {
        buf[k++] = arr[i++];
    }
    while (j <= R) {
        buf[k++] = arr[j++];
    }

    memcpy((char*)(arr + L), (char*)buf, sizeof(int) * (R - L + 1));
}

int main(void) {
    int N;
    while (1) {
        scanf("%d", &N);
        if (N == 0) break;
        for (int i = 0; i < N; i++) {
            scanf("%d", arr + i);
        }

        swaps = 0;
        mergeSort(0, N-1);

        if (swaps & 1)
            printf("Marcelo\n");
        else
            printf("Carlos\n");
    }

    return 0;
}