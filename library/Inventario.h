#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include "string.h"

//Model of products
#include "../models/Producto.h"

#define SEGUNDOS 5000

void Delay(int second);
void MenuInventario();
void AgregarInentario();
void EditarInventario(struct Producto *productos);
void Roles_menu();
void EliminarInventario(struct Producto *productos);
void ReporteInventario(struct Producto *productos, int number);

int num = 0;

void MenuInventario(struct Producto *productos)
{
    system("cls");
    int option = 0;
    printf("    |      [1]  Agregar Producto           |\n");
    printf("    |      [2]  Modificar Producto         |\n");
    printf("    |      [3]  Eliminar Producto          |\n");
    printf("    |      [4]  Ver Reporte                |\n");
    printf(" \n          Diguite su opcion: ");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            AgregarInentario();
        break;
        case 2:
            EditarInventario(productos);
        break;
        case 3:
            EliminarInventario(productos);
        break;
        case 4:
            ReporteInventario(productos,num);
        break;
        default:
            Roles_menu();
        break;
    }
}

void AgregarInentario()
{
    struct Producto *productos;
    int cantidad = 0;
    system("cls");
    printf("\n\nAgregar producto al inventario\n\n");
    printf("Cantidad de producto que deseas agregar%c: \t", 63); scanf("%d", &cantidad);

    num = cantidad;

    productos = (struct Producto *)malloc(cantidad * sizeof(struct Producto *));

    fflush(stdin);

    for(int i = 0; i < cantidad; i++)
    {
        //system("cls");%[^\n]

        (productos+i)->id = i;

        printf("Agregar el nombre del producto: \t");
        getchar();
        scanf("%[^\n]", (productos+i)->nombre_producto);

        printf("Agregar la cantidad de productos que 'habr%c' disponibles: \t", 160);
        scanf("%d", &(productos+i)->cantidad_items);

        printf("Agregar el precio del producto: \t");
        scanf("%d", &(productos + i)->price);

        fflush(stdin);
    }
    fflush(stdin);
    system("cls");
    printf("Saliendo...\n\n");
    Delay(SEGUNDOS);
    ReporteInventario(productos, num);
    Roles_menu(productos);
}

void EditarInventario(struct Producto *productos)
{
    system("cls");

    int id = 0;
    char respuesta;
    ReporteInventario(productos, num);
    printf("\n\nQue producto deseas editar (seleccionar por el ID):\t"); scanf("%d", &id);

    for(int i = 0; i < num; i++)
    {
        if(id == ((productos + i)->id + 1))
        {
            printf("\n\nUsted ha seleccionado '%s' \n\n", (productos + i)->nombre_producto);

            printf("%cDeseas editar el '%s' de su inventario%c (escribir 'Y' para un si o 'N' para un no):",168, (productos + i)->nombre_producto, 63); scanf("%s", &respuesta);

            if(respuesta == 'y')
            {
                printf("Nuevi nombre del producto: \t");
                getchar();
                scanf("%[^\n]", (productos + i)->nombre_producto);

                printf("Agregar nueva cantidad de productos que 'habr%c' disponibles: \t", 160);
                scanf("%d", &(productos + i)->cantidad_items);

                printf("Agregar el nuevo precio del producto: \t");
                scanf("%d", &(productos + i)->price);

                printf("\n\nEl '%s' a sido editado del inventario, pase un buen d%ca", (productos + i)->nombre_producto, 161);
                ReporteInventario(productos, num);

                printf("\n\n%cDeseas salir%c (escribir 'Y' para un si o 'N' para un no):\t",168 ,63); scanf("%s", &respuesta);

                if(respuesta == 'y')
                    ReporteInventario(productos,num);
                else if(respuesta == 'n')
                    ReporteInventario(productos, num);
            }
        }
        else if(id > (productos->id + 1))
        {
            printf("\n\nEl libro aun no se ha agregado :(\n\n");
            system("cls");
        }
        else if(id < (productos->id + 1))
        {
            printf("\n\nEl libro no existe :()\n\n");
            system("cls");
        }
    }

    MenuInventario(productos);
}

void ReporteInventario(struct Producto *productos, int number)
{
    system("cls");
    if (number == 0)
        printf("Usted no tiene ning%cn producto de inventario guardado en nuestras bases de datos",163);

    printf("\n\nLista de los Productos");
    printf("\n\nID || Nombre || Disponibilidad || Precio\n");

    for(int i = 0; i < number; i++)
    {
        printf("\n\n%d || %s || %d || %d \n", ((productos + i)->id + 1), (productos + i)->nombre_producto, (productos + i)->cantidad_items, (productos + i)->price);
    }
}

void EliminarInventario(struct Producto *productos)
{
    int id = 0;
    char respuesta;
    printf("\n\nQue producto deseas eliminar (seleccionar por el ID):\t"); scanf("%d", &id);

    for(int i = 0; i < num; i++)
    {
        if(id == ((productos + i)->id + 1))
        {
            printf("\n\nUsted ha seleccionado '%s' \n\n", (productos + i)->nombre_producto);

            printf("%cDeseas eliminar el '%s' de su inventario%c (escribir 'Y' para un si o 'N' para un no):",168, (productos + i)->nombre_producto, 63); scanf("%s", &respuesta);

            if(respuesta == 'y')
            {
                (productos + i)->id = 0;
                strcpy((productos + i)->nombre_producto, "");
                (productos + i)->cantidad_items = 0;
                (productos + i)->price = 0;

                printf("\n\nEl '%s' a sido retirado del inventario, pase un buen d%ca", (productos + i)->nombre_producto, 161);
                ReporteInventario(productos, num);

                printf("\n\n%cDeseas salir%c (escribir 'Y' para un si o 'N' para un no):\t",168 ,63); scanf("%s", &respuesta);

                if(respuesta == 'y')
                    ReporteInventario(productos,num);
                else if(respuesta == 'n')
                    ReporteInventario(productos, num);
            }
        }
        else if(id > (productos->id + 1))
        {
            printf("\n\nEl libro aun no se ha agregado :(\n\n");
            system("cls");
        }
        else if(id < (productos->id + 1))
        {
            printf("\n\nEl libro no existe :()\n\n");
            system("cls");
        }
    }
}