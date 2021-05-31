class MyCircularQueue {
public:
    vector<int> queue;
    int front;
    int rear; 
    bool reset;
    
    MyCircularQueue(int k) {
        queue.resize(k);
        front = 0;
        rear = 0;
        reset = true;
    }
    
    bool enQueue(int value) {
        // printqueue();
        if(isFull()) return false;
        if(front==rear && reset) reset = false;
        // cout<<reset<<endl;
        queue[rear] = value;
        rear = (rear+1)%queue.size();
        return true;
    }
    
    bool deQueue() {
        // printqueue();
        if(isEmpty()) return false;
        front = (front+1)%queue.size();
        if(front==rear && !reset) reset = true;
        // cout<<reset<<endl;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return queue[front];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return queue[(rear+queue.size()-1)%queue.size()];
    }
    
    bool isEmpty() {
        if(front==rear && reset) return true;
        return false;
    }
    
    bool isFull() {
        if(front==rear && !reset) return true;
        return false;
    }
    
    void printqueue(){
        if(!reset){
            int i = front;
            while(i!=(rear)%queue.size()){
                cout<<queue[i]<<" ";
                i+=1;
                i%=queue.size();
            }
            cout<<endl;
        }
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */