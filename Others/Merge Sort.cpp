#include<bits/stdc++.h>
using namespace std;
int arr[100000];

void mergeit(int l,int m,int r)   {
    int len1,len2,i,j,k;
    len1= (m-l)+1;
    len2= (r-m);

    int tem1[len1], tem2[len2];
    for(i=0;i<len1;i++) tem1[i]=arr[l+i];
    for(i=0;i<len2;i++) tem2[i]=arr[m+1+i];

    k=l,i=0,j=0;
    while(i<len1&&j<len2)   {
        if(tem1[i]<=tem2[j]) arr[k++] = tem1[i++];
        else  arr[k++] = tem2[j++];
    }

    while(i<len1) arr[k++] = tem1[i++];
    while(j<len2) arr[k++] = tem2[j++];
}

void merge_sort(int lr, int rr) {
    if(lr<rr)   {
        int mid=(lr+rr)/2;
        merge_sort(lr,mid);
        merge_sort(mid+1,rr);

        mergeit(lr,mid,rr);
    }
}


int main() {
    int n; cin>>n;
    for(int i=0;i<n;i++) cin>>arr[i];

    merge_sort(0,n-1);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
