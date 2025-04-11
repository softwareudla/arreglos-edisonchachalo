#include <stdio.h>
#include <string.h>
// TRABAJO REALIZADO POR: EDISON CHACHALO y EYBRAHAM SAAVEDRA
int main(int argc, char *argv[])
{

    char materia[3][20];
    char estudiante[5][30];
    float calificaciones[5][3];
    float promedio = 0, max = 0, min = 10, nota;
    int opc, contM = 0, contE = 0, auxM, auxE, len;
    int aprobados = 0, reprobados = 0, maxM = 0, minM = 10;
    int val;

    do
    {
        printf("\nSeleccione una opcion:\n");
        printf("1. Registro Materias\n");
        printf("2. Ingresar Notas\n");
        printf("3. Informacion Estudiantes\n");
        printf("4. Informacion Materias\n");
        printf("5. Salir\n");
        printf(">> ");
        scanf("%d", &opc);

        switch (opc)
        {
        case 1:
            do
            {

                printf("Ingrese el nombre de la materia %d: ", contM);
                fflush(stdin);
                fgets(materia[contM], 30, stdin);

                len = strlen(materia[contM]) - 1;
                materia[contM][len] = '\0';
                contM++;

            } while (contM < 3);

            break;
        case 2:
            if (contM == 0)
            {
                printf("No hay materias registradas. Primero registre\n");
                break;
            }

            printf("Materias Registradas\n");
            printf("#\t\tMateria\n");
            for (int i = 0; i < contM; i++)
            {
                printf("%d\t\t%s\n", i, materia[i]);
            }
            printf("\nIngreso de Notas\n");
            do
            {

                printf("Ingrese el nombre del estudiante %d: ", contE);
                fflush(stdin);
                fgets(estudiante[contE], 30, stdin);

                len = strlen(estudiante[contE]) - 1;
                estudiante[contE][len] = '\0';

                printf("Ingrese las Notas de %s:\n", estudiante[contE]);
                float suma = 0;
                for (int i = 0; i < 3; i++)
                {
                    do
                    {
                        printf("%s: ", materia[i]);
                        val = scanf("%f", &calificaciones[contE][i]);
                        if (val != 1)
                        {
                            printf("Error: Dato invalido\n");
                            getchar();
                        }
                        if (calificaciones[contE][i] < 0 || calificaciones[contE][i] > 10)
                        {
                            printf("Nota no valida. La calificacion debe estar entre 0 y 10\n");
                        }

                    } while (val != 1 || calificaciones[contE][i] < 0 || calificaciones[contE][i] > 10);
                    suma += calificaciones[contE][i];
                }
                promedio = suma / 3;
                printf("Promedio: %.2f\n", promedio);

                contE++;
            } while (val != 1 || contE < 5);

            break;
        case 3:
            if (contE == 0)
            {
                printf("No hay estudiantes registrados\n");
                break;
            }

            printf("Lista de estudiantes\n");
            printf("#\tNombre\n");
            for (int i = 0; i < contE; i++)
            {
                printf("%d\t%s\n", i, estudiante[i]);
            }
            printf("\nSeleccione un estudiante\n");
            printf("Ingrese el # del estudiante en la lista: ");
            val = scanf("%d", &auxE);
            if (val != 1)
            {
                printf("Error: Dato invalido\n");
            }

            if (auxE < 0 || auxE >= contE)
            {
                printf("Estudiante no se encuentra en la lista");
                break;
            }
            float suma = 0;
            min = 10;
            max = 0;
            for (int i = 0; i < 3; i++)
            {
                suma += calificaciones[auxE][i];
                if (calificaciones[auxE][i] > max)
                {
                    max = calificaciones[auxE][i];
                }
                if (calificaciones[auxE][i] < min)
                {
                    min = calificaciones[auxE][i];
                }
            }
            promedio = suma / 3;

            printf("\nPromedio de %s: %.2f\n", estudiante[auxE], promedio);
            if (promedio >= 6)
            {
                printf("APROBADO\n");
            }
            else
            {
                printf("REPROBADO\n");
            }

            printf("Nota mas alta: %.2f\n", max);
            printf("Nota mas baja: %.2f\n", min);

            break;
        case 4:
            if (contM == 0)
            {
                printf("No hay materias registradas\n");
                break;
            }
            printf("Lista de Materias\n");
            printf("#\tNombre\n");
            for (int i = 0; i < contM; i++)
            {
                printf("%d\t%s\n", i, materia[i]);
            }
            printf("Seleccione una Materia\n");
            printf("Ingrese el # de la Materia de la lista: ");
            val = scanf("%d", &auxM);
            do
            {
                if (val != 1)
                {
                    printf("Error: Dato Inválido\n");
                    getchar();
                }
            } while (val != 1);

            if (auxM < 0 || auxM >= contM)
            {
                printf("# ingresado no se encuentra en la lista");
                break;
            }
            aprobados = 0;
            reprobados = 0;
            maxM = 0;
            minM = 10;
            int tieneNotas = 0;
            for (int i = 0; i < contE; i++)
            {
                nota = calificaciones[i][auxM];
                if (nota >= 0 && nota <= 10)
                {
                    tieneNotas = 1;
                    if (nota >= 6)
                    {
                        aprobados++;
                    }
                    else
                    {
                        reprobados++;
                    }
                    if (nota > maxM)
                    {
                        maxM = nota;
                    }
                    if (nota < minM)
                    {
                        minM = nota;
                    }
                }
            }
            printf("\nMateria: %s\n", materia[auxM]);
            printf("Estudiantes aprobados: %d\n", aprobados);
            printf("Estudiantes Reprobados: %d\n", reprobados);
            printf("Nota mas alta en la Materia: %.2f\n", maxM);
            printf("Nota mas baja en la Materia: %.2f\n", minM);

            break;
        case 5:
            printf("Saliendo del sistema ... \n");
            break;
        default:
            break;
        }
    } while (opc != 5);

    return 0;
}