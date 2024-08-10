#include "stdout_help.h"

void ViewVersionInfo(){
    printf("%s by %s v%s\n", _TOOL_, _AUTHOR_, _VERSION_);
    printf("%s\n", _COPYRIGHT_);
    printf("This program is free software; you may redistribute it under the terms\n");
    printf("and condition of the %s License\n", _LICENSE_);
    printf("Written by %s, dated: %s\n", _AUTHOR_, _DATE_);
    printf("Visit %s for more projects\n", _WEBSITE_);
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
    printf("|  -u, --update  |  performs an update for the tool                              |\n");
    printf(" --------------------------------------------------------------------------------\n");
}
