/*****************************************************************************
URL: https://leetcode.com/problems/binary-tree-level-order-traversal

Given a binary tree, return the level order traversal of its nodes' values
(i.e., from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},

    3
   / \
  9  20
    /  \
   15   7

Return its level order traversal as:

[
  [3],
  [9,20],
  [15,7]
]

OJ's Binary Tree Serialization specification:

The serialization of a binary tree follows a level order traversal, where '#'
signifies a path terminator where no node exists below.

Here's an example:

   1
  / \
 2   3
    /
   4
    \
     5

The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}". 

*****************************************************************************/

#define NULL 0

#include <vector>
#include <stdio.h>

using namespace std;

//***************************************************//
//*********** Struct for offline testing ************//
//***************************************************//

struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//***************************************************//

class Solution
{
public:

    vector<vector<int> > levelOrder(TreeNode *root)
    {
    	if(root != NULL)
    	{
    		_nodeBuffer.push_back(root);

	    	while(_nodeBuffer.size() > 0)
	    		processLevel();
	    }

        return _output;
    }

private:

	void processLevel()
	{
		vector<TreeNode*> aux;
		vector<int> levelValues;

		for(unsigned int i = 0; i < _nodeBuffer.size(); i++)
		{
			aux.push_back(_nodeBuffer[i]);
			levelValues.push_back(_nodeBuffer[i]->val);
		}

		_nodeBuffer.clear();
		_output.push_back(levelValues);

		for(unsigned int i = 0; i < aux.size(); i++)
		{
			if(aux[i]->left != NULL)
				_nodeBuffer.push_back(aux[i]->left);

			if(aux[i]->right != NULL)
				_nodeBuffer.push_back(aux[i]->right);
		}
	}

private:

	vector<TreeNode*> _nodeBuffer;
	vector< vector<int> > _output;
};

//***************************************************//
//************ Main for offline testing *************//
//***************************************************//

int main(void)
{
	TreeNode n1(3);
	TreeNode n2(9);
	TreeNode n3(20);
	TreeNode n4(15);
	TreeNode n5(17);

	n1.left  = &n2;
	n1.right = &n3;
	n3.left  = &n4;
	n3.right = &n5;

	Solution* solution = new Solution();
	vector< vector<int> > result = solution->levelOrder( &n1 );

	for(unsigned int i = 0; i < result.size(); i++)
	{
		if( i != 0 ) printf("\n");

		vector<int> aux = result[i];
		for(unsigned int j = 0; j < aux.size(); j++)
		{
			if( j != 0 ) printf(" ");
			printf("%d", aux[j]);
		}
	}

	return 1;
}
