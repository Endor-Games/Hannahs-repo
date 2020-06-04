#include <iostream>
#include <string>
#include "ShopItems.h"

using namespace std;

ShopItems CSVFile;

//Prototypes
void printInventory();
void printShop();
bool buyItems();

struct ItemInInventory
{
	Item ItemBought;
	int ItemAmount;
};

vector <ItemInInventory> Inventory;

int main()
{
	//Tells us when the game is over
	bool isDone = false;
	
	isDone = !CSVFile.LoadCSV("TestShop.csv");
		
	cout << "*** Welcome to the item shop! ***\n";

	//Game loop
	while (isDone == false) {

		printShop();

		printInventory();

		isDone = buyItems();

		cout << "\n\n\n";
	}

	return 0;
}

void printInventory()
{
	cout << "Your inventory is: \n";
	//We have to loop through each item one at a time and print it out
	for (int i = 0; i < Inventory.size(); i++) {

	cout << Inventory[i].ItemBought.ItemName << " x " << Inventory[i].ItemAmount << endl;

	}
	cout << endl;
}

void printShop()
{
	cout << "Shop Inventory: \n";
	//Print each shop item with a number in front
	for (int i = 0; i < CSVFile.GetArrayLength(); i++) {
		CSVFile.GetSpecificData(i).PrintShopList();
	}

}

bool buyItems()
{
	int input;
	bool ItemFound = false;

	cout << "What would you like to buy? Enter -1 to quit. Enter (" << 0 << "-" << CSVFile.GetArrayLength() << "):";
	cin >> input;

	if (input == -1) {
		return true; //the program is over
	}
	//Had to change this to stop a bug!
	if (input < 0 || input >= CSVFile.GetArrayLength()) {
		cout << "That was a bad input!\n";
		return false; //keep going
	}

	//Add one to the item that we bought
	for (int i = 0; i < Inventory.size(); i++)
	{
		if (Inventory[i].ItemBought.ItemName == CSVFile.GetSpecificData(input).ItemName)
		{
			Inventory[i].ItemAmount++;
			ItemFound = true;
		}
		
	}
	if (!ItemFound)
	{
		ItemInInventory in;
		in.ItemBought = CSVFile.GetSpecificData(input);
		in.ItemAmount = 1;
		Inventory.push_back(in);
	}

	return false;
}
