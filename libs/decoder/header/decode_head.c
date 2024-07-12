#include "decode_head.h"
/*----------------------------------------------------------
second hand copy of the header structure for conversion
------------------------------------------------------------*/
    
unsigned char       LSB_TYPE[sizeof(HalfWord)];
unsigned char       LSB_MACHINE[sizeof(HalfWord)];
unsigned char       LSB_VERSION[sizeof(WORD)];
unsigned char       LSB_ADDRESS[sizeof(ADDRESS)];
unsigned char       LSB_PGMPTR[sizeof(OFFSET)];
unsigned char       LSB_SCTNPTR[sizeof(OFFSET)];
unsigned char       LSB_FLAGS[sizeof(WORD)];
unsigned char       LSB_HEADERSIZE[sizeof(HalfWord)];
unsigned char       LSB_PPGMHEADER[sizeof(HalfWord)];
unsigned char       LSB_PGMHEADERNUM[sizeof(HalfWord)];
unsigned char       LSB_PSCTNHEADER[sizeof(HalfWord)];
unsigned char       LSB_PSCTNHEADERSIZE[sizeof(HalfWord)];
unsigned char       LSB_STRINGTABLEPTR[sizeof(HalfWord)];

unsigned char       MSB_TYPE[sizeof(HalfWord)];
unsigned char       MSB_MACHINE[sizeof(HalfWord)];
unsigned char       MSB_VERSION[sizeof(WORD)];
unsigned char       MSB_ADDRESS[sizeof(ADDRESS)];
unsigned char       MSB_PGMPTR[sizeof(OFFSET)];
unsigned char       MSB_SCTNPTR[sizeof(OFFSET)];
unsigned char       MSB_FLAGS[sizeof(WORD)];
unsigned char       MSB_HEADERSIZE[sizeof(HalfWord)];
unsigned char       MSB_PPGMHEADER[sizeof(HalfWord)];
unsigned char       MSB_PGMHEADERNUM[sizeof(HalfWord)];
unsigned char       MSB_PSCTNHEADER[sizeof(HalfWord)];
unsigned char       MSB_PSCTNHEADERSIZE[sizeof(HalfWord)];
unsigned char       MSB_STRINGTABLEPTR[sizeof(HalfWord)];


uint64_t head_little_endian(const unsigned char* char_array) {
  uint64_t result = 0;
  for (int i = 7; i >= 0; --i) {
    result = (result << 8) | char_array[i];
  }
  return result;
}

/*----------------------------------------------------------
These are converters, which will help to convert the bytes
into integer, which can be furthur used to match the different
cases
------------------------------------------------------------*/
    
union {
    unsigned char   bytes[2];
    uint16_t        intValue; 
} converter_2byte;

union {
    unsigned char   bytes[4];
    uint16_t        intValue; 
} converter_4byte;

union {
    unsigned char   bytes[8];
    uint16_t        intValue; 
} converter_8byte;


void HeaderProbe_LSB(ELF_HEADER *container, char_byte_stream *byte_stream){

    //memcpy(container -> elf_ident, byte_stream[0].byte, EI_NIDENT);

    LSB_TYPE[0] = byte_stream[1].byte[0];
    LSB_TYPE[1] = byte_stream[1].byte[1];

    uint16_t typeEndianValue = LSB_TYPE[0] | (LSB_TYPE[1] << 8);

    converter_2byte.bytes[0] = LSB_TYPE[0];
    converter_2byte.bytes[1] = LSB_TYPE[1];

    uint16_t LSB_TYPE_systemEndianValue = converter_2byte.intValue;

    container->type = LSB_TYPE_systemEndianValue;

    /*----------------------------------------------------------
    Conversion of the second stream byte 3 & 4 into little 
    endian, converting that value into int & pushing it into 
    the container
    ------------------------------------------------------------*/

    LSB_MACHINE[0] = byte_stream[1].byte[2];
    LSB_MACHINE[1] = byte_stream[1].byte[3];

    uint16_t machineEndianValue = LSB_MACHINE[0] | (LSB_MACHINE[1] << 8);

    converter_2byte.bytes[0] = LSB_MACHINE[0];
    converter_2byte.bytes[1] = LSB_MACHINE[1];

    uint16_t LSB_MACHINE_systemEndianValue = converter_2byte.intValue;

    container->machine = LSB_MACHINE_systemEndianValue;

    /*----------------------------------------------------------
    Conversion of the second stream byte 5, 6, 7 & 8 into 
    little endian, converting that value into int &
    pushing it into the container
    ------------------------------------------------------------*/

    LSB_VERSION[0] = byte_stream[1].byte[4];
    LSB_VERSION[1] = byte_stream[1].byte[5];
    LSB_VERSION[2] = byte_stream[1].byte[6];
    LSB_VERSION[3] = byte_stream[1].byte[7];

    uint32_t versionEndianValue = LSB_VERSION[0] | (LSB_VERSION[1] << 8) | (LSB_VERSION[2] << 16) | (LSB_VERSION[3] << 24);

    converter_4byte.bytes[0] = LSB_VERSION[0];
    converter_4byte.bytes[1] = LSB_VERSION[1];
    converter_4byte.bytes[2] = LSB_VERSION[2];
    converter_4byte.bytes[3] = LSB_VERSION[3];

    uint32_t LSB_VERSION_systemEndianValue = converter_4byte.intValue;

    container->version = LSB_VERSION_systemEndianValue;

    /*----------------------------------------------------------
    Conversion of the second stream byte 9, 10, 11, 12, 13, 14,
    15 & 16 into little endian, converting that value into int &
    pushing it into the container
    ------------------------------------------------------------*/

    LSB_ADDRESS[0] = byte_stream[1].byte[8];
    LSB_ADDRESS[1] = byte_stream[1].byte[9];
    LSB_ADDRESS[2] = byte_stream[1].byte[10];
    LSB_ADDRESS[3] = byte_stream[1].byte[11];
    LSB_ADDRESS[4] = byte_stream[1].byte[12];
    LSB_ADDRESS[5] = byte_stream[1].byte[13];
    LSB_ADDRESS[6] = byte_stream[1].byte[14];
    LSB_ADDRESS[7] = byte_stream[1].byte[15];

    uint64_t addressEndianValue = head_little_endian(LSB_ADDRESS);

    converter_8byte.bytes[0] = LSB_ADDRESS[0];
    converter_8byte.bytes[1] = LSB_ADDRESS[1];
    converter_8byte.bytes[2] = LSB_ADDRESS[2];
    converter_8byte.bytes[3] = LSB_ADDRESS[3];
    converter_8byte.bytes[4] = LSB_ADDRESS[4];
    converter_8byte.bytes[5] = LSB_ADDRESS[5];
    converter_8byte.bytes[6] = LSB_ADDRESS[6];
    converter_8byte.bytes[7] = LSB_ADDRESS[7];

    uint64_t LSB_ADDRESS_systemEndianValue = converter_8byte.intValue;

    container->EntryPoint = LSB_ADDRESS_systemEndianValue;

    /*----------------------------------------------------------
    Conversion of the third stream byte 1, 2, 3, 4, 5, 6, 7 & 8
    into little endian, converting that value into int & pushing
    it into the container
    ------------------------------------------------------------*/

    LSB_PGMPTR[0] = byte_stream[2].byte[0];
    LSB_PGMPTR[1] = byte_stream[2].byte[1];
    LSB_PGMPTR[2] = byte_stream[2].byte[2];
    LSB_PGMPTR[3] = byte_stream[2].byte[3];
    LSB_PGMPTR[4] = byte_stream[2].byte[4];
    LSB_PGMPTR[5] = byte_stream[2].byte[5];
    LSB_PGMPTR[6] = byte_stream[2].byte[6];
    LSB_PGMPTR[7] = byte_stream[2].byte[7];

    uint64_t LSB_PGMPTREndianValue = head_little_endian(LSB_PGMPTR);


    converter_8byte.bytes[0] = LSB_PGMPTR[0];
    converter_8byte.bytes[1] = LSB_PGMPTR[1];
    converter_8byte.bytes[2] = LSB_PGMPTR[2];
    converter_8byte.bytes[3] = LSB_PGMPTR[3];
    converter_8byte.bytes[4] = LSB_PGMPTR[4];
    converter_8byte.bytes[5] = LSB_PGMPTR[5];
    converter_8byte.bytes[6] = LSB_PGMPTR[6];
    converter_8byte.bytes[7] = LSB_PGMPTR[7];

    uint64_t LSB_PGMPTR_systemEndianValue = converter_8byte.intValue;

    container->PgmHeader_PTR = LSB_PGMPTR_systemEndianValue;

    /*----------------------------------------------------------
    Conversion of the third stream byte 9, 10, 11, 12, 13, 14, 
    15 & 16 into little endian, converting that value into int &
    pushing it into the container
    ------------------------------------------------------------*/

    LSB_SCTNPTR[0] = byte_stream[2].byte[8];
    LSB_SCTNPTR[1] = byte_stream[2].byte[9];
    LSB_SCTNPTR[2] = byte_stream[2].byte[10];
    LSB_SCTNPTR[3] = byte_stream[2].byte[11];
    LSB_SCTNPTR[4] = byte_stream[2].byte[12];
    LSB_SCTNPTR[5] = byte_stream[2].byte[13];
    LSB_SCTNPTR[6] = byte_stream[2].byte[14];
    LSB_SCTNPTR[7] = byte_stream[2].byte[15];

    uint64_t LSB_SCTNPTREndianValue = head_little_endian(LSB_SCTNPTR);

    converter_8byte.bytes[0] = LSB_SCTNPTR[0];
    converter_8byte.bytes[1] = LSB_SCTNPTR[1];
    converter_8byte.bytes[2] = LSB_SCTNPTR[2];
    converter_8byte.bytes[3] = LSB_SCTNPTR[3];
    converter_8byte.bytes[4] = LSB_SCTNPTR[4];
    converter_8byte.bytes[5] = LSB_SCTNPTR[5];
    converter_8byte.bytes[6] = LSB_SCTNPTR[6];
    converter_8byte.bytes[7] = LSB_SCTNPTR[7];

    uint64_t LSB_SCTNPTR_systemEndianValue = converter_8byte.intValue;

    container->SctnHeader_PTR = LSB_SCTNPTR_systemEndianValue;

    /*----------------------------------------------------------
    Conversion of the fourth stream byte 1, 2, 3, 4 into little 
    endian, converting that value into int & pushing it into the
    container
    ------------------------------------------------------------*/

    LSB_FLAGS[0] = byte_stream[3].byte[0];
    LSB_FLAGS[1] = byte_stream[3].byte[1];
    LSB_FLAGS[2] = byte_stream[3].byte[2];
    LSB_FLAGS[3] = byte_stream[3].byte[3];

    uint32_t LSB_FLAGSEndianValue = LSB_FLAGS[0] | (LSB_FLAGS[1] << 8) | (LSB_FLAGS[2] << 16) | (LSB_FLAGS[3] << 24);

    converter_4byte.bytes[0] = LSB_FLAGS[0];
    converter_4byte.bytes[1] = LSB_FLAGS[1];
    converter_4byte.bytes[2] = LSB_FLAGS[2];
    converter_4byte.bytes[3] = LSB_FLAGS[3];

    uint32_t LSB_FLAGS_systemEndianValue = converter_4byte.intValue;

    container->flags = LSB_FLAGS_systemEndianValue;

    /*------------------------------------------------------------
    Conversion of the fourth stream byte 5, 6 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/

    LSB_HEADERSIZE[0] = byte_stream[3].byte[4];
    LSB_HEADERSIZE[1] = byte_stream[3].byte[5];

    uint16_t LSB_HEADERSIZEEndianValue = LSB_HEADERSIZE[0] | (LSB_HEADERSIZE[1] << 8);

    converter_2byte.bytes[0] = LSB_HEADERSIZE[0];
    converter_2byte.bytes[1] = LSB_HEADERSIZE[1];

    uint16_t LSB_HEADERSIZE_systemEndianValue = converter_2byte.intValue;

    container->HeaderSize = LSB_HEADERSIZE_systemEndianValue;

    /*------------------------------------------------------------
    Conversion of the fourth stream byte 7, 8 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/

    LSB_PPGMHEADER[0] = byte_stream[3].byte[6];
    LSB_PPGMHEADER[1] = byte_stream[3].byte[7];
    
    uint16_t LSB_PPGMHEADEREndianValue = LSB_PPGMHEADER[0] | (LSB_PPGMHEADER[1] << 8);

    converter_2byte.bytes[0] = LSB_PPGMHEADER[0];
    converter_2byte.bytes[1] = LSB_PPGMHEADER[1];

    uint16_t LSB_PPGMHEADER_systemEndianValue = converter_2byte.intValue;

    container->PerPgmHeaderSize = LSB_PPGMHEADER_systemEndianValue;

    /*------------------------------------------------------------
    Conversion of the fourth stream byte 9, 10 into little endian,
    converting that value into int & pushing it into the container
        --------------------------------------------------------------*/

    LSB_PGMHEADERNUM[0] = byte_stream[3].byte[8];
    LSB_PGMHEADERNUM[1] = byte_stream[3].byte[9];

    uint16_t LSB_PGMHEADERNUMEndianValue = LSB_PGMHEADERNUM[0] | (LSB_PGMHEADERNUM[1] << 8);

    converter_2byte.bytes[0] = LSB_PGMHEADERNUM[0];
    converter_2byte.bytes[1] = LSB_PGMHEADERNUM[1];

    uint16_t LSB_PGMHEADERNUM_systemEndianValue = converter_2byte.intValue;

    container->PgmHeaderNum = LSB_PGMHEADERNUM_systemEndianValue;

    /*------------------------------------------------------------
    Conversion of the fourth stream byte 11, 12 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/

    LSB_PSCTNHEADER[0] = byte_stream[3].byte[10];
    LSB_PSCTNHEADER[1] = byte_stream[3].byte[11];

    uint16_t LSB_PSCTNHEADEREndianValue = LSB_PSCTNHEADER[0] | (LSB_PSCTNHEADER[1] << 8);

    converter_2byte.bytes[0] = LSB_PSCTNHEADER[0];
    converter_2byte.bytes[1] = LSB_PSCTNHEADER[1];

    uint16_t LSB_PSCTNHEADER_systemEndianValue = converter_2byte.intValue;

    container->PerSctnHeaderSize = LSB_PSCTNHEADER_systemEndianValue;


    /*------------------------------------------------------------
    Conversion of the fourth stream byte 13, 14 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/

    LSB_PSCTNHEADERSIZE[0] = byte_stream[3].byte[12];
    LSB_PSCTNHEADERSIZE[1] = byte_stream[3].byte[13];

    uint16_t LSB_PSCTNHEADERSIZEEndianValue = LSB_PSCTNHEADERSIZE[0] | (LSB_PSCTNHEADERSIZE[1] << 8);

    converter_2byte.bytes[0] = LSB_PSCTNHEADERSIZE[0];
    converter_2byte.bytes[1] = LSB_PSCTNHEADERSIZE[1];

    uint16_t LSB_PSCTNHEADERSIZE_systemEndianValue = converter_2byte.intValue;

    container->SctnHeaderNum = LSB_PSCTNHEADERSIZE_systemEndianValue;

    /*------------------------------------------------------------
    Conversion of the fourth stream byte 15, 16 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/

    LSB_STRINGTABLEPTR[0] = byte_stream[3].byte[14];
    LSB_STRINGTABLEPTR[1] = byte_stream[3].byte[15];

    uint16_t LSB_STRINGTABLEPTREndianValue = LSB_STRINGTABLEPTR[0] | (LSB_STRINGTABLEPTR[1] << 8);

    converter_2byte.bytes[0] = LSB_STRINGTABLEPTR[0];
    converter_2byte.bytes[1] = LSB_STRINGTABLEPTR[1];

    uint16_t LSB_STRINGTABLEPTR_systemEndianValue = converter_2byte.intValue;

    container->StringTable_PTR = LSB_STRINGTABLEPTR_systemEndianValue;
}

void HeaderProbe_MSB(ELF_HEADER *container, char_byte_stream *byte_stream){
    /*----------------------------------------------------------
    Conversion of the second stream byte 1 & 2 into little 
    endian, converting that value into int & pushing it into
    the container
    ------------------------------------------------------------*/
                    
    MSB_TYPE[0] = byte_stream[1].byte[0];
    MSB_TYPE[1] = byte_stream[1].byte[1];
                
    uint16_t typeBigEndianValue = (MSB_TYPE[0] << 8) | MSB_TYPE[1];
                    
    converter_2byte.bytes[0] = MSB_TYPE[0];
    converter_2byte.bytes[1] = MSB_TYPE[1];
                    
    uint16_t MSB_TYPE_systemBigEndianValue = converter_2byte.intValue;
                    
    container->type = MSB_TYPE_systemBigEndianValue;
                
    /*----------------------------------------------------------
    Conversion of the second stream byte 3 & 4 into little 
    endian, converting that value into int & pushing it into 
    the container
    ------------------------------------------------------------*/
                
    MSB_MACHINE[0] = byte_stream[1].byte[2];
    MSB_MACHINE[1] = byte_stream[1].byte[3];
                    
    uint16_t machineBigEndianValue = (MSB_MACHINE[0] << 8) | MSB_MACHINE[1];
                    
    converter_2byte.bytes[0] = MSB_MACHINE[0];
    converter_2byte.bytes[1] = MSB_MACHINE[1];
                    
    uint16_t MSB_MACHINE_systemBigEndianValue = converter_2byte.intValue;
                    
    container->machine = MSB_MACHINE_systemBigEndianValue;
                
    /*----------------------------------------------------------
    Conversion of the second stream byte 5, 6, 7 & 8 into 
    little endian, converting that value into int &
    pushing it into the container
    ------------------------------------------------------------*/
                
    MSB_VERSION[0] = byte_stream[1].byte[4];
    MSB_VERSION[1] = byte_stream[1].byte[5];
    MSB_VERSION[2] = byte_stream[1].byte[6];
    MSB_VERSION[3] = byte_stream[1].byte[7];
                    
    uint16_t versionBigEndianValue = (MSB_VERSION[0] << 8) | MSB_VERSION[1];
                    
    converter_4byte.bytes[0] = MSB_VERSION[0];
    converter_4byte.bytes[1] = MSB_VERSION[1];
    converter_4byte.bytes[2] = MSB_VERSION[2];
    converter_4byte.bytes[3] = MSB_VERSION[3];
                    
    uint16_t MSB_VERSION_systemBigEndianValue = converter_4byte.intValue;
                    
    container->version = MSB_VERSION_systemBigEndianValue;
                
    /*----------------------------------------------------------
    Conversion of the second stream byte 9, 10, 11, 12, 13, 14,
    15 & 16 into little endian, converting that value into int &
    pushing it into the container
    ------------------------------------------------------------*/
                
    MSB_ADDRESS[0] = byte_stream[1].byte[8];
    MSB_ADDRESS[1] = byte_stream[1].byte[9];
    MSB_ADDRESS[2] = byte_stream[1].byte[10];
    MSB_ADDRESS[3] = byte_stream[1].byte[11];
    MSB_ADDRESS[4] = byte_stream[1].byte[12];
    MSB_ADDRESS[5] = byte_stream[1].byte[13];
    MSB_ADDRESS[6] = byte_stream[1].byte[14];
    MSB_ADDRESS[7] = byte_stream[1].byte[15];
                    
    uint16_t addressBigEndianValue = (MSB_ADDRESS[0] << 8) | MSB_ADDRESS[1];
                    
    converter_8byte.bytes[0] = MSB_ADDRESS[0];
    converter_8byte.bytes[1] = MSB_ADDRESS[1];
    converter_8byte.bytes[2] = MSB_ADDRESS[2];
    converter_8byte.bytes[3] = MSB_ADDRESS[3];
    converter_8byte.bytes[4] = MSB_ADDRESS[4];
    converter_8byte.bytes[5] = MSB_ADDRESS[5];
    converter_8byte.bytes[6] = MSB_ADDRESS[6];
    converter_8byte.bytes[7] = MSB_ADDRESS[7];
                
    uint16_t MSB_ADDRESS_systemBigEndianValue = converter_8byte.intValue;
                    
    container->EntryPoint = MSB_ADDRESS_systemBigEndianValue;
                
    /*----------------------------------------------------------
    Conversion of the third stream byte 1, 2, 3, 4, 5, 6, 7 & 8
    into little endian, converting that value into int & pushing
    it into the container
    ------------------------------------------------------------*/
                
    MSB_PGMPTR[0] = byte_stream[2].byte[0];
    MSB_PGMPTR[1] = byte_stream[2].byte[1];
    MSB_PGMPTR[2] = byte_stream[2].byte[2];
    MSB_PGMPTR[3] = byte_stream[2].byte[3];
    MSB_PGMPTR[4] = byte_stream[2].byte[4];
    MSB_PGMPTR[5] = byte_stream[2].byte[5];
    MSB_PGMPTR[6] = byte_stream[2].byte[6];
    MSB_PGMPTR[7] = byte_stream[2].byte[7];
                
    uint16_t MSB_PGMPTR_BigEndianValue = (MSB_PGMPTR[0] << 8) | MSB_PGMPTR[1];
                    
    converter_8byte.bytes[0] = MSB_PGMPTR[0];
    converter_8byte.bytes[1] = MSB_PGMPTR[1];
    converter_8byte.bytes[2] = MSB_PGMPTR[2];
    converter_8byte.bytes[3] = MSB_PGMPTR[3];
    converter_8byte.bytes[4] = MSB_PGMPTR[4];
    converter_8byte.bytes[5] = MSB_PGMPTR[5];
    converter_8byte.bytes[6] = MSB_PGMPTR[6];
    converter_8byte.bytes[7] = MSB_PGMPTR[7];
                
    uint16_t MSB_PGMPTR_systemBigEndianValue = converter_8byte.intValue;
                    
    container->PgmHeader_PTR = MSB_PGMPTR_systemBigEndianValue;
                
    /*----------------------------------------------------------
    Conversion of the third stream byte 9, 10, 11, 12, 13, 14, 
    15 & 16 into little endian, converting that value into int &
    pushing it into the container
    ------------------------------------------------------------*/
                
    MSB_SCTNPTR[0] = byte_stream[2].byte[8];
    MSB_SCTNPTR[1] = byte_stream[2].byte[9];
    MSB_SCTNPTR[2] = byte_stream[2].byte[10];
    MSB_SCTNPTR[3] = byte_stream[2].byte[11];
    MSB_SCTNPTR[4] = byte_stream[2].byte[12];
    MSB_SCTNPTR[5] = byte_stream[2].byte[13];
    MSB_SCTNPTR[6] = byte_stream[2].byte[14];
    MSB_SCTNPTR[7] = byte_stream[2].byte[15];
                    
    uint16_t MSB_SCTNPTR_BigEndianValue = (MSB_SCTNPTR[0] << 8) | MSB_SCTNPTR[1];
                    
    converter_8byte.bytes[0] = MSB_SCTNPTR[0];
    converter_8byte.bytes[1] = MSB_SCTNPTR[1];
    converter_8byte.bytes[2] = MSB_SCTNPTR[2];
    converter_8byte.bytes[3] = MSB_SCTNPTR[3];
    converter_8byte.bytes[4] = MSB_SCTNPTR[4];
    converter_8byte.bytes[5] = MSB_SCTNPTR[5];
    converter_8byte.bytes[6] = MSB_SCTNPTR[6];
    converter_8byte.bytes[7] = MSB_SCTNPTR[7];
                
    uint16_t MSB_SCTNPTR_systemBigEndianValue = converter_8byte.intValue;
                    
    container->SctnHeader_PTR = MSB_SCTNPTR_systemBigEndianValue;
                    
    /*----------------------------------------------------------
    Conversion of the fourth stream byte 1, 2, 3, 4 into little 
    endian, converting that value into int & pushing it into the
    container
    ------------------------------------------------------------*/
                
    MSB_FLAGS[0] = byte_stream[3].byte[0];
    MSB_FLAGS[1] = byte_stream[3].byte[1];
    MSB_FLAGS[2] = byte_stream[3].byte[2];
    MSB_FLAGS[3] = byte_stream[3].byte[3];
                    
    uint16_t MSB_FLAGS_BigEndianValue = (MSB_FLAGS[0] << 8) | MSB_FLAGS[1];
                    
    converter_4byte.bytes[0] = MSB_FLAGS[0];
    converter_4byte.bytes[1] = MSB_FLAGS[1];
    converter_4byte.bytes[2] = MSB_FLAGS[2];
    converter_4byte.bytes[3] = MSB_FLAGS[3];
                
    uint16_t MSB_FLAGS_systemBigEndianValue = converter_4byte.intValue;
                    
    container->flags = MSB_FLAGS_systemBigEndianValue;
                    
    /*------------------------------------------------------------
    Conversion of the fourth stream byte 5, 6 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/
                
    MSB_HEADERSIZE[0] = byte_stream[3].byte[4];
    MSB_HEADERSIZE[1] = byte_stream[3].byte[5];
                
    uint16_t MSB_HEADERSIZE_BigEndianValue = (MSB_HEADERSIZE[0] << 8) | MSB_HEADERSIZE[1];
                    
    converter_2byte.bytes[0] = MSB_HEADERSIZE[0];
    converter_2byte.bytes[1] = MSB_HEADERSIZE[1];
                
    uint16_t MSB_HEADERSIZE_systemBigEndianValue = converter_2byte.intValue;
                    
    container->HeaderSize = MSB_HEADERSIZE_systemBigEndianValue;
                
    /*------------------------------------------------------------
    Conversion of the fourth stream byte 7, 8 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/
                
    MSB_PPGMHEADER[0] = byte_stream[3].byte[6];
    MSB_PPGMHEADER[1] = byte_stream[3].byte[7];
                    
    uint16_t MSB_PPGMHEADER_BigEndianValue = (MSB_PPGMHEADER[0] << 8) | MSB_PPGMHEADER[1];
                    
    converter_2byte.bytes[0] = MSB_PPGMHEADER[0];
    converter_2byte.bytes[1] = MSB_PPGMHEADER[1];
            
    uint16_t MSB_PPGMHEADER_systemBigEndianValue = converter_2byte.intValue;
                    
    container->PerPgmHeaderSize = MSB_PPGMHEADER_systemBigEndianValue;
                
    /*------------------------------------------------------------
    Conversion of the fourth stream byte 9, 10 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/
                
    MSB_PGMHEADERNUM[0] = byte_stream[3].byte[8];
    MSB_PGMHEADERNUM[1] = byte_stream[3].byte[9];
                
    uint16_t MSB_PGMHEADERNUM_BigEndianValue = (MSB_PGMHEADERNUM[0] << 8) | MSB_PGMHEADERNUM[1];
                    
    converter_2byte.bytes[0] = MSB_PGMHEADERNUM[0];
    converter_2byte.bytes[1] = MSB_PGMHEADERNUM[1];
                
    uint16_t MSB_PGMHEADERNUM_systemBigEndianValue = converter_2byte.intValue;
                    
    container->PgmHeaderNum = MSB_PGMHEADERNUM_systemBigEndianValue;
                
    /*------------------------------------------------------------
    Conversion of the fourth stream byte 11, 12 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/
                
    MSB_PSCTNHEADER[0] = byte_stream[3].byte[10];
    MSB_PSCTNHEADER[1] = byte_stream[3].byte[11];
                    
    uint16_t MSB_PSCTNHEADER_BigEndianValue = (MSB_PSCTNHEADER[0] << 8) | MSB_PSCTNHEADER[1];
                    
    converter_2byte.bytes[0] = MSB_PSCTNHEADER[0];
    converter_2byte.bytes[1] = MSB_PSCTNHEADER[1];
                
    uint16_t MSB_PSCTNHEADER_systemBigEndianValue = converter_2byte.intValue;
                    
    container->PerSctnHeaderSize = MSB_PSCTNHEADER_systemBigEndianValue;
                
                
    /*------------------------------------------------------------
    Conversion of the fourth stream byte 13, 14 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/
                
    MSB_PSCTNHEADERSIZE[0] = byte_stream[3].byte[12];
    MSB_PSCTNHEADERSIZE[1] = byte_stream[3].byte[13];
                    
    uint16_t MSB_PSCTNHEADERSIZE_BigEndianValue = (MSB_PSCTNHEADERSIZE[0] << 8) | MSB_PSCTNHEADERSIZE[1];
                    
    converter_2byte.bytes[0] = MSB_PSCTNHEADERSIZE[0];
    converter_2byte.bytes[1] = MSB_PSCTNHEADERSIZE[1];
                
    uint16_t MSB_PSCTNHEADERSIZE_systemBigEndianValue = converter_2byte.intValue;
                    
    container->SctnHeaderNum = MSB_PSCTNHEADERSIZE_systemBigEndianValue;
                
    /*------------------------------------------------------------
    Conversion of the fourth stream byte 15, 16 into little endian,
    converting that value into int & pushing it into the container
    --------------------------------------------------------------*/
                
    MSB_STRINGTABLEPTR[0] = byte_stream[3].byte[14];
    MSB_STRINGTABLEPTR[1] = byte_stream[3].byte[15];
                    
    uint16_t MSB_STRINGTABLEPTR_BigEndianValue = (MSB_STRINGTABLEPTR[0] << 8) | MSB_STRINGTABLEPTR[1];
                    
    converter_2byte.bytes[0] = MSB_STRINGTABLEPTR[0];
    converter_2byte.bytes[1] = MSB_STRINGTABLEPTR[1];
                
    uint16_t MSB_STRINGTABLEPTR_systemBigEndianValue = converter_2byte.intValue;
                    
    container->StringTable_PTR = MSB_STRINGTABLEPTR_systemBigEndianValue;
}




