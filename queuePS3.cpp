#include<iostream>
#include<queue>
using namespace std;

int findTop(queue<int> q){
    while(q.size()!=1){
        if(q.size()>1){
            int temp=q.front();
            q.pop();
            q.push(temp);
            q.pop();
        }
    }
    return q.front();
}

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        queue<int> q;
        for(int i=1;i<n+1;i++)
            q.push(i);
        cout<<findTop(q)<<endl;
    }
    return 0;
}