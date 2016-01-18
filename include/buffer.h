#ifndef BUFFER_H
#define BUFFER_H

#include <cstdio>
#include <cstdlib>
#include "virtualfile.h"

class Buffer {
    private:
        t_pos r_pos;          // Posi��o de Leitura para next();
        t_pos w_pos;          // Posi��o de Escrita para add();
        t_pos buff_size;      // Tamanho do Buffer
        VirtualFile **buffer; // Buffer
        
    public:
        Buffer(t_size);
        virtual ~Buffer();
        
        int set(t_pos, VirtualFile*);
        VirtualFile* get(t_pos);

        VirtualFile* next();
        
        int add(VirtualFile*);      
        void remove(t_pos);
        
        int size();
};

#endif
