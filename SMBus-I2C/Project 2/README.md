## Float Study for both UNO & PI
-  When using the SMBus-I2C communication between the UNO & PI, the only data type that can be sent and received is the type *byte* and type *char* which is the data type most often used whose base type is the *uint8_t*, an unsigned integer containing 8-bits. 
### **TypeConv.h**
- Has following methods:
  - WordTo2Bytes()
  - BytesToWord()
  - DWordTo4Bytes()
  - BytesToDWord()
- Code development for the following methods:
  - floatToBytes()
  - bytesToFloat
### Test Results
```
20241019 TypeConv.h File
author: Jesse Carpenter
Carpenter Software LC

Expermental Conversion
additional algorithms used for both UNO & PI...
(1) Float to Bytes
(2) Bytes to Float

--------------------------------------------------------
--------------------------------------------------------
UnoSlaveI2C - Has more detail - no sci...
--------------------------------------------------------
double size:  a: 4
float size:  a: 4
MAX int32_t:  a: 2147483647 b: 4    Used
MAX int16_t:  a: 32767 b: 2         NOT needed
MAX int8_t:  a: 127 b: 1            Used
--------------------
0.0000314
*10:  a: 0.0003142 b: -1
*10:  a: 0.0031416 b: -2
*10:  a: 0.0314159 b: -3
*10:  a: 0.3141593 b: -4
*10:  a: 3.1415927 b: -5
*0.10:  a: 0.3141593 b: -4
1.0e8:  a: 31415928.0000000 b: -12
mantissa-exp:  a: 31415928 b: -12
BytesToFloat decimalPlaces: a: -12
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: -4
*0.10:  a: 0.0314159 b: -3
*0.10:  a: 0.0031416 b: -2
*0.10:  a: 0.0003142 b: -1
*0.10:  a: 0.0000314 b: 0
BytesToFloat float: a: 0.00
0.0000314
--------------------
0.0003142
*10:  a: 0.0031416 b: -1
*10:  a: 0.0314159 b: -2
*10:  a: 0.3141593 b: -3
*10:  a: 3.1415927 b: -4
*0.10:  a: 0.3141593 b: -3
1.0e8:  a: 31415928.0000000 b: -11
mantissa-exp:  a: 31415928 b: -11
BytesToFloat decimalPlaces: a: -11
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: -3
*0.10:  a: 0.0314159 b: -2
*0.10:  a: 0.0031416 b: -1
*0.10:  a: 0.0003142 b: 0
BytesToFloat float: a: 0.00
0.0003142
--------------------
0.0031416
*10:  a: 0.0314159 b: -1
*10:  a: 0.3141593 b: -2
*10:  a: 3.1415927 b: -3
*0.10:  a: 0.3141593 b: -2
1.0e8:  a: 31415928.0000000 b: -10
mantissa-exp:  a: 31415928 b: -10
BytesToFloat decimalPlaces: a: -10
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: -2
*0.10:  a: 0.0314159 b: -1
*0.10:  a: 0.0031416 b: 0
BytesToFloat float: a: 0.00
0.0031416
--------------------
0.0314159
*10:  a: 0.3141593 b: -1
*10:  a: 3.1415927 b: -2
*0.10:  a: 0.3141593 b: -1
1.0e8:  a: 31415928.0000000 b: -9
mantissa-exp:  a: 31415928 b: -9
BytesToFloat decimalPlaces: a: -9
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: -1
*0.10:  a: 0.0314159 b: 0
BytesToFloat float: a: 0.03
0.0314159
--------------------
0.3141593
*10:  a: 3.1415927 b: -1
*0.10:  a: 0.3141593 b: 0
1.0e8:  a: 31415928.0000000 b: -8
mantissa-exp:  a: 31415928 b: -8
BytesToFloat decimalPlaces: a: -8
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: 0
BytesToFloat float: a: 0.31
0.3141593
--------------------
3.1415927
*0.10:  a: 0.3141593 b: 1
1.0e8:  a: 31415928.0000000 b: -7
mantissa-exp:  a: 31415928 b: -7
BytesToFloat decimalPlaces: a: -7
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: 1
*10:  a: 3.1415927 b: 0
BytesToFloat float: a: 3.14
3.1415927
--------------------
31.4159280
*0.10:  a: 3.1415927 b: 1
*0.10:  a: 0.3141593 b: 2
1.0e8:  a: 31415928.0000000 b: -6
mantissa-exp:  a: 31415928 b: -6
BytesToFloat decimalPlaces: a: -6
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: 2
*10:  a: 3.1415927 b: 1
*10:  a: 31.4159280 b: 0
BytesToFloat float: a: 31.42
31.4159280
--------------------
314.1592700
*0.10:  a: 31.4159280 b: 1
*0.10:  a: 3.1415927 b: 2
*0.10:  a: 0.3141593 b: 3
1.0e8:  a: 31415928.0000000 b: -5
mantissa-exp:  a: 31415928 b: -5
BytesToFloat decimalPlaces: a: -5
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: 3
*10:  a: 3.1415927 b: 2
*10:  a: 31.4159280 b: 1
*10:  a: 314.1592700 b: 0
BytesToFloat float: a: 314.16
314.1592700
--------------------
3141.5928000
*0.10:  a: 314.1592700 b: 1
*0.10:  a: 31.4159280 b: 2
*0.10:  a: 3.1415927 b: 3
*0.10:  a: 0.3141593 b: 4
1.0e8:  a: 31415928.0000000 b: -4
mantissa-exp:  a: 31415928 b: -4
BytesToFloat decimalPlaces: a: -4
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: 4
*10:  a: 3.1415927 b: 3
*10:  a: 31.4159280 b: 2
*10:  a: 314.1592700 b: 1
*10:  a: 3141.5928000 b: 0
BytesToFloat float: a: 3141.59
3141.5928000
--------------------
31415.9280000
*0.10:  a: 3141.5928000 b: 1
*0.10:  a: 314.1592700 b: 2
*0.10:  a: 31.4159280 b: 3
*0.10:  a: 3.1415927 b: 4
*0.10:  a: 0.3141593 b: 5
1.0e8:  a: 31415928.0000000 b: -3
mantissa-exp:  a: 31415928 b: -3
BytesToFloat decimalPlaces: a: -3
BytesToFloat b_dWordOUT: a: 31415928
BytesToFloat 1.0e8:  a: 0.3141593 b: 5
*10:  a: 3.1415927 b: 4
*10:  a: 31.4159280 b: 3
*10:  a: 314.1592700 b: 2
*10:  a: 3141.5928000 b: 1
*10:  a: 31415.9280000 b: 0
BytesToFloat float: a: 31415.93
31415.9280000

--------------------------------------------------------
--------------------------------------------------------
PiMasterI2C - minimum detail - has sci...
--------------------------------------------------------
double size: 8
float size: 4
INT32_MAX: 2147483647 MIN: -2147483648 size: 4
INT16_MAX: 32767 MIN: -32768 size: 2
INT8_MAX: 127 MIN: -128 size: 1
--------------------
g_FLOAT: 3.14159e-05
val: 3.14159e-05
--------------------
g_FLOAT: 0.000314159
val: 0.000314159
--------------------
g_FLOAT: 0.00314159
val: 0.00314159
--------------------
g_FLOAT: 0.0314159
val: 0.0314159
--------------------
g_FLOAT: 0.314159
val: 0.314159
--------------------
g_FLOAT: 3.14159
val: 3.14159
--------------------
g_FLOAT: 31.4159
val: 31.4159
--------------------
g_FLOAT: 314.159
val: 314.159
--------------------
g_FLOAT: 3141.59
val: 3141.59
--------------------
g_FLOAT: 31415.9
val: 31415.9
```



