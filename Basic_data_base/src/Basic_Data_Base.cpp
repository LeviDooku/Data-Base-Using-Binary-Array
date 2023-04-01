//Basic_Data_Base.cpp

#include "User_Pssw_Matrix_Class.h"
#include "User_Pssw_Matrix_Functions.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int main(){

	User_Pssw_Matrix data_base;
	char option;
	
	//Opening a menu with an infinite while structure 
	while(true){

		cout << endl;
		cout << "a) Registrar usuario" << endl;
		cout << "b) Iniciar sesión" << endl;
		cout << "q) Salir del menú" << endl;
		cout << "¿Que desea hacer?: ";
		cin >> option;

		if(option == 'a'){
			Add_New_User(data_base);
		}
		else if(option == 'b'){			
			Log_In(data_base);
		}
		else if(option == 'q'){
			break;
		}

		cout << endl << endl; 

		//Show the matrix in the console to make sure all running ok
		cout << "************************" << endl;
		data_base.Show_Matrix();
		cout << "************************" << endl;
		
		cout << endl << endl;

		data_base.Save_To_File();
	}
	
	return 0;
}