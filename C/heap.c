#include<stdio.h>
void swap(int *a,int *b){
        int t=*a;
        *a=*b;
        *b=t;
}
void heapify(int a[],int n,int i){
    int left=(i*2)+1;
    int right=(i*2)+2;
    int largest =i;
    if(left<n && a[left]>a[largest]){
        largest=left;
    }
    if(right<n && a[right]>a[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&a[i],&a[largest]);
        heapify(a,n,largest);
    }

}
void heapsort(int a[],int n){
        for(int i=n/2-1;i>=0;i--){
            heapify(a,n,i);
        }
        for(int i=n-1;i>=0;i--){
            swap(&a[0],&a[i]);
            heapify(a,i,0);
        }
}
int main(){
        int a[10]={7,4,-3,8,12,6,14,-1,9,5};
        int n=sizeof(a)/sizeof(a[0]);
        for(int i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        printf("\n");
        heapsort(a,n);
        for(int i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        return 0;
}