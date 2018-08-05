# -----------------------------------------------
# Program by Liskunov Roman
#
#
#  Version  Date        Info
#  1.0      2018    Initial Version
#
# -----------------------------------------------
import random

random_list = random.sample(range(-100, 100), 20)
random_list.sort()


def binary_search(search_list, required, start, stop):
    if start > stop:
        return False
    else:
        mid = (start + stop) // 2
        if required == search_list[mid]:
            return mid
        elif required < search_list[mid]:
            return binary_search(search_list, required, start=start, stop=mid - 1)
        else:
            return binary_search(search_list, required, start=mid + 1, stop=stop)


search = random.randint(-100, 100)
x = binary_search(random_list, search, 0, len(random_list))
print(random_list)
if not x:
    print("Item ", search, " not found!")
else:
    print("Item ", search, " found at index: ", x)
