#include <stdio.h>

struct empleado{
    int id;
    char nombre[50];
    float sueldo;
};

int main() {
    struct empleado emp[3] = {
        {1, "Ana", 500.5},
        {2, "Luis", 700.2},
        {3, "Carlos", 300.8}
    };
    
    float max_sueldo = 0.0;
    int idx_max = -1;
    
    for (int i = 0; i < 3; i++) {
        if (emp[i].sueldo > max_sueldo) {
            max_sueldo = emp[i].sueldo;
            idx_max = i;
        }
    }
    
    printf("Mayor sueldo: %s ($%.2f)\n", emp[idx_max].nombre, max_sueldo);
    return 0;
}
