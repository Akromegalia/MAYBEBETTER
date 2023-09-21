#include "Functions.h"

void print_weapon_items() {
    cout << "Оружие:" << endl;
    int itemIndex = 1;

    for (const Item& item : weaponItems) {
        if (item.category == Category::Weapon) {
            cout << itemIndex << ". " << item.name << " - " << item.price << " золота" << endl;
            itemIndex++;
        }
    }
}
void print_armour_items() {
    cout << "Броня:" << endl;
    int itemIndex = 1;

    for (const Item& item : armourItems) {
        if (item.category == Category::Armour) {
            cout << itemIndex << ". " << item.name << " - " << item.price << " золота" << endl;
            itemIndex++;
        }
    }
}
void print_consum_items() {
    cout << "Расходники:" << endl;
    int itemIndex = 1;

    for (const Item& item : consumableItems) {
        if (item.category == Category::Consumables) {
            cout << itemIndex << ". " << item.name << " - " << item.price << " золота" << endl;
            itemIndex++;
        }
    }
}
void enterShop(Player& player) {
    bool returnToMenu = false;

    while (!returnToMenu) {
        cout << "Выберите категорию:" << endl;
        cout << "1. Оружие" << endl;
        cout << "2. Броня" << endl;
        cout << "3. Расходники" << endl;
        cout << "4. Вернуться в меню" << endl;
        cout << "Введите номер категории: ";

        int categoryChoice;
        cin >> categoryChoice;

        switch (categoryChoice) {
        case 1:
            cout << "Вы выбрали категорию 'Оружие':" << endl;
            print_weapon_items();
            int itemChoice;
            cout << "Введите номер предмета для добавления в корзину (или 0 для выхода из категории): ";
            cin >> itemChoice;
            if (itemChoice >= 1 && itemChoice <= weaponItems.size() && weaponItems[itemChoice - 1].category == Category::Weapon) {
                addToCart(player,weaponItems[itemChoice - 1]);
                cout << weaponItems[itemChoice - 1].name << " успешно добавлен в корзину!" << endl;
            }
            else if (itemChoice == 0) {
                // Вернуться назад
            }
            else {
                cout << "Некорректный выбор предмета." << endl;
            }
            break;

        case 2:
            cout << "Вы выбрали категорию 'Броня':" << endl;
            print_armour_items();
            cout << "Введите номер предмета для добавления в корзину (или 0 для выхода из категории): ";
            cin >> itemChoice;
            if (itemChoice >= 1 && itemChoice <= armourItems.size() && armourItems[itemChoice - 1].category == Category::Armour) {
                addToCart(player, armourItems[itemChoice - 1]);
                cout << armourItems[itemChoice - 1].name << " успешно добавлен в корзину!" << endl;
            }
            else if (itemChoice == 0) {
                // Вернуться назад
            }
            else {
                cout << "Некорректный выбор предмета." << endl;
            }
            break;

        case 3:
            cout << "Вы выбрали категорию 'Расходники':" << endl;
            print_consum_items();
            cout << "Введите номер предмета для добавления в корзину (или 0 для выхода из категории): ";
            cin >> itemChoice;
            if (itemChoice >= 1 && itemChoice <= consumableItems.size() && consumableItems[itemChoice - 1].category == Category::Consumables) {
                addToCart(player, consumableItems[itemChoice - 1]);
                cout << consumableItems[itemChoice - 1].name << " успешно добавлен в корзину!" << endl;
            }
            else if (itemChoice == 0) {
                // Вернуться назад
            }
            else {
                cout << "Некорректный выбор предмета." << endl;
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
    player.cart.push_back(item);
}
void displayInventory(Player player) {
    // Display player's inventory
}
void addItemToShop() {
    int key;
    cout << "Выберите категорию: " << endl;
    cout << "1. Оружие" << endl;
    cout << "2. Броня" << endl;
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
        newItem.category = Category::Weapon;
        weaponItems.push_back(newItem);
        cout << "Предмет успешно добавлен в категорию 'Оружие'!" << endl;
        break;

    case 2:
        cout << "Введите название предмета: ";
        cin.ignore();
        getline(cin, newItem.name);
        cout << "Введите цену за предмет: ";
        cin >> newItem.price;
        newItem.category = Category::Armour;
        armourItems.push_back(newItem);
        cout << "Предмет успешно добавлен в категорию 'Броня'!" << endl;
        break;

    case 3:
        cout << "Введите название предмета: ";
        cin.ignore();
        getline(cin, newItem.name);
        cout << "Введите цену за предмет: ";
        cin >> newItem.price;
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
        cout << item.name << " - " << item.price << " золота" << endl;
        total += item.price;
    }

    cout << "Всего " << total << " золота" << endl;
}