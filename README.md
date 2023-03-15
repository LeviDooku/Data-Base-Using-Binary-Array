# Data-Base-Using-Binary-Array
My very first "complex" proyect in C++.

The program consist in stroring users and their passwords in a binary array using a class that include methods to modify user names, passwords or deleting a user. 

To compile and try the program use the makefile: `makefile -f makefile.mak directories` then `makefile -f makefile.mak` and `./bin/Basic_Data_Base`

- March 10, 2023:

Upload the basic program, it's not finished yet. I already see many ways to modify methods for them to be more efficient. In the future I'd like to change the way to add a user and modify their credentials, I think I could try to combine many methods to not have a huge class, same as the functions in the Basic_Data_Base.cpp. After (or before?) doing those changes, I'm going to modularize the functions. 

- March 12, 2023:

Created a new function "Save_To_File" that store new users in a txt file. I´m looking for the way to work with this 
file, to avoid getting users with same user names and all that stuff. Also I update the Show_Matrix function, no it 
shows the file, not the current matrix.

- March 15, 2023:

Modularized functions in "Basic_Data_Base.cpp". I'm looking forward to reduce those function cuz they're huuuuge.
