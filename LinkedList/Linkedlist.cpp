/**************************************
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

/****************************************
 * @method : addToList
 * @description : This function will be
 * used to add new element to the list
 *
*****************************************/
void Slist::addToList(int data)
{
    Node* temp = new Node;
    if(head == NULL)
    {
        temp->data = data;
        temp->nextNode = NULL;
        head = temp;
        tail = temp;
    }
    else
    {
        head->nextNode = temp;
        temp->data = data;
        temp->nextNode = NULL;
        head = temp;
    }
}

/****************************************
 * @method : displayListData
 * @description : This function will
 * display element of the list.
 *
****************************************/
void Slist::displayListData()
{
    Node* temp = new Node;
    unsigned int index = 1U;
    std::cout<<"          Disply List elements"<<std::endl;

    if(tail != NULL)
    {
        std::cout<<"          "<<tail->data<<"    ";
        temp = tail->nextNode;
        while(temp != NULL)
        {
            std::cout<<temp->data<<"    ";
            temp = temp->nextNode;
            index++;
            if(index == 10u)
            {
                std::cout<<"\n          ";
                index = 0U;
            }
        }
    }
    else
    {
        std::cout<<"          There are no List elements"<<std::endl;
    }

    std::cout<<std::endl;
}

/***************************************
 * @method : removeFrmList
 * @description : This function will
 * remove all the elements which are
 * matched with the passed data value
 *
***************************************/
void Slist::removeFrmList(int data)
{
    if(tail != NULL)
    {
        Node* tempCurr = new Node;
        Node* tempNext = new Node;
        Node* tempPrev = new Node;
        tempCurr = tail;
        tempNext = tail->nextNode;
        tempPrev = NULL;
        if((tempNext == NULL) && (data == tempCurr->data))
        {
            tail = NULL;
            head = NULL;
        }
        else
        {
            while(tempCurr != NULL)
            {
                tempNext = tempCurr->nextNode;
                if((data == tempCurr->data) && (NULL != tempCurr->nextNode))
                {
                    if(tempCurr == tail)
                    {
                        tail = tempCurr->nextNode;
                        tempCurr = tail;
                    }
                    else
                    {
                        tempPrev->nextNode = tempNext;
                        tempCurr = tempPrev->nextNode;
                        tempNext = tempCurr->nextNode;
                    }
                }
                else if((data == tempCurr->data) && (NULL == tempCurr->nextNode))
                {
                    if(tempCurr == tail)
                    {
                        tail = NULL;
                        head = NULL;
                        tempCurr = NULL;
                    }
                    else
                    {
                        tempPrev->nextNode = NULL;
                        tempCurr = tempPrev->nextNode;
                    }
                }
                else
                {
                    tempPrev = tempCurr;
                    tempCurr = tempCurr->nextNode;
                }
            }
        }
    }
    else
    {

    }
}

/***************************************
 * @method : removeFrmList
 * @description : This function will
 * remove all the elements which are
 * matched with the passed data value
 *
***************************************/
unsigned int Slist::countListData()
{
    unsigned int listNum = 0u;
    Node* temp = new Node;
    temp = tail;
    while(temp != NULL)
    {
        listNum++;
        temp = temp->nextNode;
    }
    return listNum;
}


/***************************************
 * @main
 *
***************************************/
int main()
{
    std::cout<<"----------Singly Linked List program----------\n"<<std::endl;
    Slist* Ls1 = new Slist;
    unsigned int i;

    //Add data to List
    for(i = 1u; i <= 100u; i++)
    {
        Ls1->addToList(100U);
    }
    std::cout<<"          after AddtoList\n";

    Ls1->displayListData();
    std::cout<<"          Number of List elements "<<Ls1->countListData()<<std::endl;

    //Remove data to list
    std::cout<<"          after removingFrmList\n";

    Ls1->removeFrmList(100);

    Ls1->displayListData();
    std::cout<<"          Number of List elements "<<Ls1->countListData()<<std::endl;

    std::cout<<"----------Singly Linked List program----------\n"<<std::endl;
}
/***************************************
 *@end
 
***************************************/