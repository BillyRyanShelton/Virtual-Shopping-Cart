/*********************************************************************
** Author:		Billy R. Shelton
** Date:		7/23/2018
** Description:		This is the client code file which implements a 
virtual shopping cart.  The user is allowed to enter in as many items 
as they wish.  For each item they must enter the item name, quantity,
unit type and price.  Also, if a user re-enters the name of one of the
items the program will display that the item is already in the cart.
After they are finished entering in their items the user simply presses
enter and a list of their items is printed to the screen.  They will
see the name, quanity, unit type, price and extended price for each item.
A cart total is also printed.  After the user has time to review their 
cart they have the option to remove any of the items.  First they enter
the item's name and then the quantity they wish to delete.  After they
are done removing items the user simply presses enter and a list of their
items is printed to the screen.  The program then says farewell.
*********************************************************************/

#include <iostream>
#include "Item.hpp"
#include "List.hpp"
#include <string>

using std::cout;
using std::cin;
using std::getline;
using std::string;

int main()
{
	cout << "Welcome to a virtual shopping cart.\n\n";											//Introduction
	List ShoppingList;																			//A List Object is created

	do																							//An infiite loop is created which asks the user to enter in items
	{
		int count1 = 0;

		string currentItemName;																	//The four item specification variables are created
		string currentUnit;
		int currentQuantity;
		double currentPrice;

		cout << "Enter in the name of the item you want to add.  If none press enter.\n";		//Item Name is asked

		getline(cin, currentItemName);															

		if (currentItemName == "")																//If the use presses enter with no input the infinite loop is stopped with a break
		{
			break;
		}

		else																					//If the user enters in something a series of steps is taken
		{
			cout << "Type of unit(can, box, lb, oz, etc...):";									//Input Type is asked
			cin >> currentUnit;
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Quantity:";																//Quantity is asked
			cin >> currentQuantity;
			cin.clear();
			cin.ignore(100, '\n');

			cout << "Price:$";																	//Price is asked
			cin >> currentPrice;
			cin.clear();
			cin.ignore(100, '\n');

			Item currentItem(currentItemName, currentUnit, currentQuantity, currentPrice);		//An item object is created with the four variables


			for (int i = 0; i < ShoppingList.getArraySize(); i++)								//If the item is already in the list, then program tells the user
			{
				if (currentItem == (ShoppingList.ItemsArray[i]))								//Overload == Operator is used here to compare items in the list
				{
					count1++;
					cout << "\n";
					cout << "This item is already in your cart.\n\n";
				}
			}

			if (count1 == 0)																	//If the item is not in the list then it is added to the list using 
			{																					//the addTolist function which is a public member of the List class
				ShoppingList.addTolist(currentItem);
			}
		}
		cout << "\n";
	
	} while (true);


	ShoppingList.printList();																	//The List is printed when the user is done entering in items










	do																							//An infiite loop is created which asks the user to remove in items
	{																							//This loop is very similar to the loop above.  
		int count1 = 0;

		string removeItemName;
		string removeUnit = "";
		int removeQuantity;
		double removePrice = 0;
																								//Item Name is asked
		cout << "Enter the name of the item you would like to remove, if any.  If none press enter.\n";

		getline(cin, removeItemName);

		if (removeItemName == "")																//If the use presses enter with no input the infinite loop is stopped with a break
		{
			break;
		}

		else
		{
			

			cout << "How many items would you like to remove.\n";								//Quantity is asked
			cin >> removeQuantity;
			cin.clear();
			cin.ignore(100, '\n');

			Item removeItem(removeItemName, removeUnit, removeQuantity, removePrice);			//An item object is created with the four variables.  Two of them are dummy variables


			
				for (int i = 0; i < ShoppingList.getArraySize(); i++)							//If the item to remove is found in the list
				{
					if (removeItem == (ShoppingList.ItemsArray[i]))							
					{
						if (((ShoppingList.ItemsArray[i]).getQuantity()) == removeQuantity)		//If the quanity they want to remove is equal to the quantity of the item in the cart, then they are all removed
						{
							ShoppingList.removeFromlist(removeItem);
						}

						else																	//If the user only wants to remove some items then the quantity is changed
						{
							ShoppingList.changeCartSum((ShoppingList.ItemsArray[i]));			//The ChangeCartSum subtracts the old quantity from the cart

																								//The old quantity is subtracted from the amount the user wants to remove from the cart
							double newQ = (((ShoppingList.ItemsArray[i]).getQuantity()) - removeQuantity);		

																								
							ShoppingList.ItemsArray[i].SetQuantity(newQ);						//The new quantity is updated to the item object
							ShoppingList.changeExtendedPrice((ShoppingList.ItemsArray[i]));		//The extended price of the item is changed
						}

					}
				}
	

			
		}
		cout << "\n";

	} while (true);




	ShoppingList.printList();																	//The shopping cart is printed

	ShoppingList.deleteArray();																	//the shopping cart is delete to deallocate memory

	cout << "\n";

	cout << "Hope you enjoyed using this virtual shopping cart.  Goodbye!\n\n";					//Farewell message
}




