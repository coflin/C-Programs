#include<stdio.h>
#include<string.h>

struct student
{
	long long int prn;
	char name[30];
	char program[10];
	float cgpa;
};

struct maxbcadetails
{
	long long int prn;
	char name[30];
	char program[10];
	float cgpa;
}maxstubca;

struct maxbbadetails
{
	long long int prn;
	char name[30];
	char program[10];
	float cgpa;
}maxstubba;


void main()
{
	float maxbca=0.0,maxbba=0.0;

	int i=0;
	struct student stu[10];
	FILE *fp;
	fp=fopen("student.txt","r");
	fscanf(fp,"%lld %s %s %f",&stu[i].prn,stu[i].name,stu[i].program,&stu[i].cgpa);
	printf("%lld",stu[0].prn);
	if(strcmp(stu[0].program,"BCA")==0){
	maxbca=stu[0].cgpa;
	maxstubca.prn=stu[0].prn;
	strcpy(maxstubca.name,stu[0].name);
	strcpy(maxstubca.program,stu[0].program);
	maxstubca.cgpa=stu[0].cgpa;
	i=i+1;
	}
	else if(strcmp(stu[0].program,"BBA")==0){
	maxbba=stu[0].cgpa;
	maxstubba.prn=stu[0].prn;
	strcpy(maxstubba.name,stu[0].name);
	strcpy(maxstubba.program,stu[0].program);
	maxstubba.cgpa=stu[0].cgpa;
	i=i+1;
	}
	while(!feof(fp))
	{
		fscanf(fp,"%lld %s %s %f",&stu[i].prn,stu[i].name,stu[i].program,&stu[i].cgpa);
		if(strcmp(stu[i].program,"BCA")==0)
		{
			if(maxbca<stu[i].cgpa)
			{
				maxstubca.prn=stu[i].prn;
				strcpy(maxstubca.name,stu[i].name);
				strcpy(maxstubca.program,stu[i].program);
				maxstubca.cgpa=stu[i].cgpa;
				maxbca=stu[i].cgpa;
				i=i+1;
			}
			else{
				i=i+1;
			}
		}
		else if(strcmp(stu[i].program,"BBA")==0)
		{
			if(maxbba<stu[i].cgpa)
			{
				maxstubba.prn=stu[i].prn;
				strcpy(maxstubba.name,stu[i].name);
				strcpy(maxstubba.program,stu[i].program);
				maxstubba.cgpa=stu[i].cgpa;
				maxbba=stu[i].cgpa;
				i=i+1;
			}
			else{
				i=i+1;
			}
		}
	}
	printf("PRN: %lld\n Name: %s\n Program: %s\n CGPA: %f\n",maxstubca.prn,maxstubca.name,maxstubca.program,maxstubca.cgpa);
	printf("PRN: %lld\n Name: %s\n Program: %s\n CGPA: %f",maxstubba.prn,maxstubba.name,maxstubba.program,maxstubba.cgpa);

}
