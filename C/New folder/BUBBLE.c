//PROGRAM TO PERFORM BUBBLE SORT ON INTEGER ARRAY
#include<stdio.h>
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubble(int arr[],int n){
	int i,j,temp;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
			}
		}
		printf("\nPASS %d : ",i+1);
		for(int k=0;k<n;k++)
			printf("%d\t",arr[k]);
		printf("\n");
		
	}	
}
int main(){
	int n;
	int arr[50];
	printf("PROGRAM TO PERFORM BUBBLE SORT\n");
	printf("ENTER SIZE OF THE ARRAY: ");
	scanf("%d",&n);
	printf("ENTER ELEMENT: \n");
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	bubble(arr,n);
	printf("\nSORTED ARRAY\n");
	for(int i=0;i<n;i++)
		printf("%d  ",arr[i]);
	printf("\n");
	return 0;
}			
/*   OUTPUT
PROGRAM TO PERFORM BUBBLE SORT
ENTER SIZE OF THE ARRAY: 5
ENTER ELEMENT: 
66
88
22
16
97
PASS 1 : 66	22	16	88	97	
PASS 2 : 22	16	66	88	97	
PASS 3 : 16	22	66	88	97	
PASS 4 : 16	22	66	88	97	
SORTED ARRAY
16  22  66  88  97 
*/
