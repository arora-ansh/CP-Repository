class MyLinkedList {
public:
    /** Initialize your data structure here. */
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int a) : val(a), next(nullptr) {}
    };
    
    ListNode *head;
    int size;
    
    MyLinkedList() {
        head = nullptr;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        //printLinkedList();
        if(index<0 || index>=size){
            return -1;
        }
        int i = 0;
        ListNode *temp = head;
        while(i<index){
            temp = temp->next;
            i++;
        }
        return temp->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        if(size==0){
            ListNode *newNode = new ListNode(val);
            head = newNode;
            size++;
            return;
        }
        ListNode *newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        if(size==0){
            ListNode *newNode = new ListNode(val);
            head = newNode;
            size++;
            return;
        }
        ListNode *temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        ListNode *newNode = new ListNode(val);
        temp->next = newNode;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
            return;
        }
        if(index==size){
            addAtTail(val);
            return;
        }
        if(index>size){
            return;
        }
        int i = 0;
        ListNode *temp = head;
        while(i<index-1){
            temp=temp->next;
            i++;
        }
        ListNode *newNode = new ListNode(val);
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if(index>=size){
            return;
        }
        if(index==0){
            head = head->next;
            size--;
            return;
        }
        int i=0;
        ListNode *temp = head;
        while(i<index-1){
            temp = temp->next;
            i++;
        }
        temp->next = temp->next->next;
        size--;
    }
    
    void printLinkedList(){
        cout<<size<<endl;
        ListNode *temp = head;
        while(temp!=nullptr){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
