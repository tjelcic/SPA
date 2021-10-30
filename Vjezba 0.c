#include <stdio.h>

int myStrlen (char* str)
{
    int len=0;
    while(*str!='\0')
    {
        str++;
        len++;
    }
    return len;
}

char* myStrcpy (char* str1, char *str2)
{
    char *p=str1;
    while(*str2!='\0')
    {
        *str1=*str2;
        str1++;
        str2++;
    }
    *str1 = '\0';
    return p;
}

int myStrcmp (char* str1, char* str2)
{
    while(*str1)
    {
        if(*str1!=*str2)
        {
            break;
        }
        str1++;
        str2++;
    }
    return *str1-*str2;
}

char* myStrcat (char* str1, char* str2)
{
    int c=0;
    int i;

    while(str1[c]!='\0')
    {
        c++;
    }

    for (i=0;i<strlen(str2);i++)
    {
        str1[i+c]=str2[i];
    }

    str1[i+c]='\0';

    return str1;
}

char* myStrstr (char* str1, char* str2)
{
    char* temp1=str1;
    char* temp2=str2;

    while(*temp1!='\0')
    {
        str1=temp1;
        str2=temp2;

        while(*str2!='\0' && *str2==*str1)
        {
            str2++;
            str1++;
        }
        if(*str2=='\0')
        {
            return temp1;
        }
        temp1++;
    }
    return NULL;
}

void reverse (char* str1, char* str2)
{
    int len=myStrlen(str1);
    int i=0;
    int j=len-1;

    while(i<len)
    {
        str2[i]=str1[j];
        i++;
        j--;
    }

    str2[i]='\0';
    printf("%s\n", str2);
}

void main()
{
    char str1[20]="prviii";
    char str2[20]="prvi";
    printf("Length of string %s: %d\n", str1, myStrlen(str1));
    printf("Second string copied into first one: %s\n",myStrcpy(str1,str2));
    char str3[20]="manji";
    char str4[20]="veciiiii";
    printf("Difference between two strings: %d\n", myStrcmp(str3,str4));
    printf("Second string added to the first one: %s\n", myStrcat(str3,str4));
    char str5[20]="datoteka";
    char str6[20]="teka";
    if(myStrstr(str5,str6)==NULL)
        printf("no substring found\n");
    printf("String %s found in %s: %c %d %s\n", str6, str5, *myStrstr(str5,str6), *myStrstr(str5,str6), myStrstr(str5,str6));
    char str7[20]="krov";
    char str8[20]="auto";
    printf("String %s copied in reverse: ", str7 );
    reverse(str7,str8);
}
