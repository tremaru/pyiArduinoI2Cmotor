# ДАННЫЙ ПРИМЕР ИНФОРМИРУЕТ О НАБОРЕ СКОРОСТИ:

from pyiArduinoI2Cmotor import *                    #   Подключаем библиотеку для работы с мотором I2C-flash.
mot = pyiArduinoI2Cmotor(0x09)                      #   Объявляем объект mot для работы с функциями и методами библиотеки pyiArduinoI2Cmotor, указывая адрес модуля на шине I2C.
                                                    #   Если объявить объект без указания адреса (mot = pyiArduinoI2Cmotor ), то адрес будет найден автоматически.
while True:                                         #
    print("Запускаем мотор 100 об/мин.")            #   Выводим сообщение о запуске мотора.
    mot.setSpeed(100, MOT_RPM)                      #   Запускаем мотор на скорости 100 об/мин.
    while mot.getError()==MOT_ERR_SPD:              #   Пока сохраняется ошибка скорости.
        print("Реальная скорость = ")               #   Выводим сообщение.
        print( mot.getSpeed(MOT_RPM) )              #   Выводим реальное значение скорости.
        print(" об/мин.\r\n")                       #   Выводим сообщение.

    print("Скорость набрана.")                      #   Выводим сообщение.
    sleep(.5)                                       #   Приостанавливаем выполнение скрипта на 500 миллисекунд.
    print("Останавливаем мотор.")                   #   Выводим сообщение.
    mot.setStop()                                   #   Останавливаем мотор.
    print("====================")                   #   Выводим разделитель.
    sleep(.5)                                       #   Приостанавливаем выполнение скрипта на 500 миллисекунд.
