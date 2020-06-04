#include "ShopItems.h"
using namespace std;

void ShopItems::ReadString(std::ifstream& _ip, std::string& _string)
{

	_ip.ignore(2, '<'); //ignores all characters until it reaches the start of the string

	getline(_ip, _string, '>');   //reads string

	_ip.ignore(2, ','); //sets to next collumn
}

void ShopItems::ReadStringAndEndLine(std::ifstream& _ip, std::string& _string)
{

	_ip.ignore(2, '<'); //ignores all characters until it reaches the start of the string

	getline(_ip, _string, '>'); //reads string

	_ip.ignore(2, '\n'); //sets to next collumn
}

void ShopItems::ReadInt(std::ifstream& _ip, int& _int)
{
	string TempString;

	getline(_ip, TempString, ','); //Reads Line up to the next comma as String

	_int = stoi(TempString); //Changes String Value read in from file to an int

}

void ShopItems::ReadIntAndEndLine(std::ifstream& _ip, int& _int)
{
	string TempString;

	getline(_ip, TempString, '\n');

	_int = stoi(TempString); //Changes String Value read in from file to an int
}

bool ShopItems::LoadCSV(std::string Location)
{
	ifstream ip(Location);

	if (!ip.is_open())
	{
		cout << "ERROR: File has failed to Open" << '\n';
		return false;
	}

	ip.ignore(5000, '\n');
	ip.ignore(5000, '\n');

	while (ip.peek() != EOF)
	{
		Item NewItem;
		ReadString(ip, NewItem.ItemName);
		ReadString(ip, NewItem.ItemDesc);
		ReadString(ip, NewItem.ItemPic);
		ReadInt(ip, NewItem.Cost);
		ReadIntAndEndLine(ip, NewItem.LevelRequired);

		ItemArray.push_back(NewItem);
	}

	ip.close();
	ip.clear();

	return true;
}
