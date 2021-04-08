#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include "string.h"

//Model of products
#include "../models/Producto.h"


#define SEGUNDOS 5000

void Roles_menu();
void AgregarCompras();
void Delay(int second);
void ModificarCompras(struct Producto *producto);
void MenuCompras(struct Producto *producto);
void LitaCompras(struct Producto *producto, int number);

//Global Variable
int cantidadCompras = 0;

void MenuCompras(struct Producto *producto)
{
    int option = 0;
    system("cls");
    printf("    |      [1]  Comprar y Crear Compras      |\n");
    printf("    |      [2]  Modificar Compras            |\n");
    printf("    |      [3]  Eliminar Compras             |\n");
    printf("    |      [4]  Ver Compras hechas           |\n");
    printf(" \n          Diguite su opcion: ");
    scanf("%d", &option);

    switch (option)
    {
        case 1:
            AgregarCompras();
        break;
        case 2:
            ModificarCompras(producto);
        break;
        case 3:
            AgregarCompras();
        break;
        case 4:
            LitaCompras(producto, cantidadCompras);
        break;
        default:
            Roles_menu();
        break;
    }
}

void AgregarCompras()
{
    int id = 0;

    int cantidad = 0;
    int cantidadComprada = 0;

    struct Producto *producto;
    system("cls");
    printf("\n\nAgregar compras al carrito\n\n");
    printf("%cCantidad de compras que deseas agregar%c: \t", 168, 63); scanf("%d", &cantidad);

    cantidadCompras = cantidad;
    producto = (struct Producto *)malloc(cantidad * sizeof(struct Producto *));

    printf("\n\nQue producto deseas editar (seleccionar por el ID):\t"); scanf("%d", &id);

    fflush(stdin);
    for(int i = 0; i < cantidad; i++)
    {
        if(id == (producto + i)->id + 1)
        {
            printf("\n\nUsted ha seleccionado '%s' \n\n", (producto + i)->nombre_producto);
            printf("Cuantos deseas comprar%c\n", 63);
            getchar();
            scanf("%d", &cantidadComprada);

            (producto + i)->cantidad_compras = (producto + i)->price * cantidadComprada;
        }
        if(id != (producto + i)->id)
        {
            printf("Producto no existente\n\nVolviendo a cargar el carrito de compras");
            AgregarCompras();
        }
        fflush(stdin);
    }
    fflush(stdin);
    system("cls");
    printf("Saliendo...\n\n");
    Delay(SEGUNDOS);
    LitaCompras(producto,cantidadCompras);
}

void ModificarCompras(struct Producto *producto)
{
    int id = 0;

    int cantidad = 0;
    int cantidadComprada = 0;

    system("cls");
    printf("\n\nModificar compras al carrito\n\n");
    printf("%cCantidad de compras que deseas agregar%c: \t", 168, 63); scanf("%d", &cantidad);

    cantidadCompras = cantidad;
    producto = (struct Producto *)malloc(cantidad * sizeof(struct Producto *));

    printf("\n\nQue producto deseas editar (seleccionar por el ID):\t"); scanf("%d", &id);

    fflush(stdin);
    for(int i = 0; i < cantidad; i++)
    {
        if(id == (producto + i)->id + 1)
        {
            printf("\n\nUsted ha seleccionado '%s' \n\n", (producto + i)->nombre_producto);
            printf("Cuantos deseas comprar%c\n", 63);
            getchar();
            scanf("%d", &cantidadComprada);

            (producto + i)->cantidad_compras = (producto + i)->price * cantidadComprada;
        }
        if(id != (producto + i)->id)
        {
            printf("Producto no existente\n\nVolviendo a cargar el carrito de compras");
            AgregarCompras();
        }
        fflush(stdin);
    }
    fflush(stdin);
    system("cls");
    printf("Saliendo...\n\n");
    Delay(SEGUNDOS);
    LitaCompras(producto,cantidadCompras);
}

void LitaCompras(struct Producto *producto, int number)
{
    system("cls");

    char respuesta;

    if (number == 0)
        printf("Usted no tiene ninguna compra en el carrito",163);

    printf("\n\nLista de los Productos");
    printf("\n\nID || Nombre || Cantidad || Precio || Contabilidad\n");

    for (int i = 0; i < number; ++i)
    {
        printf("\n\nID || Nombre || Cantidad || Precio || Contabilidad\n");
        printf("\n%d || %s || %d || %d || %d",(producto + i)->id,(producto + i)->nombre_producto, (producto + i)->cantidad_items, (producto + i)->price, (producto + i)->cantidad_compras);
    }

    printf("\n\nDeseas modificar algo de su compra%c (escribir 'Y' para un si o 'N' para un no):",63);
    scanf("%s", &respuesta);

    if(respuesta == 'y' || respuesta == 'Y')
        ModificarCompras(producto);
}