#include "sort.h"
#include <fstream>

sort::sort(string txt)
{
	readToArr(txt);
}
sort::~sort(){}

int sort::partition (double arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (arr[j] <= pivot)
        {
            i++;    // increment index of smaller element
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void sort::quickSort(double arr[], int low, int high)
{
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        double pi = partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void sort::selectionSort(double arr[], int n)
{
	int i, j, minIndex;
	double tmp;
	for ( i =0; i < n-1; i++)
	{
		minIndex = i;
		for(j=i+1;j <n; j++) // goes through each index to see if the value to the right is bigger
		{
			if (arr[j] < arr[minIndex]) //if it is in fact bigger, swap them
			{
				minIndex = j;
			}
			if(minIndex != i) // checks that values are sorted
			{
				tmp = arr[i];
				arr[i] = arr[minIndex];
				arr[minIndex]=tmp;
			}
		}
	}
}

void sort::insertSort(double arr[])
{
	for (int j = 0; j < size; ++j) //marker
	{
		double temp = arr[j]; //store marked item
		int k = j; //where to begin shifting
		while (k>0 && arr[k-1] >=temp) //while value to the left is bigger, shift
		{
			arr[k] = arr[k-1];
			--k;
		}
		arr[k] = temp; //marked item gets put in correct spot
		// correct value literally gets 'inserted' into the right index
	}

	//cout << "Insertion Sort!" << endl;
}

void sort::bubbleSort(double arr[])
{
	for (int i = 0; i < size; ++i)
	{
		int temp = 0;
		for (int j = 0; j < size; ++j)
		{
			if(arr[j] > arr[j+1]) // compares the 2 numbers to the left and right of temp
			{
				temp = arr[j+1]; // if the one on left is bigger, swap
				arr[j+1] = arr[j]; // move one index to the right
				arr[j] = temp;
			}
		}
	}
	//cout << "Bubble Sort!" << endl;
}
void sort::readToArr(string txt)
{

	ifstream file(txt);
	//File.open(txt);
	if (file) // checks to see if we are testing the correct file for numbers to sort
	{
		string line;
		getline(file,line); // the first line gives us the size of the array so we know how big to make it 
		size = stoi(line);
		arr = new double[size];

		while (getline(file,line)) // loops through the rest of the file and puts the contents of the file into the game arrays (all of the X's and -'s')
		{
			for (int i = 0; i < size; i++)
			{
				arr[i] = stod(line);
			}
		}
		file.close();
	}
}
