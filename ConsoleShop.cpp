#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

enum class Category { Weapon, Armour, Consumables };



struct Item {
    string name;
    double price;
    Category category;
    int quantity;
};
struct Player {
    vector <Item> cart;
    int gold = 1000.00;
};

vector<Item> weaponItems = {
    {"Quelling Blade", 100, Category::Weapon, 1},
    {"Claymore", 400, Category::Weapon,3},
    {"Daedalus", 600, Category::Weapon,2}
};
vector<Item> armourItems = {
    {"Vanguard", 200, Category::Armour, 10},
    {"Eternal Shroud", 490, Category::Armour, 12},
    {"Black King Bar", 1200, Category::Armour,4}
};  
vector<Item> consumableItems = {
    {"Tango", 100, Category::Consumables, 4},
    {"Clarity", 50, Category::Consumables, 5},
    {"Healing Salve", 150, Category::Consumables, 6}
};  
void displayMenu(Player& player);
void enterShop(Player& player);
void addToCart(Player& player, const Item& item);
void addItemToShop();
void displayCart(Player player);
void print_weapon_items() {
    cout << "Урон:" << endl;
    int itemIndex = 1;

    for (const Item& item : weaponItems) {
        if (item.category == Category::Weapon) {
            cout << itemIndex << ". " << item.name << " - " << item.price << " золота " << " осталось " << item.quantity << endl;
            itemIndex++;
        }
    }
}
void print_armour_items() {
    cout << "Защита:" << endl;
    int itemIndex = 1;

    for (const Item& item : armourItems) {
        if (item.category == Category::Armour) {
            cout << itemIndex << ". " << item.name << " - " << item.price << " золота" << " осталось " << item.quantity << endl;
            itemIndex++;
        }
    }
}
void print_consum_items() {
    cout << "Расходники:" << endl;
    int itemIndex = 1;

    for (const Item& item : consumableItems) {
        if (item.category == Category::Consumables) {
            cout << itemIndex << ". " << item.name << " - " << item.price << " золота" << " осталось " << item.quantity << endl;
            itemIndex++;
        }
    }
}


const string Password = "roshan";

int main() {

    Player player;
    string storedPassword;
    while (true) {
        displayMenu(player);
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            enterShop(player);
            break;
        case 2:
            displayCart(player);
            break;
        case 3:
            cout << "Введите пароль для добавления предмета: ";
            cin >> storedPassword;

            if (storedPassword == Password) {
                addItemToShop();
            }
            else {
                cout << "Неправильный пароль. Добавление предметов запрещено." << endl;
            }
            break;
        case 4:
            exit(0);
        default:
            cout << "Некорректный выбор." << endl;
            break;
        }
    }
}
void displayMenu(Player& player) {
    cout << "Secret Shop" << endl;
    cout << "1. Войти в магазин" << endl;
    cout << "2. Посмотреть корзину" << endl;
    cout << "3. Добавить свой предмет в магазин" << endl;
    cout << "4. Выйти" << endl;
    cout << player.gold << " - ваше золото" << endl;
}
void enterShop(Player& player) {
    bool returnToMenu = false;

    while (!returnToMenu) {
        cout << "Выберите категорию:" << endl;
        cout << "1. Урон" << endl;
        cout << "2. Защита" << endl;
        cout << "3. Расходники" << endl;
        cout << "4. Вернуться в меню" << endl;
        cout << "Введите номер категории: ";

        int categoryChoice;
        cin >> categoryChoice;

        switch (categoryChoice) {
        case 1:
            cout << "Вы выбрали категорию 'Урон':" << endl;
            print_weapon_items();
            int itemChoice;
            cout << "Введите номер предмета для добавления в корзину (или 0 для выхода из категории): ";
            cin >> itemChoice;
            if (itemChoice >= 1 && itemChoice <= weaponItems.size() && weaponItems[itemChoice - 1].category == Category::Weapon && player.gold >= weaponItems[itemChoice - 1].price) {
                if (weaponItems[itemChoice - 1].quantity > 0) { // Проверяем доступное количество
                    addToCart(player, weaponItems[itemChoice - 1]);
                    player.gold -= weaponItems[itemChoice - 1].price;
                    weaponItems[itemChoice - 1].quantity--; // Уменьшаем доступное количество
                }
                else {
                    cout << "Извините, этот предмет больше недоступен." << endl;
                }
            }
            else if (itemChoice == 0) {
                // Вернуться назад
            }
            else {
                cout << "Некорректный выбор предмета или у вас недостаточно золота для его покупки." << endl;
            }
            break;


        case 2:
            cout << "Вы выбрали категорию 'Защита':" << endl;
            print_armour_items();
            cout << "Введите номер предмета для добавления в корзину (или 0 для выхода из категории): ";
            cin >> itemChoice;
            if (itemChoice >= 1 && itemChoice <= armourItems.size() && armourItems[itemChoice - 1].category == Category::Armour && player.gold >= armourItems[itemChoice - 1].price) {
                if (armourItems[itemChoice - 1].quantity > 0) { // Проверяем доступное количество
                    addToCart(player, armourItems[itemChoice - 1]);
                    armourItems[itemChoice - 1].quantity--; // Уменьшаем доступное количество
                    player.gold -= armourItems[itemChoice - 1].price;
                }
                else {
                    cout << "Извините, этот предмет больше недоступен." << endl;
                }
            }
            else if (itemChoice == 0) {
                // Вернуться назад
            }
            else {
                cout << "Некорректный выбор предмета или у вас недостаточно золота для его покупки." << endl;
            }
            break;

        case 3:
            cout << "Вы выбрали категорию 'Расходники':" << endl;
            print_consum_items();
            cout << "Введите номер предмета для добавления в корзину (или 0 для выхода из категории): ";
            cin >> itemChoice;
            if (itemChoice >= 1 && itemChoice <= consumableItems.size() && consumableItems[itemChoice - 1].category == Category::Consumables && player.gold >= consumableItems[itemChoice - 1].price) {
                if (consumableItems[itemChoice - 1].quantity > 0) { // Проверяем доступное количество
                    addToCart(player, consumableItems[itemChoice - 1]);
                    player.gold -= consumableItems[itemChoice - 1].price; // Отнимаем золото у игрока
                    consumableItems[itemChoice - 1].quantity--; // Уменьшаем доступное количество
                }
                else {
                    cout << "Извините, этот предмет больше недоступен." << endl;
                }
            }
            else if (itemChoice == 0) {
                // Вернуться назад
            }
            else {
                cout << "Некорректный выбор предмета или у вас недостаточно золота для его покупки." << endl;
            }
            break;
        case 4:
            returnToMenu = true;
            break;
        default:
            cout << "Некоректный выбор" << endl;
        }
    }
}
void addToCart(Player& player, const Item& item) {
    // Проверяем, есть ли у игрока достаточно золота
    if (player.gold >= item.price) {
        player.cart.push_back(item); 
        cout << item.name << " успешно добавлен в корзину за " << item.price << " золота!" << endl;
       
    }
}

void addItemToShop() {
    int key;
    cout << "Выберите категорию: " << endl;
    cout << "1. Урон" << endl;
    cout << "2. Защита" << endl;
    cout << "3. Расходники" << endl;
    cin >> key;

    Item newItem;

    switch (key) {
    case 1:
        cout << "Введите название предмета: ";
        cin.ignore();
        getline(cin, newItem.name);
        cout << "Введите цену за предмет: ";
        cin >> newItem.price;
        cout << "Введите количество предметов доступных для покупки: ";
        cin >> newItem.quantity;
        newItem.category = Category::Weapon;
        weaponItems.push_back(newItem);
        cout << "Предмет успешно добавлен в категорию 'Урон'!" << endl;
        break;

    case 2:
        cout << "Введите название предмета: ";
        cin.ignore();
        getline(cin, newItem.name);
        cout << "Введите цену за предмет: ";
        cin >> newItem.price;
        cout << "Введите количество предметов доступных для покупки: ";
        cin >> newItem.quantity;
        newItem.category = Category::Armour;
        armourItems.push_back(newItem);
        cout << "Предмет успешно добавлен в категорию 'Защита'!" << endl;
        break;

    case 3:
        cout << "Введите название предмета: ";
        cin.ignore();
        getline(cin, newItem.name);
        cout << "Введите цену за предмет: ";
        cin >> newItem.price;
        cout << "Введите количество предметов доступных для покупки: ";
        cin >> newItem.quantity;
        newItem.category = Category::Consumables;
        consumableItems.push_back(newItem);
        cout << "Предмет успешно добавлен в категорию 'Расходники'!" << endl;
        break;

    default:
        cout << "Некорректный выбор категории." << endl;
        break;
    }
}
void displayCart(Player player) {
    cout << "Содержимое корзины:" << endl;
    double total = 0;

    for (const Item& item : player.cart) {
        cout << item.name << " - " << item.price << " золота " << item.quantity << " штук(а)" << endl;
        total += item.price;
    }

    cout << "Всего " << total << " золота" << endl;
}
