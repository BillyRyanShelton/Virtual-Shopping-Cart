/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:		This is a source file which defines the functions
created in the List.hpp file.  
*********************************************************************/


#include "List.hpp"
#include <string>
#include <iostream>
#include <iomanip>
using std::string;
using std::cout;
using std::setw;
using std::setprecision;
#include "Item.hpp"

/*********************************************************************
					  List::List()
 Description:  This is List class constructor which sets the cart sum 
 and arraySize to 0.
*********************************************************************/
List::List()
{
	cartSum = 0;
	arraySize = 0;
}



/*********************************************************************
			void List::addTolist(Item itemIn)
Description:  This is a function which adds Item objects to the List Object.
*********************************************************************/
void List::addTolist(Item itemIn)
{

	if (ItemsArray == 0)																		//If the list is empty a new slot is added
	{
		ItemsArray = new Item[1];
		ItemsArray[0] = itemIn;
		arraySize++;
		cartSum += (itemIn.getPrice() * itemIn.getQuantity());
	}

	else
	{
		Item* newList = ItemsArray;																//A temporary list is created to hold the items of our main list
		
		ItemsArray = new Item[arraySize + 1];													//Our main list is resized by +1

		for (int i = 0; i < (arraySize); i++)													//Everything from our temporary list is placed back into our temporary list
			{
				ItemsArray[i] = newList[i];
			}

		ItemsArray[arraySize] = itemIn;															//The new item to be entered is added to the extra slot we created two comments above
		arraySize++;
		cartSum += (itemIn.getPrice() * itemIn.getQuantity());

		delete[] newList;																		//Our temporary list is deleted to deallocate memory
	}
}


/*********************************************************************
				void List::removeFromlist(Item itemIn)
This function removes an item from the list.
*********************************************************************/

void List::removeFromlist(Item itemIn)
{
	Item emptyItem;

	for (int i = 0; i < (arraySize); i++)			
	{
		if (ItemsArray[i] == itemIn)
		{
			
			cartSum = cartSum - ((ItemsArray[i]).ExtendedPrice());
			(ItemsArray[i]) = emptyItem;
		}
	}
}


/*********************************************************************
						void List::printList()
The list is printed to the screen.
*********************************************************************/
void List::printList()
{
	cout << setw(21) << "Item Name     " << setw(17) << "Unit Type  " << setw(16) << "Price($)  " << setw(12) << "Quantity" << setw(22) << "Extended Price($)\n";
	cout << setw(21) << "-------------------" << setw(17) << "-------------" << setw(16) << "------------" << setw(12) << "--------" << setw(22) << "-----------------\n";

	for (int i = 0; i < (arraySize); i++)		//this makes our main list equal to our new list
	{
		currentItem = (ItemsArray[i]);

		cout << setw(21) << currentItem.getitemName() << setw(17) << currentItem.getUnit()  << setw(16) << std::setprecision(10) <<currentItem.getPrice() << setw(12) << currentItem.getQuantity() << setw(21) << std::setprecision(10) << currentItem.ExtendedPrice();
		cout << "\n\n";
		
	}

	cout << "Cart Total($):" << cartSum;
	cout << "\n";
}



/*********************************************************************
					int List::getArraySize()
This functions returns the size of the list/array.
*********************************************************************/
int List::getArraySize()
{
	return arraySize;
}



/*********************************************************************
					double List::getCartSum()
This functions returns the sum of the Cart.
*********************************************************************/
double List::getCartSum()
{
	return cartSum;
}





/*********************************************************************
			void List::changeExtendedPrice(Item removeItemIN)
The extended price is changed when an item's quantity changes.  
*********************************************************************/
void List::changeExtendedPrice(Item removeItemIN)
{
	
	cartSum = cartSum + (removeItemIN.getQuantity())*(removeItemIN.getPrice()); //add new extended price to cartSum
				
}


/*********************************************************************
			void List::changeCartSum(Item deleteExtendedPrice)
This function calculates the new cart sum when an item's quantity goes down.
*********************************************************************/

void List::changeCartSum(Item deleteExtendedPrice)
{
	cartSum = cartSum - deleteExtendedPrice.ExtendedPrice();
}


/*********************************************************************
				void List::deleteArray()
This function dealloctes the List Object's list.
*********************************************************************/
void List::deleteArray()
{
	delete[] ItemsArray;							
}
