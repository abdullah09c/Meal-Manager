#include "bazar.h"

void help()
{
   system("title Meal Manager");
   system("cls");
   system("color B");
   printf("\t\t\t\tTIPS\n");
   printf("\t---------------------------------------------------\n");
   printf("\t-> To increase or decrease font size press Ctrl+Mouse Scroll\n");
   printf("\t-> Press F11 for Fullscreen\n");
   getche();
}

void welcome(int i)
{
   FILE *acc = fopen("acc.dat", "r");
   int day;
   char name[30], date[30];
   fscanf(acc, "%d %s %s\n", &day, name, date);
   if (day < 10)
      printf("\tDATE : 0%d%s\n", day, date);
   else
      printf("\tDATE : %d%s\n", day, date);
   if (i == 1)
      printf("\tAssalamu Alaykum %s,\n\n", name);
}

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

void pass_change(FILE *password)
{
up:
   password = fopen("pass.dat", "r");
   char new_pass[25], pass[25];
   system("cls");
   printf("Enter old password : \n");
   scanf("%s", new_pass);
   fscanf(password, "%s", pass);

   if (!strcmp(new_pass, pass))
   {
      system("cls");
      printf("Enter New Password : \n");
      scanf("%s", pass);
      password = fopen("pass.dat", "w");
      fprintf(password, "%s", pass);
      fclose(password);
      system("cls");
      system("color 2");
      printf("Password Changed Successful!\n");
      getche();
      return;
   }
   else
   {
      fclose(password);
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

void account()
{
   help();
   system("cls");
   system("color 7");
   FILE *account_data = NULL, *password = NULL;
   account_data = fopen("acc.dat", "w");
   char pass[30];
   char manager_name[30], date[30];
   int day = 0;
   printf("\t\t\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2Meal Manager\xb2\xb2\xb2\xb2\xb2\xb2\xb2\xb2\n\n");

   printf("\tCreate New Account\n");
   printf("\t---------------------------------------------\n\n");
   printf("\tEnter Manager Name : ");
   scanf("%s", manager_name);
   printf("\tEnter New Password : ");
   scanf("%s", pass);
   printf("\tDate (DD/MM/YY) : ");
   scanf("%2d", &day);
   if (day > 31)
      day -= '/';
   scanf("%s", date);
   password = fopen("pass.dat", "w");
   fprintf(password, "%s", pass);
   fprintf(account_data, "%d %s %s\n", day, manager_name, date);
   fclose(password);
   fclose(account_data);
   system("cls");
   printf("\n\n\t\t");
   loading(4);
   system("cls");
   system("color 2");
   printf("\tAccount Created Successfully!\n\a");
   getche();
   printf("\tPlease Log In with password!\n");
   getche();
}

void clear_data()
{
there:
   system("cls");
   system("color 4");
   printf("Do you want to clear all data\n\a");
   printf("1.Yes\n2.No\n");
   char ch[30];
   scanf("%s", ch);
   if (!strcmp(ch, "1"))
   {
      system("cls");
      loading(4);
      remove("data.dat");
      remove("meal.dat");
      // remove("bazar.dat");
      system("cls");
      printf("Remove all data Successfully!\n\a");
      getche();
      return;
   }
   else if (!strcmp(ch, "2"))
      return;
   else
      goto there;
}

void remove_acc()
{
there:
   system("cls");
   system("color 4");
   printf("Do you want to remove the account\n\a");
   printf("1.Yes\n2.No\n");
   char ch[30];
   scanf("%s", ch);
   if (!strcmp(ch, "1"))
   {
      system("cls");
      loading(4);
      remove("data.dat");
      remove("meal.dat");
      remove("acc.dat");
      remove("pass.dat");
      // remove("bazar.dat");
      system("cls");
      printf("Removed Account Successfully!\n\a");
      getche();
      account();
      return;
   }
   else if (!strcmp(ch, "2"))
      return;
   else
      goto there;
}

int log_in(FILE *password)
{
up:

   password = fopen("pass.dat", "r");
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
