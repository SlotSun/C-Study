//
// Created by SUN on 2019/9/14.
//

#ifndef STUDY_SORT_H
#define STUDY_SORT_H

#endif //STUDY_SORT_H

//直接插入排序
void InsertSort(int *a, int n) {
    int i, j, temp;
    for (i = 1; i < n; ++i) {
        if (a[i] < a[i - 1]) {
            temp = a[i];
            for (j = i - 1; a[j] > temp; --j) {
                a[j + 1] = a[j];
            }
            a[j + 1] = temp;
        }
    }
}

//折半插入排序
void InsertSort2(int *a, int n) {
    int i, j, low, high, mid, temp;
    for (i = 1; i < n; ++i) {
        temp = a[i];
        low = 0;
        high = i - 1;
        while (low <= high) {
            mid = (low + high) / 2;
            if (a[mid] > temp) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        for (j = i - 1; j >= high + 1; --j) {
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

//冒泡排序
void bubbleSort(int *a, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (a[j] > a[j + 1])
                swap(a + j, a + j + 1);
        }
    }
}

//选择排序
void selectSort(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (a[i] > a[j])
                swap(a + i, a + j);
        }
    }
}

//快速排序划分算法
int Partition(int A[], int low, int high) {
    int pivot = A[low];                                 //将表中第一个元素作为枢纽值，对表进行划分
    while (low < high) {
        while (low < high && A[high] >= pivot) --high;  //
        A[low] = A[high];
        while (low < high && A[low] <= pivot) ++low;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

//快速排序
void QuickSort(int *A, int low, int high) {
    if (low < high) {
        int pivotpos = Partition(A, low, high);
        QuickSort(A, low, pivotpos - 1);
        QuickSort(A, pivotpos + 1, high);
    }
}

//调整算法
void AdjustDown(int *A, int k, int len) {
    A[0] = A[k];
    for (int i = 2 * k; i < len; i *= 2) {
        if (i < len && A[i] < A[i + 1]) i++;
        if (A[0] >= A[i]) {
            break;
        } else {
            A[k] = A[i];
            k = i;
        }
    }//end if
    A[k] = A[0];
}
void BuildeMaxHeap(int *A,int len){
    for (int i = len/2; i > 0; i--) {
        AdjustDown(A,i,len);
    }
}
//堆排序
void Heapsort(int *A, int len) {
    BuildeMaxHeap(A,len);
    for (int i = len; i >1 ; --i) {
        swap(A+i,A+1);
        AdjustDown(A,1,i-1);
    }
}
//外部排序：归并排序











