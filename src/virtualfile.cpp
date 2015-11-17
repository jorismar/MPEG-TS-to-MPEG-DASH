/*
#include "virtualfile.h"

VirtualFile(std::string filename) {
    this->name = filename;
    this->bin = NULL;
    this->length = 0;
}

VirtualFile(std::string filename, t_size size) {
    this->name = filename;
    this->bin = new DataPacket(size);
    this->length = size;
}

VirtualFile(std::string filename, DataPacket * packet) {
    this->name = filename;
    this->bin = packet;
    this->length = packet->size();
}

VirtualFile(std::string filename, t_byte* bin, t_size size) {
    this->name = filename;
    this->bin = new DataPacket(size);
    this->length = size;
    
    this->bin->set(bin);
}

virtual ~VirtualFile() {
    // VAZIO
}

void setFilename(std::string filename) {
    this->name = filename;
}

void setSize(t_size size) {
    this->length = size;
}

void setBinary(t_byte * bin) {
    this->bin->set(bin);
}

void setBinPacket(DataPacket * packet) {
    this->bin = packet;
}

std::string getFilename() {
    return this->name;
}

t_size getSize() {
    return this->length;
}

t_byte * getBinary() {
    return this->bin->get();
}

DataPacket * getBinPacket() {
    return this->bin;
}

/*
void copyBinary(t_byte * bin, t_size size) {
    if(this->length == 0) {
        this->length = size;
        this->bin = (t_byte*) malloc(sizeof(t_byte) * size);
    }
    
    EXIT_IF(this->length != size, "[VirtualFile] ERROR: Incompatible sizes");
    
    t_byte byte;
    
    do {
        byte = *bin++;
        *this->bin++ = byte;
    } while(byte != EOF);
}

/*
void copyBinary(t_byte * bin, t_size size) {
    if(this->length == 0) {
        this->length = size;
        this->bin = (t_byte*) malloc(sizeof(t_byte) * size);
    }
    
    EXIT_IF(this->length != size, "[VirtualFile] ERROR: Incompatible sizes");
    
    for(int i = 0; i < this->length; i++)
        this->bin[i] = bin[i];
}
*/
