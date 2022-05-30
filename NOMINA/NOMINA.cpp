#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std;

void escribir();


int main (){
    escribir();
string prinombre,segnombre, priapellido, segapellido, puesto;
float sueldo, votros ,nohoras,valorhoraextras,bonificacion,comisiones, judiciales, anticipo, totaldescuento, sueldoliquido, totaldevengado,IGSS,suord, boni,rentaexcenta, totalrenta,dedupersonal, rentaIGSS, excenta, totalgasto, imponible, isrA, credito, israpagar,  ISR;


// datos de entrada
cout << "-------------------DATOS----------------"  << endl ;
cout << "INGRESE PRIMER NOMBRE......................: ";
cin >> prinombre;
cout << "INGRESE SEGUNDO NOMBRE.....................: ";
cin >> segnombre;
cout << "INGRESE PRIMER APELLIDO....................: ";
cin >> priapellido;
cout << "INGRESE SEGUNDO APELLIDO...................: ";
cin >> segapellido;
cout << "INGRESE PUESTO.............................: ";
cin >> puesto;
cout << "*******************************************************"  << endl ;

cout << "INGRESE SUELDO ORDINARIO...................: ";
cin >> sueldo;
cout << "SUELDO EXTRAORDINARIO:"  << endl;

cout << "INGRESE NO. DE HORAS.......................: ";
cin >> nohoras;
cout << "-----------------------------------------------------"  << endl ;
cout << " "  << endl ;
cout << "INGRESE VALOR DE BONIFICACION INVENTIVO............: ";
cin >> bonificacion;

cout << "INGRESE COMISIONES.................................: ";
cin >> comisiones;
cout << "-------------------DESCUENTOS--------------"  << endl ;
cout << "INGRESE VALOR DE JUDICIALES........................: ";
cin >> judiciales;
cout << "INGRESE VALOR DE ANTICIPO..........................: ";
cin >> anticipo;
cout << "INGRESE VALOR DE OTROS.............................: ";
cin >> votros;

// calculos
valorhoraextras = sueldo / 30 / 8 * 1.5 *nohoras;
totaldevengado = sueldo + valorhoraextras + bonificacion;
IGSS = (sueldo + valorhoraextras + comisiones)* 0.0483;
suord = sueldo * 12;
boni = bonificacion * 12;
rentaexcenta = (sueldo) * 2;
totalrenta = suord + boni + rentaexcenta;
dedupersonal = 36000;
rentaIGSS = suord * 0.0483;
excenta = rentaexcenta;
totalgasto = dedupersonal + rentaIGSS + excenta;
imponible = (totalrenta - totalgasto);
isrA = (imponible) * 0.15;
credito = (totalrenta * 0.50) * 0.12;
israpagar = isrA - credito;
ISR = israpagar / 12;
totaldescuento = IGSS + ISR + judiciales + anticipo + votros;
sueldoliquido = totaldevengado - totaldescuento;



// Mostrar los resultados
if(sueldoliquido<totaldevengado) {
    cout << "  " << endl ;
    cout << "-------------------DATOS DEL EMPLEADO ----------------"  << endl ;
    cout << "     "  << endl ;
    cout << "PRIMER NOMBRE...........................: " << prinombre << endl;
    cout << "SEGUNDO NOMBRE..........................: " << segnombre << endl;
    cout << "PRIMER APELLIDO.........................: " <<  priapellido << endl;
    cout << "SEGUNDO APELLIDO........................: " << segapellido << endl;
    cout << "  "  << endl ;
    cout << "****************************************************"  << endl ;
    cout << "PUESTO DEL EMPLEADO.....................:"  << puesto << endl ;
    cout << "SUELDO ORDINARIO........................:"  << sueldo << endl ;
    cout << "   "  << endl ;
    cout << "----------SUELDO EXTRAORDINARIO-----------"  << endl ;
    cout << "   "  << endl ;
    cout << "VALOR DE LAS HORAS EXTRAS...............: " << valorhoraextras << endl ;
    cout << "VALOR DE BONIFICACION INCENTIVO.........: " << bonificacion << endl;
    cout << "-----------------------------------------------------"  << endl ;
    cout << " " <<endl;
    cout << "EL TOTAL DEVENGADO...............................: "  <<  totaldevengado << endl ;
    cout << "   "  << endl ;
    cout << "-------------------DESCUENTOS-----------------"  << endl ;
    cout << "IGSS......................: " << IGSS <<endl;
    cout << "ISR ......................: " << ISR << endl;
    cout << "-----------------------------------------------------"  << endl ;
    cout << "JUDICIALES................:"  << judiciales << endl ;
    cout << "ANTICIPOS.................:"  << anticipo << endl ;
    cout << "TOTAL DE DESCUENTOS.............................: " << totaldescuento << endl;
    cout << "" << endl;
    cout << "" << endl;
    cout << "............SUELDO LIQUIDO.....................................: " << sueldoliquido << endl;

} else {
     cout << "NOMBRE.........................: " << prinombre  ;
     }



}


void escribir(){
    ofstream archivo;

    archivo.open("RegistroNOMA.txt",ios::out); // abriendo el archivo

    if(archivo.fail()){
         cout<<"no se pudo abrir el archivo";
         exit(1);
}

    archivo.close();//cerrar el archivo
}

