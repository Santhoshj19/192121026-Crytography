#include<stdio.h>
#include<string.h>
int main()
{
    char plain[100], cipher[100], key[27];
    int i, j, k, len;
    printf("Enter the plain text: ");
    fgets(plain, 100, stdin);
    printf("Enter Unique key for A-Z(26 letters): ");
    fgets(key, 27, stdin);
    len = strlen(plain);
    for(i=0; i<len; i++)
    {
        if(plain[i]>='a' && plain[i]<='z')
        {
            j = plain[i] - 'a';
            cipher[i] = key[j];
        }
        else if(plain[i]>='A' && plain[i]<='Z')
        {
            j = plain[i] - 'A';
            cipher[i] = key[j];
        }
        else
        {
            cipher[i] = plain[i];
        }
    }
    printf("The cipher text is: %s", cipher);
    return 0;
}
