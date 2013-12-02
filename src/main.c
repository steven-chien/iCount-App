/********************************************************************************/
/*Program name: iCountApp							*/
/*Author: Chien Wei Der								*/
/*Date of Completion: 12 Mar 2013						*/
/*Description: this is a program written in accordance to the requirement of	*/
/*             HKPU COMP305 2013 Assignment 1 "iCountApp".			*/
/*										*/
/*	Copyright CHIEN, Wei Der 2013						*/
/*										*/
/*	This program is free software: you can redistribute it and/or modify	*/
/*	it under the terms of the GNU General Public License as published by	*/
/*	the Free Software Foundation, either version 3 of the License, or	*/
/*	(at your option) any later version.					*/
/*										*/
/*	This program is distributed in the hope that it will be useful,		*/
/*	but WITHOUT ANY WARRANTY; without even the implied warranty of		*/
/*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the		*/
/*	GNU General Public License for more details.				*/
/*										*/
/*	You should have received a copy of the GNU General Public License	*/
/*	along with this program.  If not, see <http://www.gnu.org/licenses/>.	*/
/*										*/
/********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//type definition for structure node
typedef struct Node {
	char *words;
	int count;
	struct Node *next;
} node;

//type definition for structure list
typedef struct List {
	node *start, *end;
	int size;
} list;

//comparasion for the sorting function
int cmp(struct Node *a, struct Node *b) {

	return b->count - a->count;
}

//sorting function for the linked list
void list_sort(struct List *list) {					//merge sort

	struct Node *p, *q, *e, *head, *tail;
	int insize, nmerges, psize, qsize, i;

	head = list->start;

	if (!head)
		return;

	insize = 1;

	while (1) {
		p = head;
		head = NULL;
		tail = NULL;

		nmerges = 0;

		while (p) {
			nmerges++;

			q = p;
			psize = 0;
			for (i = 0; i < insize; i++) {

				psize++;
				q = q->next;
				if (!q) break;
			}

			qsize = insize;

			while (psize > 0 || (qsize>0 && q)) {

				if (psize == 0) {

					e = q;
					q = q->next;
					qsize--;
				}
				else if (qsize == 0 || !q) {
					e = p;
					p = p->next;
					psize--;
				}
				else if (cmp (p, q) <= 0) {
					e = p;
					p = p->next;
					psize--;
				} else {
					e = q;
					q = q->next;
					qsize--;
				}

				if (tail)
					tail->next = e;
				else
					head = e;
				tail = e;
			}

			p = q;
		}
		tail->next = NULL;
		if (nmerges <= 1) {
			list->start = head;
			return;
		}
	insize *= 2;
	}
}

//list searching algorithm to see if word is already recorded
node *listSearch(char string[], list *theList) {

	node *p;
	for(p=theList->start; p!=NULL; p=p->next) {				//search from start of list
		if(strcmp(string, p->words)==0)
			return p;						//return node if found
	}
	return NULL;								//return NULL if not found
}

//function to create a new "list"
void listCreate(list **theList) {
	
	(*theList) = (list*)malloc(sizeof(list));				//space allocation
	if((*theList)==NULL) {
		printf("\nMemory error! Abort\n");
		exit(-1);
	}
	(*theList)->start = NULL;						//initialize start
	(*theList)->end = NULL;							//initialize end
	(*theList)->size = 0;							//initialize list variables
}

//function to add a word to list
void listAdd(char string[], list *theList) {

	node *search = listSearch(string, theList);				//check if word appeared before

	if(search!=NULL) {							//if word was there increast count
		search->count = search->count+1;
		return;
	} else if(search==NULL) {						//if word not there
		node *p = (node*)malloc(sizeof(node));				//create new node for word
		if(p==NULL) {
			printf("\nMemory error! Abort\n");
			exit(-1);
		}
		p->words = (char*)malloc(strlen(string)+1);			//allocate space for string
		if(p->words==NULL) {
			printf("\nMemory error! Abort\n");
			exit(-1);
		}
		strcpy(p->words, string);					//store words to list
		p->next = NULL;
		p->count = 1;							//increase word count to 1
		theList->size++;						//record new size of list

		if(theList->end==NULL)						//check if word is 1st element
			theList->start = theList->end = p;
		else {
			theList->end->next = p;
			theList->end = p;
		}
	}

}

//function for list printing
void listPrint(list *theList) {

	node *p;
	int i;
	printf("No.\tWord\t\tCount\n");
	printf("-----------------------------\n");
	for(i=1,p=theList->start; p!=NULL; i++,p=p->next)
		printf("%d\t%s\t\t%d\n", i, p->words, p->count);
}

//function for list deletion
void listDelete(list *theList) {

	int i = 0;
	node *p = theList->start;

	while(p!=NULL) {
		node *temp = p->next;
		free(p);
		p = temp;
	}
}

int main(int argc, char *argv[]) {

	//variables declaration
	FILE *file  = fopen(argv[1],"r");					//open file given by user
	char ch;
	char x[50];
	int i = 0;
	//create new list
	list *list;
	listCreate(&list);

	if(file!=NULL) {							//word only if file exists

		while(fscanf(file, "%s", x)!=EOF) {				//read string from file
			listAdd(x, list);						//call listAdd to add word
		}
		fclose(file);							//close file after operation
		list_sort(list);							//sort the list according to word count
		listPrint(list);							//print the list
		listDelete(list);							//free the list
		free(list);
	}
	
	return 0;								//bye!
}
