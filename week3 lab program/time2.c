#include<stdio.h>
#include<time.h>


unsigned int recursiveLS(unsigned int arr[],unsigned int n,unsigned int key){
    if (arr[n]== key){
        printf("found at index %u\n\n",n);
    }
    else{
        return recursiveLS(arr,n-1,key);
    }
}
unsigned int recursiveBS(unsigned int arr[],unsigned int low,unsigned int high,unsigned int key){
    unsigned int mid = (low+high)/2;
    if(low<=high){
        if(arr[mid]==key){
        printf("Found at index %u\n\n",mid);
        }
        else if(arr[mid]<key){
            recursiveBS(arr,mid+1,high,key);
        }
        else{
           recursiveBS(arr,low,mid-1,key);
        }


    }
     else {
        return -1;
     }
}

void main(){
    unsigned int n,key,low=0;
    clock_t start,end;
    printf("Enter the no of elements\n");
    scanf("%u",&n);
    printf("Enter the element to be searched\n");
    scanf("%u",&key);
    unsigned int arr[n];
    for(unsigned int i=0;i<n;i++){
        arr[i]=i;
    }
    start = clock();
    recursiveLS(arr,n,key);
    end = clock();
    double time_taken = ((double)end-start)/CLOCKS_PER_SEC;
    printf("Time taken to search %u using linear search technique is %f sec\n",key,time_taken);
    start = clock();
    recursiveBS(arr,low,n,key);
    end = clock();
    time_taken = ((double)end-start)/CLOCKS_PER_SEC;
    printf("Time taken to search %u using binary search technique is %f sec\n",key,time_taken);
}