#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void swap(int *a,int *b){
    int t=*a;
    *a=*b;
    *b=t;
}
int partition(int A[],int p,int r){
    int i=p-1;
    int x=A[r];
    for (int j=p;j<r;j++){
        if (A[j]<=x){
            i+=1;
            swap(&A[j],&A[i]);
        }
    }
    swap(&A[i+1],&A[r]);
    return i+1;
}
void q_sort(int A[],int p,int r){
    if (p<r){
        int q=partition(A,p,r);
        q_sort(A,p,q-1);
        q_sort(A,q+1,r);
    }
}
int mode_1(int arr[],int n){
    q_sort(arr,0,n-1);
    int c=1,max_c=1;
    int mode=arr[0];
    for (int i=0;i<n-1;i++){
        if (arr[i]==arr[i+1]){
            c+=1;
        }else{
            if (c>max_c){
                mode=arr[i];
                max_c=c;
                c=1;
            }
        }
        
    }
    return mode;
}
int main(){
    int n;
    scanf("%d",&n);
    int A[n];
    for (int i=0;i<n;i++){
        scanf("%d",&A[i]);
    }
    A[n-2]=1;
    clock_t start,end;
    start=clock();
    printf("the mode is :%d\n",mode_1(A,n));
    end=clock();
    end-=start;
    printf("the time : %f\n",(float)(end/CLOCKS_PER_SEC));
    return 0;
}
