//***********************BISMILLAHIR RAHMANIR RAHIM***********************
//*This project is written in C.
//*Programmed by Abdullah Al Fuwad
//*CSTE, NSTU.
#include "stdcxx.h"

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

   fscanf(old, "%s", pass);

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

int log_in(FILE *password)
{
up:
   char s[25], pass[25];
   system("cls");
   printf("Enter Password : ");
   scanf("%s", s);
   fscanf(password, "%s", pass);
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

/*void edit_meal()
{
   FILE *data = NULL, *today_meal = NULL, *new = NULL, *new_today_meal = NULL;
   data = fopen("data.dat", "r");
   new = fopen("new.dat", "w");
   today_meal = fopen("meal.dat", "a+");
   new_today_meal = fopen("new_meal.dat", "w");

   printf("Enter Name or SL No to update meal : \n");
   char s[30];
   double new_meal;
   scanf("%s", s);
   while (fscanf(data, "%d %s %lf %lf\n", &update.sl, update.name, &update.deposit, &update.total_meal) != EOF)
      ;
   {
      if (!strcmp("1", s) || !strcmp(update.name, s))
      {
         scanf("%lf", &new_meal);
         update.total_meal += new_meal;
         fprintf(new, "%d %s %lf %lf\n", update.sl, update.name, update.deposit, update.total_meal);
         fprintf(new, "%");
      }
   }
   getch();
}
*/

void menu()
{
up:
   system("color 9");
   system("cls");
   printf("\t\t******************[Meal Manager]*****************\n");
   printf("\t    **********************************************************\n\n");

   printf("\t1. View Today's Meal\n");
   printf("\t2. Manage Meal\n");
   printf("\t3. Manage Member\n");
   printf("\t4. Bazar\n");
   printf("\t5. Clear All Data\n");
   printf("\t6. Log Out\n");
   printf("\tEnter : ");
   char choice[100];
   scanf("%s", choice);
   if (!strcmp(choice, "1"))
   {
      today_meal();
      goto up;
   }
   else if (!strcmp(choice, "2"))
   {
      manage_meal();
      goto up;
   }

   else if (!strcmp(choice, "3"))
   {
      manage_member();
      goto up;
   }

   else if (!strcmp(choice, "4"))
   {
      manage_bazar();
      goto up;
   }

   else if (!strcmp(choice, "5"))
   {
   there:
      system("cls");
      system("color 4");
      printf("Do you want to clear all data\n\a");
      printf("1.Yes\n2.No\n");
      char ch = getchar();
      if (ch == '1')
      {
         system("cls");
         loading(4);
         remove("data.dat");
         remove("meal.dat");
         system("cls");
         printf("Remove all data Successfully!\n\a");
         getche();
         goto up;
      }
      else if (ch == '2')
         goto up;
      else
         goto there;
   }
   else if (!strcmp(choice, "6"))
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
