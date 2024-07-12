#include <sys/stat.h>
#include "libs/view/stdout_header.h"
#include "libs/view/stdout_pgm.h"
#include "libs/view/stdout_help.h"
#include "libs/decoder/header/decode_head.h"

struct stat stats;
ELF_HEADER header;


int main(int argc, char* argv[]) {
    
    FILE *filePointer;
    stat(argv[2], &stats);
    long MAX_STRUCTS = stats.st_size/2;
    char_byte_stream stream[MAX_STRUCTS];
    size_t chunkCount = 0;
    int pgm_start = header.PgmHeader_PTR / 16;
/*------------------------------------------------------------------------------------------------------------------------------------------*/
    if(argc<2){
        ViewHelpScreen();
    }
/*------------------------------------------------------------------------------------------------------------------------------------------*/
    else if(argc < 3){
            if((strcmp(argv[1], "-H") == 0) || (strcmp(argv[1], "--help") == 0)){
                ViewHelpScreen();
            }
            else if((strcmp(argv[1], "-v") == 0) || (strcmp(argv[1], "--version") == 0)){
                ViewVersionInfo();
            }
            else{
                printf("provide proper data\n");
                ViewHelpScreen();
            }
    }
/*------------------------------------------------------------------------------------------------------------------------------------------*/
    else if(argc == 3){

        filePointer = fopen(argv[2], "rb");
        if (filePointer == NULL) {
            perror("Error opening file");
            ViewHelpScreen();
            return 1;
        }

        while (!feof(filePointer) && chunkCount < MAX_STRUCTS) {
            size_t bytesRead = fread(stream[chunkCount].byte, 1,CHUNK_SIZE, filePointer);
            if (ferror(filePointer)) {
                perror("Error reading file");
                fclose(filePointer);
                return 1;
            }

            stream[chunkCount].dataSize = bytesRead;
            chunkCount++;
        }

        fclose(filePointer);
        memcpy(header.elf_ident, stream[0].byte, 16);
/*------------------------------------------------------------------------------------------------------------------------------------------*/
        if(header.elf_ident[0] == 0x7F && header.elf_ident[1] == 0x45 && header.elf_ident[2] == 0x4C && header.elf_ident[3] == 0x46){
/*------------------------------------------------------------------------------------------------------------------------------------------*/
            if((strcmp(argv[1], "-a")==0) || (strcmp(argv[1], "--all")==0) ){
                switch (header.elf_ident[4]){
                    case ELF0:
                        printf("unsupported architecture detected !\n");
                        break;
            
                    case ELF32:
                        printf("This tool doesn't yet support 32 bit architecture\n");
                        break;
            
                    case ELF64:
                        switch (header.elf_ident[5]){
                            case FMT_0:
                                printf("no file format detected (endian system not found !)\n");
                                break;
                            case FMT_1:
                                HeaderProbe_LSB(&header, stream);
                                ViewHeaderInfo_formatLSB(&header);
                                printf("\n\n");
                                if (header.PerPgmHeaderSize == 0){
                                    printf("No program headers present in the binary\n");
                                    printf("withdrawing ViewProgramHeaderInfo_x64 request\n");
                                }
                                else{
                                    int start_pgm = header.PgmHeader_PTR/16;
                                    PGM_HEADER_x64 *pgm = programHeaderProbe_x64_LSB(stream, start_pgm,(int)header.PgmHeaderNum, (int)header.PerPgmHeaderSize);
                                    ViewProgramHeaderInfo_x64(pgm, (int)header.PgmHeaderNum);
                                    free(pgm);
                                }
                                break;
                            case FMT_2:
                                printf("development for MSB system is still going on !\n");
                                printf("sorry for the inconvenience\n");
                                break;
                            default:
                                printf("error processing the file !\n");
                                break;
                        }
                        break;

                    default:
                        printf("could not detect any architecture format\n");
                        printf("check your file !\n");
                        break;
                }
            }
/*------------------------------------------------------------------------------------------------------------------------------------------*/
            else if((strcmp(argv[1], "-h") == 0) || (strcmp(argv[1], "--header") == 0)){
                switch (header.elf_ident[4]){
                    case ELF0:
                        printf("unsupported architecture detected !\n");
                        break;
            
                    case ELF32:
                        printf("This tool doesn't yet support 32 bit architecture\n");
                        break;
            
                    case ELF64:
                        switch (header.elf_ident[5]){
                            case FMT_0:
                                printf("no file format detected (endian system not found !)\n");
                                break;
                            case FMT_1:
                                HeaderProbe_LSB(&header, stream);
                                ViewHeaderInfo_formatLSB(&header);
                                printf("\n\n");
                                break;
                            case FMT_2:
                                printf("development for MSB system is still going on !\n");
                                printf("sorry for the inconvenience\n");
                                break;
                            default:
                                printf("error processing the file !\n");
                                break;
                        }
                        break;

                    default:
                        printf("could not detect any architecture format\n");
                        printf("check your file !\n");
                        break;
                }                
            }
/*------------------------------------------------------------------------------------------------------------------------------------------*/
            else if((strcmp(argv[1], "-p") == 0) || (strcmp(argv[1], "--pgm") == 0)){
                 switch (header.elf_ident[4]){
                    case ELF0:
                        printf("unsupported architecture detected !\n");
                        break;
            
                    case ELF32:
                        printf("This tool doesn't yet support 32 bit architecture\n");
                        break;
            
                    case ELF64:
                        switch (header.elf_ident[5]){
                            case FMT_0:
                                printf("no file format detected (endian system not found !)\n");
                                break;
                            case FMT_1:
                                HeaderProbe_LSB(&header, stream);
                                if (header.PerPgmHeaderSize == 0){
                                    printf("No program headers present in the binary\n");
                                    printf("withdrawing ViewProgramHeaderInfo_x64 request\n");
                                }
                                else{
                                    int start_pgm = header.PgmHeader_PTR/16;
                                    PGM_HEADER_x64 *pgm = programHeaderProbe_x64_LSB(stream, start_pgm,(int)header.PgmHeaderNum, (int)header.PerPgmHeaderSize);
                                    ViewProgramHeaderInfo_x64(pgm, (int)header.PgmHeaderNum);
                                    free(pgm);
                                }
                                break;
                            case FMT_2:
                                printf("development for MSB system is still going on !\n");
                                printf("sorry for the inconvenience\n");
                                break;
                            default:
                                printf("error processing the file !\n");
                                break;
                        }
                        break;

                    default:
                        printf("could not detect any architecture format\n");
                        printf("check your file !\n");
                        break;
                }                                        
            }
/*------------------------------------------------------------------------------------------------------------------------------------------*/
            else{
                printf("use the right flag !\n");
                ViewHelpScreen();
            }  
        }
        else{
            printf("Provide and ELF binary file !\n");
            printf("The file you provided does not contain ELF footprints\n");
        }
    }
    else{
        ViewHelpScreen();
    }
    return 0;
}