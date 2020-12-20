#ifndef AVL_TREE
#define AVL_TREE

#include "binary_tree.h"

namespace dsa {

template <typename K>
class avl_node : public bst_node<K> 
{
public:
	using node_p = avl_node*;
	size_t height;
};

template <typename T>
class avl_tree : public binary_tree<T> 
{
	using node_p = typename avl_tree<T>::node_p;
};

} // namespace dsa

#endif
