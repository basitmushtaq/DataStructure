#include<stdio.h>
main()
{
    char a[30];
    int i=0;
    printf("enter the string\n");
    scanf("%s",&a);

for(a[i];a[i]!='\0';i++)
    {

        if(a[i]>=97 && a[i]<=122)
        {
            a[i]=a[i]-32;
        }
    }


    printf("%s\n",a);
}
