#include "LinkedList.h"

/*template<class eType>
LinkedList<eType>::LinkedList()
{
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

        if(first->info > item){
            newNode->link = first;
            first = newNode;
        }else{
            while(current != NULL && !found){
                if(current->info > item){
                    trailCurrent = current;
                    current = current->link;
                }else
                    found = true;

            }

            if(found){
                newNode->link = current;
                trailCurrent->link = newNode;
                if(current == NULL)
                    last = newNode;

                count++;
            }

        }
    }

}

template<class eType>
void LinkedList<eType>::deleteNode(const eType& item){
    nodeType<eType> *current, trailCurrent;
    bool found;

    if(first == NULL)
        cout<<"The linked list is empty!\n";
    else{
        current = first;
        found = false;
        while(current != NULL && !found){
            if(current->info != item){
                trailCurrent = current;
                current = current->link;
            }
            else
                found = true;
        }

        if(found){
            if(current == first){
                first = first->link;
                if(first == NULL)
                    last = NULL;
                delete current;
                count--;
            }else{
                trailCurrent->link = current->link;
                if(current == last)
                    last = trailCurrent;
                delete current;

                count--;
            }
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
*/













