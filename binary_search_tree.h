#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include <bits/stdc++.h>
#include "node.h"

using namespace std;

namespace dsa 
{

template <typename K>
struct binary_search_tree_node : public node<K, binary_search_tree_node<K>>
{
	// using node_p = typename node<K, binary_search_tree_node<K>>::node_p;
	using typename node<K, binary_search_tree_node<K>>::node_p;

	binary_search_tree_node(K _key = {})
	: node<K, binary_search_tree_node<K>>(_key)
	{}
};

template <typename T, typename Node = binary_search_tree_node<T>>
class binary_search_tree
{
	using node_p = typename Node::node_p;

protected:
	node_p m_root = nullptr;
	size_t m_size;

	auto zig(node_p n) -> node_p
	{
		cout << "zig: " << n->key << endl;
		node_p aux = n->right;
		n->right = aux->left;
		aux->left = n;

		return aux;
	}

	auto zag(node_p n) -> node_p
	{
		cout << "zag: " << n->key << endl;
		node_p aux = n->left;
		n->left = aux->right;
		aux->right = n;

		return aux;
	}

public:
	auto insert(T key) -> bool
	{
		node_p z = node_p(new Node(key));
		node_p x = m_root;
		node_p y = nullptr;

		while (x != nullptr)
		{
			if (z->key == x->key)
			{
				delete z;
				return false;
			}

			y = x;

			if (z->key < x->key)
				x = x->left;
			else
				x = x->right;
		}

		m_size++;

		if (y == nullptr)
			m_root = z;
		else if (z->key < y->key)
			y->left = z;
		else
			y->right = z;

		return true;
	}

	auto find(T key) -> node_p
	{
		return find(key, m_root);
	}

	auto find(T key, node_p n) -> node_p
	{
		if (n == nullptr || key == n->key)
			return n;
		else if (key < n->key)
			return find(key, n->left);
		else
			return find(key, n->right);
	}

	auto print() -> void
	{
		preorder_walk(m_root);
		cout << endl;
	}
	
	auto inorder_walk(node_p n) -> void
	{
		if (n != nullptr)
		{
			inorder_walk(n->left);
			cout << n->key << " ";
			inorder_walk(n->right);
		}
	}

	auto preorder_walk(node_p n) -> void
	{
		if (n != nullptr)
		{
			cout << n->key << " ";
			preorder_walk(n->left);
			preorder_walk(n->right);
		}
	}
};

} // namespace dsa

#endif
