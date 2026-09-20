#pragma once
struct node {
	int data;
	node* left, * right;
	node(int d, node* l=0, node* r=0) {
		data = d;
		left = l;
		right = r;
	}


};
class tree {
	node* root;
	bool add(int el, node* &r);
	void pre(node* r);
	void in(node* r);
	void post(node* r);
	int size(node* r);
	int height(node* r);
	bool search(int el, node* r);
	void delete_tree(node*& r);
	void copy_tree(node* &r,node* ro);


public:
	~tree();
	tree();
	tree(tree& o);
	tree& operator=(tree & o);
	bool is_empty();
	bool add(int el);
	void preorder();
	void postorder();
	void inorder();
	bool search(int el);
	int size();
	int height();
	void copy_tree(tree& o);
	void delete_tree();
};