#### Description
This program is written in accordance to the assignment reqirement for HKPU COMP305 Assignment "iCountApp".

#### Usage
Compile the program by typing 'make' in src folder. The data file should be stored in the 'dat' folder. the compiled binary will be stored in 'bin' folder. The program is executed upon user's request and operate on data provided by user. The program is excuted in the following format:
```bash
		[user@locathost bin]$ ./main ../dat/(name of data file)
```

The data file supplied by user should contain string of words separated by space without symbols other than alphabats. The program will count the frequency of occurance of strings within the data file and report user the frequency. The output will be sorted according to frequency.

#### Explanation
The program contains a number of functions as explained below:

- cmp(struct, struct) and list_sort(struct) sort the linked list;
- listSearch(char, struct) searches the lists to see if the words being searched is already included in the list. Pointer to the node is return is word found otherwise NULL is returned.
- listCreate(struct) initialize the variables within a list given by user.
- listAdd(char, struct) calls the listSearch() function to see if word is already in the list. If true increase the count otherwise create a new element and update the list size.
- listPrint(struct) prints the linked list with words and word counts.
- listDelete(struct) is used to free the list at the end of the program.

The program reads strings from the file to a string buffer x which can contain maximum 50 characters which is reasonable to avoid infinitive long strings which can over load the program. After each successful read of string listAdd() is called to add word to the linked list of increase word count. When the whole file is read and the sort function is called to sort the linked list according word count. Finally listPrint() is called to print the final result.

##License##

Copyright (C) 2012 Steven Chien

This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with this program. If not, see http://www.gnu.org/licenses/.
