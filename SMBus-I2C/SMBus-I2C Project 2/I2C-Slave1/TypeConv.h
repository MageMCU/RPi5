//
// Carpenter Software
// File: Class TypeConv.h
// Github: MageMCU
// Repository: Numerics
// Folder: include
//
// By Jesse Carpenter (carpentersoftware.com)
//
// Testing Platform:
//  * MCU:Atmega328P
//  * IDE:PlatformIO
//  * Editor: VSCode
//
// MIT LICENSE
//

#ifndef Type_Conversion_h
#define Type_Conversion_h

#include "Bitwise.h"
#include "MiscMath.h"

using namespace std;

// Carpenter Software - Jesse Carpenter
namespace csjc
{
    class TypeConv
    {
    private:
        // total of 5-bytes for serial data
        // contains sign (+/-)
        // int8_t _exponent; USE b_byte4
        // Scientific (Arduino test atof)
        // contains sign (+/-)
        // int32_t _mantissa; USE b_dWordIN & b_dWordOUT

        //
        Bitwise<uint32_t> _bitwise;

        // AVR-LSB Word Order bit15, bit14, ... , bit1, bit0.
        // Long 4 -------------------
        uint32_t b_dWordIN;
        uint32_t b_dWordOUT;
        // Int 2 -------------------
        uint16_t b_wordIN;
        uint16_t b_wordOUT;
        // Bytes -------------------
        uint8_t b_byte4;
        uint8_t b_byte3;
        uint8_t b_byte2;
        uint8_t b_byte1;
        uint8_t b_byte0;
        // Bytes
        // uint8_t b_byteHi; USE b_byte1
        // uint8_t b_byteLo; USE b_byte0

        // Private Methods
        void b_setHiByte();
        void b_setLoByte();
        void b_glue2Bytes();
        uint16_t b_fGlue2Bytes(uint8_t hi, uint8_t lo);
        //
        void b_setByte4();
        void b_setByte3();
        void b_setByte2();
        void b_setByte1();
        void b_setByte0();
        void b_glue4Bytes();
        uint32_t b_fGlue4Bytes(uint8_t b3, uint8_t b2, uint8_t b1, uint8_t b0);

        // other
        float _inputValue;
        float _bytesToFloat();
        void _floatToBytes();

    public:
        // Constructor
        TypeConv();
        ~TypeConv() = default;

        // Public Methods
        void WordTo2Bytes(uint16_t word);
        void DWordTo4Bytes(uint32_t dWord);
        uint8_t GetHiByte();
        uint8_t GetLoByte();
        uint16_t GetWord();
        uint32_t GetDWord();
        uint16_t BytesToWord();
        uint32_t BytesToDWord();
        uint16_t BytesToWord(uint8_t hi, uint8_t lo);
        uint32_t BytesToDWord(uint8_t b3, uint8_t b2,
                              uint8_t b1, uint8_t b0);

        // NEW Methods
        uint8_t GetByte3();
        uint8_t GetByte2();
        uint8_t GetByte1();
        uint8_t GetByte0();
        void dWordTo4Bytes(uint32_t dWord);
        void FloatTo5Bytes(float inputValue);
    };

    TypeConv::TypeConv()
    {
        _bitwise = Bitwise<uint32_t>();
    }

    void TypeConv::WordTo2Bytes(uint16_t uint16)
    {
        b_wordIN = uint16;
        b_setHiByte();
        b_setLoByte();
    }

    void TypeConv::DWordTo4Bytes(uint32_t dWord)
    {
        b_dWordIN = dWord;
        b_setByte3();
        b_setByte2();
        b_setByte1();
        b_setByte0();
    }

    uint8_t TypeConv::GetHiByte()
    {
        // return b_byteHi;
        return b_byte1;
    }

    uint8_t TypeConv::GetLoByte()
    {
        // return b_byteLo;
        return b_byte0;
    }

    uint16_t TypeConv::GetWord()
    {
        return b_wordOUT;
    }

    uint32_t TypeConv::GetDWord()
    {
        return b_dWordOUT;
    }

    uint16_t TypeConv::BytesToWord()
    {
        b_glue2Bytes();
        return b_wordOUT;
    }

    uint32_t TypeConv::BytesToDWord()
    {
        b_glue4Bytes();
        return b_dWordOUT;
    }

    uint8_t TypeConv::GetByte3()
    {
        return b_byte3;
    }

    uint8_t TypeConv::GetByte2()
    {
        return b_byte2;
    }

    uint8_t TypeConv::GetByte1()
    {
        return b_byte1;
    }

    uint8_t TypeConv::GetByte0()
    {
        return b_byte0;
    }

    uint16_t TypeConv::BytesToWord(uint8_t hi, uint8_t lo)
    {
        return b_fGlue2Bytes(hi, lo);
    }

    uint32_t TypeConv::BytesToDWord(uint8_t b3, uint8_t b2,
                                    uint8_t b1, uint8_t b0)
    {
        return b_fGlue4Bytes(b3, b2, b1, b0);
    }

    void TypeConv::dWordTo4Bytes(uint32_t dWord)
    {
        b_dWordIN = dWord;
        b_setByte3();
        b_setByte2();
        b_setByte1();
        b_setByte0();
    }

    void TypeConv::FloatTo5Bytes(float inputValue)
    {
        _inputValue = inputValue;
        _floatToBytes();
    }

    void TypeConv::b_setHiByte()
    {
        // b_byteHi = (uint8_t)((b_wordIN >> 8) & 0xff);
        b_byte1 = (uint8_t)((b_wordIN >> 8) & 0xff);
    }

    void TypeConv::b_setLoByte()
    {
        // b_byteLo = (uint8_t)(b_wordIN & 0xff);
        b_byte0 = (uint8_t)(b_wordIN & 0xff);
    }

    void TypeConv::b_glue2Bytes()
    {
        // b_wordOUT = b_fGlue2Bytes(b_byteHi, b_byteLo);
        b_wordOUT = b_fGlue2Bytes(b_byte1, b_byte0);
    }

    void TypeConv::b_setByte3()
    {
        b_byte3 = (uint8_t)((b_dWordIN >> 24) & 0xff);
    }

    void TypeConv::b_setByte2()
    {
        b_byte2 = (uint8_t)((b_dWordIN >> 16) & 0xff);
    }

    void TypeConv::b_setByte1()
    {
        b_byte1 = (uint8_t)((b_dWordIN >> 8) & 0xff);
    }

    void TypeConv::b_setByte0()
    {
        b_byte0 = (uint8_t)(b_dWordIN & 0xff);
    }

    void TypeConv::b_glue4Bytes()
    {
        b_dWordOUT = b_fGlue4Bytes(b_byte3, b_byte2, b_byte1, b_byte0);
    }

    uint16_t TypeConv::b_fGlue2Bytes(uint8_t hi, uint8_t lo)
    {
        return ((((uint16_t)hi << 8) & (uint16_t)0xff00) | (uint16_t)lo);
    }

    uint32_t TypeConv::b_fGlue4Bytes(uint8_t b3, uint8_t b2, uint8_t b1, uint8_t b0)
    {
        return ((((uint32_t)b3 << 24) & (uint32_t)0xff000000) |
                (((uint32_t)b2 << 16) & (uint32_t)0x00ff0000) |
                (((uint32_t)b1 << 8) & (uint32_t)0x0000ff00) |
                (uint32_t)b0);
    }

    // namespace
}
#endif
