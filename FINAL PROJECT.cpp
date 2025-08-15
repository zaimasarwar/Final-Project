#include <iostream>
using namespace std;
class MenuItem {
public:
    string name;
    float price;

    MenuItem(string n, float p) {
        name = n;
        price = p;
    }
};

class Restaurant {
private:
    float totalBill;

public:
    Restaurant() {
        totalBill = 0;
    }

    void resetBill() {
        totalBill = 0;
    }

    void showMenu() {
        cout << "\n=====  Restaurant Menu =====" << endl;
        cout << "1. Burger      - Rs.450" << endl;
        cout << "2. Pizza       - Rs.800" << endl;
        cout << "3. Fries       - Rs.200" << endl;
        cout << "4. Sandwich    - Rs.350" << endl;
        cout << "5. Pasta       - Rs.1200" << endl;
        cout << "6. Cold Drink  - Rs.200" << endl;
        cout << "7. Exit & Show Bill" << endl;
    }

    void order(int choice, int quantity) {
        MenuItem burger("Burger", 450);
        MenuItem pizza("Pizza", 800);
        MenuItem fries("Fries", 200);
        MenuItem sandwich("Sandwich", 350);
        MenuItem pasta("Pasta", 1200);
        MenuItem drink("Cold Drink", 200);
        switch (choice) {
        case 1:
            totalBill += burger.price * quantity;
            cout << quantity << " " << burger.name << "(s) added!" << endl;
            break;
        case 2:
            totalBill += pizza.price * quantity;
            cout << quantity << " " << pizza.name << "(s) added!" << endl;
            break;
        case 3:
            totalBill += fries.price * quantity;
            cout << quantity << " " << fries.name << "(s) added!" << endl;
            break;
        case 4:
            totalBill += sandwich.price * quantity;
            cout << quantity << " " << sandwich.name << "(s) added!" << endl;
            break;
        case 5:
            totalBill += pasta.price * quantity;
            cout << quantity << " " << pasta.name << "(s) added!" << endl;
            break;
        case 6:
            totalBill += drink.price * quantity;
            cout << quantity << " " << drink.name << "(s) added!" << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    void showBill() {
        cout << "\n===== Final Bill =====" << endl;
        cout << "Total Amount: Rs." << totalBill << endl;
        cout << "Thank you for visiting!" << endl;
    }
};

int main() {
    Restaurant myRestaurant;
    int choice, quantity;
    char moreOrders;

    do {
        do {
            myRestaurant.showMenu();
            cout << "\nEnter your choice: ";
            cin >> choice;

            if (choice >= 1 && choice <= 6) {
                cout << "Enter quantity: ";
                cin >> quantity;
                myRestaurant.order(choice, quantity);
            } else if (choice == 7) {
                myRestaurant.showBill();
            } else {
                cout << "Invalid choice! Try again." << endl;
            }

        } while (choice != 7);

        cout << "\nDo you want to place another order? (Y/N): ";
        cin >> moreOrders;
        if (moreOrders == 'Y' || moreOrders == 'y') {
            myRestaurant.resetBill();
        }

    } while (moreOrders == 'Y' || moreOrders == 'y');

    cout << "\nGoodbye! Have a nice day!" << endl;
    return 0;
}

