#include <stdio.h>
#include <string.h>
#include <ctype.h>

int strength_meter(const char *password) {
    int pwdlen = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    int score = 0;

    for (int i = 0; i < pwdlen; i++)
    {
        if (isupper((unsigned char)password[i])) has_upper = 1;
        else if (islower((unsigned char)password[i])) has_lower = 1;
        else if (isdigit((unsigned char)password[i])) has_digit = 1;
        else if (strchr("!@#$%^&*()", password[i])) has_special = 1;
    }

    if (pwdlen >= 8) score += 20;
    if (has_upper) score += 20;
    if (has_lower) score += 20;
    if (has_digit) score += 20;
    if (has_special) score += 20;

    return score;
}

int main() {
    char password[100];

    printf("Enter password: ");
    scanf("%s",password);
    
    printf("Password Strength: %d%%\n", strength_meter(password));

    return 0;
}
