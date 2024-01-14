#include<iostream>
#include<queue>
#include<algorithm>
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
//1 3 2 3 4 2 5 6 2 7 8 0 0 0 0 1 9 0
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

//The funciton counts Number of nodes in a Tree
int numNodes(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    int ans = 1;
    for(int i=0; i < root->children.size(); i++){
        ans += numNodes(root->children[i]);
    }
    return ans;
}
//height according to nodes, 
// if we want height of the tree according to edges in base case we can return 0.
double heightOfTree(TreeNode<int>* root){
    if(root == NULL){
        return 0;
    }
    vector<int> height;
    if(root->children.size() == 0){
        return 1;
    }
    for(int i=0; i < root->children.size(); i++){
        height.push_back(heightOfTree(root->children[i]));
        
    }
    double max_height = *max_element(begin(height), end(height))+1;

    return max_height;

}

void printAtLevelK(TreeNode<int>* root, int k){
    if(root == NULL){
        return;
    }
    if(k == 0){
        cout << root->data << endl;
        return;
    }

    for(int i=0; i < root->children.size(); i++){
        printAtLevelK(root->children[i], k-1);
        
    }
        return;
}

int noOfLeafNodes(TreeNode<int>* root){
    int ans = 0;
    if(root == NULL){
        return 0;
    }
    if(root->children.size() == 0 ){
        return 1;
    }
    for(int i=0; i< root->children.size(); i++){
         ans += noOfLeafNodes(root->children[i]);

    }
    return ans;
}

void preorder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout<< root->data << endl;
    
    for(int i=0; i < root->children.size(); i++){
        preorder(root->children[i]);
    }
    
}
void postorder(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
   
    for(int i=0; i < root->children.size(); i++){
        postorder(root->children[i]);        
    }
    cout<< root->data << endl;
}

void deleteTree(TreeNode<int>* root){
    for(int i=0; i<root->children.size(); i++){
        deleteTree(root->children[i]);
    }
    delete root;
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

    int totNodes = numNodes(root);
    cout<<"Total Number of Nodes in Tree : "<< totNodes << endl;

    int height_of_Tree = heightOfTree(root);

    cout <<"Height of the Tree is :" << height_of_Tree << endl;

    int k;
    cout<< "Enter the value of K to print the kth level of elements of the tree :"<< endl;
    cin >> k;

    cout <<"Depth of the Tree at Level "<< k  <<":" << endl;
    printAtLevelK(root,k);

    
    int leafNodes = noOfLeafNodes(root);
    cout << "No.of Leaf nodes in a tree are :" << leafNodes << endl;

    cout << "Preorder Traversal :" << endl;
    preorder(root);
    
    cout << "Postorder Traversal :" << endl;
    postorder(root);

    //TODO delete the Tree
/*
    We can do it in two ways, 
    1. By Postorder Traversal
    2. By calling Destructor.

    delete root;............
    if we do this, root will be deleted for sure,but we have declared the "vectors statically",
    Therefore we will not have the access to those vectors.if we directly delete the root.

    We need to delete the children first and then we need delete the parent.It is kind of Postorder Traversal.
*/

//delete root will call the destructor. 
delete root;

    deleteTree(root);
}