//************************************************************
//
//		File:			Tree.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #6		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			May 10, 2018
//		
//************************************************************
#include <fstream>
#ifndef TREE_H
#define TREE_H

//************************************************************
struct treeNode
{
	treeNode* left;
	char key;
	treeNode* right;
};

//************************************************************
class Tree
{
	private:
		treeNode* root;
		void addBST(treeNode*& root, treeNode* newNode);
	public:
		Tree();
		/*~Tree();*/
		void insert(char);
};
#endif