/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:		This is the client code file which implements a
virtual shopping cart.
*********************************************************************/


#include "Item.hpp"
#include <string>
#include <iostream>
using std::string;


/*********************************************************************
					int Item::operator== (Item ItemIn)
This function defines the == operator for items objects.
*********************************************************************/
int Item::operator== (Item ItemIn)
{
	
	if (itemName == ItemIn.itemName)
	{
		return 1;
		//return ItemIn;
		//If ItemIn is returned this means it
		//is not yet in the array
	}

	else
	{
		return 0;
		//return checkedItem;
		//If checkedItem is returned this means the item is
		//already in the array
	}
}


/*********************************************************************
					double Item::ExtendedPrice()
This functions calculates the extended price for an item.
*********************************************************************/
double Item::ExtendedPrice()
{
	extendedPrice = Quantity*Price;
	return extendedPrice;
}


/*********************************************************************
						Item::Item()
This is the default Item class constructor.
*********************************************************************/
Item::Item()
{
	itemName = "Item Removed";
	Unit = "";
	Quantity = 0;
	Price = 0;
}

/*********************************************************************
Item::Item(string stringIn, string unitIn, int quantityIn, double priceIn)
This is an Item class constructor which sets 4 of its data members.
*********************************************************************/
Item::Item(string stringIn, string unitIn, int quantityIn, double priceIn)
{
	itemName = stringIn;
	Unit = unitIn;
	Quantity = quantityIn;
	Price = priceIn;
}

/*********************************************************************
					string Item::getitemName()
This functions returns the item's name.
*********************************************************************/
string Item::getitemName()
{
	return itemName;
}

/*********************************************************************
					int Item::getQuantity()
This function returns the item's quantity.
*********************************************************************/
int Item::getQuantity()
{
	return Quantity;
}

/*********************************************************************
				double Item::getPrice()
This function returns the item's price.
*********************************************************************/
double Item::getPrice()
{
	return Price;
}

/*********************************************************************
					string Item::getUnit()
This function returns the item's unit type.
*********************************************************************/
string Item::getUnit()
{
	return Unit;
}


/*********************************************************************
					void Item::SetQuantity()
This function sets the item's quantity.
*********************************************************************/
void Item::SetQuantity(double blah)
{
	Quantity = blah;
}
