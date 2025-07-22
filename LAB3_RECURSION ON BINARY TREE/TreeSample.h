#ifndef __TREESAMPLE__H__
#define __TREESAMPLE__H__

enum Error_code
{
	success,
	fail,
	rangeerror,
	overflow,
	not_present,
	dupplicated,
	found
};

//---------------------------------------------------------
template <class Node_entry>
struct TreeNode
{
	Node_entry entry;
	TreeNode<Node_entry> *left, *right;
	TreeNode();
	TreeNode(Node_entry item, TreeNode<Node_entry> *left = NULL, TreeNode<Node_entry> *right = NULL);
};

//---------------------------------------------------------
template <class Tree_entry>
class Tree
{
public:
	Tree();
	~Tree();
	TreeNode<Tree_entry> *getNode(const Tree_entry &value)
	{
		return findNode(root, value);
	}

	bool empty();
	//	int size();
	Error_code insertAt(TreeNode<Tree_entry> *, bool, Tree_entry, TreeNode<Tree_entry> *&);
	void printLNR();
	void printLRN();
	void printNLR();
	void printNRL();
	void printRNL();
	void printRLN();
	int height();
	bool is_balanced();
	void swap_left_right(TreeNode<Tree_entry> *subroot);
	int count_leaves(); // { return count_leaves_recursive(root); }
	void build_tree_from_keyboard();
	void delete_leaves();

protected:
	TreeNode<Tree_entry> *root;
	TreeNode<Tree_entry> *findNode(TreeNode<Tree_entry> *node, const Tree_entry &value)
	{
		if (!node)
			return nullptr;
		if (node->entry == value)
			return node;
		TreeNode<Tree_entry> *leftResult = findNode(node->left, value);
		if (leftResult)
			return leftResult;
		return findNode(node->right, value);
	}

	void destroy(TreeNode<Tree_entry> *);
	void printLNR_recursive(TreeNode<Tree_entry> *);
	void printLRN_recursive(TreeNode<Tree_entry> *);
	void printNLR_recursive(TreeNode<Tree_entry> *);
	void printNRL_recursive(TreeNode<Tree_entry> *);
	void printRNL_recursive(TreeNode<Tree_entry> *);
	void printRLN_recursive(TreeNode<Tree_entry> *);
	int height_recursive(TreeNode<Tree_entry> *);
	bool is_balanced_recursive(TreeNode<Tree_entry> *);
	int count_leaves_recursive(TreeNode<Tree_entry> *subroot);
	void delete_leaves_recursive(TreeNode<Tree_entry> *&subroot);

	TreeNode<Tree_entry> *build_tree_from_keyboard_recur();
};

#endif //__TREESAMPLE__H__