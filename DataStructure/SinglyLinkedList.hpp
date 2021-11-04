/**************************************
 * CPP-Projects : SinglyLinkedList.hpp
 * This is a singly linked list program
 *
 * @author : https://github.com/Pavanbk7
***************************************/

/**************************************
 * Header files
 *************************************/
#include<iostream>

/***************************************
 *@structure : Node
 *
***************************************/
struct Node
{
    int data;
    Node* nextNode;
};

/***************************************
 *@class : Singly linked Class
 *
****************************************/
class Slist
{
    public:
        Slist()
        {
            head = NULL;
            tail = NULL;
        }
        void addToList(int data);
        void removeFrmList(int data);
        unsigned int countListData();
        void displayListData();
        void sortList(char sorttype);

    private:
        Node* head;
        Node* tail;
};

/***************************************
 * @function : SinglyLinkedListMain
 * @description : Singly Linked List
 *
***************************************/
extern void SinglyLinkedListMain();

/***************************************
 * end
 *
***************************************/