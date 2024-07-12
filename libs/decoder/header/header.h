#ifndef DECODE_HEAD_H_
#define DECODE_HEAD_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils/header/header.h"

typedef unsigned long size_t;

typedef struct {
    unsigned char byte[CHUNK_SIZE];
    size_t dataSize;
} char_byte_stream;

void HeaderProbe_LSB(ELF_HEADER*, char_byte_stream*);
void HeaderProbe_MSB(ELF_HEADER*, char_byte_stream*);

#endif
