#include <iostream>
using namespace std;

int Max(int arr[], int size) {
    if (size == 1)
        return arr[0];
    return max(arr[size - 1], Max(arr, size - 1));
}
int Min(int arr[], int size) {
    if (size == 1)
        return arr[0];
    return min(arr[size - 1], Min(arr, size - 1));
}
int part(int arr[], int l, int h) {
    int p = arr[h];
    int ind = l - 1;

    for (int i = l; i < h; i++) {
        if (arr[i] < p) {
            ind++;
            swap(arr[ind], arr[i]);
        }
    }
    swap(arr[ind + 1], arr[h]);
    return (ind + 1);
}
void qSort(int arr[], int l, int h) {
    if (l < h) {
        int pInd = part(arr, l, h);

        cout << "arr after: ";
        for (int i = l; i <= h; i++) {
            cout << arr[i] << " ";
        }
        cout << "\npivot ind: " << pInd << endl;

        cout << "left: ";
        for (int i = l; i < pInd; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        cout << "right: ";
        for (int i = pInd + 1; i <= h; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        qSort(arr, l, pInd - 1);
        qSort(arr, pInd + 1, h);
    }
}

void disArr(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    //1
    int arr1[] = { 34, 7, 23, 32, 5 };
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "arr: ";
    disArr(arr1, size1);
    qSort(arr1, 0, size1 - 1);
    cout << endl << "sort arr: ";
    disArr(arr1, size1);
    cout << endl << endl;

    //2
    int arr2[] = { 1, 2, 3, 4, 5, 6 };
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "arr: ";
    disArr(arr2, size2);
    qSort(arr2, 0, size2 - 1);
    cout << endl << "sort arr: ";
    disArr(arr2, size2);
    cout << endl << endl;

    //3
    int arr3[] = { 90, 80, 70, 60, 50, 40, 30 };
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << "arr: ";
    disArr(arr3, size3);
    qSort(arr3, 0, size3 - 1);
    cout << endl << "sort arr: ";
    disArr(arr3, size3);
    cout << endl << endl;

    //4
    int arr4[] = { 5, 3, 8, 8, 1, 5, 3, 9 };
    int size4 = sizeof(arr4) / sizeof(arr4[0]);
    cout << "arr: ";
    disArr(arr4, size4);
    qSort(arr4, 0, size4 - 1);
    cout << endl << "sorted arr: ";
    disArr(arr4, size4);
    cout << endl << endl;

    return 0;
}

