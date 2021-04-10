#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Queue{
    int front,rear;
    int size,capacity;
    int* arr;
}Queue;

Queue* createQueue(int capacity){
    Queue* q1=(Queue*)malloc(sizeof(Queue));
    q1->capacity= capacity;
    q1->size=0;
    q1->front=0;
    q1->rear=capacity-1;
    q1->arr=(int*)malloc(sizeof(int)*capacity);
    return q1;
}

int isEmpty(Queue* q1){
    return q1->size==0;
}

int isFull(Queue* q1){
    return q1->size==q1->capacity;
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

int front(Queue* q1){
    if(isEmpty(q1))
        return INT_MIN;
    return q1->arr[q1->front];
}

int rear(Queue* q1){
    if(isEmpty(q1))
        return INT_MIN;
    return q1->arr[q1->rear];
}

void display(Queue* q1){
    for (int i=0; i<q1->size; i++)
    {
        cout<<q1->arr[(q1->front+i)%q1->capacity]<<" ";
    }
    cout<<endl;
}

int main(){
    int capacity;
    cin>>capacity;
    Queue* q1=createQueue(capacity);
    cout<<isEmpty(q1)<<endl;
    for(int i=0;i<capacity;i++)
        enQueue(q1,i);
    cout<<"Front: "<<front(q1)<<endl;
    cout<<"Rear: "<<rear(q1)<<endl;
    cout<<"Is full: "<<isFull(q1)<<endl;
    display(q1);
    cout<<deQueue(q1)<<endl;
    cout<<deQueue(q1)<<endl;
    return 0;
}




