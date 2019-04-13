

#include <stdio.h>
#include <string.h>

typedef struct ITEM
{
	char itemName[30];
	int quantity;
	float rate;
}item;				//since typedef is used, the datatype of the structure is item

item Item[100];		//Creating an array of structure of datatype item
int flag;			//Global Variable.
item* find_item(FILE* fp, char *iname)				//Function to search the element
{
	
	int i=0;		
	item * it;			//This will contain the reference of the structure or this will point to the structure of datatype item. 
	while(!feof(fp))	//Loop until End of file is not reached
	{
		fscanf(fp,"%s %d %f",Item[i].itemName,&Item[i].quantity,&Item[i].rate);		//Storing all the items in the array of structure. 
		i=i+1;				//Incrementing i
	}
	 for(int i=0;i<(sizeof(Item)/sizeof(Item[0]));i++)			//Loop until the whole array size isnt reached
	{
		if(strcmp(iname,Item[i].itemName)==0)		//Check If the user search item is found in the array
		{
			it=&Item[i];		//If found, store the address of the structure in a pointer
			flag=1;			//Setting flag 1
			break;			//Break the loop
		}
		else		
		{
			flag=0;			//If not found, set flag as 0
		}
	}
	if(flag==1)
	{
		return it;		//If the item is found, return the address of the structure that is stored in pointer 'it'
	}

	else
	{
		return NULL;		//If not found, the return NULL
	} 
}

void print_struct(item *it)//To print the structure containing the parameter of the reference to the structure that contains the item user searched for
{
	if(flag==1)
	{
		printf("Name: %s\nQuantity: %d\nPrice: %f\n",it->itemName,it->quantity,it->rate); //Printing the details of items. 
	}
	else
	{
		printf("The item does not exist");	//Else not found
	}
}

void main()
{
	item *ptr;	//a pointer that will store the reference to the structure
	char iname[30],fileinp[50];		//user input for searching the element and the file name
	printf("Enter the file name you want to search the item in: /n");
	scanf("%s",fileinp);
	printf("Enter the item you want to search: /n");
	scanf("%s",iname);	//storing the user input in iname
	FILE *fp;		//Initializing a pointer variable to file
	fp=fopen(fileinp,"r");	//Open the file
	int i=0;
	ptr=find_item(fp,iname);	//ptr will store the result of the find_item function that returns the pointer to the structure user searched
	print_struct(ptr);			//function that will print the details of the user input and ptr (pointer to the structure) as argument
}
