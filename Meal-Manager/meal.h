#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>
#include <time.h>

struct member
{
   char name[30];
   char date[30];
   double deposit;
   double remaining;
   double total_meal;
   double cost;
   int sl;
} add, view, update, edit, bazar;

char* date_fun()
{
   time_t d = time(NULL);
   struct tm *dt = localtime(&d);
   char* date = (char*)malloc(30 * sizeof(char));
   strftime(date, 30, "%x", dt);
   return date;
}

void final_meal(int n)
{
   FILE *deposit = NULL, *cost = NULL;
   deposit = fopen("data.dat", "r");
   cost = fopen("cost.dat", "r");
   double total_cost = 0, total_deposit = 0, total_meal = 0, meal_rate = 0, remaining = 0;
   while (fscanf(deposit, "%d %s %lf %lf\n", &view.sl, view.name, &view.deposit, &view.total_meal) != EOF)
   {
      total_meal += view.total_meal;
      total_deposit += view.deposit;
   }
   while (fscanf(cost, "%d %lf %s %s\n", &bazar.sl, &bazar.cost, bazar.name, bazar.date) != EOF)
   {
      total_cost += bazar.cost;
   }

   if (total_meal != 0)
      meal_rate = total_cost / total_meal;

up:
   system("cls");
   printf("-----------------------------------------------------------------------------------------\n");
   printf("DATE : %s", date_fun());
   printf("\t\t\tSTATEMENT\n");
   printf("-----------------------------------------------------------------------------------------\n\n");
   printf("SL No.   Name");
   int i;
   for (i = 4; i < 30; i++)
   {
      printf(" ");
   }
   printf("Deposit \t Total Meal \t Remaining\n");
   FILE *data = NULL;
   data = fopen("data.dat", "r");
   while (fscanf(data, "%d %s %lf %lf\n", &view.sl, view.name, &view.deposit, &view.total_meal) != EOF)
   {
      printf(" %d       %s", view.sl, view.name);
      for (i = strlen(view.name); i < 30; i++)
      {
         printf(" ");
      }
      remaining = view.deposit - meal_rate * view.total_meal;
      printf("%.1lf \t %.1lf \t\t% .1lf\n", view.deposit, view.total_meal, remaining);
   }
   printf("-----------------------------------------------------------------------------------------\n\n");

   fclose(data);
   fclose(cost);
   fclose(deposit);
   if (n == 1)
   {
      printf("\tTotal Deposit = %.2lf\n", total_deposit);
      printf("\tTotal Cost = %.2lf\n", total_cost);
      printf("\tTotal Meal = %.1lf\n", total_meal);
      printf("\tCurrent Meal Rate = %.2lf\n", meal_rate);

      printf("\n\n\t\tPress E to exit!");

      char ch = getche();
      if (ch == 'e')
         return;
      else
         goto up;
   }
}

void view_today_meal(int n)
{
up:
   system("cls");
   printf("----------------------------------------------------------------------------------------------\n\n");
   printf("DATE : %s", date_fun());
   printf("\t\t\tTODAY'S MEAL\n");
   printf("----------------------------------------------------------------------------------------------\n\n");
   printf("SL No.   Name");
   int i;
   for (i = 4; i < 30; i++)
   {
      printf(" ");
   }
   printf("BreakFast \t Launch \t Dinner\n\n");
   FILE *meal = NULL;
   double breakfast, launch, dinner;
   meal = fopen("meal.dat", "r");
   while (fscanf(meal, "%d %s %lf %lf %lf\n", &view.sl, view.name, &breakfast, &launch, &dinner) != EOF)
   {
      printf(" %d       %s", view.sl, view.name);
      for (i = strlen(view.name); i < 30; i++)
      {
         printf(" ");
      }
      printf("%.1lf \t\t %.1lf \t\t %.1lf\n", breakfast, launch, dinner);
   }

   fclose(meal);
   if (n == 1)
   {
      printf("\n\nPress E to exit!");

      char ch = getche();
      if (ch == 'e')
         return;
      else
         goto up;
   }
}

void update_meal()
{
up:
   system("cls");
   printf("To Update today's meal press 1 or exit press E\n");
   char ch = getchar();
   if (ch == '1')

   {
      FILE *data = NULL, *meal = NULL;
      FILE *new = NULL;
      data = fopen("data.dat", "r");
      new = fopen("new_.dat", "w");
      meal = fopen("meal.dat", "w");

      while (fscanf(data, "%d %s %lf %lf\n", &update.sl, update.name, &update.deposit, &update.total_meal) != EOF)
      {
         update.total_meal += 2.5;
         fprintf(new, "%d %s %.2lf %.2lf\n", update.sl, update.name, update.deposit, update.total_meal);
         fprintf(meal, "%d %s %.1lf %.1lf %.1lf\n", update.sl, update.name, 0.5, 1.0, 1.0);
      }
      fclose(data);
      fclose(meal);
      fclose(new);
      remove("data.dat");
      rename("new_.dat", "data.dat");
      system("cls");
      printf("Meal Update Successfully!");
      getche();
      return;
   }
   else if (ch == 'e')
      return;
   else
      goto up;
}

void stop_meal()
{
up:
   system("cls");
   system("color 3");
   char s[30];
   int choice, flag = 0;
   double breakfast, launch, dinner;
   view_today_meal(0);
   printf("----------------------------------------------------------------------------------------------\n\n");
   printf("\tEnter Name or SL No. or press E to exit: ");
   scanf("%s", s);
   if (!strcmp(s, "e"))
      return;
   printf("\tStop Meal -> \n");
   printf("\t\t1. Breakfast\n");
   printf("\t\t2. Launch\n");
   printf("\t\t3. Dinner\n");
   printf("\t\tEnter : ");
   scanf("%d", &choice);
   FILE *meal = fopen("meal.dat", "r"), *new_meal = NULL;
   new_meal = fopen("new_meal.dat", "w");
   FILE *data = fopen("data.dat", "r"), *new_data = NULL;
   new_data = fopen("new_data.dat", "w");
   while (fscanf(meal, "%d %s %lf %lf %lf\n", &edit.sl, edit.name, &breakfast, &launch, &dinner) != EOF)
   {
      char sl[30];
      sprintf(sl, "%d", edit.sl);
      if (!strcmp(s, sl) || !strcmp(s, edit.name))
      {
         if (choice == 1)
            breakfast = 0;
         else if (choice == 2)
            launch = 0;
         else if (choice == 3)
            dinner = 0;
         while (fscanf(data, "%d %s %lf %lf\n", &add.sl, add.name, &add.deposit, &add.total_meal) != EOF)
         {
            if (breakfast == 0 && edit.sl == add.sl)
               add.total_meal -= 0.5;
            else if ((launch == 0 || dinner == 0) && edit.sl == add.sl)
               add.total_meal -= 1.0;

            fprintf(new_data, "%d %s %lf %lf\n", add.sl, add.name, add.deposit, add.total_meal);
         }
      }
      else
         flag++;
      fprintf(new_meal, "%d %s %.1lf %.1lf %.1lf\n", edit.sl, edit.name, breakfast, launch, dinner);
   }
   fclose(data);
   fclose(new_data);
   fclose(meal);
   fclose(new_meal);
   if (flag == edit.sl)
   {
      system("cls");
      system("color 4");
      printf("\tMember doesn't exist\n\a");
      remove("new_meal.dat");
      remove("new_data.dat");
      getche();
      goto up;
   }
   else
   {
      remove("meal.dat");
      remove("data.dat");
      rename("new_meal.dat", "meal.dat");
      rename("new_data.dat", "data.dat");
      system("cls");
      printf("\tSuccessful!\n");
      getche();
      goto up;
   }
}

void manage_meal()
{
up:
   system("cls");
   printf("\n\n\t1. Statement\n");
   printf("\t2. View Today's Meal\n");
   printf("\t3. Update Meal\n");
   printf("\t4. Stop Meal\n");
   printf("\t5. Back\n");
   printf("Enter : ");
   char s[30];
   scanf("%s", s);
   if (!strcmp(s, "1"))
   {
      final_meal(1);
      goto up;
   }
   else if (!strcmp(s, "2"))
   {
      view_today_meal(1);
      goto up;
   }
   else if (!strcmp(s, "3"))
   {
      update_meal();
      goto up;
   }
   else if (!strcmp(s, "4"))
   {
      stop_meal();
      goto up;
   }
   else if (!strcmp(s, "5"))
   {
      return;
   }
   else
      goto up;
}
