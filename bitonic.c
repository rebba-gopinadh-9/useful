#include <stdio.h>
#include <stdlib.h>
int peak_search(int *arr,int l,int u){      //peak search is like binary search but for the peak 
    if (u>=l){
        int mid=l+(u-l)/2;
        if (*(arr+mid-1)<*(arr+mid) && *(arr+mid)>*(arr+mid+1))
            return mid;
    
        else if (*(arr+mid-1)<*(arr+mid) && *(arr+mid)<*(arr+mid+1))
            return peak_search(arr,mid+1,u);
    
        else if (*(arr+mid-1)>*(arr+mid) && *(arr+mid)>*(arr+mid+1))
            return peak_search(arr,l,mid-1);
    }
    return -1; 
        }
int B_left(int *arr,int l,int r,int x){        // this is normal binary searrch function for sorted array .(sorted ascending order.)
    if (r>=l){
        int mid=l+(r-l)/2;
        if (*(arr+mid)==x){
            return mid;
        }
        if (*(arr+mid)>x){
            return B_left(arr,l,mid-1,x);
        }
        return B_left(arr,mid+1,r,x);
    }
    return -1;
}
int B_right(int *arr,int l,int r,int x){      //bonary search function for descending sorted array.
    if (r>=l){
        int mid=l+(r-l)/2;
        if (*(arr+mid)==x){
            return mid;
        }
        if (*(arr+mid)<x){
            return B_right(arr,l,mid-1,x);
        }
        return B_right(arr,mid+1,r,x);
    }
    return -1;
}
int main(){
    int n;
    printf("enter the number of elements :\n");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for (int i=0;i<n;i++){
        scanf("%d",arr+i);
    }
    printf("the peak is at : %d\n",peak_search(arr,1,n-2));
    printf("enter element for searching :");
    int x;
    scanf("%d",&x);
    printf("right side :%d\n",B_right(arr,peak_search(arr,1,n-2),n-1,x));
    printf("left side :%d\n",B_left(arr,0,peak_search(arr,1,n-1),x));
    return 0;
}
