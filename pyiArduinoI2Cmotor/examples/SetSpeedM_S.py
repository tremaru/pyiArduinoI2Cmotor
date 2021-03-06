# ПРИМЕР ЗАПУСКАЕТ МОТОР С УКАЗАНИЕМ СКОРОСТИ:

from pyiArduinoI2Cmotor import *                #   Подключаем библиотеку для работы с мотором I2C-flash.
mot = pyiArduinoI2Cmotor(0x09)                  #   Объявляем объект mot для работы с функциями и методами библиотеки pyiArduinoI2Cmotor, указывая адрес модуля на шине I2C.
                                                #   Если объявить объект без указания адреса (mot = pyiArduinoI2Cmotor ), то адрес будет найден автоматически.
mot.radius = 12.2                               #   Указываем радиус колеса в мм.
                                                #
while True:                                     #
    mot.setSpeed( 0.0766, MOT_M_S)              #   Запускаем мотор на скорости  0.0766 м/сек, что соответствует   60 об/мин при радиусе колеса в 12,2 мм.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
    mot.setSpeed( 0.1532, MOT_M_S)              #   Запускаем мотор на скорости  0.1532 м/сек, что соответствует  120 об/мин при радиусе колеса в 12,2 мм.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
    mot.setSpeed( 0.0766, MOT_M_S)              #   Запускаем мотор на скорости  0.0766 м/сек, что соответствует   60 об/мин при радиусе колеса в 12,2 мм.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
    mot.setSpeed(       0, MOT_M_S)             #   Запускаем мотор на скорости       0 м/сек, что соответствует остановке мотора.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
    mot.setSpeed(-0.0766, MOT_M_S)              #   Запускаем мотор на скорости -0.0766 м/сек, что соответствует  -60 об/мин при радиусе колеса в 12,2 мм.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
    mot.setSpeed(-0.1532, MOT_M_S)              #   Запускаем мотор на скорости -0.1532 м/сек, что соответствует -120 об/мин при радиусе колеса в 12,2 мм.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
    mot.setSpeed(-0.0766, MOT_M_S)              #   Запускаем мотор на скорости -0.0766 м/сек, что соответствует  -60 об/мин при радиусе колеса в 12,2 мм.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
    mot.setSpeed(       0, MOT_M_S)             #   Запускаем мотор на скорости       0 м/сек, что соответствует остановке мотора.
    sleep(5)                                    #   Приостанавливаем выполнение  скрипта на 5 секунд.
