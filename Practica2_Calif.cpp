#include <stdio.h>

//Practica2_CALIF.cpp
//Quiros_Vicencio_Diego_Demian_372688
//09/07/2023
/*Convierte una calificacion ingresada en decimal a una calificacion en
caracter utilizando operadores ternarios*/
//Practica2_TiposOperadoresExpresiones_Quiros_Diego.cpp

int main(){

    int calif;

   
    printf("Ingresa una calificacion entre el 1-100: ");scanf("%d",&calif);
     char califletra=
        (calif>=90)? 'A':
        (calif>=80)? 'B':
        (calif>=70)? 'C':
        (calif>=60)? 'D':
        'F'
    ;

    printf("La calificacion en letra del alumno es %c ",califletra);
    printf("\nLa calificacion en numero fue: %d ",calif);

    return 0;
}