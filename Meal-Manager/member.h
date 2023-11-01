#include "meal.h"

void add_member()
{
   system("cls");
   system("color 4");
   printf("Do not write name using space!");
   getche();
   new :

       system("cls");
   system("color 9");
   printf("Enter Name : ");
   char s[30];
   scanf("%s", s);

   // creating a file to store data.
   FILE *data = NULL;
   data = fopen("data/data.dat", "a+");
   while (fscanf(data, "%d %s %lf %lf\n", &add.sl, add.name, &add.deposit, &add.total_meal) != EOF)
   {
      if (!strcmp(s, add.name))
      {
         system("cls");
         system("color 4");
         printf("This member already has in the list!\a");
         getche();
         goto new;
      }
   }

   printf("Enter deposit : $");
   scanf("%lf", &add.deposit);
   add.remaining = add.deposit;
   fprintf(data, "%d %s %.2lf %.2lf\n", ++add.sl, s, add.deposit, 0.0);
   fclose(data);
   system("cls");
   printf("Member is added successfully\n");
   getche();
   return;
}

void delete_member()
{
up:
   system("cls");
   system("color 3");
   char s[30];
   int flag = 0;
   view_today_meal(0);
   printf("----------------------------------------------------------------------------------------------\n\n");
   printf("\tEnter Name or SL No. or press E to exit: ");
   scanf("%s", s);
   if (!strcmp(s, "e"))
      return;
   FILE *data = fopen("data/data.dat", "r"), *new_data = NULL;
   new_data = fopen("data/new_data.dat", "w");
   while (fscanf(data, "%d %s %lf %lf\n", &edit.sl, edit.name, &edit.deposit, &edit.total_meal) != EOF)
   {
      char sl[30];
      sprintf(sl, "%d", edit.sl);
      if (!strcmp(s, sl) || !strcmp(s, edit.name))
      {
         flag++;
         continue;
      }
      else
         fprintf(new_data, "%d %s %lf %lf\n", edit.sl, edit.name, edit.deposit, edit.total_meal);
   }
   fclose(data);
   fclose(new_data);

   // removing today's meal
   FILE *meal = fopen("data/meal.dat", "r"), *new_meal = NULL;
   new_meal = fopen("data/new_meal.dat", "w");
   if (flag > 0)
   {
      double breakfast, launch, dinner;
      while (fscanf(meal, "%d %s %lf %lf %lf\n", &edit.sl, edit.name, &breakfast, &launch, &dinner) != EOF)
      {
         char sl[30];
         sprintf(sl, "%d", edit.sl);
         if (!strcmp(s, sl) || !strcmp(s, edit.name))
         {
            flag++;
            continue;
         }
         else
            fprintf(new_meal, "%d %s %lf %lf %lf\n", edit.sl, edit.name, breakfast, launch, dinner);
      }
   }
   fclose(meal);
   fclose(new_meal);

   if (flag == 0)
   {
      system("cls");
      system("color 4");
      printf("\tMember doesn't exist\n\a");
      remove("data/new_data.dat");
      remove("data/new_meal.dat");
      getche();
      goto up;
   }
   else
   {
      remove("data/data.dat");
      remove("data/meal.dat");
      rename("data/new_data.dat", "data/data.dat");
      rename("data/new_meal.dat", "data/meal.dat");
      system("cls");
      printf("\tSuccessful!\n");
      getche();
      goto up;
   }
}

void deposit()
{
   {
   up:
      system("cls");
      system("color 3");
      char s[30];
      int flag = 0;
      final_meal(0);
      printf("\tEnter Name or SL No. or press E to exit: ");
      scanf("%s", s);
      if (!strcmp(s, "e"))
         return;
      FILE *data = fopen("data/data.dat", "r"), *new_data = NULL;
      new_data = fopen("data/new_data.dat", "w");
      while (fscanf(data, "%d %s %lf %lf\n", &edit.sl, edit.name, &edit.deposit, &edit.total_meal) != EOF)
      {
         char sl[30];
         sprintf(sl, "%d", edit.sl);
         if (!strcmp(s, sl) || !strcmp(s, edit.name))
         {
            double money;
            printf("\tAdd money : $");
            scanf("%lf", &money);
            edit.deposit += money;
         }
         else
            flag++;
         fprintf(new_data, "%d %s %lf %lf\n", edit.sl, edit.name, edit.deposit, edit.total_meal);
      }
      fclose(data);
      fclose(new_data);

      if (flag == edit.sl)
      {
         system("cls");
         system("color 4");
         printf("\tMember doesn't exist\n\a");
         remove("data/new_data.dat");
         getche();
         goto up;
      }
      else
      {
         remove("data/data.dat");
         rename("data/new_data.dat", "data/data.dat");
         system("cls");
         printf("\tSuccessful!\n");
         getche();
         goto up;
      }
   }
}

void manage_member()
{
up:
   system("cls");
   printf("\n\n\t1. Add New Member\n");
   printf("\t2. Delete Existing Member\n");
   printf("\t3. Deposit\n");
   printf("\t4. Back\n");
   printf("Enter : ");
   char s[30];
   scanf("%s", s);
   if (!strcmp(s, "1"))
   {
      add_member();
      goto up;
   }
   else if (!strcmp(s, "2"))
   {
      delete_member();
      goto up;
   }
   else if (!strcmp(s, "3"))
   {
      deposit();
      goto up;
   }
   else if (!strcmp(s, "4"))
   {
      return;
   }
   else
      goto up;
}