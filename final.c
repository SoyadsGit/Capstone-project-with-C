#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

void registration()
{
   FILE *file;
   char profession[15], id[15], fname[15], lname[15], password[15];

    printf("\nWhat is your profession?\n");
    printf("If you are a teacher type (TEACHER) or if you are a student type (STUDENT) :: ");
    scanf("%s",profession);

    printf("Enter your ID :: ");
    scanf("%s",id);

    printf("Enter first name :: ");
    scanf("%s",fname);

    printf("Enter last name :: ");
    scanf("%s",lname);

    printf("Enter password :: ");
    scanf("%s",password);

    file=fopen("record.txt","a");
    fprintf(file,"\n%s %s %s %s %s \n", profession, id, fname, lname, password);
    printf("                                      Registration was successful. Please Log In.\n");
    fclose(file);
}

int login()
{
    char id[15],password[15];
    printf("\nEnter your ID :: ");
    scanf("%s",id);;

    printf("Enter your password :: ");
    scanf("%s",password);

    int flag=0;
    char  prof2[15], id2[15], fname2[15], lname2[15], pass2[15];
    FILE *file;
    FILE *file2;
    file=fopen("record.txt","r");
    while(fscanf(file,"\n%s %s %s %s %s\n", prof2, id2, fname2, lname2, pass2)!= EOF)
    {
        if((strcmp(id2,id)==0) && (strcmp(pass2,password)==0))
            {
                flag=1;
                printf("                                                Welcome %s %s\n",fname2, lname2);
                file2=fopen("login.txt","w");
                fprintf(file2,"\n%s %s %s %s\n", prof2, id2, fname2, lname2);

                if(strcmp(prof2,"TEACHER")==0)
                {
                    return 1;
                }
                else if(strcmp(prof2,"STUDENT")==0)
                {
                    return 2;
                }
                else
                    printf("\n");

                fclose(file2);
            }
        else
            flag=2;
    }

    if(flag==2)
              printf("\n \n                                           Invalid credentials! Please try again.");

    fclose(file);
}

void add_project()
{
    FILE *file;
    char pro_title[100], source[100], id[15];
    char res[50] ="not_evaluated_yet.";

    printf("\nPlease Enter your student ID :: ");
    scanf("%s", id);
    strcat(id,".txt");

    printf("Write the title code of your Project :: ");
    scanf("%s", pro_title);

    printf("Type your source code link here :: ");
    scanf("%s", source);

    int length = strlen(source);
    int i;
    for (i =0; i<length; i++)
    {
        if(source[i]==',')
        {
            printf("\nYou can't insert a comma while taking the source code URL");
        }
    }

    file=fopen(id,"a");
    fprintf(file,"\n%s %s %s\n", pro_title, source, res);
    if(file!=NULL)
    printf("                                                   Record written successfully\n");
    fclose(file);
}

void teacher()
{
    char id[15];
    printf("\nWhich project do you wants to see? Please enter the student ID :: ");
    scanf("%s", id);
    strcat(id,".txt");

    int ch;
    char pt[20], sc[50], gd[50];
    char pt2[20], sc2[50], gd2[50], gd3[50];

    FILE *file;
    FILE *file2;
    file=fopen(id,"r");

    if(file==NULL)
        printf("\n Project not found");
    else
        {
        while(fscanf(file,"%s %s %s\n", pt, sc, gd)!= EOF)
            {
                printf("Project title code :: %s\n",pt);
                printf("Project url :: %s\n",sc);
                printf("Grade :: %s\n",gd);
            }

            printf("\nDo you wants to evaluate? (yes=1 & no=0) :: ");
            scanf("%d",&ch);
            if(ch==1)
            {
                file2=fopen(id,"w");
                printf("\nWhat grade do you wants to give? :: ");
                scanf("%s",gd2);
                fprintf(file2,"%s %s %s\n", pt, sc, gd2);
                fclose(file2);
                printf("Grade added successfully.");
            }

            fclose(file);
        }
}

void result()
{
    char id[10];
    printf("\nEnter your student id to see your result :: ");
    scanf("%s", id);
    strcat(id,".txt");

    FILE *file;
    file=fopen(id,"r");
    char pt[20], sc[50], res[50];
    if(file==NULL)
        printf("\nProject not found");
    else
        {
        while(fscanf(file,"%s %s %s\n", pt, sc, res)!= EOF)
            {
                printf("\nYour grade is = %s",res);
            }
        fclose(file);
        }
}

void logout()
{
    char prof[15]="NULL";
                     char id[15]="NULL";
                     char fname[15]="NULL";
                     char lname[15]="NULL";

                     FILE *file;
                     file=fopen("login.txt","w");
                     fprintf(file,"\n%s %s %s %s\n", prof, id, fname, lname);
                     fclose(file);
                printf("\n \n                                                  Logout successful.");
}

void menu()
{
    int ch, ch2, ch3, ch4, ch5, ch6;
    int res;
    printf("\n\nWants to REGISTRATION again?\n");
    printf("Enter (1) for REGISTRATION or (0) to LOGIN :: ");
    scanf("%d",&ch);
    if(ch==1)
        registration();
        system("CLS");

    printf("\nDo you wants to LOGIN now?\n");
    printf("Enter (1) for LOGIN or (0) to skip :: ");
    scanf("%d",&ch2);
    if(ch2==1)
    {
        res = login();
        if(res==2)
        {
            printf("\n\nDo you wants to add a new project?\n");
            printf("Enter (1) to add new project or (0) to skip :: ");
            scanf("%d",&ch3);
            if(ch3==1)
                add_project();

            printf("\n\nDo you wants to see your grade?\n");
            printf("Enter (1) for YES or (0) to skip :: ");
            scanf("%d",&ch4);
            if(ch4==1)
                result();

            printf("\n\nDo you want to LOGOUT?\n");
            printf("Enter (1) for YES or (0) to skip :: ");
            scanf("%d",&ch5);
            if(ch5==1)
            {
                   logout();
            }
            else
                {
                    system("CLS");
                    menu();
                }
        }

        else if(res==1)
        {
            teacher();

            printf("\n\nDo you want to LOGOUT?\n");
            printf("Enter (1) for YES or (0) to skip :: ");
            scanf("%d",&ch6);
            if(ch6==1)
            {
                logout();
            }
        }

        else
            {
                system("CLS");
                menu();
            }
    }
}

void main()
{
     system("color 9F");
    printf("                                                 <---MAIN MENU--->\n");
    printf("\n");
    printf("                    'IF YOU'RE NOT REGISTERED YET, PLEASE REGISTER FIRST TO LOGIN YOURSELF'\n");

    int ch, ch2, ch3, ch4, ch5, ch6;
    int res;
    printf("\n\nDo you wants to REGISTRATION now?\n");
    printf("Enter (1) for REGISTRATION or (0) to LOGIN :: ");
    scanf("%d",&ch);
    if(ch==1)
        registration();
        system("CLS");

    printf("\nDo you wants to LOGIN now?\n");
    printf("Enter (1) for LOGIN or (0) to skip :: ");
    scanf("%d",&ch2);
    if(ch2==1)
    {
        res = login();
        if(res==2)
        {
            printf("\n\nDo you wants to add a new project?\n");
            printf("Enter (1) to add new project or (0) to skip :: ");
            scanf("%d",&ch3);
            if(ch3==1)
                add_project();

            printf("\n\nDo you wants to see your grade?\n");
            printf("Enter (1) for YES or (0) to skip :: ");
            scanf("%d",&ch4);
            if(ch4==1)
                result();

            printf("\n\nDo you want to LOGOUT?\n");
            printf("Enter (1) for YES or (0) to skip :: ");
            scanf("%d",&ch5);
            if(ch5==1)
            {
                   logout();
            }
            else
                {
                    system("CLS");
                    menu();
                }
        }

        else if(res==1)
        {
            teacher();

            printf("\n\nDo you want to LOGOUT?\n");
            printf("Enter (1) for YES or (0) to skip :: ");
            scanf("%d",&ch6);
            if(ch6==1)
            {
                logout();
            }
            else
                {
                    system("CLS");
                    menu();
                }
        }

        else
            printf("Please enter your valid identity!");
    }
}
