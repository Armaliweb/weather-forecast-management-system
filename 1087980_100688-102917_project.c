
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define s 50
#define l 50
int login(FILE *fptr, char email[], char password[], char question[], char answer[])
{
char useremail[l];
char userpassword[l];
char useranswer[l];
int i, index, user1, index_2, flag = 0, flag_2;
int j;
FILE *out;
int choice;
char day_FILE, day[s][l];
int month[s][l], year[s][l], temperature[s][l], maxUV_index[s][l], humidity[s][l], wind_speed[s][l]; printf("please enter your email:\n");
scanf("%s", useremail); for (i = 0; i < s; i++)
{
if (strcmp(useremail, email) == 0)
{
flag = 1;
index = i;
}
} if (flag != 1)
{
printf("there is no account under that email");
sign_up(fptr, email, password, question, answer);
} 
else
{
printf("please enter your password:\n");
scanf("%s", userpassword);
}
if (strcmp(userpassword, password) == 0)
{
forecast_data(fptr, out, choice, day_FILE, day, month, year, temperature, maxUV_index, humidity, wind_speed);
}
else
{ if (strlen(userpassword) != strlen(password))
{
printf("incorrect password");
} else
{
for (j = 0; j < strlen(password); j++)
{
if (userpassword[j] == password[j + 1] && userpassword[j + 1] == password[j])
{
index_2 = j;
}
}
printf("answer %s ", question);
scanf("%s", useranswer); if (strcmp(useranswer, answer) == 0)
{
Update_delete_forecast_data( &day, &month, &year);
}
return user1;
}
}
}
void sign_up(FILE *fptr, char *email, char *password, char *question , char *answer)
{ 
char useremail[l], userpassword[l], userquestion[l], useranswer[l];
int i;
printf("this is the sign up:\n");
printf("please enter your email:\n");
scanf("%s", useremail);
printf("please enter your password:\n");
scanf("%s", userpassword);
printf("please enter a secret question:\n");
scanf("%s", userquestion);
printf("please answer the secret question you wrote :\n");
scanf("%s", useranswer);
for (i = 0; i < s; i++)
{
if (strcmp(useremail, &email[i]) != 0)
{
printf("this email is already used ");
}
else
{
fprintf(fptr ,"%s\t%s\t%s\t%s\t\n", useremail, userpassword, userquestion, useranswer); fclose(fptr);
}
}
}
void log_out()
{ int r;
printf("do you want to exit ?:\n1)YES 2)NO");
scanf("%d", &r);
if (r == 1)
exit(0);
}
void change_userinfo(FILE *fptr, FILE *out, char email[], char password[], char pname[], int index, char question[], char answer[])
{ char newname[s][l], newemail[s][l], newpassword[s][l], newquestion[s][l], newanswer[s][l];
char userpassword[s][l];
int choice;
int flag = 0, i, d; printf("\nPlease reenter your password: ");
scanf("%s", *userpassword);
if (strcmp(*userpassword, &password[index] )!= 0)
{
flag = 1;
}
printf("Wrong password, try again: ");
scanf("%s", *userpassword); if (flag != 1)
{
printf("\n1)Change your Name:\n2)Change E-mail:\n3)Change Password:\n");
scanf("%d", &choice);
}
while (d == 1)
{
switch (choice)
{
case 1:
printf("\nUpdated your name: ");
scanf("%s", *newname);
strcpy(pname, *newname);
break; case 2:
printf("\nUpdated email: ");
scanf("%s", *newemail);
strcpy(email, *newemail);
break;
case 3:
printf("\nUpdated password: ");
scanf("%s", *newpassword);
strcpy(password, *newpassword);
break; case 4:
printf("\nUpdated secret quetion: ");
scanf("%s", *newquestion);
strcpy(question, *newquestion);
break; case 5:
printf("\nUpdated answer: ");
scanf("%s", *newanswer);
strcpy(answer, *newanswer);
break;
}
printf("do you want to change anything else:\n 1) YES 2)NO");
scanf("%d", &d);
}
fprintf(out, "%s/t%s/t%s/t%s/t%s/t", *newname, *newemail, *newpassword, *newquestion, *newanswer);
fclose(out);
}





void display_forecast(FILE *fptr, FILE *out, int choice, char day_FILE, char** day, int** month, int** year, int** temperature, int** maxUV_index, int** humidity, int** wind_speed)
{
int average;
int p = 248;
fptr = fopen("forecast.txt", "r");
if (fptr == NULL)
{
printf("Error opening the file");

}
else
{
printf("Day:\t Month:\t Year:\t Temp:\t UV:\t Humidity:\t Wind Speed:\n");
for (int i = 0; i < 3; i++)
{
fscanf(fptr, "%d %d %d %d %d %d %d", day[i], month[i], year[i], temperature[i], maxUV_index[i], humidity[i], wind_speed[i]);
printf("%d\t %d\t %d\t %d%cC\t %d\t %d %%\t %dkm/h\n", *day[i], *month[i], *year[i], *temperature[i], p, *maxUV_index[i], *humidity[i], *wind_speed[i]);
}
fclose(fptr);
}
}



void temp_average(int *temp)
{
float average;
int sum = 0;
int m;
char c = 248;
for (int i = 0; i < 3; i++)
{
sum += temp[i];
}
for (int i = 0; i < 3; i++)
{
m = temp[i];
printf("%d\n", m);
}
average = sum / 3;
printf("The average temperature is %.2f%cC\n", average, c);}
void add_forecast_data(FILE * fptr, FILE * out, int choice, char day_FILE, char* day, int* month, int* year, int* temperature, int maxUV_index, int* humidity, int* wind_speed)
{
char answer;
fptr = fopen("forecast.txt", "r");
for(int i = 0; i< s; i++){
printf("please enter the day:\n");
scanf("%s", day);
printf("please enter the month:\n");
scanf("%d", &month[i]);
printf("please enter the year:\n");
scanf("%d", &year[i]);
printf("please enter the temperature :\n");
scanf("%d", &temperature[i]);
printf("please enter the max uv index:\n");
scanf("%d", &maxUV_index);
printf("please enter the humidity:\n");
scanf("%d", &humidity[i]);
printf("please enter the wind speed:\n");
scanf("%d", &wind_speed[i]);
if (strcmp(day, &day_FILE) == 0)
{
printf("press 1 if you want to overwrite the data\t press 2 if not");
scanf("%d", &choice);
if (choice == 1)
{
printf("the data is overwriten");
}
else {
printf("the data still the same");
}
}
else
{
fclose(fptr);
}
}}void Update_delete_forecast_data(char *day, int *month, int *year){
int choice1;
printf("please modify your data: \npress 1 if you want to modify the day \nprass 2 if you want to modify the month \npress 3 if you want to modify the year \n");
scanf("%d", &choice1); switch (choice1)
{
case 1:
printf("please modify the day:\n");
scanf("%s", day);
break;
case 2:
printf("please modify the month:\n");
scanf("%d", month);
break; case 3:
printf("please modify the month:\n");
scanf("%d", year);
break;
default:
printf("error try again");
}
*day = *day + strlen(*day);
*month = *month + strlen(*month);
*year = *year + strlen(*year);
printf("we delete the following date %c %d %d ", day, month, year);
}
int main()
{
int flag = 0, user = 0, index = 0, try = 0;
char i, j;
char pass[50];
char email[50], password[50], useremail[50], userpassword[50], em[50], pw[50];
int temperature[s][l], maxUV_index[s][l], humidity[s][l], wind_speed[s][l],choice, year[s][l], month[s][l];
FILE *fptr;
FILE *out;
char day[s][l];
char question[50], useranswer[50], answer[50],pname[s][l],day_FILE;
int user1 = login(fptr, email, password, question, answer);
login(fptr, email, password, question, answer); for (int i = 0; i < s; i++)
{
if (strcmp(email, em) == 0)
{
flag = 1;
index = i + 1;
}
if (flag != 1)
{
printf("there is no account under that email");
}
else
{
printf("please enter your password:\n");
scanf("%s", password);
}
if (strcmp(password, pw) == 0)
{
printf("you have a successful login to your email");
}
else
{
if (strlen(password) != strlen(password))
{
printf("incorrectpassword");
}
else
{
for (j = 0; j < strlen(password); j++)
{
if (password[j] == password[j + 1] && password[j + 1] == password[j])
{
printf("answer %s ", question);
scanf("%s", useranswer);
while (try <= s)
{
printf("please enter your password:\n");
scanf("%s", password);
if (strcmp(password, userpassword) == 0)
{
printf("you have a successful login to your email");
} else
{
strcmp(&email[j], &email[j + 1]);
try++; if (strcmp(userpassword, question) == 0)
{
flag = 1;
}
else
{
printf("there is no secret question under that email");
}
}
sign_up(fptr, email, password, question, answer);
change_userinfo(fptr, out, email, password, pname, index, question, answer);
forecast_data(fptr, out, choice, day_FILE, *day, *month, *year, *temperature, *maxUV_index, *humidity, *wind_speed);
add_forecast_data(fptr, out, choice, day_FILE, *day, *month, *year, *temperature, *maxUV_index, *humidity, *wind_speed);
Update_delete_forecast_data(*day, *year, *month);
log_out();
return 0;
}
}
}
}
}
}
}

