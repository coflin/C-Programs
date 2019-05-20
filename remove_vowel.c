#include <stdio.h>
#include <string.h>

void remove_vowel(FILE *fp, char *name)		//function to remove the vowel from word.
{
	int i=0;	//initialize a variable.
	char ch,word[30],sentence[100]; //initialize character and words. 
	while(!feof(fp))	//run a loop till the end of file.
	{
		fscanf(fp,"%s",word);	//store words of the file in variable .
		if(strcmp(word,name)==0)	//if the word of the file matches with the word that the user wanted.
		{
			while((ch=fgetc(fp))!='\n')	//loop through the word found.
			{
				if(!('a'==ch||'e'==ch||'i'==ch||'o'==ch||'u'==ch||'A'==ch||'E'==ch||'I'==ch||'O'==ch||'U'==ch))	//If the character isn't a vowel.
				{
					sentence[i]=ch;	//Store the consonant of the word in a variable.
					i=i+1;	//Increment i.
				}	//end of if
			}	//end of while
			printf("%s",sentence);		//Print the variable that contains all the consonants of the word found.
		}	//end of if
	}	//end of while
}	//end of remove_vowel()

void main()		//main function. 
{
	char name[30];	//initialize a variable to store user input.
	FILE *fp;	//Initilize file pointer.
	fp=fopen("some.txt","r");	//Open the file in read mode.
	printf("Enter a name: ");	
	scanf("%s",name);	//Store user input.
	remove_vowel(fp,name);	//Call the remove_vowel method
}	//end of main
