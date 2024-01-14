#include<iostream>
#include<queue>
using namespace std;
#include "TreeNode.h"

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout<< "Enter root Data" << endl;
    cin>> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes; 

    pendingNodes.push(root);
    while(pendingNodes.size() != 0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of children of " << front->data << endl;
        int numChild;
        cin >> numChild;
        for(int k = 0; k < numChild; k++){
            int childData;
            cout<< "Enter " << k << "th child of " << front->data << endl;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);

        }
    }
        return root;
}

//Taking input in the below method is bit difficult(implemented as DFS), Because we need to understand the Recursion very well.
// We made it simple in the above takeInputLevelWise()

TreeNode<int>* takeInput(){
    int rootData;
    cout<< "Enter Data" << endl;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of Children of " << rootData << endl;
    cin >> n;
    for(int i = 0; i < n; i++){
        TreeNode<int>* child = takeInput();
        //connecting child to Parent(i.e root)
        root->children.push_back(child);
    }
    return root;

}



void printTree(TreeNode<int>* root){
    // No need of base case, in genric trees. conditions itself work as base case. 

    //The below is the Edge case but not the Base case.
    //Because, we will never enter in this if condition untill unless the root which we passing is null
    // In Base case we will enter the condition to terminate. 
    if(root == NULL){
        return;
    }

    //Printing Nodes Levelwise(inorder)
    queue<TreeNode<int>*> NodesToPrint;
    NodesToPrint.push(root);
    while(NodesToPrint.size() !=0 ){
        TreeNode<int>* front = NodesToPrint.front();
        NodesToPrint.pop();
         cout << front->data << ":" ;
        for(int i=0; i<front->children.size(); i++){
            cout << front->children[i]->data << ",";
            NodesToPrint.push(front->children[i]);
        }
        cout << endl;
    }
    // cout << root->data << ":" ;
    // for(int j=0; j<root->children.size(); j++){
    //     cout << root->children[j]->data << ",";
    // }
    // cout << endl;

    // for(int i=0; i<root->children.size(); i++){
    //     printTree(root->children[i]);
    // }
}

int main(){

    /*
    //The below three lines will create individual nodes, Not yet connected
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* node1 = new TreeNode<int>(20);
    TreeNode<int>* node2 = new TreeNode<int>(30);

    // To connect the above three nodes we code the below two lines
    root->children.push_back(node1);
    root->children.push_back(node2);
    */
    // TreeNode<int>* root = takeInput();
    TreeNode<int>* root = takeInputLevelWise();
    cout << "Tree output: "<< endl;
    printTree(root);


}