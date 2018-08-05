#! python3
# randomQuizGenerator.py - Создает экзаменационные билеты с вопросами и ответами,
# расположенными в случайном порядке, вместе с ключами ответов.
import random

# Данные билета. Ключи - названия штатов, значения - столицы
capitals = {
    'Alabama': 'Montgomery', 'Alaska': 'Juneau',
    'Arizona': 'Phoenix', 'Arkansas': 'Little Rock',
    'California': 'Sacramento', 'Colorado': 'Denver',
    'Connecticut': 'Hartford', 'Delaware': 'Dover',
    'Florida': 'Tallahassee', 'Georgia': 'Atlanta',
    'Hawaii': 'Honolulu', 'Idaho': 'Boise',
    'Illinois': 'Springfield', 'Indiana': 'Indianapolis',
    'Iowa': 'Des Moines', 'Kansas': 'Topeka',
    'Kentucky': 'Frankfort', 'Louisiana': 'Baton Rouge',
    'Maine': 'Augusta', 'Maryland': 'Annapolis',
    'Massachusetts': 'Boston', 'Michigan': 'Lansing',
    'Minnesota': 'Saint Paul', 'Mississippi': 'Jackson',
    'Missouri': 'Jefferson City', 'Montana': 'Helena',
    'Nebraska': 'Lincoln', 'Nevada': 'Carson City',
    'New Hampshire': 'Concord', 'New Jersey': 'Trenton',
    'New Mexico': 'Santa Fe', 'New York': 'Albany',
    'North Carolina': 'Raleigh', 'North Dakota': 'Bismarck',
    'Ohio': 'Columbus', 'Oklahoma': 'Oklahoma City',
    'Oregon': 'Salem', 'Pennsylvania': 'Harrisburg',
    'Rhone Island': 'Providence', 'South Carolina': 'Columbia',
    'South Dakota': 'Pierre', 'Tennessee': 'Nashville',
    'Texas': 'Austin', 'Utah': 'Salt Lake City',
    'Vermont': 'Montpelier', 'Virginia': 'Richmond',
    'Washington': 'Olympia', 'West Virginia': 'Charleston',
    'Wisconsin': 'Madison', 'Wyoming': 'Cheyenne',
}

numberStudent = 35
numberQuestion = 10
# Генерация 35 файлов билетов
for quizNum in range(numberStudent):
    quizFile = open(f'capitalsQuiz{quizNum + 1}.txt', 'w')
    answerKeyFile = open(f'capitalsQuizAnswers{quizNum + 1}.txt', 'w')

    quizFile.write('Имя:\n\nДата:\n\nКурс:\n\n')
    quizFile.write((' ' * 15) + f'Проверка знания столиц штатов (Билет {quizNum + 1})')
    quizFile.write('\n\n')

    states = list(capitals.keys())
    random.shuffle(states)

    for questionNum in range(numberQuestion):
        correctAnswer = capitals[states[questionNum]]
        wrongAnswer = list(capitals.values())
        del wrongAnswer[wrongAnswer.index(correctAnswer)]
        wrongAnswer = random.sample(wrongAnswer, 3)
        answerOptions = wrongAnswer + [correctAnswer]
        random.shuffle(answerOptions)

        quizFile.write(f'{questionNum + 1}. Выберите столицу шатта {states[questionNum]}.\n')

        for j in range(4):
            quizFile.write(f' {"ABCD"[j]}. {answerOptions[j]}\n')
        quizFile.write('\n')
        answerKeyFile.write(f' {questionNum + 1}. {"ABCD"[answerOptions.index(correctAnswer)]}\n')
    quizFile.close()
    answerKeyFile.close()
