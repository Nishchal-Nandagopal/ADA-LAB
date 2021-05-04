#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateArray(int arr[10], int n)
{
	for(int i = 0; i<n; i++)
		arr[i] = (rand()%10000);
}
void print(int *arr, int n)
{
	printf("\nThe elements in the array are:\n");
	for(int i = 0; i<n; i++)
		printf("%d\t", arr[i]);
}

int LinearSearch(int* arr, int n, int i, int e)
{
	if(i==n)
		return -1;
	if(arr[i] == e)
		return i;
	return LinearSearch( arr, n, i+1, e);
}

void Sort(int* arr, int n)
{
	for(int i = 0; i<n; i++)
	{
		for(int j = i+1; j<n; j++)
		{
			if(arr[i]>arr[j])
			{
				int t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
			}
		}
	}
}
int BinarySearch(int* arr, int low,int mid, int high, int e)
{
	if(low == high)
		return -1;
	if(e==arr[mid])
	{
		return mid;
	}
	else if(e>arr[mid])
	{
		return BinarySearch(arr, mid, (int)(high+low)/2, high, e);
	}
	else
	{
		return BinarySearch(arr, low, (int)(high-low)/2, mid, e);
	}
}


int main()
{
	int *arr, ch=10, n;
	clock_t start_l, start_b, end_l, end_b;
	srand(time(0));
	while(ch!=3)
	{
		printf("\n\n\n\t1]Linear Search\n\t2]Binary Search\n\t3]Exit\nEnter Choice:\t");
		scanf("%d", &ch);
		if(ch==3)
			break;
		printf("\nEnter the size of Array:\t");
		scanf("%d", &n);
		generateArray(arr, n);
		print(arr, n);
		int e, res;
		switch(ch)
		{
			case 1: printf("\nEnter the search element:	");
					scanf("%d", &e);
					start_l = clock();
					for (int c = 1; c <= 32767; c++) 
						for (int d = 1; d <= 32767; d++) { }
					res = LinearSearch(arr, n, 0, e);
					end_l = clock();
					break;
			case 2: printf("\nEnter the search element:	");
					scanf("%d", &e);
					start_b = clock();
					for (int c = 1; c <= 32767; c++)
						for (int d = 1; d <= 32767; d++) { }
					Sort(arr, n);
					printf("\n\nSorted array is");
					print(arr, n);
					res = BinarySearch(arr, 0, (int)(n/2), n, e);
					end_b = clock();
					break;
			default: printf("\nEnter Valid Choice\n\n\n");
		}
		if(res <0)
			printf("\nElement not found!");
		else printf("\nThe Element found at index %d", res);
	}
	printf("\nTime taken for binary search: %Lf", (long double)(end_b - start_b)/CLOCKS_PER_SEC);
	printf("\nTime taken for linear search: %Lf", (long double)(end_l - start_l)/CLOCKS_PER_SEC);
	}