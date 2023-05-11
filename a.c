#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char str[100], str_inv[100];
    int len, i, j, vocales, consonantes, espacios, palabras, n;
    FILE *archivo;

    printf("Numero de cadenas a ingresar: ");
    scanf("%d", &n);
    getchar();

    archivo = fopen("resultado.txt", "w");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo\n");
    }

    for (int k = 1; k <= n; k++) {
        printf("\nIngrese la cadena %d: ", k);
        fgets(str, 100, stdin);
        len = strlen(str);

        // Imprimir cadena invertida
        printf("Cadena invertida: ");
        fprintf(archivo, "Cadena original: %s", str);
        palabras = espacios = 0;
        for (i = len - 2; i >= 0; i--) {
            printf("%c", str[i]);
            str_inv[len - i - 2] = str[i];
            if (str[i] == ' ') {
                espacios++;
                palabras++;
            }
        }
        palabras++;
        str_inv[len - 1] = '\0';

        // Contar vocales y consonantes
        vocales = consonantes = 0;
        for (i = 0; i < len - 1; i++) {
            if (str[i] == ' ') {
                espacios++;
            } else if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
                vocales++;
            } else if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
                consonantes++;
            }
        }

        // Imprimir información de la cadena
        printf("\nLa cadena ingresada tiene %d palabras\n", palabras);
        printf("La cadena ingresada tiene %d vocales\n", vocales);
        printf("La cadena ingresada tiene %d consonantes\n", consonantes);
        printf("La cadena ingresada tiene %d espacios\n", espacios);
        //imprimir en archivo
        fprintf(archivo, "Cadena invertida: %s\n", str_inv);
        fprintf(archivo, "La cadena ingresada tiene %d palabras\n", palabras);
        fprintf(archivo, "La cadena ingresada tiene %d vocales\n", vocales);
        fprintf(archivo, "La cadena ingresada tiene %d consonantes\n", consonantes);
        fprintf(archivo, "La cadena ingresada tiene %d espacios\n", espacios);

        printf("\n");
    }

    fclose(archivo);
    return 0;
}
