#include<stdio.h>
#include<string.h>
void main()
{
	FILE *fp;	//Initialize file pointer
	char word[30],search[30],ch;	//Will store all the words present in the file
	printf("Enter the word you want to search: ");      //Take user input
	scanf("%s",search);	//Store it in a variable
	fp=fopen("string.txt","r");		//Open the file in read mode 
	long int a=ftell(fp);		//ftell tells the current file pointer. Currently, it is set to 0 and is stored in a variable a. 
	while(!feof(fp))		//Loop until it does not reach the end of the file
	{
		fscanf(fp,"%s ",word);		//Store all the words in the file in a variable 'word'
		if(strcmp(word,"\n")!=0)	//Check if the line end has reached or not
		{	if(strcmp(word,search)==0)	 //Check if the word is found or not
			{
				fseek(fp,SEEK_SET,a);		/*If word is found, point the file pointer to the beginning of the line. 
								Variable 'a' points to the first character of the line. */
				while(ch=fgetc(fp)!='\n')	//once the file pointer points to the beginning character of the line,
					printf("%c ",ch);	//print all the characters of the line.
			}  //end of if
		}  //end of if
		else	//If line end has reached
		{
			a=ftell(fp)+1;		//Point the file pointer to the first character of the next line. 
		}  //end of else
	} //end of while
}  //end of main()
