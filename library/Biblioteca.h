//
// Created by
//
#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

//Model of products
#include "../models/Producto.h"

void AgregarProducto();
char AreYouAdmin();
void Usuario(struct Producto *productos);
void Pedidos(struct Producto *productos);
void List_Products(struct Producto *productos, int n);
void Roles_menu(struct Producto *productos);

int num = 0;

void Usuario(struct Producto *productos)
{
    char name;
    char respuesta;

    system("cls");
    printf("Escribir su Nombre: \t"); scanf("%s", &name);
    if(name == 0)
        Usuario(productos);
    if(name != 0)
    {
        printf("\n\n%cDeseas ver la lista de los productos disponibles%c, (escribir 'Y' para un si o 'N' para un no): \t", 168,63); scanf("%s", &respuesta);
        if(respuesta == 'y')
        {
            List_Products(productos,num);
            Pedidos(productos);
        }
    }
}

char AreYouAdmin()
{
    system("cls");
    char option;
    fflush(stdin);
    printf("Usted es bibliotecario (escribir Y si es verdadero o N si es falso):\t"); scanf("%s", &option);

    if(option == 'y')
        return option;
    else if(option == 'n')
        return option;
    else
        AreYouAdmin();
}

void AgregarProducto()
{
    struct Producto *productos;
    int cantidad = 0;
    system("cls");
    printf("\n\nAgregar producto\n\n");
    printf("%cCantidad de producto que deseas agregar%c: \t", 168, 63); scanf("%d", &cantidad);

    num = cantidad;

    productos = (struct Producto *)malloc(cantidad * sizeof(struct Producto *));

    fflush(stdin);

    for(int i = 0; i < cantidad; i++)
    {
        //system("cls");%[^\n]

        (productos+i)->id = i;

        printf("Agregar el nombre del producto: \t");
        getchar();
        scanf("%[^\n]", &(productos+i)->nombre_producto);

        printf("Agregar la cantidad de productos que 'habr%c' disponibles: \t", 160);
        scanf("%d", &(productos+i)->cantidad_items);

        fflush(stdin);
    }
    fflush(stdin);
    system("cls");
    printf("Saliendo...\n\n");
    List_Products(productos, num);
    Roles_menu(productos);
}

void List_Products(struct Producto *productos, int number)
{
    system("cls");
    if (number == 0)
        printf("Usted no tiene ning%cn producto guardado en nuestras bases de datos",163);

    printf("\n\nLista de los Productos");
    printf("\n\nID || Nombre || Disponibilidad \n");

    for(int i = 0; i < number; i++)
    {
        printf("\n\n%d || %s || %d \n", ((productos+i)->id + 1), (productos+i)->nombre_producto, (productos+i)->cantidad_items);
    }
}

void Pedidos(struct Producto *productos)
{
    int buscar, retiro;
    char respuesta;
    printf("\n\nQue producto deseas adquirir (seleccionar por el ID):\t"); scanf("%d", &buscar);

    for(int i = 0; i < num; i++)
    {
        if(buscar == ((productos + i)->id + 1))
        {
            printf("\n\nUsted ha seleccionado '%s' \n\n", (productos + i)->nombre_producto);

            printf("%cDeseas arquirir el '%s'%c (escribir 'Y' para un si o 'N' para un no):",168, (productos + i)->nombre_producto, 63); scanf("%s", &respuesta);

            if(respuesta == 'y')
            {
                printf("%cCuantos deseas retirar%c: \t", 168, 63); scanf("%d", &retiro);
                (productos + i)->cantidad_items = (productos + i)->cantidad_items - retiro;

                printf("\n\nEl '%s' a sido retirado, pase un buen d%ca", (productos + i)->nombre_producto, 161);
                List_Products(productos, num);

                printf("\n\n%cDeseas salir%c (escribir 'Y' para un si o 'N' para un no):\t",168 ,63); scanf("%s", &respuesta);

                if(respuesta == 'y')
                    List_Products(productos,num);
                else if(respuesta == 'n')
                    List_Products(productos, num);
            }
        }
        else if(buscar > (productos->id + 1))
        {
            printf("\n\nEl libro aun no se ha agregado :(\n\n");
            system("cls");
        }
        else if(buscar < (productos->id + 1))
        {
            printf("\n\nEl libro no existe :()\n\n");
            system("cls");
        }
    }
}