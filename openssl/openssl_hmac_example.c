//Para compilar este programa, se puede utilizar el siguiente comando
// gcc -std=c99 openssl_hmac_example.c -o openssl_hmac_example -lcrypto


// NOTA:
// Se utilizo gcc ver 10.2.0. 

#include <openssl/hmac.h>


int main(void)
{
    printf("Hola Talentos, esto es un ejemplo para HMAC - SHA256 \n");

    HMAC_CTX *l_ctx_ptr_t = HMAC_CTX_new();

    int l_hmac_resultado_ini;
    int l_longitud_resultado;

    uint8_t l_llave_au8[16] = {0};
    uint8_t l_msjCAN_au8[8] = {0};
    uint8_t l_hash_resultante_au8[32] = {0};

    l_hmac_resultado_ini =  HMAC_Init_ex(l_ctx_ptr_t,   //HMAC context
                                        l_llave_au8,    //Reference to the key
                                        16,             //Size in bytes
                                        EVP_sha256(),   //Type of hash
                                        NULL);          //Engine. In this case NULL
    HMAC_Update(l_ctx_ptr_t, l_msjCAN_au8, 8);
    HMAC_Final(l_ctx_ptr_t, l_hash_resultante_au8, &l_longitud_resultado);
    HMAC_CTX_free(l_ctx_ptr_t);

    printf("La longitud del hash fue: %d \n", l_longitud_resultado);
    printf("Estos son los bytes: \n");
    for(uint8_t i = 0; i < 32; i++)
    {
        printf("0x%02x ", l_hash_resultante_au8[i]);
    }

    return 0;
}
