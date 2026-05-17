#include<stdio.h>
void swap(int *a,int *b){
        int t=*a;
        *a=*b;
        *b=t;
}
int partition(int a[],int l,int h){
        int pivot=a[l];
        int i=l+1;
        int j=h;
        while(i<=j){
while(i<=h && a[i]<=pivot){
        i++;
}
while(j>l && a[j]>pivot){
        j--;
}
if(i<j){
swap(&a[i],&a[j]);
}
        }
swap(&a[l],&a[j]);
return j;
}
void quicksort(int a[],int l,int h){
        if(l<h){
        int j=partition(a,l,h);
        quicksort(a,l,j-1);
        quicksort(a,j+1,h);
}
}
int main(){
        int a[10]={7,4,-3,8,12,6,14,-1,9,5};
        int n=sizeof(a)/sizeof(a[0]);
        for(int i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        printf("\n");
        quicksort(a,0,n-1);
        for(int i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        return 0;
}