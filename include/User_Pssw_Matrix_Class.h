#ifndef USER_PSSW_MATRIX_CLASS
#define USER_PSSW_MATRIX_CLASS

#include<iostream>
#include<string>
using namespace std;

class User_Pssw_Matrix{

private:
	static const int MAX_ROWS = 100;
	static const int MAX_COL = 2;
	static const int USER_NAME_MAX_CAR = 15;
	static const int USER_NAME_MIN_CAR = 3;
	static const int PSSW_MIN_CAR = 8;
	int num_rows;
	string matrix[MAX_ROWS][MAX_COL];

public: 

	User_Pssw_Matrix();

	int Get_Rows();

	int Find_User_Index(string user_name);

	string Get_User_Name(string user_name);

	string Get_User_Password(string user_name);

	string Get_User_Info(string user_name);

	void Set_User_Name(string new_user_name, string old_user_name);

	void Set_User_Password(string new_password, string old_password, string user_name);

	void Delete_User(string user_name);

	bool User_Name_Comprobation(string user_name);

	bool Char_Comprobation_un(string user_name);

	bool Char_Comprobation_pssw(string password);

	void Add_User(string user_name, string password);

	void Show_Matrix();

};

#endif