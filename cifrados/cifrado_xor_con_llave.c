//Para compilar este programa, se puede utilizar el siguiente comando
//  gcc cifrado_xor_con_llave.c -std=c99 -o cifrado_xor_con_llave


// NOTA:
// Se utilizo gcc ver 10.2.0. 

#include <stdio.h>
#include <stdint.h>

#define LONGITUD_BUFFER  (7U)
#define LONGITUD_LLAVE   (5U)

int main(void)
{
    uint8_t l_buffer_datos_au8[LONGITUD_BUFFER]         = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x99};
    uint8_t l_llave_encriptacion_au8[LONGITUD_LLAVE]    = {0x12, 0x34, 0x56, 0x78};
    uint8_t l_buffer_encriptado_au8[LONGITUD_BUFFER]    = {0};

    for(uint8_t i = 0; i < LONGITUD_BUFFER; i++)
    {
        l_buffer_encriptado_au8[i] = l_buffer_datos_au8[i] ^ l_llave_encriptacion_au8[ i % LONGITUD_LLAVE ];
    }

    printf("\nBuffer de datos:\n");
    for(uint8_t i = 0; i < LONGITUD_BUFFER; i++)
    {
        printf("0x%02x ", l_buffer_datos_au8[i]);
    }

    printf("\nBuffer de datos encriptado:\n");
    for(uint8_t i = 0; i < LONGITUD_BUFFER; i++)
    {
        printf("0x%02x ", l_buffer_encriptado_au8[i]);
    }

    return 0;
}