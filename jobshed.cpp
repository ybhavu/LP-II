#include <bits/stdc++.h>
using namespace std;

struct Job{
    char id;
    int dead;
    int profit;
};

bool comparison(Job a, Job b){
    return (a.profit>b.profit);
}

void Jobshed(vector<Job> v,int n){
    sort(v.begin(),v.end(),comparison);

    vector<int> res(n);
    vector<bool> slot(n,false);

    for(int i=0;i<n;i++){
        for(int j = min(n,v[i].dead) - 1;j>=0;j--){
            if(slot[j] == false){
                res[j] = i;
                slot[j] = true;
                break;

            }
        }
    }

    for(int i=0;i<n;i++){
        if(slot[i]){
            cout<<v[res[i]].id<<" ";
        }
    }
    cout<<endl;

}

int main(){
    int n;
    cout<<"Enter number of Jobs: ";
    cin>>n;
    cout<<"ENter job id, deadline, profit\n";
    vector<Job> v;
    for(int i=0;i<n;i++){
        char id;
        int dead;
        int pr;
        cin>>id>>dead>>pr;
        v.push_back({id,dead,pr});
    }

    cout<<"Sequence will be as follows \n";
    Jobshed(v,n);
    return 0;
}