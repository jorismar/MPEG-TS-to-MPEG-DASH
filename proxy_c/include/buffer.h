#ifndef BUFFER_H
#define BUFFER_H

#include "datapacket.h"

typedef struct {
    unsigned int r_pos;          // Posi��o de Leitura para next();
    unsigned int w_pos;          // Posi��o de Escrita para add();
    unsigned int buff_size;      // Tamanho do Buffer
    unsigned int data_size;      // Tamanho do elemento
    tDataPacket **buffer;        // Buffer    
} tBuffer;

#endif