def fibonacci_of_any_element(n):
    a = 0
    b = 1
    for __ in range(n):
        a, b = b, a + b
    return a


def fibonacci_of_all_element(maximum):  # генератор (а не функция, т.к. оператор return заменён на yield)
    a, b = 0, 1
    while a <= maximum:
        yield a  # return a, + запоминаем место рестарта для следующего вызова
        a, b = b, a + b  # параллельное присваивание, которое выполняется одновременно и параллельно


print("Тысячный элемент последовательности Фибоначчи равен: ", end='')
print(fibonacci_of_any_element(1000))
your_element = int(input("Введите число до которого вас интересует сумма включительно: "))
amount = 0
for _ in fibonacci_of_all_element(fibonacci_of_any_element(your_element)):
    amount += _

print(amount)
