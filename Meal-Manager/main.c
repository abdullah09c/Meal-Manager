//***********************BISMILLAHIR RAHMANIR RAHIM***********************
//*This project is written in C.
//*Programmed by Abdullah Al Fuwad
//*CSTE, NSTU.
#include "stdcxx.h"

void menu()
{
up:
   system("color 3");
   system("cls");
   printf("\t\t******************[Meal Manager]*****************\n");
   printf("\t    **********************************************************\n\n");
   welcome(0);
   printf("\n\n\t1. Manage Meal\n");
   printf("\t2. Manage Member\n");
   printf("\t3. Bazar\n");
   printf("\t4. Clear All Data\n");
   printf("\t5. Log Out\n");
   printf("\tEnter : ");
   char choice[100];
   scanf("%s", choice);
   if (!strcmp(choice, "1"))
   {
      manage_meal();
      goto up;
   }

   else if (!strcmp(choice, "2"))
   {
      manage_member();
      goto up;
   }

   else if (!strcmp(choice, "3"))
   {
      manage_bazar();
      goto up;
   }

   else if (!strcmp(choice, "4"))
   {
      clear_data();
      goto up;
   }
   else if (!strcmp(choice, "5"))
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
   printf("\t3. Forget Password\n");
   printf("\t4. Remove the Account\n");
   printf("\t5. About\n");
   printf("\t6. Help\n");
   printf("\t7. Exit\n");
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
      pass_change(password, 1);
      goto top;
   }
   else if (!strcmp(s, "3"))
   {
      forget_pass();
      goto top;
   }
   else if (!strcmp(s, "4"))
   {
      fclose(password);
      remove_acc();
      goto top;
   }
   else if (!strcmp(s, "5"))
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
   else if (!strcmp(s, "6"))
   {
      help();
      goto top;
   }
   else if (!strcmp(s, "7"))
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