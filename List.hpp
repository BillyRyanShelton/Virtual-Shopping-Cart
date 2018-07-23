#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:		This is a header file for a virtual shopping
cart.
*********************************************************************/

#include <string>
#include <iostream>
using std::string;

#ifndef LIST_HPP
#define LIST_HPP
#include "Item.hpp"


class List
{
	private:
		double cartSum;
		int arraySize;
		Item currentItem;
		

	public:
		List();
		void addTolist(Item);
		void removeFromlist(Item);
		void printList();
		int getArraySize();
		Item* ItemsArray = 0;
		double getCartSum();
		void changeExtendedPrice(Item);
		void changeCartSum(Item);
		void deleteArray();
		
		
		
};
#endif
