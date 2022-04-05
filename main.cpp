#include <iostream>
using namespace std;
int main()
{

int m;
cout<<"\t\t\tElija una opci—n\n\n";
cout<<"1. Ingresos\n";
cout<<"2. Modificacion\n";
cout<<"3. Consultas\n";
cout<<"4. Reporter\n";
cout<<"5. Utilidades\n";
cout<<"6. Salir\n\n";
cin>>m;
switch(m)
{


case 1:cout<<"Usted tiene $2500"<<endl; break;
case 2:cout<<"ÀQue desea Modificar?"<<endl; break;
case 3:cout<<"Escriba su Consulta, aqui: "<<endl; break;
case 4:cout<<"Usted, no presenta Reportes"<<endl; break;
case 5:cout<<"Este servicio se encuentra Bloqueado por mantenimiento"<<endl; break;
case 6:cout<<"Ya esta fuera"<<endl; break; default: cout<<"El valor ingresado no esta en el menu"<<endl; break;
}
cin.ignore();
return 0;
}
