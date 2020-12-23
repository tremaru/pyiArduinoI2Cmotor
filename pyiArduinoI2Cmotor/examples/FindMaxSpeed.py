# ПРИМЕР НАХОДИТ МАКСИМАЛЬНУЮ СКОРОСТЬ:     #
                                            #
from pyiArduinoI2Cmotor import *            #   Подключаем библиотеку для работы с мотором I2C-flash.
mot = pyiArduinoI2Cmotor(0x09)              #   Объявляем объект mot для работы с функциями и методами библиотеки pyiArduinoI2Cmotor, указывая адрес модуля на шине I2C.
                                            #   Если объявить объект без указания адреса (mot = pyiArduinoI2Cmotor ), то адрес будет найден автоматически.
mot.begin()                                 #   Инициируем работу с мотором.
mot.setSpeed( 100.0 , MOT_PWM )             #   Запускаем мотор на максимальной скорости (ШИМ=100%).
result = 0                                  #   Определяем переменную для получения результата.
cnt    = 1                                  #   Определяем счётчик отсутствия рекордов скорости.
while cnt < 255:                            #   Выполняем цикл пока устанавливаются новые рекорды.
    cnt += 1
    s = mot.getSpeed(MOT_RPM)               #   Получаем текущее количество оборотов в минуту.
    if result < s:
        result=s                            #   Сохраняем скорость если это новый рекорд.
        cnt=1
                                            #   Выход из цикла произойдёт если счётчик cnt досчитает до 256.
mot.setStop()                               #   Останавливаем мотор.
t = "Максимальная скорость {} об/мин.".format(result)
print(t)                                    #   Выводим максимальную скорость мотора.
