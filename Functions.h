#pragma once
#include "Data.h"
//Прототипы функций

void displayMenu(Player& player);
void enterShop(Player& player);
void addToCart(Player& player, const Item& item);
void displayInventory(Player player);
void addItemToShop();
void displayCart(Player player);