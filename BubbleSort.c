// Optimized implementation of Bubble sort
#include <bits/stdc++.h>
using namespace std;
void swap(int *xp, int *yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
int i, j;
bool swapped;

    std::cout <<"------n = "<< n <<std::endl;

    for (i = 0; i < n-1; i++)
    {
        std::cout <<"----i = "<< i <<std::endl;

        swapped = false;
        for (j = 0; j < n-i-1; j++)
        {
            std::cout <<"--j = "<< j <<std::endl;
            std::cout <<"arr[j] = "<< arr[j]<<" arr[j+1] = "<< arr[j+1] <<std::endl;
            
            if (arr[j] > arr[j+1])
            {
                std::cout <<"swapped " <<std::endl;

                swap(&arr[j], &arr[j+1]);
                swapped = true;
            }
        }

        // IF no two elements were swapped by inner loop, then break
        if (swapped == false)
        {
            std::cout <<"Array in order " <<std::endl;
            break;
        }   
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	
    for (i = 0; i < size; i++)
    {
        cout <<" "<< arr[i];
    }
	
    cout <<" <--Result";
}

// Driver program to test above functions
int main()
{
	int arr[] = {1, 34, 25, 12};
	int n = sizeof(arr)/sizeof(arr[0]);

    for(int index = 0; index < n; index++)
    {
        std::cout << "n=" << n<< "value=" << arr[index] << std::endl;
    }
    
	bubbleSort(arr, n);
	cout <<"Sorted array: \n";
	printArray(arr, n);
	return 0;
}


// This code is contributed by shivanisinghss2110
