//Para compilar este programa, se puede utilizar el siguiente comando
//  gcc hash_32bits.c -std=c99 -o hash_32bits


// NOTA:
// Se utilizo gcc ver 10.2.0. 

#include <stdio.h>
#include <stdint.h>

#define LONGITUD_BUFFER  (8U)

uint32_t jenkins_one_at_a_time_hash(const uint8_t* l_datos_au8, uint8_t l_length_u8) 
{
    uint32_t hash = 0;
    for(uint8_t i = 0; i < l_length_u8; i++)
    {
        hash += l_datos_au8[i];
        hash += hash << 10;
        hash ^= hash >> 6;
    }
    hash += hash << 3;
    hash ^= hash >> 11;
    hash += hash << 15;

    return hash;
}

uint32_t print_arreglo(const uint8_t* l_datos_au8, uint8_t l_length_u8) 
{
    printf("La llave es: 0x");
    for(uint8_t i = 0; i < l_length_u8; i++)
    {
        printf("%02x", l_datos_au8[i]);
    }
    printf("\n");
}

int main(void)
{
    uint32_t hash_de_datos = 0;
    uint8_t datos[LONGITUD_BUFFER] = {  0x00, 0x01, 0x02, 0x03, 
                                        0x04, 0x05, 0x06, 0x07 };
    print_arreglo(datos, LONGITUD_BUFFER);
    hash_de_datos = jenkins_one_at_a_time_hash(datos, LONGITUD_BUFFER);
    printf("El hash es: 0x%08llx \n", hash_de_datos);

    printf("--------------------------------------------------\n");

    printf("Modificando un solo elemento del arreglo en 1\n");
    datos[7] = 0x08;
    print_arreglo(datos, LONGITUD_BUFFER);
    hash_de_datos = jenkins_one_at_a_time_hash(datos, LONGITUD_BUFFER);
    printf("El hash es: 0x%08llx \n", hash_de_datos);

    return 0;
}