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
//1 2 3 4 5 6 7 -1 -1 8 9 -1 -1 -1 -1 -1 -1 -1 -1
int main(){

/*
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(1);
    BinaryTreeNode<int>* node1 = new BinaryTreeNode<int>(2);
    BinaryTreeNode<int>* node2 = new BinaryTreeNode<int>(3);

    root->left = node1;
    root->right = node2;
*/

    //BinaryTreeNode<int>* root = takeInput();

    BinaryTreeNode<int>* root = takeInputLevelWise();

    cout << "\nFinal Binary Tree :" << endl; 
    printBinaryTree(root);

    delete root;

}