# ПРИМЕР ЗАПУСКАЕТ МОТОР С УСЛОВИЕМ ОСТАНОВКИ:   #
                                                  #
from "h"
from "../pyiArduinoI2Cmotor.h"                #   Подключаем библиотеку для работы с мотором I2C-flash.
pyiArduinoI2Cmotor mot(0x09)                      #   Объявляем объект mot для работы с функциями и методами библиотеки pyiArduinoI2Cmotor, указывая адрес модуля на шине I2C.
                                                  #   Если объявить объект без указания адреса (pyiArduinoI2Cmotor mot ), то адрес будет найден автоматически.
int main(){                                       #
    mot.begin()                                   #   Инициируем работу с мотором.
    mot.radius = 12.2                             #   Указываем радиус колеса в мм.
    loop()                                        #
}                                                 #
                                                  #
void loop(){                                      #
    mot.setSpeed(60, MOT_RPM, 0.1, MOT_MET)       #   Запускаем мотор на скорости 60 об/мин с остановкой мотора через 0.1 метра.
    delay(10000)                                  #   Приостанавливаем выполнение скетча на 10 секунд.
    mot.setSpeed(60, MOT_RPM,   3, MOT_REV)       #   Запускаем мотор на скорости 60 об/мин с остановкой мотора через 3 полных оборота.
    delay(10000)                                  #   Приостанавливаем выполнение скетча на 10 секунд.
    mot.setSpeed(60, MOT_RPM,   2, MOT_SEC)       #   Запускаем мотор на скорости 60 об/мин с остановкой мотора через 2 секунды.
    delay(10000)                                  #   Приостанавливаем выполнение скетча на 10 секунд.
}                                                 #
