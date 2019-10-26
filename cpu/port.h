#ifndef PORT_H
#define PORT_H
#include <stdint.h>
unsigned char port_byte_in  (uint16_t port);
void          port_byte_out (uint16_t port, uint8_t ata);
unsigned char port_word_in  (uint16_t port);
void          port_word_out (uint16_t port, uint16_t ddata);
#endif
