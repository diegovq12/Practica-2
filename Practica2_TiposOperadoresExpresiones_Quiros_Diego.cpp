#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

#define CAPACIDAD_MAX 20

//Practica2_BINARIO.cpp
//Quiros_Vicencio_Diego_Demian_372688
//09/07/2023
//Practica2_TiposOperadoresExpresiones_Quiros_Diego.cpp


//prototipos para funcion de inventario
int msges(void);
void menu(void);
int agregar_elementos(int inventario);
int retirar_elementos(int inventario);
void inspeccionar_elementos(int inventario);
//******************************************
//prototipos para ejercicio1 ,2,3

int decimal_a_binario(void);
void calif_a_letra(void);
int inventario(void);
void mainmenu(void);
//******************************
int mainmsges(void);

int main()
{
    mainmenu();

    return 0;   
}

void mainmenu()
{
    int op;

    do
    {
        op=mainmsges();

        switch (op)
        {
        case 1:
                decimal_a_binario();
            break;
        case 2:
                calif_a_letra();
            break;
        case 3:
                inventario();
            break;
        case 0:
                printf("Gracias por usar!");
            break;
        default:
                printf("Opcion invalida, porfavor escoja otra\n");
            break;
        }
    } while (op!=0);
}

int mainmsges()
{
    int op;
    printf("\nPractica 2: Tipos, Operadores y Expresiones\n");
    printf("1. Convertir Decimal a Binario\n");
    printf("2. Calificaciones Decimales a Caracteres\n");
    printf("3. Inventario\n");
    printf("0. Salir\n");
    scanf("%d",&op);
    return op;
}


//Funcion para resolver el ejercicio 1
int decimal_a_binario(void)
{
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
//funcion para resolver ejercicio 2
void calif_a_letra(void)
{
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

}

int inventario()
{
    menu();

    return 0;
}

int msges()
{
    int op;
    printf("\n\tMENU INVENTARIO\n");
    printf("1. Agregar Elementos\n");
    printf("2. Retirar Elementos\n");
    printf("3. Inspeccionar Elementos\n");
    printf("0. Salir\n");
    scanf("%d",&op);
    return op;
}


void menu()
{
    int op,inventario=0, cantidad;

    do
    {
        op=msges();

        switch (op)
        {
        case 1:
                inventario=agregar_elementos(inventario);
            break;
        case 2:
                inventario=retirar_elementos(inventario);
            break;
        case 3:
                inspeccionar_elementos(inventario);
            break;
        case 0:
                printf("Gracias por usar!");
            break;
        default:
                printf("Opcion invalida, porfavor escoja otra\n");
            break;
        }
    } while (op!=0);
}

int agregar_elementos(int inventario)
{
    int cantidad;
    printf("\nCapacidad del inventario: %d\n",CAPACIDAD_MAX);
    if (inventario<CAPACIDAD_MAX)
    {
        printf("Ingrese la cantidad de elementos a agregar: ");scanf("%d",&cantidad);
        if (inventario + cantidad <= CAPACIDAD_MAX)
        {
            inventario+=cantidad;
            printf("%02d elementos han sido agregados al inventario\n",cantidad);
            printf("Elementos en inventario: %d\n",inventario);
        }
        else
        {
            printf("No es posible agregar tantos elementos, Excede la capacidad del inventario\n");
            printf("Elementos en inventario: %d\n",inventario);

        }
    }
    return inventario;
}

int retirar_elementos(int inventario)
{
    int cantidad;
    printf("\nElementos en el inventario: %d\n",inventario);
    if (inventario>0)
    {
        printf("Ingrese la cantidad de elementos a retirar: ");scanf("%d",&cantidad);
        if (cantidad <= inventario)
        {
            inventario-=cantidad;
            printf("%d elementos han sido eliminados del inventario\n",cantidad);
            printf("Elementos en inventario: %d\n",inventario);
        }
        else
        {
            printf("No es posible retirar tantos elementos, no hay suficientes en el inventario\n");
            printf("Elementos en inventario: %d\n",inventario);
        }
    }
    else
    {
        printf("No se pueden retirar elementos, el inventario esta vacio");
    }
    return inventario;
}

void inspeccionar_elementos(int inventario)
{
    printf("Elementos en el inventario: %d\n",inventario);
    printf("Capacidad maxima: %d",CAPACIDAD_MAX);
}