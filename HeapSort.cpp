#include <iostream>
#define MAX_SIZE 1000
using namespace std;

// from the last non-leaf element, compare with its child element 
// and swap them if the parent is greater than its child.
void HeapAdjust(int a[], int s, int n){

    int j, t;

    while(2 * s + 1 < n){
        j = 2 * s + 1;
        if ((j + 1) < n){
            if(a[j] < a[j + 1]){
                j++;
            }
        }

        if (a[s] < a[j]){
            t =  a[s]; a[s] = a[j]; a[j] = t;
            s = j;
        }
        else {
            break;
        }
    }

}


void HeapSort(int a[], int n){
    int t, i, j;
    for (i = n / 2 - 1; i >= 0; i--) {
        HeapAdjust(a, i, n);
    }

    // the top of the heap swap with the last element in the array, 
    // and adjust the i - 1 elements to be a heap and repeat until every element has been selected.
    for (i = n - 1; i > 0; i--) {
        t = a[0]; a[0] = a[i]; a[i] = t;
        HeapAdjust(a, 0, i);
    } // adjust the heap from a[0] to a[i - 1]
}



int main(){
    int a[MAX_SIZE];
    int N;
    
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
    }

    HeapSort(a, N);
    
    for(int i = 0; i < N; i++){
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}