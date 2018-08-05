#! python3
# phoneAndEmail.py - Находит телефонные номера и адреса электронной почты в буфере обмена.
import re

import pyperclip

phoneRegex = re.compile(r'''( # Регулярное выражение для телефонных номеров
(\d{3}|\d{3}\)}? # территориальный код
(\s|-|\.)? # разделитель
(\d{3}) # первые три цифры
(\s|-|\.) # разделитель 
(\d{4}) # последние четыре цифры
(\s*{ext|x|ext.)\s*(\d{2,5}))? # добавочный номер
)''', re.VERBOSE)

emailRegex = re.compile(r'''( # Регулярное выражение для адресов электронной почты 
[a-zA-Z-0-9._%+-]+ # имя пользователя
@ # знак @
[a-zA-Z0-9.-]+ # имя домена
(\.[a-zA-Z]{2,4}) # остальная часть адреса
)''', re.VERBOSE)

# Поиск соответствий в тексте, содержащемся в буфере обмена
text = str(pyperclip.paste())
matches = []
for groups in phoneRegex.findall(text):
    phoneNum = '-'.join([groups[1], groups[3], groups[5]])
    if groups[0] != '':
        phoneNum += ' x' + groups[8]
    matches.append(phoneNum)
for groups in emailRegex.findall(text):
    matches.append(groups[0])

if len(matches) > 0:
    pyperclip.copy('\n'.join(matches))
    print('Скопировано в буфер обмена:')
    print('\n'.join(matches))
else:
    print('Телефонные номера и адреса электронной почты не обнаружены')
