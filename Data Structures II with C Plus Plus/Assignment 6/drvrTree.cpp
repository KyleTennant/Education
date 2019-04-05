//************************************************************
//
//		File:			drvrTree.cpp
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
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Tree.h"

using namespace std;

//************************************************************
struct Category
{
	char code;
	string description;
};

//************************************************************
Tree::Tree()
{
	root = NULL;
}

//************************************************************
void Tree::addBST(treeNode*& root, treeNode* newNode)
{
	if (root == NULL)
		root = newNode;
	else
		if (newNode->key < root->key)
			addBST(root->left, newNode);
		else
			addBST(root->right, newNode);
}

//************************************************************
void Tree::insert(char obj)
{
	treeNode* pNew;
	pNew = new treeNode;
	pNew->key = obj;
	pNew->right = NULL;
	pNew->left = NULL;
	addBST(root, pNew);
}

//************************************************************
int main()
{
	Category array[7];
	int index = 0;
	Category object;

	fstream inFile("Categories.csv");
	if (!inFile)
	{
		cout << "There was a problem opening Categories.csv" << endl;
		exit(99);
	}
	
	while (!inFile.eof())
	{
		inFile >> object.code;
		if (!inFile.eof())
		{
			inFile.ignore();
			getline(inFile, object.description);
			array[index] = object;
			index++;
		}
	}
	inFile.close();

	// Testing to see if data has been loaded
	for (int i = 0; i < 7; i++)
		cout << array[i].code << '\t' << array[i].description << endl;

}