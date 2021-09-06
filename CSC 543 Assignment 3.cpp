#include<iostream>
using namespace std;

//When I was attempting to write this from scratch and jog my memory of linked lists, about half way through I ended up finding the exact solution to the implementation.
//Once I saw it I couldn't unsee it so my solution ended up looking pretty much the same since I barely use linked lists in the first place.
//At the very least, I understand it completely now.
struct Node
{
    int rows;
    int columns;
    int value;
    struct Node* next;
};

void createNode(Node** head, int row, int column, int value)
{
    Node* newNode = *head;
    Node* node;

    if (newNode == NULL)
    {
        newNode = new Node();
        newNode->rows = row;
        newNode->columns = column;
        newNode->value = value;
        newNode->next = NULL;
        *head = newNode;
    }
    else
    {
        while (newNode->next != NULL) 
        {
            newNode = newNode->next;
        }
            
        node = new Node();
        node->rows = row;
        node->columns = column;
        node->value = value;
        node->next = NULL;
        newNode->next = node;
    }
}

void printList(Node* start)
{
    Node* current = start;

    while (current != NULL)
    {
        cout << current->rows << " ";
        current = current->next;
    }
    cout << endl;

    current = start;
    while (current != NULL)
    {
        cout << current->columns << " ";
        current = current->next;
    }
    cout << endl;

    current = start;

    while (current != NULL)
    {
        cout << current->value << " ";
        current = current->next;
    }
}

int main()
{
    //Sample set
    const int sampleRow = 4, sampleColumn = 5;
    int badMatrix[sampleRow][sampleColumn] =
    {
        {0 , 0 , 3 , 0 , 4 },
        {0 , 0 , 5 , 7 , 0 },
        {0 , 0 , 0 , 0 , 0 },
        {0 , 2 , 6 , 0 , 0 }
    };

    Node* first = NULL;
    for (int i = 0; i < sampleRow; i++)
    {
        for (int j = 0; j < sampleColumn; j++)
        {
            if (badMatrix[i][j] != 0) 
            {
                createNode(&first, i, j, badMatrix[i][j]);
            }
        }
    }
    printList(first);

    return 0;
}