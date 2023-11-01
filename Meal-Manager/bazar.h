#include "member.h"

void add_bazar()
{
   system("cls");
   double bazar_cost;
   char name[30];
   FILE *cost = fopen("cost.dat", "a+");
   while (fscanf(cost, "%d %lf %s %s\n", &bazar.sl, &bazar.cost, bazar.name, bazar.date) != EOF)
   {
      bazar.sl;
   }

   printf("\tEnter Date (DD/MM/YY) : ");
   scanf("%s", bazar.date);
   printf("\tEnter Bazar Cost : $");
   scanf("%lf", &bazar_cost);
   printf("\tEnter Member Name : ");
   scanf("%s", name);
   
   fprintf(cost, "%d %.2lf %s %s\n", ++bazar.sl, bazar_cost, name, bazar.date);
   fclose(cost);
   system("cls");
   printf("Bazar is added Successfully!\n");
   getche();
}

void view_bazar()
{
   up:
   system("cls");
   printf("----------------------------------------------------------------------\n");
   printf("\t\t\tBAZAR\n");
   printf("----------------------------------------------------------------------\n\n");
   printf("SL No.   Name");
   int i;
   for (i = 4; i < 30; i++)
   {
      printf(" ");
   }
   printf("Bazar Cost\t Date\n");
   FILE *cost = NULL;
   cost = fopen("cost.dat", "r");
   while (fscanf(cost, "%d %lf %s %s\n", &view.sl, &view.cost, view.name, view.date) != EOF)
   {
      printf(" %d       %s", view.sl, view.name);
      for (i = strlen(view.name); i < 30; i++)
      {
         printf(" ");
      }
      printf("%.1lf \t\t%s\n", view.cost, view.date);
   }

   fclose(cost);
   printf("\n\nPress E to exit!");

   char ch = getche();
   if (ch == 'e')
      return;
   else
      goto up;
}

void manage_bazar()
{
up:
   system("cls");
   printf("\n\n\t1. Add Bazar\n");
   printf("\t2. View Bazar\n");
   printf("\t3. Back\n");
   printf("Enter : ");
   char s[30];
   scanf("%s", s);
   if (!strcmp(s, "1"))
   {
      add_bazar();
      goto up;
   }
   else if (!strcmp(s, "2"))
   {
      view_bazar();
      goto up;
   }
   else if (!strcmp(s, "3"))
   {
      return;
   }
   else
      goto up;
}