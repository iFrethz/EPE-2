    struct Estudiante {
    char nombre[20]; 
    float nota;
    } e1 = {"Juan", 5.5};
    
    struct Estudiante *ptr = &e1;
    ptr->nota = 6.0; 
