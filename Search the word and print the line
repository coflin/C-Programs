#include<stdio.h>
#include<string.h>
void main()
{
	FILE *fp;	//Initialize file pointer
	char word[30],ch;	//Will store all the words present in the file
	fp=fopen("string.txt","r");		//Open the file in read mode 
	long int a=ftell(fp);		//ftell tells the current file pointer. Currently, it is set to 0 and is stored in a variable a. 
	while(!feof(fp))		//Loop until it does not reach the end of the file
	{
		fscanf(fp,"%s ",word);		//Store all the words in the file in a variable 'word'
		if(strcmp(word,"\n")!=0)	//Check if the line end has reached or not
		{	printf("ftell=%d",ftell(fp));
			if(strcmp(word,"hello")==0)	 //If the line end has not reached, check if the word is "hello" or not
			{
			fseek(fp,SEEK_SET,a);		/*If word is "hello", point the file pointer to the beginning of the file. 
											Variable 'a' points to the first character of the line. */
			while(ch=fgetc(fp)!='\n')	//once the file pointer points to the beginning character of the line, print all the characters of the line
					printf("%c ",ch);
			//fseek(fp,SEEK_CUR,-1);
			printf("char :%d\n ",ch );	 
			fseek(fp,SEEK_CUR,-1);
		}
		}
		else						//If line end has reached
		{
			a=ftell(fp)+1;		//Point the file pointer to the first character of the next line. 
		}
	}
}
