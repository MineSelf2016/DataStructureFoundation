#include <iostream>
#define MAX_SIZE 1000
using namespace std;

void swap(int a[], int i, int j){
    int t = a[i];
    a[i] = a[j];
    a[j] = t;
}


void QuickSort(int a[], int left, int right) {
    if (left < right) {
        int i = left, j = right;
        while(true) {
            while(i + 1 < n && a[++i] < a[left]);
            while(j > 1 && a[--j] > a[left]);
            if (i >= j) {
                break;
            }
            swap(a, i, j);
        }
        swap(a, left, j);
        QuickSort(a, left, j - 1);
        QuickSort(a, j + 1, right);

    }
}


int main() {
    int a[MAX_SIZE];
    int N;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    QuickSort(a, 0, N);
    
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;


    return 0;
}