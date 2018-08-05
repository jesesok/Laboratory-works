import sys


def collatz_sequence(number):
    """ Последовательность Коллатца
    Описание: По заданому числу выводит все преобразования с ним до тех пор, пока не получит единицу"""
    try:
        if number == 'exit':
            print("Program completed successfully")
            sys.exit()
        else:
            number = int(number)
            print(number)
            while number != 1:
                if number % 2 == 0:
                    number = round(number / 2)
                    print(number)
                elif number % 2 == 1:
                    number = round(number * 3 + 1)
                    print(number)
    except ValueError:
        print("Input information not integer")


def fibonacci_sequence(number):
    """Последовательность Фибоначчи
    Описание: По номеру числа выводит его самого"""
    try:
        if number == 'exit':
            print("Program completed successfully")
            sys.exit()
        else:
            a, b = 0, 1
            for sequence in range(int(number)):
                a, b = b, a + b
            return a
    except ValueError:
        print("Input information not integer")


def amount_fibonacci(amount_limit):
    amount = 0
    for sequence in range(amount_limit):
        amount += fibonacci_sequence(sequence)
    return amount


if __name__ == '__main__':
    collatz_sequence(3)
