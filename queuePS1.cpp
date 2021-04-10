#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Queue{
    int front,rear;
    int size,capacity;
    int* arr;
}Queue;

int isEmpty(Queue* q1){
    return q1->size==0;
}

int isFull(Queue* q1){
    return q1->size==q1->capacity;
}

Queue* createQueue(int capacity){
    Queue* q1=(Queue*)malloc(sizeof(Queue));
    q1->capacity= capacity;
    q1->size=0;
    q1->front=0;
    q1->rear=capacity-1;
    q1->arr=(int*)malloc(sizeof(int)*capacity);
    return q1;
}
void enQueue(Queue* q1, int item){
    if(isFull(q1)){
        cout<<"The queue is full\n";
        return;
    }
    q1->rear=(q1->rear+1)%q1->capacity;
    q1->arr[q1->rear]=item;
    q1->size++;
}

int deQueue(Queue* q1){
    if(isEmpty(q1)){
        cout<<"The queue is empty\n";
        return INT_MIN;
    }
    int temp=q1->arr[q1->front];
    q1->front=(q1->front+1)%q1->capacity;
    q1->size--;
    return temp;
}

void display(Queue* q1){
    for (int i=0; i<q1->size; i++)
        cout<<q1->arr[(q1->front+i)%q1->capacity]<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    Queue* q1=createQueue(n);
    for(int i=0;i<n;i++){
        enQueue(q1,arr[i]);
        display(q1);
    }
    for(int i=0;i<n;i++){
        deQueue(q1);
        display(q1);
    }
    return 0;
}