# nice_table.py - обрабатывает список списков строк и выводит их в форме красивой таблицы
# Задача (кое-как) решена с помощью PrettTable
# TODO: Нормальное решение задачи

from prettytable import PrettyTable

tableData = PrettyTable([['apples', 'oranges', 'cherries', 'banana'],
                         ['Alice', 'Bob', 'Carol', 'David'],
                         ['dogs', 'cats', 'moose', 'goose']
                         ])
print(tableData)


def print_table():
    pass
