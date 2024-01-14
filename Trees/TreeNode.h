#include<vector>
using namespace std;
template <typename T> 
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children;
    //if we don't specify the type of the children, it will by default take its parents type.
    //vector<TreeNode*> children;....children will take parents type by default in this case. 
    //Since TreeNode is also a template 

    TreeNode(T data){
        this->data = data;
    }

    ~TreeNode(){
        for(int i=0; i<children.size(); i++){
            delete children[i];
        }
    }
};