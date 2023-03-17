#include<iostream>
#define SPACE 10
using namespace std;
class TreeNode {
  public:
    int value;
  TreeNode * left;
  TreeNode * right;

  TreeNode() {
    value = 0;
    left = NULL;
    right = NULL;
  }
  TreeNode(int v) {
    value = v;
    left = NULL;
    right = NULL;
  }
};

class BST {
  public:
    TreeNode * root;
  BST() {
    root = NULL;
  }

  bool isTreeEmpty() {
    if (root == NULL) {
      return true;
    } else {
      return false;
    }
  }

  void insertNode(TreeNode * new_node) {
    if (root == NULL) {
      root = new_node;
      cout << "Value Inserted as root node!" << endl;
    } else {
      TreeNode * temp = root;
      while (temp != NULL) {
        if (new_node -> value == temp -> value) {
          cout << "Value Already exist," <<
            "Insert another value!" << endl;
          return;
        }
        else if ((new_node -> value < temp -> value) && (temp -> left == NULL)) {
          temp -> left = new_node;
          cout << "Value Inserted to the left!" << endl;
          break;
        }
         else if (new_node -> value < temp -> value) {
          temp = temp -> left;
        }
         else if ((new_node -> value > temp -> value) && (temp -> right == NULL)) {
          temp -> right = new_node;
          cout << "Value Inserted to the right!" << endl;
          break;
        }
         else {
          temp = temp -> right;
        }
      }
    }
  }

  void printPreOrder(TreeNode* n){
    if(n==NULL){
      return;
    }
    cout<<n->value<<" ";
    printPreOrder(n->left);
    printPreOrder(n->right);
  }

  void printInOrder(TreeNode* n){
    if(n==NULL){
      return;
    }
    printInOrder(n->left);
    cout<<n->value<<" ";
    printInOrder(n->right);
  }

  void printPostOrder(TreeNode* n){
    if(n==NULL){
      return;
    }
    printPostOrder(n->left);
    printPostOrder(n->right);
    cout<<n->value<<" ";
  }

  void print2D(TreeNode * r, int space) {
    if (r == NULL) // Base case  1
      return;
    space += SPACE; // Increase distance between levels   2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> value << "\n"; // 6
    print2D(r -> left, space); // Process left child  7
  }

  TreeNode* binarySearch(int val){
    if(root==NULL){
      return root;
    }
    else{
      TreeNode* temp=root;
      while(temp!=NULL){
        if(temp->value==val){
          return temp;
          break;
        }
        else if(temp->value<val){
          temp=temp->left;
        }
        else if(temp->value>val){
          temp= temp->right;
        }
      }

      return NULL;
    }
  }

  int treeHeight(TreeNode* n){
    if(n==NULL){
      return -1;
    }
    else{
      int lHeight = treeHeight(n->left);
      int rHeight = treeHeight(n->right);

      if(lHeight>rHeight){
        return (lHeight+1);
      }
      else{
        return (rHeight +1);
      }
    }
  }

  TreeNode* deleteNode(TreeNode* r, int v){
    // the three checks for traversing to the node passed in the parameter as v
    if(r==NULL){
      return r;
    }


    else if(v<r->value){
      r->left= deleteNode(r->left,v);
    }

    else if(v>r->value){
      r->right= deleteNode(r->right,v);
    }

    // nopw checking the conditions (for leaf node), (for 1 child), (for 2 child)

    else{
      // node with only right child of
      // node with no child
      
      if(r->left==NULL){
        TreeNode* temp=r->right;
        delete r;
        return temp;
      }

      // node with only left child 
     else if (r -> right == NULL) {
        TreeNode * temp = r -> left;
        delete r;
        return temp;
        
      } else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        TreeNode * temp = minValue(r -> right);
        // Copy the inorder successor's content to this node 
        r -> value = temp -> value;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> value);
        //deleteNode(r->right, temp->value); 
      }
    
    return r;
  }



}
  

  TreeNode* minValue(TreeNode* node){
    TreeNode* current = node;
    while (current!=NULL)
    {
      current=current->left;
    }
    return current;
  
  }


};



int main() {
  BST obj;
  int option, val;
    
    TreeNode* n =  new TreeNode();
    return 0;
}