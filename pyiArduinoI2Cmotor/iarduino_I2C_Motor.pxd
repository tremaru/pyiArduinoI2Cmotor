cdef extern from "iarduino_I2C_Motor.cpp":
    pass

cdef extern from "iarduino_I2C_Motor.h":
    cdef cppclass iarduino_I2C_Motor:
        iarduino_I2C_Motor() except +
        iarduino_I2C_Motor(unsigned char) except +
        bint begin()
        bint changeAddress(unsigned char)
        bint reset()
        unsigned char getAddress()
        unsigned char getVersion()
