#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int cantidad;
int tipoActual;
int contTipo1, contTipo2, contTipo3;
int descuentoVehiculos(int, int);

int main()
{
    printf("ASEGURADORA STARK\n\n");
    printf("Digite Cantidad de usuarios a registrar:\n");
    scanf("%d", &cantidad);
    contTipo1 = 0, contTipo2 = 0, contTipo3 = 0;
    int tipoVehiculo[cantidad];
    char *nombres[cantidad];
    int cedula[cantidad];
    int modelo;
    int cilindraje;
    int descuento[cantidad];
    for (int i = 0; i < cantidad; i++)
    {
        printf("Vehiculos N%d\n", (i + 1));
        printf("Ingrese nombre usuario \n ");
        char nombre[20];
        scanf("%s", nombre);
        nombres[i] = nombre;
        printf("Ingrese cedula usuario \n ");
        scanf("%d", &cedula[i]);
        printf("Cilindraje del vehiculo\n");
        scanf("%d", &cilindraje);
        printf("Año de vehículo\n");
        scanf("%d", &modelo);
        descuento[i] = descuentoVehiculos(cilindraje, modelo);
        tipoVehiculo[i] = tipoActual;
        printf("El descuento de su vehiculo es: %d%%", descuento[i]);
        printf("\n");
    }
    double sumTipo1 = 0, sumTipo2 = 0, sumTipo3 = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (tipoVehiculo[i] == 1)
        {
            sumTipo1 = sumTipo1 + descuento[i];
        }
        if (tipoVehiculo[i] == 2)
        {
            sumTipo2 = sumTipo2 + descuento[i];
        }
        if (tipoVehiculo[i] == 3)
        {
            sumTipo3 = sumTipo3 + descuento[i];
        }
    }
    printf("//////////////////////////////////\n");
    printf("Ejecuciones del programa: %d\n", (cantidad));
    printf("Cantidad vehiculos tipo 1:%d \n", contTipo1);
    printf("Porcentaje vehiculos tipo 1:%lf \n", (sumTipo1/contTipo1));
    printf("Cantidad vehiculos tipo 2:%d \n", contTipo2);
    printf("Porcentaje vehiculos tipo 2:%lf \n",  (sumTipo2/contTipo2));
    printf("Cantidad vehiculos tipo 3:%d \n", contTipo3);
    printf("Porcentaje vehiculos tipo 3:%lf \n",  (sumTipo3/contTipo3));
    printf("//////////////LISTA//////////////// \n");
    for (int i = 0; i < cantidad; i++)
    {
        printf("%d: [Nombre: %s,Cedula: %d,Tipo: %d]\n", i, nombres[i], cedula[i], tipoVehiculo[i]);
    }
    return 0;
}

int descuentoVehiculos(int cilindraje, int modelo)
{
    int descuento = 0;
    if (cilindraje >= 2500)
    {
        contTipo1 = contTipo1 + 1;
        tipoActual = 1;
        if (modelo <= 2000)
        {
            descuento = 13;
        }
        if (modelo >= 2001 && modelo <= 2014)
        {
            descuento = 8;
        }
        if (modelo >= 2014)
        {
            descuento = 6;
        }
    }
    else if (cilindraje < 2500 && cilindraje > 1600)
    {
        contTipo2 = contTipo2 + 1;
        tipoActual = 2;
        if (modelo <= 2000)
        {
            descuento = 16;
        }
        if (modelo >= 2001 && modelo <= 2014)
        {
            descuento = 13;
        }
        if (modelo >= 2014)
        {
            descuento = 13;
        }
    }
    else if (cilindraje <= 1600)
    {
        tipoActual = 3;
        contTipo3 = contTipo3 + 1;
        descuento = 10;
    }
    return descuento;
}
