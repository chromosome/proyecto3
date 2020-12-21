#include "binary_search_tree.h"
#include "splay_tree.h"

int main(int argc, char const *argv[])
{
	dsa::splay_tree<int> tree;

	tree.insert(1);
	tree.insert(4);
	// tree.insert(2);
	// tree.insert(3);
	tree.insert(8);
	tree.insert(5);
	tree.print();
	tree.find(5);
	tree.print();
	// tree.find(3);
	// tree.print();

	// tree.insert(6);
	// tree.print();
	// tree.insert(3);
	// tree.print();
	// tree.insert(7);
	// tree.print();
	// tree.insert(2);
	// tree.print();
	// tree.insert(0);
	// tree.print();
	// tree.insert(1);
	// tree.print();
	// tree.insert(5);
	// tree.insert(4);
	// tree.insert(9);
	// tree.insert(8);
	// tree.print();
	// tree.find(4);
	// tree.print();
	// tree.find(8);
	// tree.print();


	return 0;
}