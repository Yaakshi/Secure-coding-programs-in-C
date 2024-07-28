#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void generate_random_password(int length)
{
    char password[length];
    
    const char uppers[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char lowers[] = "abcdefghijklmnopqrstuvwxyz";
    const char digits[] = "0123456789";
    const char specials[] = "!@#$%^&*()";

    const char *all = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                            "abcdefghijklmnopqrstuvwxyz"
                            "0123456789"
                            "!@#$%^&*()";

    int i;

    srand(time(NULL));

    password[0] = uppers[rand() % (sizeof(uppers) - 1)];
    password[1] = lowers[rand() % (sizeof(lowers) - 1)];
    password[2] = digits[rand() % (sizeof(digits) - 1)];
    password[3] = specials[rand() % (sizeof(specials) - 1)];

    for (i = 4; i < length; i++) {
        password[i] = all[rand() % (strlen(all))];
    }

    password[length] = '\0';

    for (i = 0; i < length; i++) {
        int random_index = rand() % length;
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }
    
    printf("\n\n%s",password);
}

int main()
{
    int length=0;
    
    printf("Enter length of password to be generated: ");
    scanf("%d",&length);
    
    generate_random_password(length);

    return 0;
}
