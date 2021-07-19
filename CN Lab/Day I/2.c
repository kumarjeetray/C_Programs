/*
Write   a   C   program   to   assign   values   to   each   members   of   the   following structure. 
Pass the populated structure to a function Using call-by-value andanother function using call-by-address and print the value of each member ofthe structure.
struct student_info{
	int roll_no;
	char name[50];
	float CGPA;
	struct dob age;
	};
*/
#include<stdio.h>
#include<string.h>
struct student_info{
	int roll_no;
	char name[50];
	float CGPA;
	struct dob{
		int age;
	}agecount;
	};


void pass_by_value(struct student_info stud)
{
	printf("Roll Number:%d\n",stud.roll_no);
	printf("Name:%s\n",stud.name);
	printf("CGPA:%f\n",stud.CGPA);
	printf("Age:%d\n",stud.agecount.age);
}

void pass_by_address(struct student_info *stud)
{
	printf("Roll Number:%d\n",stud->roll_no);
	printf("Name:%s\n",stud->name);
	printf("CGPA:%f\n",stud->CGPA);
	printf("Age:%d\n",stud->agecount.age);
}

int main()
{
	struct student_info stud;
	stud.roll_no = 170;
	strcpy(stud.name,"Kumarjeet");
	stud.CGPA = 9.35;
	stud.agecount.age = 19;
	pass_by_value(stud);
	pass_by_address(&stud);
	return 0;
}
