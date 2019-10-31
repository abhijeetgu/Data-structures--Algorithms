// BinaryTrees
#include <iostream>
#include<map>
#include<vector>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data = d;
		left = right = NULL;
	}
};

node* CreateTree(){
	int data;
	cin>>data;
	if(data == -1){
		return NULL;
	}

	node* root = new node(data);
	root->left = CreateTree();
	root->right = CreateTree();

	return root;
}
void vop(node* root,map<int,vector<int>> &m,int d=0)
{
    if(root==NULL)
    {
        return;
    }

    m[d].push_back(root->data);
    vop(root->left,m,d-1);
    vop(root->right,m,d+1);

}

int main(){
	node* root = NULL;
	root = CreateTree();

	map<int,vector<int> > m;

	vop(root,m);
	for(auto it=m.begin();it!=m.end();it++)
    {
        cout<<it->first<<"->";

        for(int i=0;i<it->second.size();i++)
        {
            cout<<it->second[i]<<",";
        }
        cout<<endl;
    }




	return 0;
}
///8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1(test case)
///1 2 4 -1 -1 5 -1 8 3 6 -1 9 7 -1 -1
