#include "User_Pssw_Matrix_Class.h"
#include "User_Pssw_Matrix_Functions.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//Function for adding new users.
void Add_New_User(User_Pssw_Matrix& data_base){

	string user_name;
	string password;

	cout << "Introduzca el nombre de usuario: " << endl;
	cin >> user_name;

	//Checking if the user name meets the requirements (methods described in User_Class_Matrix_Class.cpp)
	while(data_base.Char_Comprobation_un(user_name) || data_base.User_Name_Comprobation(user_name)){

		if(data_base.Char_Comprobation_un(user_name)){
			cout << "El nombre de usuario no puede superar los 15 caracteres ni tener menos de 3, pruebe nuevo: " << endl;
			cin >> user_name;
		}
		else{
			cout << "El nombre de usuario escogido está en uso, pruebe de nuevo: " << endl;
			cin >> user_name;
		}

	}

	cout << "Introduzca ahora la contraseña: " << endl;
	cin >> password;

	//Same for the password
	while(data_base.Char_Comprobation_pssw(password)){
		cout << "La contraseña debe contener al menos 8 caracteres, pruebe de nuevo: " << endl;
		cin >> password;
	}

	data_base.Add_User(user_name, password);

	cout << endl << "¡Usuario registrado con éxito!" << endl;

}

//Function to Log in and modify things about the user
void Log_In(User_Pssw_Matrix& data_base){
	
	string user_name;
	string password;
	char option;

	cout << "Introduzca el nombre de usuario: " << endl;
	cin >> user_name;

	//Checking if the credentials are correct
	while(data_base.User_Name_Comprobation(user_name) == false){
		cout << "Usuario no encontrado, pruebe de nuevo: " << endl;
		cin >> user_name;
	}

	cout << "Introduzca la contraseña: " << endl;
	cin >> password;

	while(data_base.Get_User_Password(user_name) != password){
		cout << "Contraseña incorrecta, pruebe de nuevo: " << endl;
		cin >> password;
	}

	cout << endl << "¡Sesión iniciada con éxito!, bienvenid@: " << user_name << endl;

	//Opening a sub-menu with an infinite while structure
	while(true){
		cout << endl;
		cout << "a) Modificar nombre de usuario" << endl;	//Modify user name
		cout << "b) Modificar contraseña" << endl;	//Modify password
		cout << "c) Borrar usuario" << endl;	//Delete user
		cout << "d) Cerrar sesión" << endl;	//Go to the main menu
		cout << "Seleccione una acción: ";
		cin >> option;

		if(option == 'a'){
			string new_user_name;

			cout << "Introduzca un nuevo nombre de usuario " << "(nombre actual " << user_name << "): " << endl;
			cin >> new_user_name; 

			//Checking if the new user name meet the requirements
			while(data_base.User_Name_Comprobation(new_user_name) || data_base.Char_Comprobation_un(new_user_name)){
				char option_name;

				cout << "El nombre de usuario (" << new_user_name << ") ya ha sido seleccionado o no cumple los requisitos" << endl;
				cout << "Pruebe de nuevo: " << endl;
				cin >> new_user_name;		
			}

			data_base.Set_User_Name(new_user_name, user_name);

			cout << endl << "¡Cambio realizado con éxito!" << endl;
		}
		else if(option == 'b'){
			string new_password;

			cout << "Introduzca una nueva contraseña: " << endl;
			cin >> new_password;

			while(data_base.Char_Comprobation_pssw(new_password) || data_base.Get_User_Password(user_name) == new_password){
				char option_pssw;

				cout << "La contraseña no puede ser más corta de 8 caracteres ni ser igual a la anterior" << endl;
				cout << "Pruebe de nuevo: " << endl;
				cin >> new_password;
			}

			data_base.Set_User_Password(new_password, password, user_name);

			cout << endl << "¡Cambio realizado con éxito!" << endl;

		}
		else if(option == 'c'){
			char seguro;

			//Confirmation message
			cout << "¿Quiere borrar su usuario? (Y/N): ";
			cin >> seguro;

			if(seguro != 'Y'){
				return;
			}
			else
				data_base.Delete_User(user_name);
				cout << "Usuario borrado";
		}
		else if(option == 'd'){
			break;
		}
	}
}
