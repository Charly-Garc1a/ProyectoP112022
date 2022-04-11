/*Programa: Menu de opciones con Login, Archivos y funciones
  Fecha de elaboración: 2022
  Autor: Charly Alexander Garcia Gomez
  Pablo
  Monica
  Ronald
  Marlon
  Grupo: 7
  Semestre: 1
  Materia: Programación 1
*/
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>

/*Librerias para la Fecha y La Hora*/
#include <iomanip>
#include <ctime>

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <windows.h>

#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
typedef struct {
   int  cuenta;
   char nomalum[40];
   char gmail[40];
   int primpar;
   int segpar;
   int salariom;
   int comisiones;
   int extras;
}


Alumno;
void  NomCrear(void);
void  NomImprimir(void);
void  NomAnexar (void);
void  NomModificar(void);
void  NomBorrar(void);

void  Crear(void);
void  Imprimir(void);
void  Anexar (void);
void  Modificar(void);
void  Borrar(void);
void  Mantenimiento(void);
void  Contabilidad (void);
void  Bitacora(void);
void  Pend(void);
void  MenuPri(void);

int op,cent;
#include <iostream>
#include <fstream>

using namespace std;
int main(){

//MENU PRINCIPAL//


vector<string> usuarios;
    vector<string> claves;

    // Se añaden usuarios al vector
    usuarios.push_back("Charly");
    usuarios.push_back("Pablo");
    usuarios.push_back("Ronald");
    usuarios.push_back("Monica");
    usuarios.push_back("Marlon");

    // Se añaden claves al vector
    claves.push_back("123");
    claves.push_back("456");
    claves.push_back("789");
    claves.push_back("abc");
    claves.push_back("efg");

    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {

        system("cls");
        printf("\n------------------------------------------------------------------------------------------\n");
        auto t = std::time(nullptr);
        auto tm = *std::localtime(&t);
        std::cout << std::put_time(&tm, "\n\t\t\t\t%d-%m-%Y %H-%M-%S") << std::endl;
        printf("\n------------------------------------------------------------------------------------------\n");
        printf("\n");
        Sleep(300);
        cout << "\t\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t\t----------------" << endl;
        cout << "\n\t\t\tUsuario: ";
        Sleep(200);
        getline(cin, usuario);

        char caracter;

        cout << "\t\t\tPassword: ";
        caracter = getch();

        password = "";

        while (caracter != ENTER)
        {

            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }

            caracter = getch();
        }

        for (int i = 0; i < usuarios.size(); i++)
        {
            if (usuarios[i] == usuario && claves[i] == password)
            {
                ingresa = true;
                break;
            }
        }

        if (!ingresa)
        {
            cout << "\n\n\t\t\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }

    } while (ingresa == false && contador < INTENTOS);

    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        system("cls");
        cout << "\n\n\t\t\t\t\t----------\2--------------" << endl;
        MenuPri();
        /*
        Aquí va el código del programa cuando el usuario ingresa sus credenciales correctas
        */
    }

    cin.get();

    return 0;

}
void MenuPri(void){
      while(cent<=6){
            printf("\n------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\tBIENVENDIO AL MENU DE RRHH GRUPO 7\n");
            printf("\n\t\t\t\t1.- Mantenimiento\n");
            printf("\n\t\t\t\t2.- Contabilidad\n");
            printf("\n\t\t\t\t3.- Bitacora\n");
            printf("\n\t\t\t\t4.- Pendiente\n");
            printf("\n\t\t\t\t5.- Salir del menu\n");
            printf("\n\t\t\t\tOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Mantenimiento();
               break;
               case 2:
                  Contabilidad();
               break;
               case 3:
                  Bitacora();
               break;
               case 4:
                  Pend();
               break;
               case 5:
                  cent=7;
               break;
               default:
                  system("cls");
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();

}


//MENU DE CONTABILIDAD//

void Contabilidad (void){
 system("cls");
      while(cent<=6){
            printf("\n------------------------------------------------------------------------------------------\n");
            printf("\t\t\t\tBienvenido al menu de CONTABILIDAD");
            printf("\n------------------------------------------------------------------------------------------\n");
            printf("\n\t\t1.- Crear archivo y crear un nuevo Empleado en la Nomina\n");
            printf("\n\t\t2.- Visualizar la lista de la Nomina\n");
            printf("\n\t\t3.- Anadir nuevo empleado a la Nomina\n");
            printf("\n\t\t4.- Modificar el registro de un empleado de la Nomina\n");
            printf("\n\t\t5.- Borrar el registro de un Empleado de la Nomina\n");
            printf("\n\t\t6.- Salir al Menu Principal");
            printf("\n\n\tOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  NomCrear();
               break;
               case 2:
                  NomImprimir();
               break;
               case 3:
                  NomAnexar();
               break;
               case 4:
                  NomModificar();
               break;
               case 5:
                  NomBorrar();
               break;
               case 6:
                  system("cls");
                  MenuPri();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}

//FUNCION PARA CREAR ARCHIVO Y REGISTROS DE  EMPLEADOS NOMINA//

void NomCrear(void){
FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("nomina.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
     system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN EMPLEADO A NOMINA");
      printf("\n\nIntroduce el Nombre del Empleado: ");
      gets(alm.nomalum);
      printf("\nIntroduce el No. de DPI: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el Salario Minimo:  ");
      scanf("%d",&alm.salariom);
      printf("\nIntroduce las Comisiones:  ");
      scanf("%d",&alm.comisiones);
      printf("\nIntroduce las Horas Extras:  ");
      scanf("%d",&alm.extras);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
   }

}

//FUNCION PARA IMPRIMIR REGISTROS DE  EMPLEADOS NOMINA//

void NomImprimir(void){
FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("nomina.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR NOMINA DE EMPLEADOS");
      printf("\n\n\t\t NOMINA  D E  EMPLEADOS\n");
      printf("\n------------------------------------------------------------------------------\n");
      printf("EMPLEADO \tDPI \t\t SALARIO \tCOMISIONES\tHORAS EXTRAS");
      printf("\n------------------------------------------------------------------------------\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nomalum);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t\t",alm.salariom);
         printf("%d \t\t",alm.comisiones);
         printf("%d\t",alm.extras);
      }
      printf("\n------------------------------------------------------------------------------\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }

}

//FUNCION PARA ANEXAR REGISTROS DE  EMPLEADOS NOMINA//

void NomAnexar(void){
FILE *fp;
   Alumno	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR EMPLEADOS A LA NOMINA");
   printf("\n\n!!Se anexaran nuevos EMPLEADOS al registro de NOMINA.DAT!!\n");
   if(!(fp=fopen("nomina.dat","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
     system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN EMPLEADO A NOMINA");
      printf("\n\nIntroduce el Nombre del Empleado: ");
      gets(alm.nomalum);
      printf("\nIntroduce el No. de DPI: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce el Salario Minimo:  ");
      scanf("%d",&alm.salariom);
      printf("\nIntroduce las Comisiones:  ");
      scanf("%d",&alm.comisiones);
      printf("\nIntroduce las Horas Extras:  ");
      scanf("%d",&alm.extras);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXADO CORRECTAMENTE A LA NOMINA!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
   }

}

//FUNCION PARA MODIFICAR REGISTROS DE  EMPLEADOS NOMINA//

void NomModificar(void){
FILE *fp;
   Alumno alm;
   int n,c,opc;

   if(!(fp=fopen("nomina.dat","r+b")))
   	printf("\n Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 4: MODIFICAR EL REGISTRO DE UN EMPLEADO");
      printf("\n\nIntroduzca el No. de DPI de un EMPLEADO: ");
      scanf("%d",&alm.cuenta);
      c=alm.cuenta;
      while ((n=fread(&alm, sizeof(alm), 1, fp))!=0 && alm.cuenta!=c);
      if (alm.cuenta!=c)
         printf("No existe la Cuenta: %d ",c);
      else{
         system("cls");
         printf("\n!!Se encontro el empleado!!");
         printf("\n¿Que desea cambiar?, Seleccione una opcion");
         printf("\n\n1.-Nombre");
         printf("\n\n2.-No. de DPI");
         printf("\n\n3.-Salario");
         printf("\n\n4.-Comisiones");
         printf("\n\n5.-Horas Extras");
         printf("\n\nIntroduzca opicion: ");
         scanf("%d",&opc);
         switch(opc){
                     case 1:
                        fflush(stdin);
                        printf("\nIntroduzca el nuevo nombre: ");
                        gets(alm.nomalum);
                     break;
                     case 2:
                        printf("\nIntroduza el nuevo DPI: ");
                        scanf("%d",&alm.cuenta);
                     break;
                     case 3:
                        printf("\nIntroduzca el Salario Minimo: ");
                        scanf("%d",&alm.salariom);
                     break;
                     case 4:
                        printf("\nIntroduzca la cantidad de comisiones del mes:  ");
                        scanf("%d",&alm.comisiones);
                     break;
                     case 5:
                        printf("\nIntroduzca el numero de Horas:  ");
                        scanf("%d",&alm.extras);
                     break;
                     default:
                        printf("\Error, opcion inexistente");
                     break;
         }
         printf("\nGrabando registro\n");
         fseek(fp,-sizeof(alm),SEEK_CUR);
         fwrite(&alm, sizeof(alm), 1, fp);
         printf("\nRegistro grabado con exito");
         printf("\nPresiona una tecla para continuar...");
         getch();
      }
      fclose(fp);
   }
}

//FUNCION PARA BORRAR REGISTROS DE  EMPLEADOS NOMINA//

void NomBorrar(void){

}

//FUNCION CONTROL DE BITACORA//

void Bitacora (void){
FILE *arch;
    arch=fopen("archivo1.dat","wb");
    if (arch==NULL)
        exit(1);

    char letra='A';
    fwrite(&letra, sizeof(char), 1, arch);
    int valor1=12;
    fwrite(&valor1, sizeof(int), 1, arch);
    float valor2=5.25;
    fwrite(&valor2, sizeof(float), 1, arch);

    fclose(arch);

    printf("Se creo un archivo binario que almacena un char, un int y un float.");

    getch();


}

//PENDIENTE//

void Pend(void){

}

//MENU DE MANTENIMIENTO//
void Mantenimiento(void){
    system("cls");
     cent=6;
      while(cent<=6){
            printf("Bienvenido al menu de MANTENIMIENTO");
            printf("\n\n1.- Crear archivo y crear un nuevo Empleado");
            printf("\n\n2.- Visualizar la lista existente");
            printf("\n\n3.- Añadir nuevo empleado al archivo existente");
            printf("\n\n4.- Modificar el registro de un Empleado");
            printf("\n\n5.- Borrar el registro de un Empleado");
            printf("\n\n6.- Salir al Menu Principal");
            printf("\n\nOpcion: ");
            scanf("%d",&op);

            switch(op){
               case 1:
                  Crear();
               break;
               case 2:
                  Imprimir();
               break;
               case 3:
                  Anexar();
               break;
               case 4:
                  Modificar();
               break;
               case 5:
                  Borrar();
               break;
               case 6:
                  system("cls");
                  MenuPri();
               break;
               default:
                  printf("\n!!!Error, opcion inexistente!!!");
                  printf("\n Introduce una opcion valida");
                  getch();
               break;
            }
        system("cls");
        }
        getch();
}


//FUNCION PARA CREAR EL ARCHIVO//
void Crear(void){
   FILE *fp;
   Alumno alm;
   // Creacion del archivo y guardar datos
   if(!(fp=fopen("registro.dat","wb")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
     system("cls");
      printf("\tELIGIO LA OPCION 1: CREAR ARCHIVO y AÑADIR UN EMPLEADO");
      printf("\n\nIntroduce el nombre del Empleado: ");
      gets(alm.nomalum);

      printf("\nIntroduce el No. de DPI: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la Edad:  ");
      scanf("%d",&alm.primpar);
      printf("\nIntroduce el numero de Telefono:  ");
      scanf("%d",&alm.segpar);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!REGISTRO REALIZADO CON EXITO!!!");
      printf("\nPresiona cualquier tecla para regresar al menu principal...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA IMPRIMIR EL REGISTRO DE ALUMNOS//
void Imprimir(void){
   FILE *fp;
   Alumno  alm;
   int n;
   if(!(fp=fopen("registro.dat","rb")))
   	printf("Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 2:IMPRIMIR REGISTRO DE EMPLEADOS");
      printf("\n\n\t\t R E G I S T R O  D E  EMPLEADOS\n");
      printf("\n------------------------------------------------------------------------------\n");
      printf("EMPLEADO \tDPI \t\t EDAD \t\tTELEFONO");
      printf("\n------------------------------------------------------------------------------\n");
      while ((n=fread(&alm, sizeof(alm),1, fp))!=0){
         printf("%s \t\t",alm.nomalum);
         printf("%d \t\t",alm.cuenta);
         printf("%d \t\t",alm.primpar);
         printf("%d \t\t\n",alm.segpar);
      }
      printf("\n------------------------------------------------------------------------------\n");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA ANEXAR DATOS AL REGISTRO DE EMPLEADO//
void Anexar(void){
   FILE *fp;
   Alumno	alm;

   system("cls");
   printf("\tELIGIO LA OPCION 3: ANEXAR ALUMNOS AL ARCHIVO");
   printf("\n\n!!Se anexaran nuevos EMPLEADOS al registro de Empleados.txt!!\n");
   if(!(fp=fopen("registro.alum","ab")))
   	printf("\n Error de apuertura del registro");
   else{
      fflush(stdin);
      printf("\n\nIntroduce el nombre del Empleado: ");
      gets(alm.nomalum);
      fflush(stdin);
      printf("\nIntroduce el No. de DPI: ");
      scanf("%d",&alm.cuenta);
      printf("\nIntroduce la Edad del Empleado:  ");
      scanf("%d",&alm.primpar);
      printf("\nIntroduce el Numero de Telefono:  ");
      scanf("%d",&alm.segpar);
      fwrite(&alm, sizeof(alm), 1, fp);
      printf("\n!!!ANEXO REALIZADO CON EXITO!!!");
      printf("\nPresiona una tecla para continuar...");
      getch();
      fclose(fp);
   }
}

//FUNCION PARA MODIFICAR UN REGISTRO CON BUSQUEDA
void Modificar(void){
   FILE *fp;
   Alumno alm;
   int n,c,opc;

   if(!(fp=fopen("registro.alum","r+b")))
   	printf("\n Error de apuertura del registro");
   else{
      system("cls");
      printf("\tELIGIO LA OPCION 4: MODIFICAR EL REGISTRO DE UN EMPLEADO");
      printf("\n\nIntroduzca el No. de DPI de un EMPLEADO: ");
      scanf("%d",&alm.cuenta);
      c=alm.cuenta;
      while ((n=fread(&alm, sizeof(alm), 1, fp))!=0 && alm.cuenta!=c);
      if (alm.cuenta!=c)
         printf("No existe la Cuenta: %d ",c);
      else{
         system("cls");
         printf("\n!!Se encontro el empleado!!");
         printf("\n¿Que desea cambiar?, Seleccione una opcion");
         printf("\n\n1.-Nombre");
         printf("\n\n2.-No. de DPI");
         printf("\n\n3.-Edad");
         printf("\n\n4.-Telefono");
         printf("\n\nIntroduzca opicion: ");
         scanf("%d",&opc);
         switch(opc){
                     case 1:
                        fflush(stdin);
                        printf("\nIntroduzca el nuevo nombre: ");
                        gets(alm.nomalum);
                     break;
                     case 2:
                        printf("\nIntroduza el nuevo DPI: ");
                        scanf("%d",&alm.cuenta);
                     break;
                     case 3:
                        printf("\nIntroduzca la Edad: ");
                        scanf("%d",&alm.primpar);
                     break;
                     case 4:
                        printf("\nIntroduzca el numero de Telefono:  ");
                        scanf("%d",&alm.segpar);
                     break;
                     default:
                        printf("\Error, opcion inexistente");
                     break;
         }
         printf("\nGrabando registro\n");
         fseek(fp,-sizeof(alm),SEEK_CUR);
         fwrite(&alm, sizeof(alm), 1, fp);
         printf("\nRegistro grabado con exito");
         printf("\nPresiona una tecla para continuar...");
         getch();
      }
      fclose(fp);
   }
}

//FUNCION PARA BORRAR REGISTROS DE  EMPLEADOS//

void Borrar(void){
   FILE *fp,*fd;
   Alumno alm;
   int n,c,encontrado=0;
 system("cls");
   printf("\tELIGIO LA OPCION 5: BORRAR EL REGISTRO DE UN EMPLEADO");
   printf("\n\nIngrese el No. de DPI del Empleado que desea Eliminar: ");
   scanf("%d",&alm.cuenta);
   c=alm.cuenta;
   if(!(fp=fopen("registro.alum","rb")))
   	printf("\n Error de apuertura del registro");
   else{
      if(!(fd=fopen("auxregis.txt","wb")))
         printf("\n Error,imposible borrar registro, el archivo no existe");
      else{
         while ((n=fread(&alm, sizeof(alm), 1, fp))!=0){
            if(alm.cuenta!=c)
              fwrite(&alm, sizeof(alm), 1, fd);
            else
              encontrado=1;
         }
         fclose(fd);
      }
      fclose(fp);
      if(encontrado){
         system("del registro.alum");
         system("ren auxregis.txt registro.alum");
         printf("\n!!!Registro borrado satisfactoriamente!!!\n");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
      else{
         system("del auxregis.txt");
         printf("\n!!!No se entontro ningun alumno con ese numero de cuenta!!!");
         printf("\n\nPresiona una tecla para continuar");
         getch();
      }
   }
}
