#include <iostream>
#include <conio.h>
#include <algorithm>
#include "Node.h"
using namespace std;

typedef int T;
#define CMP_GT(a, b) ((a) > (b))
#define CMP_LT(a, b) ((a) < (b))

// префиксная форма
void showPref(Node*& Tree)
{   
	if (Tree != NULL)
	{
        cout << Tree->x << " ";
        showPref(Tree->l);
        showPref(Tree->r);
	}
}

// постфиксная форма
void showPost(Node*& Tree)
{
    if (Tree != NULL)
    {     
        showPost(Tree->l);
        showPost(Tree->r);
        cout << Tree->x << " ";
    }
}

// инфиксная форма
void showInf(Node*& Tree)
{
    if (Tree != NULL)
    {
        showInf(Tree->l);
        cout << Tree->x << " ";
        showInf(Tree->r);
    }
}

// вывод вместе с уровнями
void printTree(Node* root, const char* dir, int level) 
{
    if (root) 
    {
        printf("lvl %d %s = %d\n", level, dir, root->x);
        printTree(root->l, "l", level + 1);
        printTree(root->r, "r", level + 1);
    }
}

void add_node(int x, Node*& MyTree)
{
    if (NULL == MyTree)
    {
        MyTree = new Node;
        MyTree->x = x;
        MyTree->l = MyTree->r = NULL;
    }

    if (x < MyTree->x)   //Если нововведенный элемент x меньше чем элемент x из семечка дерева, уходим влево
    {
        if (MyTree->l != NULL) 
            add_node(x, MyTree->l); //При помощи рекурсии заталкиваем элемент на свободный участок
        else
        {
            MyTree->l = new Node;
            MyTree->l->l = MyTree->l->r = NULL;
            MyTree->l->x = x;
        }
    }

    if (x > MyTree->x)
    {
        if (MyTree->r != NULL) 
            add_node(x, MyTree->r);
        else
        {
            MyTree->r = new Node;
            MyTree->r->l = MyTree->r->r = NULL;
            MyTree->r->x = x;
        }
    }
}

/*Добавили очистку памяти*/
void del(Node*& Tree) 
{
    if (Tree != NULL)
    {
        del(Tree->l);
        del(Tree->r);
        delete Tree;
        Tree = NULL;
    }
}

Node* getMinNode(Node* root) 
{
    while (root->l) 
    {
        root = root->l;
    }
    return root;
}

Node* getMaxNode(Node* root) 
{
    while (root->r) {
        root = root->r;
    }
    return root;
}

Node* getNodeByValue(Node* root, T value) 
{
    while (root) 
    {
        if (CMP_GT(root->x, value)) 
        {
            root = root->l;
            continue;
        }
        else if (CMP_LT(root->x, value)) 
        {
            root = root->r;
            continue;
        }
        else 
        {
            return root;
        }
    }
    return NULL;
}

int main()
{
    Node* Tree = NULL;
    int ElemInTree, CountNodes, userCommand = 'Y';

    /*Tree #1*/
    for (int i = 25; i > 0; i--) add_node(rand() % 150, Tree);

    /*SHOW TREE*/
    cout << "Infix form\n";
    showInf(Tree);
    cout << "\nPostfix form\n";
    showPost(Tree);
    cout << "\nPrefix form\n";
    showPref(Tree);
    cout << "\nOur print\n";
    printTree(Tree, "root", 0);

    cout << "\nMin elem - " << getMinNode(Tree)->x;
    cout << "\nMax elem - " << getMaxNode(Tree)->x;
    cout << "\nEnter elem, which you want to find: "; cin >> ElemInTree;
    cout << "\nGet Node by value - " << getNodeByValue(Tree, ElemInTree);
    del(Tree);
    cout << "\nDelete was succeeded" << endl << endl;

    system("pause");

    /*Tree #2*/
    system("cls");
    while (userCommand == 'Y' || userCommand == 'y')
    {
        do {
            cout << "Enter count nodes: "; cin >> CountNodes;
        } while (CountNodes <= 0);

        for (int i = 0; i < CountNodes; i++)
        {
            do {
                cout << "Enter elem: "; cin >> ElemInTree;
            } while (ElemInTree <= 0);
         
            add_node(ElemInTree, Tree);
        }

        /*SHOW TREE*/
        cout << "Infix form\n";
        showInf(Tree);
        cout << "\nPostfix form\n";
        showPost(Tree);
        cout << "\nPrefix form\n";
        showPref(Tree);
        cout << "\nOur print\n";
        printTree(Tree, "root", 0);

        cout << "\nMin elem - " << getMinNode(Tree)->x;
        cout << "\nMax elem - " << getMaxNode(Tree)->x;
        cout << "\nEnter elem, which you want to find: "; cin >> ElemInTree;
        cout << "\nGet Node by value - " << getNodeByValue(Tree, ElemInTree);
        del(Tree);
        cout << "\nDelete was succeeded" << endl << endl;

        cout << "\n\nDo you want to continue (Y/y)? \nYour choise >>> "; cin >> userCommand;
    }

    cout << "\nExit from programm..." << endl;
    system("pause");
    return 0;
}