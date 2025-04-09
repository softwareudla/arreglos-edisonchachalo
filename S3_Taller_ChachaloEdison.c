#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{

    char materia[5][20];
    char estudiante[5][30];
    char id[5][15];
    float n1[5], n2[5], n3[5];
    float suma, promedio;
    int opc, contM = 0, contE = 0, mat = 0, len, aux;

    do
    {
        printf("Seleccione una opcion:\n");
        printf("1. Registro Materias\n");
        printf("2. Ingresar Notas\n");
        printf("3. Informacion Estudiantes\n");
        printf("4. Informacion Materias\n");
        printf("5. Informacion del Curso\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            do
            {

                printf("Ingrese el nombre de la materia m%d: ", contM);
                fflush(stdin);
                fgets(materia[contM], 30, stdin);

                len = strlen(materia[contM]) - 1;
                materia[contM][len] = '\0';
                contM++;

            } while (contM < 3);

            break;
        case 2:
            printf("Materias Registradas\n");
            printf("#\t\tMateria\n");
            for (int i = 0; i < contM; i++)
            {
                printf("%d\t\t%s\n", i, materia[i]);
            }
            printf("Ingreso de Notas\n");
            do
            {
                printf("Ingrese el id del estudiate %d: ", contE);
                scanf("%s", id[contE]);
                printf("Ingrese el nombre del estudiante %d: ", contE);
                fflush(stdin);
                fgets(estudiante[contE], 30, stdin);

                len = strlen(materia[contE]) - 1;
                estudiante[contE][len] = '\0';

                printf("Ingrese la Nota de la materia 0: ");
                scanf("%f", &n1);
                printf("Ingrese la Nota de la materia 1: ");
                scanf("%f",&n2);
                printf("Ingrese la Nota de la materia 2: ");
                scanf("%f",&n3);

                mat++;

                contE++;
            } while (contE < 5);

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        default:
            break;
        }
    } while (opc != 6);

    return 0;
}