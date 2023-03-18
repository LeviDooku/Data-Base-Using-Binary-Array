HOME=.
SRC=$(HOME)/src
OBJ=$(HOME)/obj
LIB=$(HOME)/lib
INCLUDE=$(HOME)/include
BIN=$(HOME)/bin

all : $(BIN)/Basic_Data_Base
	@echo ALL DONE

#Libraries

$(OBJ)/User_Pssw_Matrix_Class.o : $(SRC)/User_Pssw_Matrix_Class.cpp
	@echo Creating User_Pssw_Matrix_Class.o
	@g++ -c -o $(OBJ)/User_Pssw_Matrix_Class.o $(SRC)/User_Pssw_Matrix_Class.cpp -I$(INCLUDE)

$(LIB)/libUser_Pssw_Matrix_Class.a : $(OBJ)/User_Pssw_Matrix_Class.o
	@echo Creating User_Pssw_Matrix library
	@ar -rvs $(LIB)/libUser_Pssw_Matrix_Class.a $(OBJ)/User_Pssw_Matrix_Class.o

$(OBJ)/User_Pssw_Matrix_Functions.o : $(SRC)/User_Pssw_Matrix_Functions.cpp
	@echo Creating User_Pssw_Matrix_Functions.o
	@g++ -c -o $(OBJ)/User_Pssw_Matrix_Functions.o $(SRC)/User_Pssw_Matrix_Functions.cpp -I$(INCLUDE)

$(LIB)/libUser_Pssw_Matrix_Functions.a : $(OBJ)/User_Pssw_Matrix_Functions.o
	@echo Creating User_Pssw_Functions library
	@ar -rvs $(LIB)/libUser_Pssw_Matrix_Functions.a $(OBJ)/User_Pssw_Matrix_Functions.o


#Executable

$(OBJ)/Basic_Data_Base.o : $(SRC)/Basic_Data_Base.cpp
	@echo Creating Basic_Data_Base.o
	@g++ -c -o $(OBJ)/Basic_Data_Base.o $(SRC)/Basic_Data_Base.cpp -I$(INCLUDE)

$(BIN)/Basic_Data_Base : $(OBJ)/Basic_Data_Base.o $(LIB)/libUser_Pssw_Matrix_Class.a $(LIB)/libUser_Pssw_Matrix_Functions.a
	@echo Creating Basic_Data_Base executable
	@g++ -o $(BIN)/Basic_Data_Base $(OBJ)/Basic_Data_Base.o -L$(LIB) -lUser_Pssw_Matrix_Class -lUser_Pssw_Matrix_Functions -I$(INCLUDE)

#Create directories

Directories : 
	@echo Creating directories
	@mkdir bin obj lib

#clean & mr.proper

clean : 
	@echo Deleting objects
	@-rm $(OBJ)/*
mr.proper : 
	@echo Deleting everything
	@-rm $(OBJ)/*
	@-rm $(BIN)/*
	@-rm $(LIB)/*
