//***********************BISMILLAHIR RAHMANIR RAHIM***********************
//*This project is written in C.
//*Programmed by Abdullah Al Fuwad
//*CSTE, NSTU.
#include "stdcxx.h"

// void edit_meal()
// {
//    FILE *data = NULL, *today_meal = NULL, *new = NULL, *new_today_meal = NULL;
//    data = fopen("data.dat", "r");
//    new = fopen("new.dat", "w");
//    today_meal = fopen("meal.dat", "a+");
//    new_today_meal = fopen("new_meal.dat", "w");

//    printf("Enter Name or SL No to update meal : \n");
//    char s[30];
//    double new_meal;
//    scanf("%s", s);
//    while (fscanf(data, "%d %s %lf %lf\n", &update.sl, update.name, &update.deposit, &update.total_meal) != EOF)
//       ;
//    {
//       if (!strcmp("1", s) || !strcmp(update.name, s))
//       {
//          scanf("%lf", &new_meal);
//          update.total_meal += new_meal;
//          fprintf(new, "%d %s %lf %lf\n", update.sl, update.name, update.deposit, update.total_meal);
//          fprintf(new, "%");
//       }
//    }
//    getch();
// }

void menu()
{
up:
   system("color 3");
   system("cls");
   printf("\t\t******************[Meal Manager]*****************\n");
   printf("\t    **********************************************************\n\n");
   welcome(0);
   printf("\n\t1. View Today's Meal\n");
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
      clear_data();
      goto up;
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
   FILE *password = NULL;
   password = fopen("pass.dat", "r");
   char pass[30];
   fscanf(password, "%s\n", pass);
   if (!strcmp(pass, "-1") || password == NULL)
      account();


   system("color 9");
   system("title Meal Manager");
   system("cls");
    printf("\t\t******************[Meal Manager]*****************\n");
   printf("\t    **********************************************************\n\n");
   welcome(1);
   printf("\t1. Log In\n");
   printf("\t2. Change Password\n");
   printf("\t3. Remove the Account\n");
   printf("\t4. About\n");
   printf("\t5. Help\n");
   printf("\t6. Exit\n");
   printf("\tEnter : ");
   scanf("%s", s);
   if (!strcmp(s, "1"))
   {
      if (log_in(password) == 1)
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
      pass_change(password);
      goto top;
   }
   else if (!strcmp(s, "3"))
   {
      fclose(password);
      remove_acc();
      goto top;
   }
   else if (!strcmp(s, "4"))
   {
      system("cls");
      system("color 2");
      printf("\n\n\t\tPROGRAMMED BY \n");
      printf("\t\t[ABDULLAH AL FUWAD]\n");
      printf("\t\t[MUH2201006M]\n");
      printf("\t\tCOMPUTER SCIENCE AND TELECOMMUNICATION ENGINEERING,\n");
      printf("\t\tNOAKHALI SCIENCE AND TECHNOLOGY UNIVERSITY.\n");
      getche();
      goto top;
   }
   else if (!strcmp(s, "5"))
   {
      help();
      goto top;
   }
   else if (!strcmp(s, "6"))
   {
      fclose(password);
      system("exit");
   }
   else
   {
      system("cls");
      goto top;
   }

   return 0;
}