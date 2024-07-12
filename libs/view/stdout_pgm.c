#include "stdout_pgm.h"

extern unsigned char INTERP_PGM[30];

void ViewProgramHeaderInfo_x64(PGM_HEADER_x64 *container, int container_count){
   for(int i = 0; i<160; i++){
      printf("=");
   }
   printf("\n");
   printf("[TYPE]            ");printf("[OFFSET]            "); printf("[VIRT_ADDR]            ");printf("[PHY_ADDR]            ");
   printf("[FILE_SIZE]            ");printf("[MEM_SIZE]            ");printf("[FLAGS]            ");printf("[ALIGN]\n");

    for(int i = 0; i<160; i++){
      printf("=");
   }
   printf("\n");
   if(container_count>=2){
      for(int i = 0; i<2; i++){
         switch (container[i].type){
            case x64_PT_0:
               printf("%s            ", x64_PT_NULL_0);
               break;
            case x64_PT_1:
               printf("%s            ", x64_PT_LOAD_1);
               break;
            case x64_PT_2:
               printf("%s             ",x64_PT_DYN_2 );
               break;
            case x64_PT_3:
               printf("%s          ", x64_PT_INTERP_3);
               break;
            case x64_PT_4:
               printf("%s            ", x64_PT_NOTE_4);
               break;
            case x64_PT_5:
               printf("%s            ", x64_PT_SHLIB_5);
               break;
            case x64_PT_6:
               printf("%s         ", x64_PT_PHDR_6);
               break;
            case x64_PT_7:
               printf("%s            ", x64_PT_TLS_7);
               break;
            case x64_PT_8:
               printf("%s    ", x64_PT_GNU_PROPERTY_8);
               break;
            case x64_PT_9:
               printf("%s    ", x64_PT_GNU_EH_FRAME_9);
               break;
            case x64_PT_10:
               printf("%s       ", x64_PT_GNU_STACK_10);
               break;
            case x64_PT_11:
               printf("%s       ", x64_PT_GNU_RELRO);
               break;
            default:
               printf("[UN_IDTY]           ");
               break;
         }

         printf("0x%08X          ", container[i].offset);
         printf("0x%08X             ", container[i].vaddr);
         printf("0x%08X             ", container[i].paddr);
         printf("0x%08X            ", container[i].file_size);
         printf("0x%08X            ", container[i].mem_size);
         switch (container[i].flags){
         case R:
            printf("   %s              ", PF_R);
            break;
         case RX:
            printf("   %s             ", PF_RX);
            break;
         case RW:
            printf("   %s             ", PF_RW);
            break;
         default:
            printf("   U              ");
            break;
      }
      printf("0x%08X            ", container[i].align);
      printf("\n");
    }

   printf("\n\n");
   printf("\t\t\t\t\t\t\t     [Found interpreter shared object]\n");
   printf("\t\t\t\t\t\t  [Requesting interpreter : %s]\n", INTERP_PGM);
   printf("\n\n");


   for(int i = 0; i<160; i++){
      printf("=");
   }
   printf("\n");
   printf("[TYPE]            ");printf("[OFFSET]            "); printf("[VIRT_ADDR]            ");printf("[PHY_ADDR]            ");
   printf("[FILE_SIZE]            ");printf("[MEM_SIZE]            ");printf("[FLAGS]            ");printf("[ALIGN]\n");

    for(int i = 0; i<160; i++){
      printf("=");
   }
   printf("\n");

     for(int i = 2; i<container_count; i++){
      switch (container[i].type){
         case x64_PT_0:
            printf("%s            ", x64_PT_NULL_0);
            break;
         case x64_PT_1:
            printf("%s            ", x64_PT_LOAD_1);
            break;
         case x64_PT_2:
            printf("%s             ",x64_PT_DYN_2 );
            break;
         case x64_PT_3:
            printf("%s          ", x64_PT_INTERP_3);
            break;
         case x64_PT_4:
            printf("%s            ", x64_PT_NOTE_4);
            break;
         case x64_PT_5:
            printf("%s            ", x64_PT_SHLIB_5);
            break;
         case x64_PT_6:
            printf("%s         ", x64_PT_PHDR_6);
            break;
         case x64_PT_7:
            printf("%s            ", x64_PT_TLS_7);
            break;
         case x64_PT_8:
            printf("%s    ", x64_PT_GNU_PROPERTY_8);
            break;
         case x64_PT_9:
            printf("%s    ", x64_PT_GNU_EH_FRAME_9);
            break;
         case x64_PT_10:
            printf("%s       ", x64_PT_GNU_STACK_10);
            break;
         case x64_PT_11:
            printf("%s       ", x64_PT_GNU_RELRO);
            break;
         default:
            printf("[UN_IDTY]           ");
            break;
      }

      printf("0x%08X          ", container[i].offset);
      printf("0x%08X             ", container[i].vaddr);
      printf("0x%08X             ", container[i].paddr);
      printf("0x%08X            ", container[i].file_size);
      printf("0x%08X            ", container[i].mem_size);
            switch (container[i].flags){
      case R:
         printf("   %s              ", PF_R);
         break;
      case RX:
         printf("   %s             ", PF_RX);
         break;
      case RW:
         printf("   %s             ", PF_RW);
         break;
      default:
         printf("   U              ");
         break;
      }
      printf("0x%08X            ", container[i].align);
      printf("\n");
    }

   }

}