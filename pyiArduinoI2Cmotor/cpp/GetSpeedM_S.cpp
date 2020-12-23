// ДАННЫЙ ПРИМЕР ИНФОРМИРУЕТ О НАБОРЕ СКОРОСТИ:   //
                                                  //
#include "Serial.h"
#include "../iarduino_I2C_Motor.h"                //   Подключаем библиотеку для работы с мотором I2C-flash.
iarduino_I2C_Motor mot(0x09);                     //   Объявляем объект mot для работы с функциями и методами библиотеки iarduino_I2C_Motor, указывая адрес модуля на шине I2C.
                                                  //   Если объявить объект без указания адреса (iarduino_I2C_Motor mot;), то адрес будет найден автоматически.
int main(){                                       //
    mot.begin();                                  //   Инициируем работу с мотором.
    mot.radius = 12.2;                            //   Указываем радиус колеса в мм.
    loop();                                       //
}                                                 //
                                                  //
void loop(){                                      //
    Serial.println("Запускаем мотор 0,07 м/сек.");//   Выводим сообщение о запуске мотора.
    mot.setSpeed(0.07f, MOT_M_S);                 //   Запускаем мотор на скорости 0.07 м/сек.
    while(mot.getError()==MOT_ERR_SPD){           //   Пока сохраняется ошибка скорости.
        Serial.print("Реальная скорость = ");     //   Выводим сообщение.
        Serial.print( mot.getSpeed(MOT_M_S), 5 ); //   Выводим реальное значение скорости, 5 знаков после запятой.
        Serial.print(" м/сек.\r\n");              //   Выводим сообщение.
    }   Serial.println("Скорость набрана.");      //   Выводим сообщение.
    delay(500);                                   //   Приостанавливаем выполнение скетча на 500 миллисекунд.
    Serial.println("Останавливаем мотор.");       //   Выводим сообщение.
    mot.setStop();                                //   Останавливаем мотор.
    Serial.println("====================");       //   Выводим разделитель.
    delay(500);                                   //   Приостанавливаем выполнение скетча на 500 миллисекунд.
}                                                 //