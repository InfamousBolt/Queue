#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverse(queue<int> q1){
    while(!q1.empty())
        cout<<q1.pop()<<" ";
}

int main(){
    int T;
    cin>>T;
    while(T--){
        queue<int> q1;
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            int data;
            cin>>data;
            q1.push(data);
        }
        reverse(q1);
        cout<<endl;
    }
    return 0;
}