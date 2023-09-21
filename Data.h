#pragma once
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
};
struct Player {
    vector <Item> cart;
    int gold = 100;
    vector<Item> inventory;
};
struct User {
    string username;
    string password;
};
vector<Item> weaponItems = {
    {"Двуручный меч", 50.00, Category::Weapon},
    {"Лук", 24.99, Category::Weapon},
    {"Посох", 10.00, Category::Weapon}
};
vector<Item> armourItems = {
    {"Тяжелая броня", 100.00, Category::Armour},
    {"Кожанка", 49.99, Category::Armour},
    {"Роба", 12.99, Category::Armour}
};
vector<Item> consumableItems = {
    {"Зелье лечения", 9.00, Category::Consumables},
    {"Зелье маны", 9.00, Category::Consumables},
    {"Зелье спешки", 15.69, Category::Consumables}
};