#ifndef DECODE_PGM_X64_H_
#define DECODE_PGM_X64_H_

#include "../../utils/program/PGM_x64.h"
#include "../header/decode_head.h"

PGM_HEADER_x64 *programHeaderProbe_x64_LSB(char_byte_stream*, int, int, int);
PGM_HEADER_x64 *programHeaderProbe_x64_MSB(char_byte_stream*, int, int, int);

#endif
