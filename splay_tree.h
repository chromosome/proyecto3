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

				n = this->zig(n);
			}
			// zig-zag
			else
			{
				n->right->left = splay(n->right->left, key);

				if (n->right->left != nullptr)
				{
					n->right = this->zag(n->right);
				}
			}

			if (n->right == nullptr)
			{
				return n;
			}
			else
			{
				return this->zig(n);
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

				n->left = this->zig(n->left);
			}
			// zag-zag
			else
			{
				n->left->left = splay(n->left->left, key);

				if (n->left->left != nullptr)
				{
					n = this->zag(n);					
				}
			}

			if (n->left == nullptr)
			{
				return n;
			}
			else
			{
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