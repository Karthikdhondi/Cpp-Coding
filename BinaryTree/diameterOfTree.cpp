 #include<iostream>
#include<queue>
#include "BinaryTreeNode.h"
using namespace std;



void printBinaryTree(BinaryTreeNode<int>* root){
    //Base case.............In Genric Trees we had edge case but not base case.
    if(root == NULL){
        return;
    }
    //printing LevelWise using queue.
    queue<BinaryTreeNode<int>*> printRoot;
    printRoot.push(root);

    while(printRoot.size() != 0){
        BinaryTreeNode<int>* front = printRoot.front();
        printRoot.pop();
        cout << front->data << ":";
        if(front->left != NULL ){
            printRoot.push(front->left);
            cout<<"L" << front->left->data << "," ;
        }
        if(front->right != NULL ){
            printRoot.push(front->right);
            cout << "R" << front->right->data ;
        }
        cout<< endl;

    }


    // cout << root->data << ":" ;
    // if(root->left != NULL){
    //     cout<<"L" << root->left->data << "," ;
    // }
    // if(root->right != NULL){
    //     cout << "R" << root->right->data ;
    // }
    // cout << endl;
    // printBinaryTree(root->left);
    // printBinaryTree(root->right);
    
    return;

}

BinaryTreeNode<int>* takeInputLevelWise(){
     int rootData;
    cout<< "Enter Root Data: " << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() != 0){
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter the Left Child of " << front->data <<endl;
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
    

        cout << "Enter the Right Child of " << front->data <<endl;
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
     
    return root;
}

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout<< "Enter Data: " << endl;
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    BinaryTreeNode<int>* leftChild = takeInput();
    BinaryTreeNode<int>* rightChild = takeInput();

    root->left = leftChild;
    root->right = rightChild;

    return root;
}

int numNodes(BinaryTreeNode<int>* root){
    
    if(root == NULL){
        return 0;
    }
   
    return 1 + numNodes(root->left) + numNodes(root->right);
    
}

void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    cout<< root->data << " ";
    inorder(root->right);

}

void preorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<< root->data << " ";
    preorder(root->left);
    preorder(root->right);

}
void postorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout<< root->data << " ";

}
BinaryTreeNode<int>* buildTreeHelper(int* in, int* pre, int inS,int inE,int preS,int preE ){
    //Base case 
    if(inS > inE){
        return NULL;
    }
   
    int rootData = pre[preS];
    int rootIndex = -1;
     
    for(int i = inS; i <= inE; i++){
        if(in[i] == rootData ){
            rootIndex = i;
            break;
        }
    }
    
    int lInS = inS;
    int lInE = rootIndex - 1;
    int lPreS = preS + 1;
    int lPreE = lInE - lInS + lPreS;
    int rPreS = lPreE + 1;
    int rPreE = preE;
    int rInS = rootIndex + 1;
    int rInE = inE;
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    root->left = buildTreeHelper(in, pre, lInS, lInE, lPreS, lPreE);
    root->right = buildTreeHelper(in, pre, rInS, rInE, rPreS, rPreE);
    
    return root;
    
}

BinaryTreeNode<int>* buildTreeUsingPreIn(int* inorder,int* preorder,int size){
    
    return buildTreeHelper(inorder, preorder, 0, size-1, 0, size-1 );

}


int height(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

//Time complexity of the this is Bestcase is O(nlogn), WorstCase is O(n^2), 
//otherwise we can write it as O(n*h)...here h is height of the tree, it depends on the type of tree. 
int diameter(BinaryTreeNode<int>* root){
    if(root == NULL){ 
        return 0;
    }
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));

}

/*
Time complexity of the heightDiameter() is O(n).

The heightDiameter is the best solution for trees. 
We use this in multiple places. 

*/
//pair is a templet
pair<int, int> heightDiameter(BinaryTreeNode<int>* root){
    if(root == NULL){
        pair<int,int> p;
        p.first = 0;
        p.second = 0;

        return p;
    }
    pair<int,int> leftAns = heightDiameter(root->left);
    pair<int,int> rightAns = heightDiameter(root->right);

    int ld = leftAns.second;
    int lh = leftAns.first;
    int rd = rightAns.second;
    int rh = rightAns.first;

    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld,rd));
    pair<int,int> p;
    p.first = height;
    p.second = diameter;
    return p;
    

}


//Input Binary Tree: 1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
int main(){

/*
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;
*/

    //BinaryTreeNode<int>* root = takeInput();
    int in[] = {4,2,8,5,9,1,6,3,7};
    int pre[] = {1,2,4,5,8,9,3,6,7};
    

    BinaryTreeNode<int>* root = buildTreeUsingPreIn(in, pre, 9);
    //BinaryTreeNode<int>* root = takeInputLevelWise();

    cout << "\nFinal Binary Tree :" << endl; 
    printBinaryTree(root);
    
    cout << "Number of Node in the Tree :" << numNodes(root) << endl;

    cout << "Inorder of the Tree :" << endl;
    inorder(root);

    cout << "\nPreorder of the Tree :" << endl;
    preorder(root);

    cout << "\nPostorder of the Tree :" << endl;
    postorder(root);
    cout << endl;
    delete root;

}