//************************************************************
//
//		File:			HashTable.h
//		
//		Student:		Kyle Tennant
//
//		Assignment:	 	Assignment  #2		
//
//		Course Name:	Data Structures II
//
//		Course Number:	COSC 3100
//
//		Due:			April 12, 2018
//		
//************************************************************
#include "List.h"

//************************************************************
template <class DT>
class HashTable
{
	public:
		HashTable(int(*hf)(const DT &), int);
		~HashTable();
		bool insert(const DT &);
		bool retrieve(DT &);
		void makeEmpty();
	private:
		List<DT>* table;
		int(*hashfunc)(const DT &);
		int size;
};

//************************************************************
template <class DT>
HashTable<DT>::HashTable(int(*hf)(const DT &), int s)
{
	size = s;
	table = new List<DT>[size];
	hashfunc = hf;
}

//************************************************************
template <class DT>
HashTable<DT>::~HashTable()
{
	delete[] table;
}

//************************************************************
template <class DT>
bool HashTable<DT>::insert(const DT & newObject)
{
	int index = hashfunc(newObject);
	if (index < 0 || index >= size)
		return false;
	cout << "The location is " << index << endl;
	table[index].insert(newObject);
	return true;
}

//************************************************************
template <class DT>
bool HashTable<DT>::retrieve(DT & retrieved)
{
	int index = hashfunc(retrieved);
	if (index < 0 || index >= size)
		return false;
	cout << "The location is " << index << endl;
	if (table[index].retrieve(retrieved))
		return true;
	else
		return false;
}

//************************************************************
template <class DT>
void HashTable<DT>::makeEmpty()
{
	for (int i = 0; i < size; i++)
		table[i].makeEmpty();
}