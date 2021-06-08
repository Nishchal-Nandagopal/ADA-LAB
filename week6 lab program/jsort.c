#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 
int flag = 1;
 
void jsort(int n, int arr[],int len){
	int temp;
	int i;

	if(n==1)
	{
		printf("\n[");
 
		for(i=0;i<len;i++)
			printf("%d,",arr[i]);
		printf("\b]");
 
		flag*=-1;
	}
	else{
		for(i=0;i<n-1;i++){
			jsort(n-1,arr,len);
 
			if(n%2==0){
				temp = arr[i];
				arr[i] = arr[n-1];
				arr[n-1] = temp;
			}
			else{
				temp = arr[0];
				arr[0] = arr[n-1];
				arr[n-1] = temp;
			}
		}
		jsort(n-1,arr,len);
	}
}
 
int main(int argC,char* argV[0])
{
	int *arr, i=0, count = 1;
	char* token;
 
	if(argC==1)
		printf("No values given",argV[0]);
	else{
		while(argV[1][i]!=00){
			if(argV[1][i++]==',')
				count++;
		}
 
		arr = (int*)malloc(count*sizeof(int));
 
		i = 0;
 
		token = strtok(argV[1],",");
 
		while(token!=NULL){
			arr[i++] = atoi(token);
			token = strtok(NULL,",");
		}
 		printf("The permutations are:");
		jsort(i,arr,count);
	}
 
	return 0;
}