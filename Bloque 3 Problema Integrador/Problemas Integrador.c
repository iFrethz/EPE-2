#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Proveedor {
    char nombre[50];
    char rut[15];
};

struct Producto {
    char nombre[50];
    int precio, cantidad;
    struct Proveedor proveedor;
};

struct Producto p[100];
int contador = 0;

void agregar() {
    char seguir;
    
    if (contador >= 100) {
        printf("No puedes exceder el limite de 100 productos.\n");
        return;
    }
    
    do {
        printf("\nAgregar el %d° producto\n", contador + 1);
        printf("---------------------\n");
        
        printf("Nombre del producto: ");
        fgets(p[contador].nombre, sizeof(p[contador].nombre), stdin);
        p[contador].nombre[strcspn(p[contador].nombre, "\n")] = 0; // Eliminar el salto de línea
        
        printf("Nombre del proveedor: ");
        fgets(p[contador].proveedor.nombre, sizeof(p[contador].proveedor.nombre), stdin);
        p[contador].proveedor.nombre[strcspn(p[contador].proveedor.nombre, "\n")] = 0; // Eliminar el salto de línea
        
        do {
            printf("Precio: ");
            scanf("%d", &p[contador].precio);
            if (p[contador].precio <= 0) {
                printf("El precio debe ser mayor a 0. Intente nuevamente.\n");
            }
        } while (p[contador].precio <= 0);
        
        do {
            printf("Cantidad: ");
            scanf("%d", &p[contador].cantidad);
            if (p[contador].cantidad <= 0) {
                printf("La cantidad debe ser mayor a 0. Intente nuevamente.\n");
            }
        } while (p[contador].cantidad <= 0);
        
        printf("---------------------\n");
        
        contador++;
        
        printf("Desea seguir agregando productos (s/n): ");
        getchar(); // Limpiar el buffer
        scanf("%c", &seguir);
    } while (seguir == 's' || seguir == 'S');   
}

void mostrar() {
    printf("\nLista de los productos\n");
    printf("========================\n");
    for(int i = 0; i < contador; i++) {
        printf("%d° Producto\n", i + 1);
        printf("Nombre: %s\n", p[i].nombre);
        printf("Proveedor: %s\n", p[i].proveedor.nombre);
        printf("Precio: %d\n", p[i].precio);
        printf("Cantidad: %d\n", p[i].cantidad);
        printf("......................\n");
    }
}

void buscarPorProveedor() {
    char nombreProveedor[50];
    printf("Ingrese el nombre del proveedor a buscar: ");
    getchar(); // Limpiar el buffer
    fgets(nombreProveedor, sizeof(nombreProveedor), stdin);
    nombreProveedor[strcspn(nombreProveedor, "\n")] = 0; // Eliminar el salto de línea

    printf("\nProductos del proveedor %s:\n", nombreProveedor);
    printf("========================\n");
    int encontrado = 0;
    for (int i = 0; i < contador; i++) {
        if (strcmp(p[i].proveedor.nombre, nombreProveedor) == 0) {
            printf("%d° Producto\n", i + 1);
            printf("Nombre: %s\n", p[i].nombre);
            printf("Precio: %d\n", p[i].precio);
            printf("Cantidad: %d\n", p[i].cantidad);
            printf("......................\n");
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron productos para el proveedor %s.\n", nombreProveedor);
    }
}

void mostrarValorTotal() {
    int total = 0;
    for (int i = 0; i < contador; i++) {
        total += p[i].precio * p[i].cantidad;
    }
    printf("El valor total del inventario es: %d\n", total);
}

int main() {
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
                break;
            case 3:
                buscarPorProveedor();
                break;
            case 4:
                mostrarValorTotal();
                break;
            case 5:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpción no valida... Intente nuevamente.\n");
                break;
        }
    } while (select != 5);
    
    return 0;
}
