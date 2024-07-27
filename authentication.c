#include <stdio.h>
#include <string.h>
#include <unistd.h>

char *namelist[]={"Alice","Bob","Oscar","Eve","Doe"};
char *pwdlist[]={"Ali@123","Bob@456","Oscar$789","Eve@012","Doe#345"};

int authenticate(const char *username, const char *password)
{
    int num_users = sizeof(namelist) / sizeof(namelist[0]);
  
    for (int i = 0; i < num_users; i++)
    {
        if (strcmp(namelist[i], username) == 0 && strcmp(pwdlist[i], password) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char username[50];
    char *password;
    int counter=0;

    printf("Enter username: ");
    scanf("%s", username);

    password = getpass("Enter password: ");
    
    while(counter<3)
    {
        if(authenticate(username,password)==1)
        {
            printf("Authentication successful!\n");
            break;
        }
        else
        {
            printf("Authentication failed :( Try again...\n");
            counter++;
            if(counter==3)
            {
                printf("Limit exceeded. Try later.");
                break;
            }
            password = getpass("Enter password: ");
        }
        
    }

    return 0;
}
