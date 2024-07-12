#ifndef PGM_X64_H_
#define PGM_X64_H_

#include <stdint.h>
#include "../header/header.h"

typedef uint64_t XWORD;

/*
    program header type definations. This will tell us
    which section represents and executes what segment
    of the program/ELF file.
*/

#define x64_PT_0                0x00
#define x64_PT_1                0x01
#define x64_PT_2                0x02
#define x64_PT_3                0x03
#define x64_PT_4                0x04
#define x64_PT_5                0x05
#define x64_PT_6                0x06
#define x64_PT_7                0x07
#define x64_PT_8                0x6474E553
#define x64_PT_9                0x6474E550
#define x64_PT_10               0x6474E551
#define x64_PT_11               0x6474E552 

#define x64_PT_NULL_0           "[NULL]"
#define x64_PT_LOAD_1           "[LOAD]"
#define x64_PT_DYN_2            "[DYN]"
#define x64_PT_INTERP_3         "[INTERP]"
#define x64_PT_NOTE_4           "[NOTE]"
#define x64_PT_SHLIB_5          "[SHRD_LIB]"
#define x64_PT_PHDR_6           "[PGM_HDR]"
#define x64_PT_TLS_7            "[TLS]"
#define x64_PT_GNU_PROPERTY_8   "[GNU_PROPERTY]"
#define x64_PT_GNU_EH_FRAME_9   "[GNU_EH_FRAME]"
#define x64_PT_GNU_STACK_10     "[GNU_STACK]"
#define x64_PT_GNU_RELRO        "[GNU_RELRO]"

/*
    Program header flags, 
        -> X: executable file type
        -> R: Readable file type
        -> W: Writable file type
*/

#define R                   0x04
#define RX                  0x05
#define RW                  0x06

#define PF_R                "R"
#define PF_RX               "RX"
#define PF_RW               "RW"

typedef struct PGM_HEADER_64 {
    WORD type;
    WORD flags;
    OFFSET offset;
    ADDRESS vaddr;
    ADDRESS paddr;
    XWORD file_size;
    XWORD mem_size;
    XWORD align;
}PGM_HEADER_x64;

#endif
