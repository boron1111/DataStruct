#include "BinaryTreePath.h"


BinaryTreePath::BinaryTreePath(void)
{
}


BinaryTreePath::~BinaryTreePath(void)
{
}

char** BinaryTreePath::binaryTreePaths(struct TreeNode* root, int* returnSize)
{
	if (root==NULL)
	{
		return 0;
	}

	TreeNode *left,*right,*temp;
	char **result;
	
}

void BinaryTreePath::TestClass()
{
	TreeNode *btree,*bt2,*bt3,*bt5;
	btree=(TreeNode *)malloc(sizeof(TreeNode));
	bt2=(TreeNode *)malloc(sizeof(TreeNode));
	bt3=(TreeNode *)malloc(sizeof(TreeNode));
	bt5=(TreeNode *)malloc(sizeof(TreeNode));
	btree->val=1;
	bt2->val=2;
	bt3->val=3;
	bt5->val=5;

	btree->left=bt2;btree->right=bt3;
	bt2->left=NULL;
	bt2->right=bt5;
	bt3->left=NULL;bt3->right=NULL;
	bt5->left=NULL;bt5->right=NULL;


}