#include <cstdio>
#include <cstring>
#include <cstdlib>

// The node class for the linked list
class MyNode
{
 private:
  int elem;
  char* str;
  MyNode* next;

 public:
  MyNode (int v1) {
    elem = v1;
    next = NULL;
  }

  MyNode (char* name) {
    str = name;
    next = NULL;
  }

  MyNode (char* name, MyNode* n) {
    str = name;
    next = n;
  }

  MyNode (int v1, MyNode* n){
    elem = v1;
    next = n;
  }

  void setElem (int e)
    {elem = e;}

  int getElem ()
    {return elem;}

  void setNext (MyNode* n)
    {next = n;}

  MyNode* getNext()
    {return next;}

  char* getStr()
    {return str; }

  void setStr(char* name)
    {str = name;}
};

// the list class for the linked list
class MyList
{
 private:
  MyNode* head;

 public:
  MyList()
    {head = nullptr;}

  bool isEmpty() {
    if(head == nullptr)
        return true;
    return false;
  }

  void insert2(int x) {
      MyNode* tmp = new MyNode (x);

      MyNode* curr = head;
      MyNode* prev = NULL;
      while(curr!=nullptr && curr->getElem() < x) {
        prev = curr;
        curr = curr->getNext();
      }
      tmp->setNext(curr);
      if(prev == NULL)
        head = tmp;
      else
        prev->setNext(tmp);
  }

  void remove2(int x) {
    MyNode *p, *tmp;

    if(head == nullptr)
        return;
    if(head->getElem() == x) {
        tmp = head;
        head = head->getNext();
        delete tmp;
        return;
    }
    p = head;
    while(p->getNext() != nullptr) {
        if(x == p->getNext()->getElem()) {
            tmp = p->getNext();
            p->setNext(tmp->getNext());
            delete tmp;
            return;
        }
        p = p->getNext();
    }
  }

  void print2() {
    MyNode* tmp = head;
    while(tmp!=nullptr){
        printf("%d, ", tmp->getElem());
        tmp = tmp->getNext();
    }
  }

  bool contains2(int x) {
    MyNode* tmp = head;
      while(tmp != NULL){
        if(tmp->getElem() == x)
            return true;
        tmp = tmp->getNext();
      }
      return false;
  }

  bool containsName(char* name) {
    MyNode* tmp = head;
    while(tmp != NULL) {
       if(strcmp(tmp->getStr(), name) == 0)
            return true;
       tmp = tmp->getNext();
    }
    return false;
  }

  void addName(char* name){
      MyNode* tmp = new MyNode(name, head);
      head = tmp;
  }

  void removeName(char* name){
      MyNode *p, *tmp;

    if(head == nullptr)
        return;
    if(head->getStr() == name) {
        tmp = head;
        head = head->getNext();
        delete tmp;
        return;
    }
    p = head;
    while(p->getNext() != nullptr) {
        if(name == p->getNext()->getStr()) {
            tmp = p->getNext();
            p->setNext(tmp->getNext());
            delete tmp;
            return;
        }
        p = p->getNext();
    }
  }

  void push(int x) {
    MyNode* tmp = new MyNode (x);
    if(head == nullptr)
        head = tmp;
    else {
        MyNode *p = head;
        while(p->getNext() != nullptr)
            p = p->getNext();
        p->setNext(tmp);
    }
  }

  void pushFront(int x) {
    MyNode* tmp = new MyNode (x);
    if(head == nullptr)
        head = tmp;
    else{
        tmp->setNext(head);
        head = tmp;
    }
  }

  int popFront() {
    int x = head->getElem();
    head = head->getNext();
    return x;
  }
};
