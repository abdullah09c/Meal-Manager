#include "member.h"

void add_bazar()
{
   getch();
}

void view_bazar()
{
   getch();
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