#include <iostream>
using namespace std;
class node
{
public:
    int key;
    int data;
    node *next;
    node()
    {
        key = 0;
        data = 0;
        next = NULL;
    }
    node(int k, int d)
    {
        key = k;
        data = d;
        next = NULL;
    }
};
class singlylinkedlist
{
public:
    node *head;
    singlylinkedlist()
    {
        head = NULL;
    }
    singlylinkedlist(node *n)
    {
        head = n;
    }
    node *nodeexist(int k)
    {
        node *temp = NULL;
        node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->key == k)
            {
                temp = ptr;
            }
            ptr = ptr->next;
        }
        return temp;
    }
    void AppendNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "Node already exists at key : " << n->key << " append another node with different key value" << endl;
        }
        else
        {
            if (head == NULL)
            {
                head = n;
            }
            else
            {
                node *ptr = head;
                while (ptr != NULL)
                {
                    ptr = ptr->next;
                }
                ptr->next = n;
                cout << "Node" << endl;
            }
        }
    }
    void PrependNode(Node *n)
    {
        if (nodeExist(n->key) != NULL)
        {
            cout << "Node already exists at key : " << n->key << " append another node with different key value" << endl;
        }

        else
        {
            n->next = head;
            head = n;
            cout << "Node prepended" << endl;
        }
    }
    void InsertNode(int k, Node *n)
    {
        node *ptr = nodeExist(k);
        if (ptr == NULL)
        {
            cout << "No node exists of key value : " << k << endl;
        }

        else
        {
            if (nodeExist(n->key) != NULL)
            {
                cout << "Node already exists at key : " << n->key << " append another node with different key value" << endl;
            }

            else
            {
                n->next = ptr->next;
                ptr->next = n;
                cout << "Node inserted" << endl;
            }
        }
    }
    void DeleteNode(int k)
    {
        if (head == NULL)
        {
            cout << "Linked list is already empty" << endl;
        }

        else if (head != NULL)
        {
            if (head->key == k)
            {
                head = head->next;
                cout << "Head Node deleted" << endl;
            }
            else
            {
                node *temp = NULL;
                node *prevptr = head;
                node *currentptr = head->next;

                while (currentptr != NULL)
                {
                    if (currentptr->key == k)
                    {
                        temp = currentptr;
                        currentptr = NULL;
                    }
                    else
                    {
                        prevptr = prevptr->next;
                        currentptr = currentptr->next;
                    }
                }
                if (temp != NULL)
                {
                    prevptr->next = temp->next;
                    cout << "Node deleted present at key value : " << k << endl;
                }
                else
                {
                    cout << "Node not found at key value : " << k << endl;
                }
            }
        }
    }
    void UpdateNode(int k, int d)
    {
        node *ptr = nodeExist(k);
        if (ptr != NULL)
        {
            ptr->data = d;
            cout << "Data updated" << endl;
            cout << "ptr->data = " << ptr->data << endl;
        }
        else
        {
            cout << "Node not found with key value : " << k << endl;
        }
    }
    void PrintList(){
            if(head==NULL){
                cout<<"No node is available to form a LINKED LIST \n";
            }
            else{
                node *temp = head;
                while(temp!=NULL){
                    cout<<"("<<temp->key<<", "<<temp->data<<")"<<"--->";
                    temp = temp->next;
                }
            }
        }
};
int main()
{
    node* n1 = new node(1,10);
    node* n2 = new node(2,20);
    singlylinkedlist s;
    s.AppendNode(n1);
    s.AppendNode(n2);
    s.PrintList();
    return 0;
}