#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node()
    {
        data = 0;
        next = NULL;
    }
};

class Hash
{
public:
    int size = 10;
    node *chain[10];

    Hash()
    {
        int i;
        for (i = 0; i < size; i++)
            chain[i] = NULL;
    }

    void insert(node *newnode)
    {

        // calculate hash key
        int key = (newnode->data) % size;

        // check if chain[key] is empty
        if (chain[key] == NULL)
            chain[key] = newnode;
        // collision
        else
        {
            // add the node at the end of chain[key].
            node *temp = chain[key];
            while (temp->next)
            {
                temp = temp->next;
            }

            temp->next = newnode;
        }
    }

    void print()
    {
        int i;

        for (i = 0; i < size; i++)
        {
            node *temp = chain[i];
            cout << "chain[" << i << "]-->";
            while (temp)
            {
                cout << temp->data << " -->";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }
};
int main()
{
    int option, Data;
    Hash s;

    while (true)
    {
        cout << "Enter 1 to insert" << endl;
        cout << "Enter 2 to print hash table" << endl;
        cout << "Enter 0 to Exit" << endl;
        cout << "Enter option number : ";
        cin >> option;
        node *n = new node();

        if (option == 1)
        {
            cout << "Enter the value for insert : ";
            cin >> Data;
            //  node* n = new node();
            n->data = Data;
            s.insert(n);
        }

        if (option == 2)
        {
            s.print();
        }

        if (option == 0)
        {
            break;
        }
    }

    return 0;
}