#pragma once
#include <iostream>
// -- NODE CLASS --
template <class T>
class Node
{
	template <typename T>
	friend class Tree;
private:
	T data;
	Node* left;
	Node* right;

	// -- LEAF --
	bool isLeaf();
public:
	Node(T data);
	~Node();

};

//-- DECLARATION --

// -- TREE CLASS --
template <class T>
class Tree
{
private:
	Node<T>* m_root;

	//-- RECURSIVE FUNCTIONS --
	void add(Node<T>* &node, T &data);

	void inorder(const Node<T>* node);
	void preorder(const Node<T>* node);
	void postorder(const Node<T>* node);

	bool find(Node<T>* node, T &data);

	// RECURSIVE DESTRUCTOR
	// it is basically a post order that deletes nodes
	void clean(Node<T>* &node);
public:
	Tree();
	~Tree();

	//-- ADD A NODE --
	void add(T data);

	//-- TRAVERSALS --
	void inorder(); // LEFT ROOT RIGHT
	void preorder(); // ROOT LEFT RIGHT
	void postorder(); // LEFT RIGHT ROOT

	//-- FIND A NODE --
	bool find(T data);
};

//-- NODE --
template <class T>
Node<T>::Node(T data) : left(nullptr), right(nullptr), data(data)
{}

template <class T>
Node<T>::~Node()
{}

template <class T>
bool Node<T>::isLeaf() {
	return !left && !right ? true : false;
}

//-- IMPLEMENTATION --

//-- TREE --
template <class T>
Tree<T>::Tree() : m_root(nullptr)
{}

template <class T>
Tree<T>::~Tree()
{
	clean(m_root);
}

template <class T>
void Tree<T>::add(T data) {
	add(m_root, data);
}

template <class T>
void Tree<T>::inorder() {
	inorder(m_root);
}

template <class T>
void Tree<T>::preorder() {
	preorder(m_root);
}

template <class T>
void Tree<T>::postorder() {
	postorder(m_root);
}

template <class T>
bool Tree<T>::find(T data) {
	return find(m_root, data);
}

//-- RECURSION --
template <class T>
void Tree<T>::add(Node<T>* &node, T &data) {
	if (!node)
		node = new Node<T>(data);
	else
		data < node->data ? add(node->left, data) : add(node->right, data);
}

template <class T>
void Tree<T>::inorder(const Node<T>* node) {
	if (node->left) // LEFT
		inorder(node->left);

	std::cout << node->data; // ROOT

	if (node->right) // RIGHT
		inorder(node->right);
}

template <class T>
void Tree<T>::preorder(const Node<T>* node) {
	std::cout << node->data; // ROOT

	if (node->left) // LEFT
		preorder(node->left);

	if (node->right) // RIGHT
		preorder(node->right);
}

template <class T>
void Tree<T>::postorder(const Node<T>* node) {
	if (node->left) // LEFT
		postorder(node->left);

	if (node->right) // RIGHT
		postorder(node->right);

	std::cout << node->data; // ROOT
}

template <class T>
bool Tree<T>::find(Node<T>* node, T &data) {
	if (!node)
		return false;
	else {
		if (node->data == data)
			return true;

		return find(node->left, data) || find(node->right, data);
	}
}

template <class T>
void Tree<T>::clean(Node<T>* &node) {
	if (node->left) // LEFT
		clean(node->left);

	if (node->right) // RIGHT
		clean(node->right);

	delete node; // ROOT
}