#! python3
# bulletPointAdder - Добавляет маркеры Википедии в начало каждой строки текста, сохранненого в буфере обмена
import pyperclip

text = pyperclip.paste()

lines = text.split('\n')
for _ in range(len(lines)):
    lines[_] = '* ' + lines[_]
text = '\n'.join(lines)

pyperclip.copy(text)
