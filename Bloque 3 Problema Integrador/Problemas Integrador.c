#include <stdio.h>

struct Proveedor {
    char nombre[50];
    char rut[15];
};

struct Producto{
    char nombre[50];
    int precio, cantidad;
    struct Proveedor proveedor;
};

struct Producto p[100];
int contador = 0;

void agregar() {
    char seguir;
    
    if (contador > 100) {
        printf("No puedes exceder el limite de 100 productos.");
    } else {
         do {
        printf("\nAgregar el %d° producto\n", contador + 1);
        printf("---------------------\n");
        printf("Nombre: ");
        scanf("%s", p[contador].nombre);
        printf("Precio: ");
        scanf("%d", &p[contador].precio);
        printf("Cantidad: ");
        scanf("%d", &p[contador].cantidad);
        printf("---------------------\n");
        
        contador++;
        
        printf("Desea seguir agregando productos (s/n): ");
        scanf(" %c", &seguir);
    } while (seguir == 's' || seguir == 'S');   
    }
}

void mostrar() {
    printf("\nLista de los productos\n");
    printf("========================\n");
    for(int i = 0; i < contador; i++){
        printf("%d° Producto\n", i + 1);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Precio: %d\n", p[i].precio);
        printf("Cantidad: %d\n", p[i].cantidad);
        printf("......................\n");
    }
}

int main(){
    int select;
    do {
    printf("\nGestión de inventario\n");
    printf("----------------------\n");
    printf("1.- Agregar Productos.\n");
    printf("2.- Listar productos registrados.\n");
    printf("3.- Buscar productos por nombre del proveedor.\n");
    printf("4.- Mostrar el valor total del inventario.\n");
    printf("5.- Salir.\n");
    printf("----------------------\n");
    printf("Selecciona una opción: ");
    scanf("%d", &select);
    
    switch (select) {
        case 1:
            agregar();
            break;
        case 2:
            mostrar();
            printf("Se congelo el listado por 5 segundos...\n");
            sleep(5);
            break;
        case 3:
            printf("opción 3\n");
            sleep(5);
            break;
        case 4:
            printf("opción 4\n");
            sleep(5);
            break;
        case 5:
            printf("\nSaliendo del programa...");
            break;
        default:
            printf("\nOpción no valida... Espere 3 segundos\n");
            sleep(3);
            break;
    }
    } while (select != 5);
}
