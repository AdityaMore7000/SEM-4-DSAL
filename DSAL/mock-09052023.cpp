
/*

Create an inordered threaded binary search tree. Perform inorder, preorder
traversals without recursion and deletion of a node. Analyze time and space
complexity of the algorithm.

*/

#include <iostream>
using namespace std;
class Node
{
    int data;
    Node *left;
    Node *right;
    bool tleft;
    bool tright;

public:
    friend class TBS;
    Node(int x = 0)
    {
        data = x;
        left = NULL;
        right = NULL;
        tleft = false;
        tright = false;
    }
};
class TBS
{
    Node *root;

public:
    TBS()
    {
        root = NULL;
    }
    Node *insert(int val)
    {
        Node *ptr = root;
        Node *parent = NULL;
        while (ptr != NULL)
        {
            if (val == ptr->data)
            {

                cout << "\nDuplicate key";
                return root;
            }

            parent = ptr;

            if (val < ptr->data)
            {

                if (ptr->tleft == false)
                {

                    ptr = ptr->left;
                }

                else
                {

                    break;
                }
            }

            else
            {

                if (ptr->tright == false)
                {

                    ptr = ptr->right;
                }

                else
                {

                    break;
                }
            }
        }
        Node *nn = new Node(val);
        nn->data = val;
        nn->tleft = true;
        nn->tright = true;
        if (parent == NULL)
        {
            root = nn;
            nn->left = NULL;
            nn->right = NULL;
        }
        else if (val < parent->data)
        {
            nn->left = parent->left;
            nn->right = parent;
            parent->tleft = false;
            parent->left = nn;
        }
        else
        {
            nn->left = parent;
            nn->right = parent->right;
            parent->tright = false;
            parent->right = nn;
        }
        return root;
    }
    Node *leftMost(Node *temp)
    {
        if (temp == NULL)
        {
            return NULL;
        }
        while (temp->tleft == false && temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    Node *inorder_succ(Node *temp)
    {
        if (temp->tright == true)
        {
            return temp->right;
        }
        else
        {
            temp = temp->right;
            while (temp->tleft == false)
            {
                temp = temp->left;
            }
            return temp;
        }
    }
    Node *inorder_pre(Node *temp)
    {
        if (temp->tleft == true)
        {
            return temp->left;
        }
        temp = temp->left;
        while (temp->tright == false)
        {
            temp = temp->right;
        }
        return temp;
    }
    void inorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
        }
        else
        {
            Node *temp = leftMost(root);
            while (temp != NULL)
            {
                cout << temp->data << " ";
                if (temp->tright == true)
                {
                    temp = temp->right;
                }
                else
                {
                    temp = temp->right;
                    temp = leftMost(temp);
                }
            }
        }
    }
    void preorder()
    {
        if (root == NULL)
        {
            cout << "Tree is empty";
        }
        else
        {
            Node *ptr = root;
            while (ptr != NULL)
            {
                cout << ptr->data << " ";
                if (ptr->tleft == false)
                {
                    ptr = ptr->left;
                }
                else if (ptr->tright == false)
                {
                    ptr = ptr->right;
                }
                else
                {
                    while (ptr != NULL && ptr->tright == true)
                    {
                        ptr = ptr->right;
                    }
                    if (ptr != NULL)
                    {
                        ptr = ptr->right;
                    }
                }
            }
        }
    }
    Node *case1(Node *parent, Node *current)
    {
        if (parent == NULL)
        {
            root = NULL;
        }
        else if (current == parent->left)
        {
            parent->tleft = true;
            parent->left = current->left;
        }
        else
        {
            parent->tright = true;
            parent->right = current->right;
        }
        free(current);
        return root;
    }
    Node *case2(Node *parent, Node *current)
    {
        Node *child = NULL;
        if (current->tleft == false)
        {
            child = current->left;
        }
        else
        {
            child = current->right;
        }
        if (parent == NULL)
        {
            root = child;
        }
        else if (current == parent->left)
        {
            parent->left = child;
        }
        else
        {
            parent->right = child;
        }
        Node *s = inorder_succ(current);
        Node *p = inorder_pre(current);
        if (current->tleft == false)
        {
            p->right = s;
        }
        else if (current->tright == false)
        {
            s->left = p;
        }
        free(current);
        return root;
    }
    Node *case3(Node *parent, Node *current)
    {
        Node *parsucc = current;
        Node *succ = current->right;
        while (succ->tleft == false)
        {
            parsucc = succ;
            succ = succ->left;
        }
        current->data = succ->data;
        if (succ->tleft == true && succ->tright == true)
        {
            root = case1(parsucc, succ);
        }
        else
        {
            root = case2(parsucc, succ);
        }
        return root;
    }
    Node *delete_node(int val)
    {
        Node *parent = NULL;
        Node *current = root;
        int found = 0;
        while (current != NULL)
        {
            if (val == current->data)
            {
                found = 1;
                break;
            }
            parent = current;
            if (val < current->data)
            {
                if (current->tleft == false)
                {
                    current = current->left;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (current->tright == false)
                {
                    current = current->right;
                }
                else
                {
                    break;
                }
            }
        }
        if (found == 0)
        {
            cout << "\nValue is not present in the tree";
        }
        else if (current->tleft == false && current->tright == false)
        {
            root = case3(parent, current);
        }
        else if (current->tleft == false)
        {
            root = case2(parent, current);
        }
        else if (current->tright == false)
        {
            root = case2(parent, current);
        }
        else
        {
            root = case1(parent, current);
        }
        return root;
    }
};
int main()
{
    TBS obj;
    int n, flag = 1, ele, ins, del, choice, t;
    cout << "\nEnter total no. of elements to create a threaded BST: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "\nEnter the element: ";
        cin >> ele;
        obj.insert(ele);
    }
    cout << "\n\nBinary Tree is(inorder traversal): ";
    obj.inorder();
    while (flag == 1)
    {
        cout << "\n\nEnter 1 to insert node in TBST\nEnter 2 to print inorder and preorder traversal in TBST\nEnter 3 to delete node from TBST\n\n";
        cin >> choice;
        if (choice == 1)
        {
            cout << "\n\nEnter the node to be inserted in TBST: ";
            cin >> ins;
            obj.insert(ins);
            cout << "\n\nBinary Tree is(inorder traversal): ";
            obj.inorder();
        }
        else if (choice == 2)
        {
            cout << "\n\nInorder traversal Binary Search Tree is: ";
            obj.inorder();
            cout << "\n\nPreorder traversal Binary Search Tree is: ";
            obj.preorder();
        }
        else if (choice == 3)
        {
            cout << "\n\nEnter the node to be deleted: ";
            cin >> del;
            obj.delete_node(del);
            cout << "\n\nBinary Tree is(inorder traversal): ";
            obj.inorder();
        }
        else
        {
            cout << "\n\n\nInvalid choice";
        }
        cout << "\n\n\nDO YOU WANT TO CONTINUE?(1/0)" << endl;
        cin >> t;
        if (t == 1)
        {
            continue;
        }
        else
        {
            cout << "\nThank you!!!" << endl;
            break;
        }
    }
    return 0;
}
