#include <iostream>
#include "Tree.h"
#include "VideoGame.h"
int main() {
	//-- TEST FOR INTEGER --
	Tree<int> myTree = Tree<int>();
	
	// ADD
	myTree.add(10);
	myTree.add(15);
	myTree.add(7);
	myTree.add(4);
	/*
	  TREE :
	       10
		  /  \
		 7    15
		/
	   4
	*/

	// TRAVERSALS
	myTree.inorder(); // THIS SHOULD DISPLAY NUMBERS IN SORTED ORDER
	std::cout << std::endl;

	myTree.preorder();
	std::cout << std::endl;

	myTree.postorder(); // ROOT SHOULD BE DISPLAYED AT THE END
	std::cout << std::endl;

	// FIND
	myTree.find(4) ? std::cout << "Found" << std::endl : std::cout << "Not in tree" << std::endl; // FOUND
	myTree.find(0) ? std::cout << "Found" << std::endl : std::cout << "Not in tree" << std::endl; // NOT IN TREE

	//-- TEST FOR VIDEOGAME CUSTOM CLASS --
	Tree<VideoGame> myTreeCustom = Tree<VideoGame>();

	// ADD
	myTreeCustom.add(VideoGame("WoW", 10));
	myTreeCustom.add(VideoGame("DarkSouls", 15));
	myTreeCustom.add(VideoGame("LeagueOfLegends", 0));
	myTreeCustom.add(VideoGame("Pokemon", 20));

	/*
	  TREE :
	      WoW
		  /  \
		 LoL  DS
		        \
	             Pokemon
	*/

	// TRAVERSALS --> HERE I ORDER USING THE PRICE !!

	myTreeCustom.inorder(); // THIS SHOULD DISPLAY NUMBERS IN SORTED ORDER
	std::cout << std::endl;

	myTreeCustom.preorder();
	std::cout << std::endl;

	myTreeCustom.postorder(); // ROOT SHOULD BE DISPLAYED AT THE END
	std::cout << std::endl;

	// FIND USING THE NAME
	myTreeCustom.find(VideoGame("CounterStrike", 5)) ? std::cout << "Found" << std::endl : std::cout << "Not in tree" << std::endl; // NOT IN TREE
	myTreeCustom.find(VideoGame("WoW", 10)) ? std::cout << "Found" << std::endl : std::cout << "Not in tree" << std::endl; // FOUND

	// TEST DELETE
	//myTreeCustom.deleteNode(VideoGame("Pokemon", 1)); // DELETES A LEAF
	//myTreeCustom.deleteNode(VideoGame("DarkSouls", 1)); // DELETES A NODE WITH 1 CHILD
	myTreeCustom.deleteNode(VideoGame("WoW", 1)); // DELETES A NODE WITH 2 CHILDREN
	myTreeCustom.preorder();

	system("pause");
	return 0;
}