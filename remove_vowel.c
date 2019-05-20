#include <stdio.h>
#include <string.h>

void remove_vowel(FILE *fp, char *name)
{
	int i=0;
	char ch;
	char word[30],sentence[100];
	while(!feof(fp))
	{
		fscanf(fp,"%s",word);
		if(strcmp(word,name)==0)
		{
			while((ch=fgetc(fp))!='\n')
			{
				if(!('a'==ch||'e'==ch||'i'==ch||'o'==ch||'u'==ch||'A'==ch||'E'==ch||'I'==ch||'O'==ch||'U'==ch))
				{
					sentence[i]=ch;
					i=i+1;
				}
			}
			printf("%s",sentence);
		}
	}
}

void main()
{
	char name[30];
	FILE *fp;
	fp=fopen("some.txt","r");
	printf("Enter a name: ");
	scanf("%s",name);
	remove_vowel(fp,name);
}
