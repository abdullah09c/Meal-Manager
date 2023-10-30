#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <conio.h>

struct member
{
   char name[20];
   double deposit;
   double remaining;
   double total_meal;
   int sl;
} add, view, update, edit, bazar;

void view_total_meal()
{
up:
   system("cls");
   printf("------------------------------------------------------------\n");
   printf("\t\t\tTotal Meal\n");
   printf("------------------------------------------------------------\n\n");
   printf("SL No.   Name");
   int i;
   for (i = 4; i < 30; i++)
   {
      printf(" ");
   }
   printf("Deposit \t Total Meal\n");
   FILE *data = NULL;
   data = fopen("data.dat", "r");
   while (fscanf(data, "%d %s %lf %lf\n", &view.sl, view.name, &view.deposit, &view.total_meal) != EOF)
   {
      printf(" %d       %s", view.sl, view.name);
      for (i = strlen(view.name); i < 30; i++)
      {
         printf(" ");
      }
      printf("%.1lf \t %.1lf\n", view.deposit, view.total_meal);
   }

   fclose(data);
   printf("\n\nPress E to exit!");

   char ch = getche();
   if (ch == 'e')
      return;
   else
      goto up;
}

void today_meal()
{
up:
   system("cls");
   printf("------------------------------------------------------------\n");
   printf("\t\t\tToday's Meal\n");
   printf("------------------------------------------------------------\n\n");
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
   printf("\n\nPress E to exit!");

   char ch = getche();
   if (ch == 'e')
      return;
   else
      goto up;
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
      new = fopen("new.dat", "w");
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
      rename("new.dat", "data.dat");
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
   getch();
}

void manage_meal()
{
up:
   system("cls");
   printf("\n\n\t1. View Total Meal\n");
   printf("\t2. View Today's Meal\n");
   printf("\t3. Update Meal\n");
   printf("\t4. Stop Meal\n");
   printf("\t5. Back\n");
   printf("Enter : ");
   char s[30];
   scanf("%s", s);
   if (!strcmp(s, "1"))
   {
      view_total_meal();
      goto up;
   }
   else if (!strcmp(s, "2"))
   {
      today_meal();
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
