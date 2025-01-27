#include <iostream>
#include <vector>
#include <string>
using namespace std;


struct Item {
	int id;
	string name;
	int quantity;
	double price;
};


void addItem(vector<Item>& inventory);
void viewItems(const vector<Item>& inventory);
void searchItem(const vector<Item>& inventory);
void deleteItem(vector<Item>& inventory);
void editItem(vector<Item>& inventory);

int main() {
	vector<Item> inventory;
	int choice;


		do {
			cout << "\n--- Inventory Management System ---\n";
			cout << "1. Add Item\n";
			cout << "2. View Items\n";
			cout << "3. Search for an Item\n";
			cout << "4. Edit an Item\n";
			cout << "5. Delete an Item\n";
			cout << "6. Exit\n";
			cout << "Enter your choice: ";
			cin >> choice;

			switch (choice) {
			case 1: 
				addItem(inventory);
				break;
			case 2:
				viewItems(inventory);
				break;
			case 3:
				searchItem(inventory);
			case 4:
				editItem(inventory);
				break;
			case 6:
				cout << "Exiting the system. Goodbye!\n";
				break;
			default: 
				cout << "Invalid choice. Please try again.\n";
			}
		} while (choice != 6);
		

		return 0;

}


void addItem(vector<Item>& inventory) {
	Item newItem;
	cout << "Enter item ID: ";
	getline(cin, newItem.name);
	cin.ignore();
	cout << "Enter the item name: ";
	cout << "Enter quantity: ";
	cin >> newItem.quantity;

}