#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Item
{
	std::string ItemName;
	std::string ItemDesc;
	std::string ItemPic;
	int			Cost;
	int			LevelRequired;

	void PrintShopList() { std::cout<< "Item Name: " << ItemName << "\n" << "Item Description: " << ItemDesc << "\n" << "Item picture: "
		<< ItemPic << "\n" << "Item cost: " << Cost << "\n" << "Level Required: " << LevelRequired << "\n\n"; }
};

class ShopItems
{
	public:
		bool LoadCSV(std::string Location);
		//Item* GetSpecificData(int LocationArray) { return &ItemArray[LocationArray];}
		int GetArrayLength() { return ItemArray.size();}
		Item GetSpecificData(int LocationArray) { return ItemArray[LocationArray]; }

	private:
		std::vector<Item> ItemArray;

		void ReadString(std::ifstream& _ip, std::string& _string); //Automaticlly reads string from CSV
		void ReadStringAndEndLine(std::ifstream& _ip, std::string& _string); //Automaticlly reads string from CSV and then moves on to next line

		void ReadInt(std::ifstream& _ip, int& _int); //Automaticly reads value as string then changes it into an int
		void ReadIntAndEndLine(std::ifstream& _ip, int& _int);
};

