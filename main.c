//
// Created by Eimy Corcino on 7/25/2020.
//

#include <stdio.h>
#include "library/Biblioteca.h"

void Roles_menu(struct Producto *productos);

void main()
{
    struct Producto *productos;
    fflush(stdin);
    printf("Antes de usar este sotfware, primero deber%c ingresar los titulos de los libros al sistema", 160);
    printf("\nen la opci%cn del bibliotecario y luego as%c podra usar el sistema de biblioteca en la opci%cn de estudiantes",162, 161, 162);
    printf("\nQue tenga un lindo d%ca :)\n",161);
    getchar();
    Roles_menu(productos);
}

//void Advertencia()
//{
//    printf("                       __\n");
//    printf("                     .'  '.");
//    printf("                 _.-'/  |  \\");
//    printf("    ,        _.-\"  ,|  /  0 `-.");
//    printf("    |\\    .-\"       `--\"\"-.__.'=====================-,");
//    printf("    \\ '-'`        .___.--._)============================|");
//    printf("     \\            .'         |                          |");
//    printf("      |     /,_.-'            |        Advertencia       |");
//    printf("    _/   _.'(                 |            de            |");
//    printf("   /  ,-' \\  \\              |      Error de Memoria    |");
//    printf("   \\  \\    `-'              |                          |");
//    printf("    `-'                       '--------------------------'");
//}

void Roles_menu(struct Producto *productos)
{
    int option = 0;
    system("cls");
    printf("\n\n 1-) Cliente \t 2-) Administrador\n\n");
    printf("\n\n Elegir una opcion: \t"); scanf("%d", &option);

    switch (option)
    {
        case 1:
            Usuario(productos);
            Pedidos(productos);
        break;
        case 2:
        {
            if(AreYouAdmin() == 'y')
                AgregarProducto();
            printf("\n\nUsted no es bibliotecario");
        }
        break;
        default:
            system("cls");
            Roles_menu(productos);
        break;
    }
}