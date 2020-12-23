# ДАННЫЙ ПРИМЕР ЗАПУСКАЕТ МОТОР С УКАЗАНИЕМ ШИМ: #
                                                  #
from "h"
from "../pyiArduinoI2Cmotor.h"                #   Подключаем библиотеку для работы с мотором I2C-flash.
pyiArduinoI2Cmotor mot(0x09)                      #   Объявляем объект mot для работы с функциями и методами библиотеки pyiArduinoI2Cmotor, указывая адрес модуля на шине I2C.
                                                  #   Если объявить объект без указания адреса (pyiArduinoI2Cmotor mot ), то адрес будет найден автоматически.
int main(){                                       #
    mot.begin()                                   #   Инициируем работу с мотором.
}                                                 #
                                                  #
void loop(){                                      #
    mot.setSpeed(  50.0, MOT_PWM)                 #   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( 100.0, MOT_PWM)                 #   Запускаем мотор установив ШИМ =  100% (ШИМ указывается в % 0 до ±100.0).
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(  50.0, MOT_PWM)                 #   Запускаем мотор установив ШИМ =   50% (ШИМ указывается в % 0 до ±100.0).
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(     0, MOT_PWM)                 #   Запускаем мотор установив ШИМ =    0% что соответствует остановке мотора.
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( -50.0, MOT_PWM)                 #   Запускаем мотор установив ШИМ =  -50% (ШИМ указывается в % 0 до ±100.0).
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(-100.0, MOT_PWM)                 #   Запускаем мотор установив ШИМ = -100% (ШИМ указывается в % 0 до ±100.0).
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed( -50.0, MOT_PWM)                 #   Запускаем мотор установив ШИМ =  -50% (ШИМ указывается в % 0 до ±100.0).
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
    mot.setSpeed(     0, MOT_PWM)                 #   Запускаем мотор установив ШИМ =    0% что соответствует остановке мотора.
    delay(5000)                                   #   Приостанавливаем выполнение скетча на 5 секунд.
}                                                 #
