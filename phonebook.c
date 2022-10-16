#include <stdio.h>
#include <windows.h>

void menu();
void showContact();
void createContact();
void deleteContact();
void searchContact();
struct Contact
   {
      char str[500];
      char num[15];
   };

int main()
{
	system("cls");
	menu();
	return 0;
}

void menu()
	{
		system("color 3");
		system("color 5a");
		printf("////////////////////////////////////////////////////////////\n");
		printf("::::::::::: Welcome in to the PhoneBook Services :::::::::::\n");
		printf("\tPress 1 : For Show Contact\n \tPress 2 : For Create a new Contact\n");
		printf("\tPress 3 : For Delete a contact\n \tPress 4 : For Search a Contact\n");
		printf("\tPress 5 : For Menu\n\n");
		printf("Press any key to start :- ");
		int user_Input;
		scanf("%d", &user_Input);
		switch (user_Input)
		{
			case 1:
				showContact();
				break;
			case 2:
				createContact();
				break;
			case 3:
				deleteContact();
				break;
			case 4:
				searchContact();
				break;
			case 5:
				menu();
				break;
			default:
				printf("Something went wrong please again check menu.....\n\n");
				menu();
				break;
		}
	}

void showContact()
	{
		system("cls");
		printf("////////////////////////////////////////////////////////////\n");
		printf(":::::::::::::::::::::: Contact List ::::::::::::::::::::::::\n");
		struct Contact MyContact;
		FILE *fptr;
		if (fptr = fopen("ContactBook.txt", "r")){
         while(fscanf(fptr,"%s %s", MyContact.str, MyContact.num)!=EOF){
         	printf("Name: %s\t Number: %s\n", MyContact.str, MyContact.num);
      	}
		}
		printf("\n");
		fclose(fptr);
		menu();
	}

void createContact()
	{
		system("cls");
		printf("////////////////////////////////////////////////////////////\n");
		printf(":::::::::::::::::::::: New Contact ::::::::::::::::::::::::\n");
		struct Contact MyContact;
		FILE *fptr;
		fptr = fopen("ContactBook.txt", "a");
		printf("Enter the name :- ");
		scanf("%s", &MyContact.str);
		printf("Enter the Number :- ");
		scanf("%s", MyContact.num);
		fprintf(fptr, "\n%s %s", MyContact.str, MyContact.num);
		fclose(fptr);
		printf("Contact created.......\n\n");
		menu();
	}

void deleteContact()
	{
		system("cls");
		printf("////////////////////////////////////////////////////////////\n");
		printf(":::::::::::::::::::::: Delete Contact ::::::::::::::::::::::::\n");
		struct Contact MyContact;
		FILE *fptr, *fptr1;
		char Nam[500];
		printf("Enter the Name you want to delete :- ");
		scanf("%s", &Nam);
		fptr = fopen("ContactBook.txt", "r");
		fptr1 = fopen("temp.txt", "w");
   		while(fscanf(fptr,"%s %s", MyContact.str, MyContact.num)!=EOF){
      		if(strcmp(Nam,MyContact.str)==0)
			{
				printf("Contact deleted.......\n\n");
        		continue;
			}
			fprintf(fptr1, "%s %s\n", MyContact.str, MyContact.num);
		}
		fclose(fptr);
		fclose(fptr1);
		fptr = fopen("ContactBook.txt", "w");
		fptr1 = fopen("temp.txt", "r");
		while(fscanf(fptr1,"%s %s", MyContact.str, MyContact.num)!=EOF){
      		fprintf(fptr, "%s %s\n", MyContact.str, MyContact.num);
   		}
   		fclose(fptr);
   		fclose(fptr1);
   		remove("temp.txt");
		menu();
	}

void searchContact()
	{
		system("cls");
		printf("////////////////////////////////////////////////////////////\n");
		printf("::::::::::::::::::::: Search Contact :::::::::::::::::::::::\n");
		struct Contact MyContact;
		FILE *fptr;
		char Nam[500];
		printf("Enter the Name you want to search :- ");
		scanf("%s", &Nam);
		fptr = fopen("ContactBook.txt", "r");
   		while(fscanf(fptr,"%s %s", MyContact.str, MyContact.num)!=EOF){
      		if(strcmp(Nam,MyContact.str)==0)
			{
				 printf("Contact searched.......\n");
        		 printf("Name: %s\t Number: %s\n\n", MyContact.str, MyContact.num);
			}
		}
		menu();
	}