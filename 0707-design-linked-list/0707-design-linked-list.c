

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} MyLinkedList;

MyLinkedList* myLinkedListCreate() {
    MyLinkedList *list = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if(index < 0 || index >= obj->size)
        return -1;

    Node *temp = obj->head;

    while(index--) {
        temp = temp->next;
    }

    return temp->data;
}


void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = obj->head;
    obj->head = newNode;
    obj->size++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if(obj->head == NULL) {
        obj->head = newNode;
    } else {
        Node *temp = obj->head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    obj->size++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    if(index < 0 || index > obj->size)
        return;

    if(index == 0) {
        myLinkedListAddAtHead(obj, val);
        return;
    }

    if(index == obj->size) {
        myLinkedListAddAtTail(obj, val);
        return;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;

    Node *temp = obj->head;

    for(int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    obj->size++;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {

    if(index < 0 || index >= obj->size)
        return;

    Node *temp = obj->head;

    if(index == 0) {
        obj->head = temp->next;
        free(temp);
        obj->size--;
        return;
    }

    for(int i = 0; i < index - 1; i++) {
        temp = temp->next;
    }

    Node *del = temp->next;
    temp->next = del->next;
    free(del);

    obj->size--;
}

void myLinkedListFree(MyLinkedList* obj) {
    Node *temp = obj->head;

    while(temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }

    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/