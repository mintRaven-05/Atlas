#ifndef STDOUT_HEADER_H_
#define STDOUT_HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include "../../libs/utils/header/header.h"

void ViewHeaderInfo_formatLSB(ELF_HEADER*);
void ViewHeaderInfo_formatMSB(ELF_HEADER*);

#endif
