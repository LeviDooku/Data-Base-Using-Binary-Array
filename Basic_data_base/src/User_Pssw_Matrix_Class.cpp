//User_Pssw_Matrix_Class.cpp

#include "User_Pssw_Matrix_Class.h"
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

	User_Pssw_Matrix::User_Pssw_Matrix()
		: num_rows(0) {}

	//Return num of rows of the users matrix
	int User_Pssw_Matrix::Get_Rows(){
		return num_rows;
	}

	//Return the Index from a specific user
	int User_Pssw_Matrix::Find_User_Index(string user_name){
		for(int i = 0; i < num_rows; i++){
			if(*(*(matrix + i) + 0) == user_name){
				return i;
			}
		}	
		return -1;
	}

	//Return password from a specific user
	string User_Pssw_Matrix::Get_User_Password(string user_name){
		int user_index = Find_User_Index(user_name);

		if(user_index != -1)
			return *(*(matrix + user_index) + 1);
			//return matrix[user_index][1];
		else 
			return "";
	}

	//Return all info from a specific user
	string User_Pssw_Matrix::Get_User_Info(string user_name){
	    int user_index = Find_User_Index(user_name);

	    if(user_index != -1)
	        return *(*(matrix + user_index) + 0) + " " + *(*(matrix + user_index) + 1);
	    else 
	        return "";
	}

	//Set user name (need improvements for more efficiency)
	void User_Pssw_Matrix::Set_User_Name(string new_user_name, string old_user_name){
		int user_index = Find_User_Index(old_user_name);

		if(user_index != -1){
			*(*(matrix + user_index) + 0) = new_user_name; 
		}
	}

	//Set password (need improvements for more efficiency)
	void User_Pssw_Matrix::Set_User_Password(string new_password, string old_password, string user_name){
		int user_index = Find_User_Index(user_name);

		if(user_index != -1){
			*(*(matrix + user_index) + 1) = new_password; 
		}
	}

	//Deletes a user
	void User_Pssw_Matrix::Delete_User(string user_name){
		int user_index = Find_User_Index(user_name);

		if(user_index != -1){
			*(*(matrix + user_index) + 0) = *(*(matrix + num_rows -1) + 0);
			*(*(matrix + user_index) + 1) = *(*(matrix + num_rows -1) + 1);
			num_rows--;
		}
	}

	//Check if the user name already exists
	bool User_Pssw_Matrix::User_Name_Comprobation(string user_name){
		
		bool choosed = false;

		for(int i = 0; i < num_rows; i++)
			for(int j = 0; j < MAX_COL; j++)
				if(*(*(matrix + i) + j) == user_name)
					choosed = true;

		return choosed;
	}

	//Check if the user name meets thge requirements
	bool User_Pssw_Matrix::Char_Comprobation_un(string user_name){

		bool num_car = false;

		if(user_name.length() > USER_NAME_MAX_CAR || user_name.length() < USER_NAME_MIN_CAR)
			num_car = true;

		return num_car;
	}

	//Same with password
	bool User_Pssw_Matrix::Char_Comprobation_pssw(string password){

		bool num_car = false;

		if(password.length() < PSSW_MIN_CAR)
			num_car = true;

		return num_car;
	}

	//Add user to the matrix (need improvements for more efficiency)
	void User_Pssw_Matrix::Add_User(string user_name, string password){
		
		if(num_rows >= MAX_ROWS){
			return;
		}
		else if(User_Name_Comprobation(user_name) == true){
				return;
		}
		else if(Char_Comprobation_un(user_name) == true){
				return;
		}
		else{

			*(*(matrix + num_rows) + 0) = user_name;
			*(*(matrix + num_rows) + 1) = password;

			num_rows++;	
		}
	}

	//Show the matrix
	void User_Pssw_Matrix::Show_Matrix(){
		ifstream filename;
		string texto;

		filename.open("users_data.txt", ios::in);

		if(filename.fail()){
			return;
		}

		while(!filename.eof()){
			getline(filename, texto);
			cout << texto << endl;
		}

		filename.close();
	}

	//Save users in a file called users_data.txt    
	void User_Pssw_Matrix::Save_To_File(){
		ofstream filename; 

		filename.open("users_data.txt", ios::app);

		if(filename.fail()){
			return; 
		}

		for(int i = 0; i < num_rows; i++){
				filename << *(*(matrix + i) + 0) << " " << *(*(matrix + i) + 1) << endl;
		}
	}

	/*
	void User_Pssw_Matrix::Load_From_File(){

	}*/
















