//Para compilar este programa, se puede utilizar el siguiente comando
//  gcc xor_con_un_solo_dato.c -std=c99 -o xor_con_un_solo_dato


// NOTA:
// Se utilizo gcc ver 10.2.0. 

#include <stdio.h>
#include <stdint.h>

int main(void)
{
    printf(">> Este programa ilustra el uso de XOR con un solo dato <<");
    printf("\n\n");

    char l_caracter     = 'A';
    char l_caracter_xor = 'm';
    char l_caracter_cifrado;

    printf("El caracter por cifrar es:%c \n", l_caracter);
    printf("El caracter con el que se hara XOR es: %c \n", l_caracter_xor);

    //El operador ^ simboliza la operación XOR en languajes de programación
    //En texto educativos o en diagramas también se puede en el simbolo ⊕.
    l_caracter_cifrado = l_caracter ^ l_caracter_xor;
    printf("%c ^ %c = %c \n", l_caracter, l_caracter_xor, l_caracter_cifrado);
    printf("El caracter cifrado es: %c\n", l_caracter_cifrado);

    printf("\n");

    //Suponiendo que la contraparte sabe cual fue el caracter con el que se 
    //hizo xor, puede obtener el resultado original. La operación es la misma. 
    printf("Haciendo el proceso inverso... \n");
    char l_caracter_original;
    l_caracter_original = l_caracter_cifrado ^ l_caracter_xor;
    printf("%c ^ %c = %c \n", l_caracter_cifrado, l_caracter_xor, l_caracter_original);
    printf("El caracter original es: %c\n", l_caracter_original);


    printf("-----------------------------------------------------\n");
    printf("El proceso del XOR se puede generalizar a un byte \n");

    uint8_t l_dato_u8 = 0x11;
    uint8_t l_valor_de_xor_u8 = 0x55;
    uint8_t l_dato_cifrado_u8 = l_dato_u8 ^ l_valor_de_xor_u8;

    printf("El dato es: 0x%02x\n", l_dato_u8);
    printf("El valor con el que se hara XOR es: 0x%02x\n", l_valor_de_xor_u8);
    printf("0x%02x ^ 0x%02x = 0x%02x \n", l_dato_u8, l_valor_de_xor_u8, l_dato_cifrado_u8);
    printf("El dato cifrado es: 0x%02x\n", l_dato_cifrado_u8);

    printf("\n");

    printf("Haciendo el proceso inverso... \n");
    uint8_t l_dato_original_u8;
    l_dato_original_u8 = l_dato_cifrado_u8 ^ l_valor_de_xor_u8;
    printf("0x%02x ^ 0x%02x = 0x%02x \n", l_dato_cifrado_u8, l_valor_de_xor_u8, l_dato_original_u8);
    printf("El dato original es: 0x%02x\n", l_dato_original_u8);

}