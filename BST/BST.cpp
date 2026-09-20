#include"BST.h"
#include<iostream>
using namespace std;
tree::~tree()
{
	delete_tree();
}
tree::tree() {
	root = 0;
}
tree::tree(tree& o)
{
	if (o.root != 0) {
		root = new node(o.root->data);
		copy_tree(root->left, o.root->left);
		copy_tree(root->right, o.root->right);

	}
}
tree& tree::operator=(tree& o)
{
	if (this != &o)
	{
		delete_tree();
		copy_tree(root, o.root);
	}
	return *this;
}

bool tree::is_empty() {
	return root == 0;
}
bool tree::add(int el) {
	return add(el, root);

}
bool tree::add(int el, node* &r) {
	if (r == 0) {
		r = new node(el);
		return true;
	}
	if (el == r->data) {
		return false;
	}
	if (el > r->data)
	{
		return add(el, r->right);
	}
	if (el < r->data)
	{
		return add(el, r->left);
	}

}
void tree::preorder() {
	pre(root);

}
void tree::pre(node* r) {
	if(r!=0)
	{
		cout << r->data << " ";
		pre(r->left);
		pre(r->right);
	}

}
void tree::postorder() {
	post(root);
}

void tree::post(node* r) {
	if (r != 0) {
		post(r->left);
		post(r->right);
		cout << r->data << " ";
	}

}
 
void tree::inorder() {
	in(root);
}

void tree::in(node* r) {
	if (r != 0) {
		in(r->left);
		cout << r->data << " ";
		in(r->right);
	}
}
int tree::size() {
	return size(root);
}
int tree::size(node* r) {
	if (r == 0)
		return 0;
	return 1 + size(r->left) + size(r->right);
}

int tree::height() {
	return height(root);
}
int tree::height(node* r) {

	if (r == 0)
		return -1;
	int lh =height(r->left);
	int rh = height(r->right);
	if (rh > lh)
		return rh+1;
	else
		return lh+1;
}
bool tree::search(int el, node* r)
{    if(r==0)
	return false;
   if (el == r->data)
     return true;
   if (el < r->data)
	   return search(el, r->left);
   if (el > r->data)
	   return search(el, r->right);

}
bool tree::search(int el) {

	return search(el, root);
}
void tree::delete_tree()
{
	delete_tree(root);

}
void tree::delete_tree(node*& r) {
	if (r != 0) {
		delete_tree(r->left);
		delete_tree(r->right);
		delete r;
		r = 0;
	}
	

}
void tree::copy_tree(tree& o) {
	copy_tree(root, o.root);

	}
void tree::copy_tree(node*& r, node* ro ) {

	if (ro != 0) {
		r = new node(ro->data);
		copy_tree(r->left, ro->left);
		copy_tree(r->right, ro->right);

	}

}

	