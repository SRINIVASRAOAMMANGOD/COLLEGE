//PROGRAM TO PERFORM SELECTION SORT ON INTEGER ARRAY
#include<stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selection(int arr[],int size){
	int i ,j,min;
	for(int i=0;i<size-1;i++){
		min=i;
		for(j=i+1;j<size;j++){
			if (arr[j]<arr[min]){
				min=j;
			}
		}
		if(min!=i){
			swap(&arr[min],&arr[i]);
		}		
		printf("\nPASS %d :",i+1);
		for(int k=0;k<size;k++)
			printf("%d\t",arr[k]);
	}	
}
int main(){
	int n;
	int arr[50];
	printf("PROGRAM TO PERFORM SELECTION SORT\n");
	printf("ENTER SIZE OF THE ARRAY: ");
	scanf("%d",&n);
	printf("ENTER ELEMENT: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	selection(arr,n);
	printf("\nSORTED ARRAY\n");
	for(int i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	return 0;
}			
/*   OUTPUT
PROGRAM TO PERFORM SELECTION SORT
ENTER SIZE OF THE ARRAY: 5
ENTER ELEMENT: 
6
2
9
7
5
PASS 1 :2	6	9	7	5	
PASS 2 :2	5	9	7	6	
PASS 3 :2	5	6	7	9	
PASS 4 :2	5	6	7	9	
SORTED ARRAY
2  5  6  7  9 
*/
