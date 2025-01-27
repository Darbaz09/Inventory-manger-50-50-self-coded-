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
	cout << "Enter price: ";
	cin >> newItem.price;
	inventory.push_back(newItem);
	cout << "Item added successfully\n";
}

void viewItems(const vector<Item>& inventory) {
	if (inventory.empty()) {
		cout << "No items in the inventory.\n";
	}
	cout << "\n--- Inventory Items ---\n";
	cout << "ID\tName\t\tQuantity\tPrice\n";
	for (const auto& item : inventory) {
		cout << item.id << "\t" << item.name << "\t\t" << item.quantity << "\t\t$" << item.price << item.price << "\n";
	}
}

void searchItem(const vector<Item>& inventory) {
	int searchId;
	cout << "Enter the item ID to serach: ";
	cin >> searchId;

	for (const auto& item : inventory) {
		if (item.id == searchId) {
			cout << "Item found:\n";
			cout << "ID: " << item.id << "\nName: " << item.name << "\nQuantity: " << item.quantity << "\nprice: $" << "\n";
			return;
		}
	}
	cout << "Item with ID " << searchId << " Not found.\n";
}


void deleteItem(vector<Item>& inventory) {
	int deleteId;
	cout << "Enter thei tem ID to delete: ";
	cin >> deleteId;


	for (auto it = inventory.begin(); it != inventory.end(); ++it) {
		if (it->id == deleteId) {
			inventory.erase(it);
			cout << "Item deleted sucessfully.\n";
			return;

		}
	}
	cout << "Item with ID " << deleteId << " not found.\n";
}


void editItem(vector<Item>& inventory) {
	int editId;
	cout << "Enter hte item ID to edit: ";
	cin >> editId;

	for (auto& item : inventory) {
		if (item.id == editId) {
			cout << "Editing item:\n";
			cout << "Current name: " << item.name << "\nEnter new name: ";
			cin.ignore();
			getline(cin, item.name);

			cout << "Current quantity: " << item.quantity << "\nEnter new quantity:	";
			cin >> item.quantity;

			cout << "Current price: $" << item.price << "\nEnter new price: ";
			cin >> item.price;
			cout << "Item updated successfully.\n";
			return;
		}
	}
	cout << "Item with ID " << editId << " not found.\n";
}
