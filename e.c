#include <stdio.h>
#include <string.h>

void Tel(char *telOriginal, char *telDos) {

    int len = strlen(telOriginal);

    telDos[0] = '(';
    telDos[1] = telOriginal[0];
    telDos[2] = telOriginal[1];
    telDos[3] = ')';
    telDos[4] = '-';
    telDos[5] = telOriginal[2];
    telDos[6] = '-';
    telDos[7] = telOriginal[3];

    for (int i = 0; i < 6; i++) {
        telDos[i + 8] = telOriginal[i + 4];
    }

    telDos[14] = '\0';
}

int main(void) {

    FILE *archivo;
    archivo = fopen("telefonos.txt", "w");

    if (archivo == NULL) {
        printf("Error\n");
        return 1;
    }

    int n;
    printf("Ingrese el numero de telefonos que desea ingresar: ");
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char telOriginal[10];
        char nuevo[13];

        printf("Ingrese el numero telefonico numero %d: ", i + 1);
        scanf("%9s", telOriginal);

        while (getchar() != '\n');


        Tel(telOriginal, nuevo);

        fprintf(archivo, "Numero telefonico: %s\n", telOriginal);
        fprintf(archivo, "Numero nuevo: %s\n\n", nuevo);
    }

    fclose(archivo);

    printf("Se han guardado los numeros telefonicos en el archivo telefonos.txt.\n");


}
