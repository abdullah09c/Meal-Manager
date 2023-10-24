//***********************BISMILLAHIR RAHMANIR RAHIM***********************
//*This project is written in C.
//*Programmed by Abdullah Al Fuwad
//*CSTE, NSTU.
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

void loading(int time)
{
   int i, j;
   printf("Loading");
   for (j = 0; j < 7; j++)
   {
      for (i = 0; i < time * 100000000; i++)
         i = i;
      printf(".");
   }
}

void pass_change(FILE *old)
{
up:
   char new_pass[25], pass[25];
   system("cls");
   printf("Enter old password : \n");
   scanf("%s", new_pass);
   FILE *new;
   new = fopen("new.dat", "w");

   while (fscanf(old, "%s", pass) != EOF)
      ;
   {
      if (!strcmp(new_pass, pass))
      {
         system("cls");
         printf("Enter New Password : \n");
         scanf("%s", pass);
         fprintf(new, "%s", pass);
         fclose(old);
         remove("pass.dat");
         fclose(new);
         rename("new.dat", "pass.dat");
         system("cls");
         system("color 2");
         printf("Password Changed Successful!\n");
         getch();
         return;
      }
      else
      {
         fclose(old);
         fclose(new);
         remove("new.dat");
         system("cls");
         system("color 4");
         printf("Password not matched!\a\n\n");
         printf("Press any key to try again Or press E to goto homepage\n");
         char ch;
         ch = getche();
         if (ch == 'e')
         {
            return;
         }
         else
            goto up;
      }
   }
}

int log_in(FILE *password)
{
up:
   char s[25], pass[25];
   system("cls");
   printf("Enter Password : ");
   scanf("%s", s);
   while (fscanf(password, "%s", pass) != EOF)
   {
      if (strcmp(pass, s) == 0)
      {
         fclose(password);
         system("cls");
         system("color 2");
         printf("Password Matched!\n");
         // loading....
         loading(4);
         return 1;
      }
      else
      {
         fclose(password);
         system("cls");
         system("color 4");
         printf("Wrong Password!\a\n");
         printf("Press any key to continue or Press E to goto homepage\n");
         char ch;
         ch = getche();
         if (ch == 'e')
            return 0;
         else
            goto up;
      }
   }
}

void view_meal()
{
   getch();
}

void update_meal()
{
   getch();
}
void add_member()
{
   getch();
}
void delete_member()
{
   getch();
}
void add_bazar()
{
   getch();
}
void view_bazar()
{
   getch();
}

void menu()
{
up:
   system("color 9");
   system("cls");
   printf("\t\t******************[Meal Manager]*****************\n");
   printf("\t    **********************************************************\n\n");
   printf("\t1. View Meal\n");
   printf("\t2. Update Meal\n");
   printf("\t3. Add New Member\n");
   printf("\t4. Delete Member\n");
   printf("\t5. Add Bazar\n");
   printf("\t6. View Bazar\n");
   printf("\t7. Log Out\n");
   printf("\tEnter : ");
   char choice[100];
   scanf("%s", choice);
   if (!strcmp(choice, "1"))
      view_meal();
   else if (!strcmp(choice, "2"))
      update_meal();
   else if (!strcmp(choice, "3"))
      add_member();
   else if (!strcmp(choice, "4"))
      delete_member();
   else if (!strcmp(choice, "5"))
      add_bazar();
   else if (!strcmp(choice, "6"))
      view_bazar();
   else if (!strcmp(choice, "7"))
      return;
   else
      goto up;
}

int main()
{

   char s[100];
top:
   FILE *pass;
   pass = fopen("pass.dat", "r");
   system("color 7");
   system("title Meal Manager");
   system("cls");
   printf("\t\t----------[Meal Manager]------------\n");
   printf("\t    ---------------------------------------------\n\n");
   printf("\t1. Log In\n");
   printf("\t2. Change Password\n");
   printf("\t3. About\n");
   printf("\t4. Exit\n");
   printf("\tEnter : ");
   scanf("%s", s);
   if (!strcmp(s, "1"))
   {
      if (log_in(pass) == 1)
      {
         menu();
         goto top;
      }
      else
      {
         goto top;
      }
   }
   else if (!strcmp(s, "2"))
   {
      pass_change(pass);
      goto top;
   }
   else if (!strcmp(s, "3"))
   {
      system("cls");
      printf("Abdullah Al Fuwad");
      getch();
      goto top;
   }
   else if (!strcmp(s, "4"))
      system("exit");
   else
   {
      system("cls");
      goto top;
   }

   return 0;
}