#ifndef SPLAY_TREE_H
#define SPLAY_TREE_H

#include "binary_search_tree.h"

using namespace std;

namespace dsa
{

template <typename K>
struct splay_tree_node : public node<K, splay_tree_node<K>>
{
	// using node_p = typename node<K, splay_tree_node<K>>::node_p;
	using typename node<K, splay_tree_node<K>>::node_p;

	splay_tree_node(K _key = {})
	: node<K, splay_tree_node<K>>(_key)
	{}
};

template <typename T, typename Node = splay_tree_node<T>>
class splay_tree : public binary_search_tree<T, Node>
{
	using node_p = typename Node::node_p;

	auto splay(T key) -> void
	{
		this->m_root = splay(this->m_root, key);
	}

	auto splay(node_p n, T key) -> node_p
	{
		if (n == nullptr || key == n->key)
		{
			return n;
		}
		cout << "key: " << key << ", node: " << n->key << endl;

		// llave en el arbol derecho
		if (key > n->key)
		{
			if (n->right == nullptr)
			{
				return n;
			}

			// zig-zig
			if (key > n->right->key)
			{
				n->right->right = splay(n->right->right, key);
				this->print();

				// if (n->right->right == nullptr)
				// 	return n->right;
				cout << "2: ";
				n = this->zig(n);
				// cout << "node: " << n->key << endl;
				cout << "root:" << this->m_root->key << endl;
				this->print();
			}
			// zig-zag
			else
			{
				n->right->left = splay(n->right->left, key);
				this->print();

				if (n->right->left != nullptr)
				{
					// return n->right;
					cout << "3: ";
					n->right = this->zag(n->right);
					this->print();
				}
			}

			if (n->right == nullptr)
			{
				return n;
			}
			else
			{
				cout << "1: ";
				return this->zig(n);
				// this->print();
			}
		}

		// llave en el arbol izquierdo
		else
		{
			if (n->left == nullptr)
				return n;

			// zag-zig
			if (key > n->left->key)
			{
				n->left->right = splay(n->left->right, key);
				this->print();

				// if (n->left->left == nullptr)
					// return n->left;

				cout << "3: ";
				n->left = this->zig(n->left);
				this->print();
			}
			// zag-zag
			else
			{
				n->left->left = splay(n->left->left, key);

				if (n->left->left != nullptr)
				{
					cout << "2: ";
					n = this->zag(n);
					this->print();
					
				}
			}

			if (n->left == nullptr)
			{
				return n;
			}
			else
			{
				cout << "1: ";
				return this->zag(n);
			}
		}
	}

public:
	splay_tree()
	: binary_search_tree<T, Node>()
	{}
	
	auto insert(T key) -> bool
	{
		bool inserted = binary_search_tree<T, Node>::insert(key);
		splay(key);
		return inserted;
	}

	auto find(T key) -> node_p
	{
		this->m_root = splay(this->m_root, key);
		return this->m_root;
	}
};

}

#endif