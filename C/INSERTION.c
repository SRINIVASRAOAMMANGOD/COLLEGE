//PROGRAM TO PERFORM INSERTION SORT ON INTEGER ARRAY
#include<stdio.h>
void insertion(int arr[],int size){
	int key ,j;
	for(int i=1;i<size;i++){
		key=arr[i];
		j=i-1;
		while(j>=0&&arr[j]>key){  
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
		printf("\nPASS %d :",i);
		for(int k=0;k<size;k++)
			printf("%d\t",arr[k]);
	}	
}
int main(){
	int n;
	int arr[50];
	printf("PROGRAM TO PERFORM INSERTION SORT\n");
	printf("ENTER SIZE OF THE ARRAY: ");
	scanf("%d",&n);
	printf("ENTER ELEMENT: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	insertion(arr,n);
	printf("\nSORTED ARRAY\n");
	for(int i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	return 0;
}			
/*   OUTPUT
PROGRAM TO PERFORM INSERTION SORT
ENTER SIZE OF THE ARRAY: 5
ENTER ELEMENT: 
9
8
7
6
5
PASS 1 :8	9	7	6	5	
PASS 2 :7	8	9	6	5	
PASS 3 :6	7	8	9	5	
PASS 4 :5	6	7	8	9	
SORTED ARRAY
5  6  7  8  9  
*/
