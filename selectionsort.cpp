#include <bits/stdc++.h>
using namespace std;

void selsort(vector<int> &v){
    int n = v.size();
    for(int i=0;i<n-1;i++){
        int mi = i;
        for(int j = i+1;j<n;j++){
            if(v[j]<v[mi]){
                mi = j;
            }
        }
        swap(v[i],v[mi]);
    }
}

int main(){
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter all the elements: ";
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    selsort(v);
    cout<<"Sorted array: "<<endl;
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}