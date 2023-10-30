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
   data = fopen("data.dat", "a+");
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
   fprintf(data, "%d %s %.2lf %.2lf\n", ++add.sl, s, add.deposit, 0.0);
   fclose(data);
   system("cls");
   printf("Member is added successfully\n");
   getche();
   return;
}

void delete_member()
{
   getch();
}

void deposit()
{
   getch();
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