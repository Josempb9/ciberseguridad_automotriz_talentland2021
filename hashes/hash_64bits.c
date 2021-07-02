//Para compilar este programa, se puede utilizar el siguiente comando
//  gcc hash_64bits.c -std=c99 -o hash_64bits


// NOTA:
// Se utilizo gcc ver 10.2.0. 

#include <stdio.h>
#include <stdint.h>

#define LONGITUD_BUFFER  (8U)

uint64_t splitmix64(uint64_t x) {
    x = (x ^ (x >> 30)) * UINT64_C(0xbf58476d1ce4e5b9);
    x = (x ^ (x >> 27)) * UINT64_C(0x94d049bb133111eb);
    x = x ^ (x >> 31);
    return x;
}

uint64_t hash(const uint8_t * l_datos_au8, uint8_t l_longitud_datos_u8)
{
    uint64_t l_llave_u64 = 0;
    for(uint8_t i = 0; i < l_longitud_datos_u8; i++)
    {
        l_llave_u64 |= l_datos_au8[i];
        if(i != (l_longitud_datos_u8 - 1))
        {
            l_llave_u64 <<= 8;
        }
    }
    printf("La llave es: 0x%016llx \n", l_llave_u64);

    return splitmix64(l_llave_u64);
}



int main(void)
{
    uint64_t hash_de_datos = 0;
    uint8_t datos[LONGITUD_BUFFER] = {  0x00, 0x01, 0x02, 0x03, 
                                        0x04, 0x05, 0x06, 0x07 };

    hash_de_datos = hash(datos, LONGITUD_BUFFER);
    printf("El hash es: 0x%016llx \n", hash_de_datos);

    printf("--------------------------------------------------\n");

    printf("Modificando un solo elemento del arreglo en 1\n");
    datos[7] = 0x08;
    hash_de_datos = hash(datos, LONGITUD_BUFFER);
    printf("El hash es: 0x%016llx \n", hash_de_datos);


    return 0;
}