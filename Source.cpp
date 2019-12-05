#include<iostream>
using namespace std;

//global variables
int money = 100;
string inventory[10];
int inventoryNums[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

void Shop(); //function decleration

int main() {

	Shop(); //function call

}

//function defenition
void Shop() {

	//local variables for function
	int input;
	int shopNums[5] = { 5, 5, 5, 5, 2 }; //keeps track of how many are left
	string shopItems[5] = { "Arrows","Potions","Keys","Socks", "Burnt Waffle" };
	int shopPrices[5] = { 10, 50, 30, 20, 75 };

	do {
		cout << "Welcome to the shop, You have " << money << " coins." << endl;
		cout << "Press 1 to view items for sale, 2 to purchase, 3 to see your inventory, 4 to loan 100 coins, and 0 to quit." << endl;
		cin >> input;

		switch (input) {
		case 0: //quits shop
			cout << "Thank you for your visit, come again soon!" << endl;
			break;
		case 1: //view items
			cout << "Here's what we have: " << endl;
			for (int i = 0; i < 5; i++) {
				cout << shopNums[i] << " " << shopItems[i] << " (" << shopPrices[i] << " coins)" << endl;
			}
			break;
		case 2: //purchase items
			cout << "Press 1 to purchase arrows, 2 for potions, 3 for keys, 4 for socks, 5 for a burnt waffle: ";
			cin >> input;
			cout << endl;
		
			if (shopNums[input - 1] <= 0) { //check if there are any left
				cout << "Sorry, this item is sold out..." << endl;
			}
			else if (money < shopPrices[input - 1]) { //check if you have enough money
				cout << "Sorry, you are brookkee..." << endl;
			}
			else {
				inventoryNums[input - 1] += 1; //add one to player's inventory numbers
				inventory[input - 1] = shopItems[input - 1]; //place item in player's inventory
				shopNums[input - 1] -= 1; //subtract from shop's supplies
				money -= shopPrices[input - 1]; //subtract player's money
			}
			break;

		case 3: //view player inventory
			cout << "Here's your current inventory: " << endl;
			for (int i = 0; i < 5; i++) {
				if (inventoryNums[i] > 0) {
					cout << inventory[i] << " : " << inventoryNums[i] << endl;
				}
			}
			break;

		case 4:
			cout << "Here are your 100 coins :)" << endl;
			cout << "DO NOT FORGET TO PAY THEM BACK!" << endl;
			money += 100;
			break;

		default: //if the user says nonsense
			cout << "Perdon, no entiendo..." << endl;
		}
	} while (input != 0);

}