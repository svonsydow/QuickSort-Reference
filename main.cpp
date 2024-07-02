#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

//creating the pivot point for the quick sort function.
int partitionArray(int arr[], int start, int end){
    int pivotPoint = arr[start];
    int count = 0;
    for (int i = start + 1; i<=end; i++) {
        if (arr[i] <= pivotPoint)
            count++;
    }

//setting the pivot point
    int Index = start + count;
    swap(arr[Index], arr[start]);

//sorting elements to the left and right of the pivot point.
    int i = start;
    int j = end;

    while (i < Index && j > Index){
        while(arr[i] <= pivotPoint){
            i++;
        }
        while (arr[j] > pivotPoint){
            j--;
        }
        if (i < Index && j > Index){
            swap(arr[i++], arr[j--]);
        }
    }
    return Index;
}

void quickSort(int arr[], int start, int end)
{

// if the first element is greater than the last element, the array is unsorted.
    if (start >= end)
        return;

// partitioning the array from the pivot
    int p = partitionArray(arr, start, end);

// Sorting the left of the pivot
    quickSort(arr, start, p - 1);

// Sorting the right of the pivot
    quickSort(arr, p + 1, end);
}

//function to format and print array.
void printArr(int arrElem[], int size){
    //print array
    for (int i = 0; i < size; i++){
        cout << setw(5) << arrElem[i]; //set width of array
        //print new line after 10 elements
        if ( (i+1)%15 == 0 )
            cout << '\n';
    }

}

int main() {

//Generate random number between 0 to 1000 and place it in array.
    int size = 250;
    int randArray[size];
    for(int i=0;i<size;i++)
        randArray[i]=rand()%1000;
    cout << "Array prior to quicksort." << endl;
    printArr(randArray, size);
    cout << endl;

    quickSort(randArray, 0, size-1);
    cout << "Array after quicksort." << endl;
    printArr(randArray, size);

    return 0;
}
