#include <stdio.h>
#include <stdlib.h>

#define CAPACIDAD_MAX 100

//Practica2_INVENTARIO.cpp
//Quiros_Vicencio_Diego_Demian_372688
//09/08/2023
//Inventario donde se puedan ingresar, retirar e ispeccionar elementos
//Practica2_TiposOperadoresExpresiones_Quiros_Diego.cpp


int msges(void);
void menu(void);
int agregar_elementos(int inventario);
int retirar_elementos(int inventario);
void inspeccionar_elementos(int inventario);

int main()
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
    printf("\nElementos en el inventario: %d\n",CAPACIDAD_MAX);
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