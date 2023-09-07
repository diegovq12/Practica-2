#include <stdio.h>
#include <limits.h>

//Practica2_BINARIO.cpp
//Quiros_Vicencio_Diego_Demian_372688
//09/07/2023
//Convierte numeros decimales a numeros binarios
//Practica2_TiposOperadoresExpresiones_Quiros_Diego.cpp

int main(){

    int numero_decimal;
    printf("Ingresa un numero decimal: ");scanf("%d",&numero_decimal);

    //validar que el numero sea positivo

    if (numero_decimal<0)
    {
        return 1;
    }

    //calcular los bits necesarios

    int num_bits=0;
    int temp=numero_decimal;

    while (temp>0)
    {
        temp/=2;
        num_bits++;
    }
    
    //Creamos el arreglo

    int bits[num_bits];
    int indice;

    while (numero_decimal>0)
    {
        bits[indice] = numero_decimal%2;
        numero_decimal/=2;
        indice++;
    }

    //imprimir la cadena de bits

    printf("Numero en bits ");

    for (int i = indice-1 ; i >=0 ; i--)
    {
        printf("%d",bits[i]);
    }
    printf("\n");

    //buscar la cantidad de bits encendidos

    int bit_encendido = -1;

    printf("Los bits encendidos estan en la posicion: \n");

    for (int i = 0; i < indice; i++)
    {
        if (bits[i]==1)
        {
            bit_encendido=i;
            printf(" %d",bit_encendido+1);
        }
    }

    if (bit_encendido == -1)
    {
        printf("No se encontro ningun bit encendido");
    }
    
    
    return 0;
}