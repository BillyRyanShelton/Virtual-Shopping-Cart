#pragma once
/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:		This is a header file for a virtual shopping
cart.
*********************************************************************/

#include <string>
using std::string;

#ifndef ITEM_HPP
#define ITEM_HPP

class Item
{
	private:
		string itemName;
		string Unit;
		int Quantity;
		double Price;
		double extendedPrice;

	public:
		Item();
		Item(string, string, int, double);
		int operator== (Item ItemIn);
		double ExtendedPrice();	
		string getitemName();
		string getUnit();
		int getQuantity();
		double getPrice();
		void SetQuantity(double);
};



#endif
