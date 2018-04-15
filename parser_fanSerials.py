import shutil

from bs4 import BeautifulSoup
import requests

url = "http://fanserials.pro"

# page_1 = requests.get(url)
# print(page_1.status_code)  # проверка на существование сайта
# print(page_1.text)  # html страницы

page = requests.get(url).text
soup = BeautifulSoup(page)
# print(soup.findAll('a'))  # все ссылки, которые есть на этой странице

divs = soup.find_all("div", {'class': 'serial-bottom'})


def find_content():
    for div in divs:
        div_title = div.find('div', {'class': 'field-title'})
        link_text = div_title.find('a').text
        print(link_text)
    return


print(find_content())
