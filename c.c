#include <stdio.h>
#include <string.h>

int contarVocales(char* palabra) {
    int contador = 0;
    int len = strlen(palabra);
    for (int i = 0; i < len; i++) {
        char c = palabra[i];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') {
            contador++;
        }
    }
    return contador;
}

int main(void) {
    int n;
    printf("Ingrese el numero de cadenas: ");
    scanf("%d", &n);
    getchar();

    FILE* archivo = fopen("resultados.txt", "w");

    if (archivo == NULL) {
        printf("Error");
        return 1;
    }

    int mx_vocales = 0;
    char winWord[100] = "";

    for (int i = 0; i < n; i++) {
        char cadena[100];
        printf("Ingrese una cadena: ");
        fgets(cadena,100,stdin);
        cadena[strcspn(cadena, "\n")] = '\0';

        int len = strlen(cadena);
        char palabra[100] = "";
        int j = 0;

        for (int k = 0; k <= len; k++) {
            char c = cadena[k];
            if (c == ' ' || c == '\0') {

                int vocales = contarVocales(palabra);

                if (vocales > mx_vocales) {
                    mx_vocales = vocales;
                    strcpy(winWord, palabra);
                }

                for (int l = 0; l < j; l++) {
                    palabra[l] = '\0';
                }
                j = 0;
            }

            else {
                palabra[j] = c;
                j++;
            }
        }
        printf("La cadena ingresada es: \"%s\"\n", cadena);
    }

    fprintf(archivo, "La palabra con mayor numero de vocales en mayuscula es \"%s\", con %d vocales.\n", winWord, mx_vocales);
    fclose(archivo);
    printf("Los resultados se han guardado en el archivo resultados.txt\n");

    return 0;
}
