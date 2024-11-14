//
//  lecture14_Node_LL.cpp
//  Copy Constructor, Destructor

#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode():data(0), next(nullptr){}
    ListNode(int iValue):data(iValue), next(nullptr){}
    ListNode(int iData, ListNode * iNext):data(iData), next(iNext){}
    int getData(void) const {return data;}
    ListNode *getNext(void) const {return next;}
    void setData(int newValue) {data = newValue;}
    void setNext(ListNode* newValue) {next = newValue;}
private:
    int data;
    ListNode *next;
};

class LinkedList {
public:
    LinkedList():head(nullptr){}
    LinkedList(ListNode *iHead):head(iHead){}
    LinkedList(const int *arr, int arrSize);
    LinkedList(const LinkedList &orgList);
    
    //TODO: a copy constructor:
    //LinkedList(const LinkedList &orgList);
    
    //TODO: a destructor:
    ~LinkedList();
    
    LinkedList& operator=(const LinkedList &rightOp);

    ListNode *getHead(void) const {
        return head;
    }
    void setHead(ListNode *newHead) {
        head = newHead;
    }
    
    void preAppend(int newValue);
    
    friend ostream& operator<<(ostream &out, const LinkedList &list);
private:
    ListNode *head;
};


//copy constructor
LinkedList::LinkedList(const LinkedList &orgList)
{
    head = nullptr;
    ListNode *orgCursor = orgList.getHead(); //tracking original list
    ListNode *cursor = head;
    
    while (orgCursor != nullptr)
    {
        ListNode *newNode = new ListNode(orgCursor->getData(), nullptr);
        if (head == nullptr)
            head = newNode;
        else
            cursor->setNext(newNode);
        cursor = newNode; //why's this here?
        orgCursor = orgCursor->getNext();
                                         
    }
}

//destructor
LinkedList::~LinkedList()
{
    ListNode* temp = head;
    
    while (head != nullptr)
    {
        temp = head;
        head = head->getNext();
        temp->setNext(nullptr);
        delete temp;
    }
    
}

LinkedList& LinkedList::operator= (const LinkedList &rightOp) {
    //step0: if lefthand operand is the same as righthand operand, return immediately
        if (this == &rightOp) return *this;
    
    //step1: clean up the lefthand list, calling object
       ListNode *cursor;
        
        for (cursor = head; cursor != nullptr;)
        {
            cursor = head->getNext();
            head->setNext(nullptr);
            delete head;
            head = cursor;
        }
    
    //step2: copy every node from righthand list src
        head = cursor = nullptr;
        ListNode *srcCursor = rightOp.head;
        while (srcCursor != nullptr) {
            ListNode *newNode = new ListNode(srcCursor->getData(), nullptr);
            if (head == nullptr) {
                cursor = newNode;
                head = cursor;
            } else {
                cursor->setNext(newNode);
                 cursor = newNode;
            }
            srcCursor = srcCursor->getNext();
        }
    
    //step3: returning the calling object with this pointer
        return *this;
}
 

ostream& operator<<(ostream & out, const LinkedList &list);

int main(int argc, char * argv[])
{
    LinkedList list1;
    list1.preAppend(1);
    list1.preAppend(2);
    list1.preAppend(3);
    
    cout << list1 << endl;
    
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    LinkedList list2(arr, sizeof(arr)/sizeof(int));
    cout << "list2: " << list2 << endl;

    LinkedList copyList(list2);
    list2.getHead()->setData(-1);
    cout << "copyList: " << copyList << endl;

    copyList = list1;
    
    cout << "copy operator = List: " << copyList << endl;

    return 0;
}


ostream& operator<<(ostream & out, const LinkedList &list) {
//void LinkedList::display(void) const {
    ListNode *temp = list.head;
    while (temp != nullptr) {
        out << temp->getData();
        temp = temp->getNext();
        if (temp != nullptr) out << ", ";
    }
    return out;
}

LinkedList::LinkedList(const int *arr, int arrSize) {
    head = nullptr;
    for (int i = arrSize - 1; i >= 0; i--) {
        preAppend(arr[i]);
    }
}

void LinkedList::preAppend(int newValue) {
    ListNode *newNode = new ListNode(newValue, head);
    head = newNode;
}
