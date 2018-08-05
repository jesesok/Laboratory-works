#! python3
# Программа для незащищенного хранения паролей
import sys
import pyperclip

PASSWOORDS = {'email': 'IHateAllMen77',
              'blog': 'OhMyGod378',
              }
if len(sys.argv) < 2:
    print('Использование python pw.py [имя учётной записи] - копирование пароля учётной записи')
    sys.exit()

account = sys.argv[1]  # имя учётной записи - первый аргумент командной строки
if account in PASSWOORDS:
    pyperclip.copy(PASSWOORDS[account])
    print('Пароль для ' + account + ' скопирован в буфер')
else:
    print('Учётная запись ' + account + ' отсутсвует в списке')
