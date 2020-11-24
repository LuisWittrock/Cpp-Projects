#include <iostream>

using namespace std;

class Node
{
public:
    Node()
    {
        head = NULL;
    }

    int data;
    Node *next;

    int get(int index);
    void addHead(int val);
    void addTail(int val);
    void addAtIndex(int val);
    void deleteAtIndex(int index);
    void addAtIndex(int val, int index);
    void reverse();
    void display();

private:
    Node *head;
};

int Node::get(int index) //gibt Node mit index 'index' zurück.
{
    Node *curr = new Node();
    bool found = true;

    if (head == NULL)
    {
        cout << "List is empty \n";
    }
    else
    {
        curr = head;
        for (int i = 0; i < index; i++)
        {
            curr = curr->next;

            if (curr == NULL)
            {
                cout << "Index out of range";
                found = false;
                break;
            }
        }
        if (found)
        {
            return curr->data;
        }
    }
};
void Node::addHead(int val) //packt eine Node an den anfang
{
    Node *newHead = new Node();

    newHead->data = val;
    newHead->next = head;
    head = newHead;
};
void Node::addTail(int val) //packt eine Node ans Ende
{
    Node *newNode = new Node();

    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node *tmp = new Node();
        tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        tmp->next = newNode;
    }
};
void Node::addAtIndex(int val, int index) //packt einen Node mit wert "val" an den Index "index"
{
    Node *prev = new Node();
    Node *newNode = new Node();
    Node *tmp = new Node();
    int counter = 0;

    newNode->data = val;
    tmp = head;
    prev = head;
    tmp = tmp->next;

    while (tmp->next != NULL)
    {
        if (counter == index - 1)
        {
            newNode->next = tmp;
            prev->next = newNode;
            break;
        }
        prev = prev->next;
        tmp = tmp->next;
        counter++;
    }
};
void Node::deleteAtIndex(int index) //löscht node an index 'index'
{
    Node *end = new Node();
    Node *prev = new Node();
    int counter = 0;

    end = head;
    prev = head;

    if (index == 0)
    {

        end = end->next;
        head = end;
    }
    else if (head != NULL)
    {
        end = end->next;
        end = end->next;
        while (end->next != NULL)
        {
            if (counter == index - 1)
            {
                prev->next = end;
            }
            prev = prev->next;
            end = end->next;
            counter++;
        }
    }
};
void Node::reverse() //dreht die list um a->b->c = c->b->a.
{
    Node *tmp = new Node();
    Node *prev = NULL;
    Node *end = NULL;
    tmp = head;

    while(tmp != NULL)
    {
        head = tmp;
        end = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = end;
    }

   
};
void Node::display() //zeigt die gesamte liste an.
{
    Node *tmp = new Node();
    
    if(head == NULL)
    {

    }
    else
    {
        tmp = head;
        while (tmp->next != NULL)
        {
        cout << tmp->data << "->";
        tmp = tmp->next;
        }
        cout << " NULL";
    }
    
   
};

int main()
{
    Node *list = new Node();
    list->display();
    delete list;
}