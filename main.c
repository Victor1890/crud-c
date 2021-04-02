//
// Created by
//

#include <stdio.h>
//#include "library/Biblioteca.h"
#include "library/Inventario.h"

void Delay(int second);
void Roles_menu(struct Producto *productos);

void main()
{
    struct Producto *productos;
    fflush(stdin);
    printf("Antes de usar este sotfware, primero deber%c ingresar los titulos de los libros al sistema", 160);
    printf("\nen la opci%cn del bibliotecario y luego as%c podra usar el sistema de biblioteca en la opci%cn de estudiantes",162, 161, 162);
    printf("\nQue tenga un lindo d%ca :)\n\n\n",161);
    printf("Precionar ENTER para continuar");
    getchar();
    //List_Products(productos,2);
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
    printf("    |      [1]  Inventarios           |\n");
    printf("    |      [2]  Compras               |\n");
    printf("    |      [3]  Ventas                |\n");
    printf("    |      [4]  Contabilidad          |\n");

    printf("\n\n Elegir una opcion: \t"); scanf("%d", &option);

    switch (option)
    {
        case 1:
            MenuInventario(productos);
        break;
        case 2:
        {
//            if(AreYouAdmin() == 'y')
//                AgregarProducto();
            printf("\n\nUsted no es bibliotecario");
        }
        break;
        default:
            system("cls");
            Roles_menu(productos);
        break;
    }
}

void Delay(int second)
{
    for (int i = 0; i < second; i++)
        for (int j = 1; j < second; j++){}
}