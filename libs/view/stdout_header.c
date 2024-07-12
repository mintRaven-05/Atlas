#include "stdout_header.h"


void ViewHeaderInfo_formatLSB(ELF_HEADER *container){
    /*  
    stdout library for the output of the LSB(Least Significant Byte)
    or the 2's compliment, Little Endian data format.
   */
    printf("\nELF Header: \n");
    printf("Magic: ");
    for(int i = 0; i<EI_NIDENT; i++){
        printf("%02x ", container->elf_ident[i]);
    }
    printf("\n");
    
    for(int i = 0; i<73; i++){
        printf("=");
    }
    printf("\n");

    printf("  [TAGS]\t\t\t");
    printf("[INFO]\n");
    
    for(int i = 0; i<73; i++){
        printf("=");
    }
    printf("\n");

    printf("  Class:\t\t\t");
    switch (container->elf_ident[4]){
        case ELF0:
            printf("%s\n", ARCH_NONE_0);
            break;
        
        case ELF32:
            printf("%s\n", ARCH_x32_1);
            break;
        
        case ELF64:
            printf("%s\n", ARCH_x64_2);
            break;

        default:
            printf("could not identify architecture!\n");
            break;
    }
    
    printf("  Data:\t\t\t\t");
    switch (container->elf_ident[5]){
    case FMT_0:
        printf("%s\n", DATA_FMT_0);
        break;
    
    case FMT_1:
        printf("%s\n", DATA_FMT_1);
        break;
    
    case FMT_2:
        printf("%s\n", DATA_FMT_2);
        break;

    default:
        printf("Could not identify data format\n");
        break;
    }

    printf("  Version:\t\t\t");
    printf("%d (current)\n", container->elf_ident[6]);

    printf("  OS/ABI:\t\t\t");
    switch (container->elf_ident[7]){
    case ABI_0:
        printf("%s\n", ABI_SYSTEMV_0);
        break;
    
    case ABI_1:
        printf("%s\n", ABI_HP_UX_1);
        break;
    
    case ABI_2:
        printf("%s\n", ABI_NETBSD_2);
        break;

    case ABI_3:
        printf("%s\n", ABI_LINUX_3);
        break;
    
    default:
        printf("could not gather ABI details\n");
        break;
    }

    printf("  ABI Version:\t\t\t");
    printf("%d\n", container->elf_ident[8]);

    printf("  Type:\t\t\t\t");
    switch (container->type){
    case ET_0:
        printf("%s\n", ET_NONE_0);
        break;
    
    case ET_1:
        printf("%s\n", ET_REL_1);
        break;

    case ET_2:
        printf("%s\n", ET_EXEC_2);
        break;

    case ET_3:
        printf("%s\n", ET_DYN_3);
        break;
    
    case ET_4:
        printf("%s\n", ET_CORE_4);
        break;
    
    default:
        printf("could not identify file type\n");
        break;
    }

    printf("  Machine:\t\t\t");
    switch (container->machine){
    case M_03:
        printf("%s\n", MACHINE_0x03);
        break;

    case M_08:
        printf("%s\n", MACHINE_0x08);
        break;
    
    case M_28:
        printf("%s\n", MACHINE_0x28);
        break;

    case M_3E:
        printf("%s\n", MACHINE_0x3E);
        break;

    case M_B7:
        printf("%s\n", MACHINE_0xB7);
        break;

    case M_F3:
        printf("%s\n", MACHINE_0xF3);
        break;

    default:
        printf("could not identify the machine used for compiling\n");
        break;
    }

    printf("  Version:\t\t\t");
    printf("%02X\n", container->version);

    printf("  Entry point address:\t\t");
    printf("0x%08X\n", container->EntryPoint);

    printf("  Start of program headers:\t");
    printf("%d byte(s) into the file\n", container->PgmHeader_PTR);

    printf("  Start of section headers:\t");
    printf("%d byte(s) into the file\n", container->SctnHeader_PTR);

    printf("  Flags:\t\t\t");
    printf("0x%04X\n", container->flags);

    printf("  Size of this header:\t\t");
    printf("%d Byte(s)\n", container->HeaderSize);

    printf("  Size of each program headers:\t");
    printf("%d Byte(s)\n", container->PerPgmHeaderSize);

    printf("  Total program headers:\t");
    printf("%d\n", container->PgmHeaderNum);

    printf("  Size of each section headers:\t");
    printf("%d Byte(s)\n", container->PerSctnHeaderSize);

    printf("  Total section headers:\t");
    printf("%d\n", container->SctnHeaderNum);

    printf("  String table index:\t\t");
    printf("0x%04X\n", container->StringTable_PTR);

}
