#ifndef NODE_H
#define NODE_H

#include <bits/stdc++.h>

namespace dsa {

template<typename K, typename P>
struct node
{
	using node_p = P*;
	using key_t = K;

	key_t key;

	node_p left = nullptr;
	node_p right = nullptr;

	node(key_t _key = {})
	: key(_key)
	{}
};

} // namespace dsa

#endif
