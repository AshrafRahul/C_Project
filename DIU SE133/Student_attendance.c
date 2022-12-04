#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

char studentName[20][30];
int presentAttendance[20]={0};
int absentAttendance[20]={0};
int indexNumber=0;


void addStudent(){
    int i,num,add;
    if (indexNumber==0){
        printf("\n\nEnter how many students you want to add: ");
        fflush(stdin);
        scanf("%d",&num);

        printf("\n\n");
        for (i=0; i<num; i++){
            printf("Enter %d no student name: ",i+1);
            fflush(stdin);
            gets(studentName[i]);
            indexNumber++;
        }
    }

    else{
        printf("\n\nEnter how many students you want to add: ");
        fflush(stdin);
        scanf("%d",&num);

        add=indexNumber+num;

        printf("\n\n");

        for (i=indexNumber; i<add; i++){
            printf("Enter %d no student name: ",i+1);
            fflush(stdin);
            gets(studentName[i]);
            indexNumber++;
        }
    }
}


void takeAttendance(){
    int i;
    char ch;

    printf("\n\nEnter Y for present and N for absent\n");

    for (i=0; i<indexNumber; i++){
        repeate:
        printf("%d. %s is present: ",i+1,studentName[i]);
        fflush(stdin);
        scanf("%c",&ch);

        if (ch=='Y'||ch=='y'){
            presentAttendance[i]++;
        }

        else if (ch=='N'||ch=='n'){
            absentAttendance[i]++;
        }

        else{
            printf("Invalid character. Try again\n");
            goto repeate;
        }
    }
}


void checkAttendance(){
    int i;

    printf("\n\n    Total Present | Total Absent\n");

    for (i=0; i<indexNumber; i++){
        printf("%s",studentName[i]);
        printf("     %d           |   %d\n",presentAttendance[i],absentAttendance[i]);
    }
}


void removeStudent(){
    char name[30];
    printf("\n\nEnter student name to remove: ");
    fflush(stdin);
    gets(name);

    for (int i=0; i<indexNumber; i++){
        if (strcmp(name,studentName[i])==0){
            for (int j = i; j < indexNumber; j++){
                strcpy(studentName[j],studentName[j+1]);
                presentAttendance[i]=presentAttendance[i+1];
                absentAttendance[i]=absentAttendance[i+1];
            }
            indexNumber--;
            printf("\n%s student is removed\n",name);
            break;
        }

        else if(i==indexNumber-1){
            printf("This name is not exits\n");
        }
    }
}


struct user{
	char phone[50];
	char password[50];
};


int main(){
	struct user user;
	char filename[100],phone[100],password[100];
	int opt,choose;
	FILE *fp;

	printf("\nWhat do you want to do?");
	printf("\n\n\t1.Sign up");
	printf("\n\t2.Sign in");

	printf("\n\nPlease enter your choice: ");
	scanf("%d",&opt);

	if(opt == 1){
		system("cls");
		printf("Enter your phone number: ");
		fflush(stdin);
		scanf("%s",user.phone);

		printf("Enter your password: ");
		fflush(stdin);
		scanf("%s",user.password);

		stpcpy(filename,user.phone);
		fp=fopen(strcat(filename,".txt"),"w");
		fwrite(&user,sizeof(user),1,fp);

		if(fwrite != 0){
			printf("\n\nSuccesfully registered\n\n");
		}
	}

	else if(opt == 2){
		system("cls");
		printf("\nPhone No.: ");
		scanf("%s",&phone);

		printf("Password: ");
		scanf("%s",&password);

		fp = fopen(strcat(phone,".txt"),"r");

		if(fp == NULL){
            printf("Account number not registered");
		}

		else{
            fread(&user, sizeof(struct user),1,fp);
            fclose(fp);

            do{
                printf("\n--------Main Menu---------\n");
                printf("Enter 1 for add student\n");
                printf("Enter 2 for take attendance\n");
                printf("Enter 3 for check attendance\n");
                printf("Enter 4 for remove student\n");
                printf("Enter 5 for exit\n");
                printf("\n\nPlease choose any menu: ");
                fflush(stdin);
                scanf("%d",&choose);

                switch(choose){
                    case 1:
                        system("cls");
                        addStudent();
                        break;

                    case 2:
                        system("cls");
                        takeAttendance();
                        break;

                    case 3:
                        system("cls");
                        checkAttendance();
                        break;

                    case 4:
                        system("cls");
                        removeStudent();
                        break;

                    case 5:
                        system("cls");
                        exit(0);
                        break;
                }
            }while(choose!=5);
		}
	}


	return 0;
}
