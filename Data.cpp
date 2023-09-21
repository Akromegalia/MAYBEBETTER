
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

using System.Collections.Generic;

enum Category { Weapon, Armour, Consumables }

struct Item
{
    public string Name;
    public double Price;
    public Category Category;
}

struct Player
{
    public List<Item> Cart;
    public int Gold;
    public List<Item> Inventory;
}

struct User
{
    public string Username;
    public string Password;
}

static class GameData
{
    public static List<Item> WeaponItems = new List<Item>
    {
        new Item { Name = "Двуручный меч", Price = 50.00, Category = Category.Weapon },
        new Item { Name = "Лук", Price = 24.99, Category = Category.Weapon },
        new Item { Name = "Посох", Price = 10.00, Category = Category.Weapon }
    };

    public static List<Item> ArmourItems = new List<Item>
    {
        new Item { Name = "Тяжелая броня", Price = 100.00, Category = Category.Armour },
        new Item { Name = "Кожанка", Price = 49.99, Category = Category.Armour },
        new Item { Name = "Роба", Price = 12.99, Category = Category.Armour }
    };

    public static List<Item> ConsumableItems = new List<Item>
    {
        new Item { Name = "Зелье лечения", Price = 9.00, Category = Category.Consumables },
        new Item { Name = "Зелье маны", Price = 9.00, Category = Category.Consumables },
        new Item { Name = "Зелье спешки", Price = 15.69, Category = Category.Consumables }
    };
}
