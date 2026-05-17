#include<stdio.h>
int temp[10];

void merge(int a[],int l,int h,int mid){
                int i=l;
                int j=mid+1;
                int k=0;
                while(i<=mid && j<=h){
                        if(a[i]<a[j]){
                                temp[k]=a[i];
                                k++; i++;
                        }else{
                                temp[k]=a[j];
                                j++, k++;
                        }
                }
                        while(i<=mid){
                                temp[k]=a[i];
                                k++;
                                i++;
                        }
                        while(j<=h){
                                temp[k]=a[j];
                                j++;
                                k++;
                        }
                
                for(int i=l;i<=h;i++){
                        a[i]=temp[i-l];
                }
                }

void mergesort(int a[],int l,int h){
        int mid;
        if(l<h){
                mid=(l+h)/2;
                mergesort(a,l,mid);
                mergesort(a,mid+1,h);
                merge(a,l,h,mid);
        }
}
int main(){
        int a[10]={7,4,-3,8,12,6,14,-1,9,5};
        int n=sizeof(a)/sizeof(a[0]);
        for(int i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        printf("\n");
        mergesort(a,0,n-1);
        for(int i=0;i<n;i++){
                printf("%d ",a[i]);
        }
        return 0;
}