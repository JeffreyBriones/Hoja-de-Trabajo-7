/*/EJERCICIO#7
Una empresa necesita llevar el control de los datos personales de sus 10 empleados contratados, por la motivo la empresa lo ha contratado para la implementacion de este proyecto, los datos a almacenar son:

Codigo Empleado,
Nombre Empleado,
Puesto,
Departamento,
Salario.

Existen 3 departamentos, 1 Gerencia, 2 Administracion y 3 Produccion.  El programa debera de desplegar la lista de empleados almacenados y el total de la planilla.

Nota: Se debe utilizar ciclos, punteros, arreglos y estructuras.

*/


#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
void insertar();
void reporte();
void mp();
using namespace std;
int main(){
	mp();
}

void insertar(){
 int codigo;
 float salario;
 string nombre,puesto,departamento;
 ofstream db;
 
 cout<<"-----------------------------"<<endl;
 cout<<"INGRESO DE DATOS DE EMPLEADOS"<<endl;
 cout<<"-----------------------------"<<endl;
 cout<<"Ingrese identificacion del Empleado: "<<endl;
 cin>>codigo;
 fflush(stdin);
 cout<<"INGRESAR UN GUION BAJO ENTRE EL NOMBRE Y APELLIDO"<<endl;
 cout<<"Ingrese Nombre del Empleado: "<<endl;
 getline(cin,nombre);
 fflush(stdin);
 cout<<"Ingrese Puesto del Empleado: "<<endl;
 getline(cin,puesto);
 fflush(stdin);
 cout<<"Ingrese Departamento del Empleado: "<<endl;
 getline(cin,departamento);
 cout<<"Ingrese Salario del Empleado: "<<endl;
 cin>>salario;
 
 /*const auto obj = regex{ " " };
 const auto repl = string{ "_" };
 const auto valor = nombre;*/
 //regex_replace(valor, obj, repl)

   
 try{
 	db.open("empresa.txt",ios::app);
	db<<codigo<<"\t"<<nombre<<"\t""\t"<<puesto<<"\t""\t"<<departamento<<"\t"<<salario<<endl;
	db.close();  
 }
 catch(exception X){
 	cout<<"Error";
 	system("Pause");
 }
	
	
}
void reporte(){
	int codigo1;
 	float salario1,opera1=0,i;
 	string nombre1,puesto1,departamento1;
	ifstream db;
	
try{
 	cout<<"-------------------------------------------------------------------------------"<<endl;
	cout<<" Codigo   /"<<"      Nombre     /" <<"    Puesto    /"<<"    Departamento   /"<<"   Salario   /"<<endl;
	cout<<"-------------------------------------------------------------------------------"<<endl; 	
	db.open("empresa.txt",ios::in);
	while(db>>codigo1>>nombre1>>puesto1>>departamento1>>salario1){
		cout<<"    "<<codigo1<<"      "<<nombre1<<"      "<<puesto1<<"          "<<departamento1<<"       "<<"Q"<<salario1<<endl;
		
		i++;
		opera1 += salario1;
		
	}
	
	
	db.close(); 
	cout<<"-------------------------------------------"<<endl; 
	cout<<"El total a pagar de su planilla es de: Q"<< opera1 <<endl;
	cout<<"-------------------------------------------"<<endl;
 }
 catch(exception X){
 	cout<<"Error";
 	system("Pause");
 }
}

void mp(){
		int resp;
	//string nombrearchivo;
	//cout<<"Indique nombre de archivo: ";
	//getline(cin,nombrearchivo);
	
	do {
		system("CLS");
		cout<<"-------------------------------"<<"\n";
		cout<<" Menu Principal De La Empresa"<<"\n";
		cout<<"-------------------------------"<<"\n";
		cout<<" 1 - Ingresar Empleados "<<"\n";
		cout<<" 2 - Reporte "<<"\n";
		cout<<" 3 - Salir"<<"\n";
		cout<<"--------------------------"<<"\n";
		cout<<" Seleccione su opcion: ";
		cin>>resp;
		if (resp==1){		
			system("CLS");
			insertar();			
		}
		else if (resp==2){		
			system("CLS");
			reporte();
			system("Pause");
	}
		else if (resp==3)
			break;
		else 
			break;
		
	} while(resp!=5);	
}
	
	
