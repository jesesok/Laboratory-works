import random

min_elem = 0
max_elem = 45


def display_inventory_key(inventory):
    print('\nInventory: ')
    item_total = 0
    # Рабочий костыль
    inventory_keys = inventory.keys()
    inventory_keys = list(inventory_keys)
    inventory_keys.sort()
    for j in inventory_keys:
        print(inventory[j], j)
        item_total += inventory[j]
    # Красиво, но не работает
    # inventory_sort = sorted(inventory.items(), key=operator.itemgetter(0), reverse=False)
    print("\nTotal number of items: " + str(item_total))


def display_inventory_value(inventory):
    print('\nInventory: ')
    item_total = 0
    # Рабочий костыль
    inventory_sort = [(k, inventory[k]) for k in sorted(inventory.keys(), key=inventory.get, reverse=True)]
    for item in inventory_sort:
        print(item[1], item[0])
        item_total += item[1]
    # Красиво, но не работает
    # inventory_sort = sorted(inventory.items(), key=operator.itemgetter(1), reverse=True)
    print("\nTotal number of items: " + str(item_total))


def add_to_inventory(inventory, added_items):
    added_item_dict = dict()
    # Создание словаря драконьих предметов
    for items in added_items:
        if items in added_item_dict:
            added_item_dict[items] += 1
        else:
            added_item_dict[items] = 1

    # Вывод на экран sorted словаря драконьих предметов
    # for item in  sorted(dragon_item):
    #     print(dragon_item[item], item)

    result = {}
    for item in inventory.keys():
        if item in added_item_dict.keys():
            result[item] = inventory[item] + added_item_dict[item]
            added_item_dict.pop(item)
        else:
            result[item] = inventory[item]
        result = dict(added_item_dict.items() | result.items())
    return result


"""Создание инвентаря персонажа"""
stuff = {'rope': random.randint(min_elem, max_elem),
         'torch': random.randint(min_elem, max_elem),
         'gold coin': random.randint(min_elem, max_elem),
         'dagger': random.randint(min_elem, max_elem),
         'arrow': random.randint(min_elem, max_elem)}

"""Совмещение выпадаемого лута и инвентаря"""
heroes_loot = {'gold coin': random.randint(min_elem, max_elem),
               'rope': random.randint(min_elem, max_elem)}
dragon_loot = ['gold coin', 'dagger', 'gold coin', 'gold coin', 'ruby']

display_inventory_key(stuff)
heroes_loot = add_to_inventory(heroes_loot, dragon_loot)
display_inventory_value(heroes_loot)
