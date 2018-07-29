#include<stdio.h>
main()
{

    char str[30];
    int i=0,c,length=0,flag=1;
    printf("enter the string\n");
    scanf("%s",str);
    for(str[i];str[i]!='\0';i++)
    {
        length++;
    }
    c=length-1;
    for(i=0;i<c;i++)
    {
        if(str[i]!=str[c])
        {
            flag=0;
            break;
        }
        c--;
    }
    if (flag==1)
    {
        printf("entered string is a pallindrome");
    }
    else
        printf("not a pallindrome");


}
