# ПРИМЕР ЗАПУСКАЕТ МОТОР С УКАЗАНИЕМ СКОРОСТИ:   #
                                                  #
from pyiArduinoI2Cmotor import *                #   Подключаем библиотеку для работы с мотором I2C-flash.
mot = pyiArduinoI2Cmotor(0x09)                      #   Объявляем объект mot для работы с функциями и методами библиотеки pyiArduinoI2Cmotor, указывая адрес модуля на шине I2C.
                                                  #   Если объявить объект без указания адреса (mot = pyiArduinoI2Cmotor ), то адрес будет найден автоматически.
mot.begin()                                   #   Инициируем работу с мотором.
                                                  #
while True:                                      #
    mot.setSpeed(  60, MOT_RPM)                   #   Запускаем мотор на скорости   60 об/мин, что соответствует 1 об/сек.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( 120, MOT_RPM)                   #   Запускаем мотор на скорости  120 об/мин, что соответствует 2 об/сек.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(  60, MOT_RPM)                   #   Запускаем мотор на скорости   60 об/мин, что соответствует 1 об/сек.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(   0, MOT_RPM)                   #   Запускаем мотор на скорости    0 об/мин, что соответствует остановке мотора.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( -60, MOT_RPM)                   #   Запускаем мотор на скорости  -60 об/мин, что соответствует -1 об/сек.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(-120, MOT_RPM)                   #   Запускаем мотор на скорости -120 об/мин, что соответствует -2 об/сек.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( -60, MOT_RPM)                   #   Запускаем мотор на скорости  -60 об/мин, что соответствует -1 об/сек.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(   0, MOT_RPM)                   #   Запускаем мотор на скорости    0 об/мин, что соответствует остановке мотора.
    sleep(5)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
