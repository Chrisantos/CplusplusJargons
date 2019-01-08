#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
using namespace std;

template<class eType>
struct nodeType{
    eType info;
    nodeType *link;
};

template<class eType>
class LinkedList
{
    public:
        /*const LinkedList<eType> &operator=(const LinkedList<eType>&);
        LinkedList<eType> operator++(); */
        bool operator==(const LinkedList<eType> &) const;
        bool operator!=(const LinkedList<eType> &) const;

        bool search(const eType&) const;
        bool isEmpty() const;
        void insertNode(const eType&);
        void deleteNode(const eType&);
        void printList() const;
        void printListReverse() const;
        void destroyList();

        LinkedList();
        LinkedList(const LinkedList<eType>&);
        ~LinkedList();
    protected:
        int count;
        nodeType<eType> *first, *last;
    private:
        void copyList(const LinkedList<eType> &);
        void reversePrint(nodeType<eType> *) const;
};

template<class eType>
LinkedList<eType>::LinkedList(){
   first = NULL;
   last = NULL;
   count = 0;
}

template<class eType>
bool LinkedList<eType>::operator==(const LinkedList<eType> &other) const{
    return (first == other.first);
}

template<class eType>
bool LinkedList<eType>::operator!=(const LinkedList<eType> &other) const{
    return (first != other.first);
}

template<class eType>
bool LinkedList<eType>::isEmpty() const{
    return (first == NULL);
}

template<class eType>
bool LinkedList<eType>::search(const eType& item) const{
    nodeType<eType> *current;
    current = first;
    bool found = false;

    while(current != NULL && !found){
        if(current->info == item)
            found = true;
        else
            current = current->link;
    }

    return found;
}

template<class eType>
void LinkedList<eType>::insertNode(const eType& item){
    nodeType<eType> *current, *trailCurrent, *newNode;
    newNode = new nodeType<eType>;
    newNode->info = item;
    newNode->link = NULL;

    bool found;

    if(first == NULL){
        first = newNode;
        last = newNode;
        count++;
    }else{
        current = first;
        found = false;

        while(current != NULL && !found){
            if(current->info >= item)
                found = true;
            else{
                trailCurrent = current;
                current = current->link;
            }

        }

        if(current == first){
            newNode->link = first;
            first = newNode;
            count++;
        }else{
            newNode->link = current;
            trailCurrent->link = newNode;
            if(current == NULL)
                last = newNode;

            count++;
        }

    }

}

template<class eType>
void LinkedList<eType>::deleteNode(const eType& item){
    nodeType<eType> *current, *trailCurrent;
    bool found;

    if(first == NULL)
        cout<<"The linked list is empty!\n";
    else{
        current = first;
        found = false;
        while(current != NULL && !found){
            if(current->info >= item)
                found = true;
            else{
                trailCurrent = current;
                current = current->link;
            }
        }

        if(current == NULL)
            cout<<"The item to be deleted is not in the list\n";

        else{
            if(current->info == item){
                if(current == first){
                    first = first->link;
                    if(first == NULL)
                        last = NULL;
                    delete current;
                }else{
                    trailCurrent->link = current->link;
                    if(current == last)
                        last = trailCurrent;
                    delete current;
                }
                count--;
            }
            else
                cout<<"The item to be deleted is nnot in the list\n";

        }

    }
}

template<class eType>
void LinkedList<eType>::printList() const{
    nodeType<eType> *current;

    if(first == NULL)
        cout<<"The linked list is empty!\n";
    else{
        current = first;
        while(current != NULL){
            cout<<current->info;
            cout<<"\n";

            current = current->link;
        }
    }
}

template<class eType>
void LinkedList<eType>::reversePrint(nodeType<eType> *current) const{

    if(current != NULL){
        reversePrint(current->link);
        cout<<current->info<<endl;
    }
}

template<class eType>
void LinkedList<eType>::printListReverse() const{
    reversePrint(first);
}

template<class eType>
void LinkedList<eType>::destroyList(){
    nodeType<eType> *current;

    if(first == NULL)
        cout<<"The linked list is already empty!\n";
    else{
        while(first != NULL){
            current = first;
            first = first->link;

            delete current;
        }
    }

    last = NULL;
    count = 0;

}

template<class eType>
void LinkedList<eType>::copyList(const LinkedList<eType> &other){
    nodeType<eType> *newNode;
    nodeType<eType> *current;

    if(first != NULL)
        destroyList();

    if(other.first == NULL){
        first = NULL;
        last = NULL;
        count = 0;
    }else{
        current = other.first;
        count = other.count;
        first = new nodeType<eType>;

        first->info = current->info;
        first->link = NULL;
        last = first;
        current = current->link;

        while(current != NULL){
            newNode = new nodeType<eType>;
            newNode->info = current->info;
            newNode->link = NULL;

            last->link = newNode;
            last = newNode;
            current = current->link;
        }
    }
}

template<class eType>
LinkedList<eType>::~LinkedList(){
   destroyList();
}

template<class eType>
LinkedList<eType>::LinkedList(const LinkedList<eType>& other){
    first = NULL;
    copyList(other);
}

#endif // LINKEDLIST_H
