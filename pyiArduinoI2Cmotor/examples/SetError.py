# ПРИМЕР ЗАДАЁТ ЧУВСТВИТЕЛЬНОСТЬ ОШИБКИ СКОРОСТИ
from time import sleep

from pyiArduinoI2Cmotor import *                    #   Подключаем библиотеку для работы с мотором I2C-flash.
mot = pyiArduinoI2Cmotor(0x09)                      #   Объявляем объект mot для работы с функциями и методами библиотеки pyiArduinoI2Cmotor, указывая адрес модуля на шине I2C.
                                                    #   Если объявить объект без указания адреса (mot = pyiArduinoI2Cmotor ), то адрес будет найден автоматически.
mot.setError(10)                                    #   Задаём максимально допустимый процент отклонения заданной скорости от реальной, превышение которого приведёт к появлению ошибки.
                                                    #
                                                    #   Теперь функция getError() будет возвращать значение MOT_ERR_SPD если текущая скорость отличается от заданной более чем на 10%.
                                                    #   При том же значении будет включаться красный светодиод на плате модуля.
while True:                                         #
    mot.setSpeed(100, MOT_RPM)                      #   Запускаем мотор на скорости 100 об/мин.
    sleep(1)                                        #   Приостанавливаем выполнение скрипта на 1 секунду.
    mot.setStop()                                   #   Останавливаем мотор.
    sleep(.5)                                       #   Приостанавливаем выполнение скрипта на 500 миллисекунд.
                                                    #
#  По умолчанию, ошибка скорости возникает при   #   Значение заданное функцией mot.setError()
#  отличии заданной скорости от реальной более   #   сохраняется в энергонезависимой памяти модуля.
#  чем на 10 процентов. Измените данное значение #
#  обратившись к функции mot.setError()  и       #
#  обратите внимание на то как изменится         #
#  длительность свечения красного светодиода     #   Для большей нагладности предлагаем изменить
#  установленного на плате модуля.               #   параметр функции mot.setError()  с 10 на 1.
