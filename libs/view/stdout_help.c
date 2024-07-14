#include "stdout_help.h"

void ViewVersionInfo(){
    printf( "   _____     __   .__                   \n");
    printf( "  /  _  \\  _/  |_ |  |  _____     ______\n");
    printf( " /  /_\\  \\ \\   __\\|  |  \\__  \\   /  ___/\n");
    printf( "/    |    \\ |  |  |  |__ / __ \\_ \\___ \\ \n");
    printf( "\\____|__  / |__|  |____/(____  //____  >\n");
    printf( "        \\/                   \\/      \\/ \n");
    printf("\n");
    printf("Atlas (github.com/mintRaven-05) v0.2.3\n");
    printf("Copyright (C) 2024 Debjeet Banerjee\n");
    printf("This program is free software; you may redistribute it\n");
    printf("under the terms of the BSD 3-Clause License\n");
    printf("THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND\n");
}

void ViewHelpScreen(){
    printf("Usage : atlas <option> <elf_file>\n");
    printf("Available flags : \n");
    printf(" --------------------------------------------------------------------------------\n");
    printf("|  -a, --all     |  Prints all information available inside the binary file      |\n");
    printf("|  -h, --header  |  Prints only the header information of the binary file        |\n");
    printf("|  -p, --pgm     |  Prints information related to the program headers section    |\n");
    printf("|  -H, --help    |  Prints the help screen                                       |\n");
    printf("|  -v, --version |  Prints current version information of the tool               |\n");
    printf(" --------------------------------------------------------------------------------\n");
}
