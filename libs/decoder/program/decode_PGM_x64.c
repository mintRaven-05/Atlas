#include "decode_PGM_x64.h"
/*----------------------------------------------------------
second hand copy of the x64 program header structure for
 conversion
------------------------------------------------------------*/

unsigned char       PGM_LSB_TYPE[sizeof(WORD)];
unsigned char       PGM_LSB_FLAGS[sizeof(WORD)];
unsigned char       PGM_LSB_OFFSET[sizeof(OFFSET)];
unsigned char       PGM_LSB_VADDR[sizeof(ADDRESS)];
unsigned char       PGM_LSB_PADDR[sizeof(ADDRESS)];
unsigned char       PGM_LSB_FILE_SIZE[sizeof(XWORD)];
unsigned char       PGM_LSB_MEM_SIZE[sizeof(XWORD)];
unsigned char       PGM_LSB_ALIGN[sizeof(XWORD)];

unsigned char       INTERP_PGM[30];
uint64_t chars_to_little_endian_64(const unsigned char* char_array) {
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
    unsigned char   bytes[4];
    uint32_t        intValue; 
} PGM_converter_4byte;

union {
    unsigned char   bytes[8];
    uint64_t        intValue; 
} PGM_converter_8byte;

PGM_HEADER_x64 *programHeaderProbe_x64_LSB(char_byte_stream *byte_stream, int pgm_start, int total_headers, int header_size){
    int byte_count = 0;
    int line_count = 0;
    int total_bytes = total_headers*header_size;
    int total_lines = (total_bytes/16);
    int idx = pgm_start;
    int container_count = 0;

    PGM_HEADER_x64 *container = malloc(sizeof(PGM_HEADER_x64)*total_headers);

   while(container_count != total_headers){
 /*----------------------------------------------------------------------------------------------------------*/
        for(int i = 0; i<4; i++){

                PGM_LSB_TYPE[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if (byte_count>=16){
                        byte_count = 0;
                        idx += 1;
                }
        }

        uint32_t pgm_type_little_endian = PGM_LSB_TYPE[0] | (PGM_LSB_TYPE[1] << 8) | (PGM_LSB_TYPE[2] << 16) | (PGM_LSB_TYPE[3] << 24);

        PGM_converter_4byte.bytes[0] = PGM_LSB_TYPE[0];
        PGM_converter_4byte.bytes[1] = PGM_LSB_TYPE[1];
        PGM_converter_4byte.bytes[2] = PGM_LSB_TYPE[2];
        PGM_converter_4byte.bytes[3] = PGM_LSB_TYPE[3];

        uint32_t type_systemEndian = PGM_converter_4byte.intValue;

        container[container_count].type = type_systemEndian;
/*----------------------------------------------------------------------------------------------------------*/
        for(int i = 0; i<4; i++){
                PGM_LSB_FLAGS[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if (byte_count>=16){
                        byte_count = 0;
                        idx += 1;
                }
        }

        uint32_t pgm_flags_little_endian = PGM_LSB_FLAGS[0] |(PGM_LSB_FLAGS[1] << 8) | (PGM_LSB_FLAGS[2] << 16) | (PGM_LSB_FLAGS[3] << 24);

        PGM_converter_4byte.bytes[0] = PGM_LSB_FLAGS[0];
        PGM_converter_4byte.bytes[1] = PGM_LSB_FLAGS[1];
        PGM_converter_4byte.bytes[2] = PGM_LSB_FLAGS[2];
        PGM_converter_4byte.bytes[3] = PGM_LSB_FLAGS[3];

        uint32_t flags_systemEndian = PGM_converter_4byte.intValue;

        container[container_count].flags = flags_systemEndian;
/*----------------------------------------------------------------------------------------------------------*/
       for(int i = 0; i<8; i++){
                PGM_LSB_OFFSET[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if(byte_count>= 16){
                        byte_count = 0;
                        idx += 1;
                }
       }
        uint64_t pgm_offset_littleEndian = chars_to_little_endian_64(PGM_LSB_OFFSET);

        PGM_converter_8byte.bytes[0] = PGM_LSB_OFFSET[0];
        PGM_converter_8byte.bytes[1] = PGM_LSB_OFFSET[1];
        PGM_converter_8byte.bytes[2] = PGM_LSB_OFFSET[2];
        PGM_converter_8byte.bytes[3] = PGM_LSB_OFFSET[3];
        PGM_converter_8byte.bytes[4] = PGM_LSB_OFFSET[4];
        PGM_converter_8byte.bytes[5] = PGM_LSB_OFFSET[5];
        PGM_converter_8byte.bytes[6] = PGM_LSB_OFFSET[6];
        PGM_converter_8byte.bytes[7] = PGM_LSB_OFFSET[7];

        uint64_t offset_systemEndian = PGM_converter_8byte.intValue;

        container[container_count].offset = offset_systemEndian;

/*----------------------------------------------------------------------------------------------------------*/
        //idx += 1;
        //line_count += 1;
/*----------------------------------------------------------------------------------------------------------*/
        for(int i = 0; i<8; i++){
                PGM_LSB_VADDR[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if (byte_count>=16){
                        byte_count = 0;
                        idx += 1;
                }
        }

        uint64_t pgm_vaddr_littleEndian = chars_to_little_endian_64(PGM_LSB_VADDR);

        PGM_converter_8byte.bytes[0] = PGM_LSB_VADDR[0];
        PGM_converter_8byte.bytes[1] = PGM_LSB_VADDR[1];
        PGM_converter_8byte.bytes[2] = PGM_LSB_VADDR[2];
        PGM_converter_8byte.bytes[3] = PGM_LSB_VADDR[3];
        PGM_converter_8byte.bytes[4] = PGM_LSB_VADDR[4];
        PGM_converter_8byte.bytes[5] = PGM_LSB_VADDR[5];
        PGM_converter_8byte.bytes[6] = PGM_LSB_VADDR[6];
        PGM_converter_8byte.bytes[7] = PGM_LSB_VADDR[7];

        uint64_t vaddr_systemEndian = PGM_converter_8byte.intValue;

        container[container_count].vaddr = vaddr_systemEndian;

/*----------------------------------------------------------------------------------------------------------*/
       for(int i = 0; i<8; i++){
                PGM_LSB_PADDR[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if (byte_count>=16){
                        byte_count = 0;
                        idx += 1;
                }

       }

        uint64_t pgm_paddr_littleEndian = chars_to_little_endian_64(PGM_LSB_PADDR);

        PGM_converter_8byte.bytes[0] = PGM_LSB_PADDR[0];
        PGM_converter_8byte.bytes[1] = PGM_LSB_PADDR[1];
        PGM_converter_8byte.bytes[2] = PGM_LSB_PADDR[2];
        PGM_converter_8byte.bytes[3] = PGM_LSB_PADDR[3];
        PGM_converter_8byte.bytes[4] = PGM_LSB_PADDR[4];
        PGM_converter_8byte.bytes[5] = PGM_LSB_PADDR[5];
        PGM_converter_8byte.bytes[6] = PGM_LSB_PADDR[6];
        PGM_converter_8byte.bytes[7] = PGM_LSB_PADDR[7];

        uint64_t paddr_systemEndian = PGM_converter_8byte.intValue;

        container[container_count].paddr = paddr_systemEndian;

/*----------------------------------------------------------------------------------------------------------*/
        //idx += 1;
        //line_count += 1;
/*----------------------------------------------------------------------------------------------------------*/
       for(int i = 0; i<8; i++){
                PGM_LSB_FILE_SIZE[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if (byte_count>=16){
                        byte_count = 0;
                        idx += 1;
                }
       }

        uint64_t pgm_file_size_littleEndian = chars_to_little_endian_64(PGM_LSB_FILE_SIZE);

        PGM_converter_8byte.bytes[0] = PGM_LSB_FILE_SIZE[0];
        PGM_converter_8byte.bytes[1] = PGM_LSB_FILE_SIZE[1];
        PGM_converter_8byte.bytes[2] = PGM_LSB_FILE_SIZE[2];
        PGM_converter_8byte.bytes[3] = PGM_LSB_FILE_SIZE[3];
        PGM_converter_8byte.bytes[4] = PGM_LSB_FILE_SIZE[4];
        PGM_converter_8byte.bytes[5] = PGM_LSB_FILE_SIZE[5];
        PGM_converter_8byte.bytes[6] = PGM_LSB_FILE_SIZE[6];
        PGM_converter_8byte.bytes[7] = PGM_LSB_FILE_SIZE[7];

        uint64_t file_size_systemEndian = PGM_converter_8byte.intValue;

        container[container_count].file_size = file_size_systemEndian;

/*----------------------------------------------------------------------------------------------------------*/
       
       for(int i = 0; i<8; i++){
                PGM_LSB_MEM_SIZE[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if (byte_count>=16){
                        byte_count = 0;
                        idx += 1;
                }
       }

        uint64_t pgm_mem_size_littleEndian = chars_to_little_endian_64(PGM_LSB_MEM_SIZE);

        PGM_converter_8byte.bytes[0] = PGM_LSB_MEM_SIZE[0];
        PGM_converter_8byte.bytes[1] = PGM_LSB_MEM_SIZE[1];
        PGM_converter_8byte.bytes[2] = PGM_LSB_MEM_SIZE[2];
        PGM_converter_8byte.bytes[3] = PGM_LSB_MEM_SIZE[3];
        PGM_converter_8byte.bytes[4] = PGM_LSB_MEM_SIZE[4];
        PGM_converter_8byte.bytes[5] = PGM_LSB_MEM_SIZE[5];
        PGM_converter_8byte.bytes[6] = PGM_LSB_MEM_SIZE[6];
        PGM_converter_8byte.bytes[7] = PGM_LSB_MEM_SIZE[7];

        uint64_t mem_size_systemEndian = PGM_converter_8byte.intValue;

        container[container_count].mem_size = mem_size_systemEndian;

/*----------------------------------------------------------------------------------------------------------*/
        //idx += 1;
        //line_count +=1 ;
/*----------------------------------------------------------------------------------------------------------*/
        
        for(int i = 0; i<8; i++){
                PGM_LSB_ALIGN[i] = byte_stream[idx].byte[byte_count];
                byte_count += 1;
                if (byte_count >= 16){
                        byte_count = 0;
                        idx += 1;
                }
        }

        uint64_t pgm_align_littleEndian = chars_to_little_endian_64(PGM_LSB_ALIGN);

        PGM_converter_8byte.bytes[0] = PGM_LSB_ALIGN[0];
        PGM_converter_8byte.bytes[1] = PGM_LSB_ALIGN[1];
        PGM_converter_8byte.bytes[2] = PGM_LSB_ALIGN[2];
        PGM_converter_8byte.bytes[3] = PGM_LSB_ALIGN[3];
        PGM_converter_8byte.bytes[4] = PGM_LSB_ALIGN[4];
        PGM_converter_8byte.bytes[5] = PGM_LSB_ALIGN[5];
        PGM_converter_8byte.bytes[6] = PGM_LSB_ALIGN[6];
        PGM_converter_8byte.bytes[7] = PGM_LSB_ALIGN[7];

        uint64_t align_systemEndian = PGM_converter_8byte.intValue;

        container[container_count].align = align_systemEndian;
        
        container_count += 1;


    }
    int i = 0;  
    while (byte_stream[idx].byte[byte_count] != 0x00){
        INTERP_PGM[i] = byte_stream[idx].byte[byte_count];
        byte_count += 1;
        if(byte_count >= 16){
                idx += 1;
                byte_count = 0;
        }
        i++;
    }
    INTERP_PGM[i] = '\0';
    return container;
}