//	Библиотека для работы с Trema-модулем джойстик, I2C-flash для Arduino: https://iarduino.ru/shop/Expansion-payments/dzhoystik-i2c---flash-trema-modul.html
//  Версия: 1.1.0
//  Последнюю версию библиотеки Вы можете скачать по ссылке: https://iarduino.ru/file/521.html
//  Подробное описание функций бибилиотеки доступно по ссылке: https://wiki.iarduino.ru/page/joystick-i2c/
//  Библиотека является собственностью интернет магазина iarduino.ru и может свободно использоваться и распространяться!
//  При публикации устройств или скетчей с использованием данной библиотеки, как целиком, так и её частей,
//  в том числе и в некоммерческих целях, просим Вас опубликовать ссылку: http://iarduino.ru
//  Автор библиотеки: Панькин Павел.
//  Если у Вас возникли технические вопросы, напишите нам: shop@iarduino.ru

#ifndef iarduino_I2C_Motor_h																						//
#define iarduino_I2C_Motor_h																						//
//#define PI 3.14195
																													//
/*
#if defined(ARDUINO) && (ARDUINO >= 100)																			//
#include		<Arduino.h>																							//
#else																												//
#include		<WProgram.h>																						//
#endif																												//
*/
																													//
#include		"iarduino_I2C_PI.h"																			//	Подключаем файл iarduino_I2C_Motor_I2C.h - для работы с шиной I2C		(используя функции структуры iI2C)
																													//
#define			DEF_CHIP_ID_FLASH		0x3C																		//	ID линейки чипов - константа для всех чипов серии Flash (позволяет идентифицировать принадлежность чипа к серии).
#define			DEF_CHIP_ID_METRO		0xC3																		//	ID линейки чипов - константа для всех чипов серии Metro (позволяет идентифицировать принадлежность чипа к серии).
#define			DEF_MODEL_MOT			0x14																		//	Идентификатор модели - константа.
//				Адреса регистров модуля:																			//
#define			REG_FLAGS_0				0x00																		//	Адрес регистра флагов управления для чтения.
#define			REG_BITS_0				0x01																		//	Адрес регистра битов  управления для чтения и записи.
#define			REG_FLAGS_1				0x02																		//	Адрес регистра флагов управления для чтения.
#define			REG_BITS_1				0x03																		//	Адрес регистра битов  управления для чтения и записи.
#define			REG_MODEL				0x04																		//	Адрес регистра содержащего номер типа модуля.
#define			REG_VERSION				0x05																		//	Адрес регистра содержащего версию прошивки.
#define			REG_ADDRESS				0x06																		//	Адрес регистра содержащего текущий адрес модуля на шине I2C. Если адрес указан с флагом IF-PIN-ADDRES то адрес установится (и запишется в регистр) только при наличии 1 на входе PIN_ADDRES.
#define			REG_CHIP_ID				0x07																		//	Адрес регистра содержащего ID линейки чипов «Flash». По данному ID можно определить принадлежность чипа к линейки «Flash».
#define			REG_MOT_FREQUENCY_L		0x08																		//	Адрес регистра хранящего частоту ШИМ в Гц (младший байт).
#define			REG_MOT_FREQUENCY_H		0x09																		//	Адрес регистра хранящего частоту ШИМ в Гц (старший байт).
#define			REG_MOT_MAX_RPM_DEV		0x0A																		//	Адрес регистра хранящего максимально допустимый % отклонения реальной скорости от заданной. При превышении данного процента загорается светодиод ошибки и устанавливается флаг «MOT_FLG_RPM_ERR».
#define			REG_MOT_FLG				0x10																		//	Адрес регистра статусных флагов «MOT_FLG_RPM_EN», «MOT_FLG_RPM_ERR», «MOT_FLG_DRV_ERR», «MOT_FLG_STOP», «MOT_FLG_NEUTRAL.
#define			REG_MOT_MAGNET			0x11																		//	Адрес регистра хранящего количество магнитов на роторе мотора возле датчика Холла.
#define			REG_MOT_REDUCER_L		0x12																		//	Адрес регистра (младший байт) хранящего передаточное отношение редуктора (в сотых долях) от 1:0.01 до 1:167'772.15.
#define			REG_MOT_REDUCER_C		0x13																		//	Адрес регистра (средний байт).
#define			REG_MOT_REDUCER_H		0x14																		//	Адрес регистра (старший байт).
#define			REG_MOT_SET_PWM_L		0x15																		//	Адрес регистра (младший байт) хранящего заданое значение ШИМ ±4095. Запись любого значения приводит к сбросу регистров «REG_MOT_SET_RPM» и сбросу флага «MOT_FLG_RPM_EN».
#define			REG_MOT_SET_PWM_H		0x16																		//	Адрес регистра (старший байт).
#define			REG_MOT_SET_RPM_L		0x17																		//	Адрес регистра (младший байт) хранящего заданое количество оборотов в минуту ±32'767. Запись любого значения приводит к сбросу регистров «REG_MOT_SET_PWM» и установке флага «MOT_FLG_RPM_EN».
#define			REG_MOT_SET_RPM_H		0x18																		//	Адрес регистра (старший байт).
#define			REG_MOT_GET_RPM_L		0x19																		//	Адрес регистра (младший байт) хранящего реальное количество оборотов в минуту ±32'767. Значение берётся с датчиков Холла.
#define			REG_MOT_GET_RPM_H		0x1A																		//	Адрес регистра (старший байт).
#define			REG_MOT_GET_REV_L		0x1B																		//	Адрес регистра (младший байт) хранящего реальное количество совершённых оборотов колеса (в сотых долях полного оборота) от 0.00 до 167'772.15. Сброс значения осуществляется записью любого числа в тройной регистр «REG_MOT_STOP_REV».
#define			REG_MOT_GET_REV_C		0x1C																		//	Адрес регистра (средний байт).
#define			REG_MOT_GET_REV_H		0x1D																		//	Адрес регистра (старший байт).
#define			REG_MOT_STOP_REV_L		0x1E																		//	Адрес регистра (младший байт) хранящего количество оборотов колеса (в сотых долях полного оборота) от 0.00 до 167'772.15, оставшееся до установки бита «MOT_BIT_STOP». Запись значения 0x000000 не приводит к установке бита «MOT_BIT_STOP».
#define			REG_MOT_STOP_REV_C		0x1F																		//	Адрес регистра (средний байт).
#define			REG_MOT_STOP_REV_H		0x20																		//	Адрес регистра (старший байт).
#define			REG_MOT_STOP_TMR_L		0x21																		//	Адрес регистра (младший байт) хранящего время (в мс) от 0 до 16'777'215, оставшееся до установки бита «MOT_BIT_STOP». Запись значения 0x000000 не приводит к установке бита «MOT_BIT_STOP».
#define			REG_MOT_STOP_TMR_C		0x22																		//	Адрес регистра (средний байт).
#define			REG_MOT_STOP_TMR_H		0x23																		//	Адрес регистра (старший байт).
#define			REG_MOT_STOP			0x24																		//	Адрес регистра остановки мотора. Содержит бит остановки мотора «MOT_BIT_STOP» и бит освобождения мотора «MOT_BIT_NEUTRAL» при его остановке.
#define			REG_BITS_2				0x25																		//	Адрес регистра битов. Содержит бит вращения вала по ч.с. «MOT_BIT_DIR_CKW» и биты инверсии «MOT_BIT_INV_RDR», «MOT_BIT_INV_PIN».
#define			REG_MOT_VOLTAGE			0x26																		//	Адрес регистра хранящего номинальное напряжение электродвигателя в десятых долях В.
#define			REG_MOT_NOMINAL_RPM_L	0x27																		//	Адрес регистра (младший байт) хранящего номинальное количество оборотов в минуту. Количество оборотов вала редуктора при номинальном напряжении питания мотора и 100% ШИМ.
#define			REG_MOT_NOMINAL_RPM_H	0x28																		//	Адрес регистра (старший байт).

//				Позиция битов и флагов:																				//
#define			MOT_FLG_RPM_EN			0x80																		//	Флаг указывает на то, что скорость мотора задана количеством оборотов в минуту. Если флаг сброшен, значит скорость мотора задана значением ШИМ.
#define			MOT_FLG_RPM_ERR			0x20																		//	Флаг отличия между заданным и реальным количеством оборотов в минуту более чем на «REG_MOT_MAX_RPM_DEV» процентов.
#define			MOT_FLG_DRV_ERR			0x10																		//	Флаг ошибки драйвера (перегрузка по току, перегрев драйвера или низкий уровень напряжения питания мотора).
#define			MOT_FLG_STOP			0x02																		//	Флаг указывает на то, что мотор остановлен.
#define			MOT_FLG_NEUTRAL			0x01																		//	Флаг указывает на то, что выводы мотора отключены (его можно вращать).
#define			MOT_BIT_STOP			0x02																		//	Бит  остановки мотора.
#define			MOT_BIT_NEUTRAL			0x01																		//	Бит  освобождения выводов мотора при его остановке.
#define			MOT_BIT_DIR_CKW			0x04																		//	Бит  вращения вала по ч.с., при положительной скорости. Бит позволяет менять направление вращения вала не меняя знак скорости или ШИМ. Используется для указания расположения модуля по левому (0) или правому (1) борту подвижного устройства.
#define			MOT_BIT_INV_RDR			0x02																		//	Бит  инверсии редуктора.      Бит должен быть установлен если вал редуктора вращается в сторону противоположную вращению ротора мотора.
#define			MOT_BIT_INV_PIN			0x01																		//	Бит  инверсии выводов мотора. Бит должен быть установлен при обратном подключении выводов мотора, если ротор мотора вращается против часовой стрелки.
																													//
#ifndef			MOT_ERR_SPD																							//
#define			MOT_ERR_SPD				1																			//	getError();
#endif																												//
																													//
#ifndef			MOT_ERR_DRV																							//
#define			MOT_ERR_DRV				2																			//	getError();
#endif																												//
																													//
#ifndef			MOT_MET																								//	Параметр информирубщий о том, что значение указано в МЕТРАХ.
#define			MOT_MET					3																			//	setStop(расстояние, MOT_MET); getStop(MOT_MET); setSpeed(скорость, MOT_RPM/MOT_PWM, расстояние, MOT_MET); getSum(MOT_MET);
#endif																												//
																													//
#ifndef			MOT_SEC																								//	Параметр информирубщий о том, что значение указано в СЕКУНДАХ.
#define			MOT_SEC					4																			//	setStop(длительность, MOT_SEC); getStop(MOT_SEC); setSpeed(скорость, MOT_RPM/MOT_PWM, длительность, MOT_SEC);
#endif																												//
																													//
#ifndef			MOT_M_S																								//	Параметр информирубщий о том, что значение указано в МЕТРАХ В СЕКУНДУ.
#define			MOT_M_S					5																			//	setSpeed(скорость, MOT_M_S); getSpeed(MOT_M_S);
#endif																												//
																													//
#ifndef			MOT_REV																								//	Параметр информирубщий о том, что значение является КОЛИЧЕСТВОМ ПОЛНЫХ ОБОРОТОВ.
#define			MOT_REV					6																			//	setStop(количество, MOT_REV); getStop(MOT_REV); setSpeed(скорость, MOT_RPM/MOT_PWM, количество, MOT_REV); getSum(MOT_REV);
#endif																												//
																													//
#ifndef			MOT_RPM																								//	Параметр информирубщий о том, что значение является КОЛИЧЕСТВОМ ОБОРОТОВ В МИНУТУ.
#define			MOT_RPM					7																			//	setSpeed(скорость, MOT_RPM); getSpeed(MOT_RPM);
#endif																												//
																													//
#ifndef			MOT_PWM																								//	Параметр информирубщий о том, что значение является КОЭФФИЦИЕНТОМ ЗАПОЛНЕНИЯ ШИМ.
#define			MOT_PWM					8																			//	setSpeed(скорость, MOT_PWM); getSpeed(MOT_PWM);
#endif																												//
																													//
class iarduino_I2C_Motor{																							//
	public:																											//
	/**	Конструктор класса **/																						//
		iarduino_I2C_Motor							(uint8_t address=0){											//	Конструктор класса													(Параметр: адрес модуля на шине I2C, если не указан (=0), то адрес будет определён).
													if(address>0x7F){ address>>=1; }								//	Корректируем адрес, если он указан с учётом бита RW.
							valAddrTemp			=	address;														//	Сохраняем переданный адрес модуля.
							objI2C				=	new iarduino_I2C;												//	Переопределяем указатель objI2C на объект производного класса iarduino_I2C.
		}																											//
	/**	Пользовательские функции **/																				//
		bool				begin					(void						);									//	Объявляем  функцию инициализации модуля								(Параметр:  отсутствует).
		bool				reset					(void						);									//	Объявляем  функцию перезагрузки модуля								(Параметр:  отсутствует).
		bool				changeAddress			(uint8_t					);									//	Объявляем  функцию смены адреса модуля на шине I2C					(Параметр:  новый адрес модуля).
		uint8_t				getAddress				(void						){ return valAddr;	}				//	Определяем функцию возвращающую текущий адрес модуля на шине I2C	(Параметр:  отсутствует).
		uint8_t				getVersion				(void						){ return valVers;	}				//	Определяем функцию возвращающую текущую версию прошивки модуля		(Параметр:  отсутствует).
		bool				getPullI2C				(void						);									//	Объявляем  функцию возвращающую флаг наличия подтяжки шины I2C		(Параметр:  отсутствует).
		bool				setPullI2C				(bool=true					);									//	Объявляем  функцию установки    подтяжки шины I2C					(Параметр:  флаг подтяжки).
																													//
		bool				setFreqPWM				(uint16_t					);									//	Объявляем  функцию установки    частоты ШИМ							(Параметр:  частота в Гц от 1 до 1000).
																													//
		bool				setMagnet				(uint8_t					);									//	Объявляем  функцию установки    количества магнитов у датчика Холла	(Параметр:  количество от 1 до 255).
		uint8_t				getMagnet				(void						);									//	Объявляем  функцию возвращающую количество магнитов у датчика Холла	(Параметр:  отсутствует).
																													//
		bool				setReducer				(float						);									//	Объявляем  функцию установки    передаточного отношения редуктора	(Параметр:  отношение от 0.01 до 167'772.15).
		float				getReducer				(void						);									//	Объявляем  функцию возвращающую передаточное  отношение редуктора	(Параметр:  отсутствует).
																													//
		bool				setError				(uint8_t					);									//	Объявляем  функцию установки    процента макс. отклонения скорости	(Параметр:  процент от 0 до 100 максимально допустимого отклонения реальной скорости от заданной).
		uint8_t				getError				(void						);									//	Объявляем  функцию возвращающую	флаг ошибки скорости или драйвера	(Параметр:  отсутствует).
																													//
		bool				setSpeed				(float,uint8_t,float,uint8_t);									//	Объявляем  функцию установки    скорости и условия остановки		(Параметры: значение скорости, MOT_RPM / MOT_PWM / MOT_M_S - тип значения скорости, значение условия остановки, MOT_MET / MOT_REV / MOT_SEC - тип условия остановки. При MOT_RPM скорость указывается от 0 до ±32'767 об/мин., при MOT_PWM скорость указывается от 0 до ±100 % ШИМ, при MOT_M_S скорость указывается в м/сек.
		bool				setSpeed				(float i, uint8_t j			){ return setSpeed(i,j,0.00,0xFF);}	//	Определяем функцию установки    скорости							(Параметры: значение скорости, MOT_RPM / MOT_PWM / MOT_M_S - тип значения скорости.                                                                                  При MOT_RPM скорость указывается от 0 до ±32'767 об/мин., при MOT_PWM скорость указывается от 0 до ±100 % ШИМ, при MOT_M_S скорость указывается в м/сек.
		float				getSpeed				(uint8_t					);									//	Объявляем  функцию возвращающую реальную скорость или ШИМ			(Параметр:  MOT_RPM / MOT_PWM / MOT_M_S - тип возвращаемого значения).
																													//
		bool				setStop					(float, uint8_t				);									//	Объявляем  функцию остановки    мотора по условию					(Параметры: значение условия остановки, MOT_MET / MOT_REV / MOT_SEC - тип условия остановки).
		bool				setStop					(void						){ return setStop(0.00, 0xFF); }	//	Определяем функцию остановки    мотора								(Параметр:  отсутствует).
		float				getStop					(uint8_t					);									//	Объявляем  функцию возвращающую	значение оставшеея до остановки		(Параметр:  MOT_MET / MOT_REV / MOT_SEC - тип возвращаемого значения).
																													//
		bool				setStopNeutral			(bool						);									//	Объявляем  функцию установки    нейтрального положения при остановке(Параметр:  флаг true/false).
		bool				getStopNeutral			(void						);									//	Объявляем  функцию возвращающую	флаг нейтраль. пол-ния при остановке(Параметр:  отсутствует).
																													//
		bool				setDirection			(bool						);									//	Объявляем  функцию установки    направления вращения вала			(Параметр:  флаг вращения вала по ч.с. при положительной скорости).
		bool				getDirection			(void						);									//	Объявляем  функцию возвращающую	направления вращения вала			(Параметр:  отсутствует).
																													//
		bool				setInvGear				(bool, bool					);									//	Объявляем  функцию установки    флагов инверсии механизма			(Параметры: флаг инверсии вращения редуктора, флаг инверсии полярности мотора).
		uint8_t				getInvGear				(void						);									//	Объявляем  функцию возвращающую	байт с флагами инверсии механизма	(Параметр:  отсутствует).
																													//
		float				getSum					(uint8_t					);									//	Объявляем  функцию возвращающую	пройденный  путь / кол-во оборотов	(Параметр:  MOT_MET / MOT_REV - тип возвращаемого значения).
		bool				delSum					(void						){ return setStop(0.00, MOT_REV); }	//	Определяем функцию сброса		пройденного пути / кол-ва оборотов	(Параметр:  отсутствует).
																													//
		bool				setVoltage				(float						);									//	Объявляем  функцию установки    номинального напряжения мотора в В	(Параметр:  напряжение в Вольтах).
		float				getVoltage				(void						);									//	Объявляем  функцию возвращающую	номинальное  напряжение мотора в В	(Параметр:  отсутствует).
																													//
		bool				setNominalRPM			(uint16_t					);									//	Объявляем  функцию установки    номинальной скорости в об/мин.		(Параметр:  скорость вращения вала редуктора от 0 до 65'535 об/мин.).
		uint16_t			getNominalRPM			(void						);									//	Объявляем  функцию возвращающую	номинальную скорость в об/мин.		(Параметр:  отсутствует).
																													//
		bool				saveManufacturer		(uint64_t					);									//	Объявляем  функцию сохранения   конструктивных данных в flash память(Параметр:  код разработчика).
																													//
	/**	Пользовательские переменные **/																				//
		float				radius				=	1.0f;															//	Определяем переменную для хранения радиуса колеса в мм.
	private:																										//
	/**	Внутренние переменные **/																					//
		uint8_t				valAddrTemp			=	0;																//	Определяем переменную для хранения адреса модуля на шине I2C который был указан, но не был проверен.
		uint8_t				valAddr				=	0;																//	Определяем переменную для хранения адреса модуля на шине I2C.
		uint8_t				valVers				=	0;																//	Определяем переменную для хранения версии прошивки модуля.
		uint8_t				data[6];																				//	Объявляем  массив     для хранения получаемых/передаваемых данных.
		iarduino_I2C_BASE*	objI2C;																					//	Объявляем  указатель  на  объект полиморфного класса iarduino_I2C_BASE, но в конструкторе данного класса этому указателю будет присвоена ссылка на производный класс iarduino_I2C.
	/**	Внутренние функции **/																						//
		bool				_readBytes				(uint8_t, uint8_t			);									//	Объявляем  функцию чтения данных в  массив  data					(Параметры: номер первого регистра, количество байт).
		bool				_writeBytes				(uint8_t, uint8_t, uint8_t=0);									//	Объявляем  функцию записи данных из массива data					(Параметры: номер первого регистра, количество байт, номер первого элемента массива data).
};																													//
																													//
#endif																												//
