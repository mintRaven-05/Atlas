/* ELF files ~ Header section info archive */
#ifndef HEADER_H_
#define HEADER_H_

#include <stdint.h>

/* type defintions for header struct */
typedef   uint16_t        HalfWord;
typedef   uint32_t        WORD;
typedef   uint64_t        ADDRESS;
typedef   uint64_t        OFFSET;
typedef   unsigned char   HEADER;

#define EI_NIDENT         16
#define CHUNK_SIZE        16

/*----------------------------------------------------
 ELF file identification info archive.
 Type matching will be done using the following
 parameters JUST FOR THE HEADER(16 BITS unsigned char).

  Architecture Info
------------------------------------------------------*/

#define ELF0                    0x00
#define ELF32                   0x01
#define ELF64                   0x02

#define  ARCH_NONE_0            "None"
#define  ARCH_x32_1             "ELF x32 - Architecture"
#define  ARCH_x64_2             "ELF x64 - Architecture"
/*----------------------------------------------------
  Data Format Info
------------------------------------------------------*/

#define FMT_0                    0x00
#define FMT_1                    0x01
#define FMT_2                    0x02

#define  DATA_FMT_0             "None"
#define  DATA_FMT_1             "2\'s compliment, little endian"
#define  DATA_FMT_2             "Big endian"

/*----------------------------------------------------
  Version info 
------------------------------------------------------*/
#define  VERSION_INFO      1
/*----------------------------------------------------
  Application Binary Information ( ABI )
------------------------------------------------------*/

#define ABI_0                    0x00
#define ABI_1                    0x01
#define ABI_2                    0x02
#define ABI_3                    0x03

#define  ABI_SYSTEMV_0          "UNIX - System V"
#define  ABI_HP_UX_1            "HP - UX"
#define  ABI_NETBSD_2           "NetBSD"
#define  ABI_LINUX_3            "Linux"

/*----------------------------------------------------
 ELF file identification info archive.
 Type matching for ELF_TYPE will done using
 the following parameters.
------------------------------------------------------*/

#define ET_0                    0x00
#define ET_1                    0x01
#define ET_2                    0x02
#define ET_3                    0x03
#define ET_4                    0x04

#define  ET_NONE_0              "No file type"
#define  ET_REL_1               "REL (Relocatable file type)"
#define  ET_EXEC_2              "EXEC (Executable file type)"
#define  ET_DYN_3               "DYN (Shared Object file type)"
#define  ET_CORE_4              "CORE (Core file type)"

/*----------------------------------------------------
 ELF file identification info archive
 Type matching for ELF_MACHINE will be done using
 the following paraameter.
------------------------------------------------------*/

#define M_03                      0x03
#define M_08                      0x08
#define M_28                      0x28
#define M_3E                      0x3E
#define M_B7                      0xB7
#define M_F3                      0xF3

#define  MACHINE_0x03             "Intel 80386"
#define  MACHINE_0x08             "Million instructions per second (MIPS)"
#define  MACHINE_0x28             "Advanced RISC Machines (ARM)"
#define  MACHINE_0x3E             "Advanced Micro Devices x86-64 (AMD)"
#define  MACHINE_0xB7             "Advanced RISC Machines 64 bit (ARMv8)"
#define  MACHINE_0xF3             "Reduced Instruction Set Computing(RISC-V)"

/*----------------------------------------------------
  ELF_HEADER struct will contain all the necessary
  containers for the elf file parameters and each
  parameter will be identified by the classification
  done above.
------------------------------------------------------*/

typedef struct HEAD{

  HEADER      elf_ident[EI_NIDENT];
  HalfWord    type;
  HalfWord    machine;
  WORD        version;
  ADDRESS     EntryPoint;
  OFFSET      PgmHeader_PTR;
  OFFSET      SctnHeader_PTR;
  WORD        flags;
  HalfWord    HeaderSize;
  HalfWord    PerPgmHeaderSize;
  HalfWord    PgmHeaderNum;
  HalfWord    PerSctnHeaderSize;
  HalfWord    SctnHeaderNum;
  HalfWord    StringTable_PTR;

} ELF_HEADER;

#endif
