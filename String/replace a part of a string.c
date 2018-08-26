#include<stdio.h>
main()
{
    char str[100],str1[30],str2[30];
    int a,i=0,length=0,length1=0,length2=0,j,flag=0;
    printf("enter first string (max 100)\n");
    scanf("%s",&str);
    printf("enter string to be replaced (MAX 30!) \n");
    scanf("%s",&str1);
    printf("enter the string to replace (Same length as above string)\n");
    scanf("%s",&str2);
    for(str[i];str[i]!='\0';i++)
    {
        length++;
    }
    i=0;
    for(str1[i];str1[i]!='\0';i++)
    {
        length1++;
    }
    i=0;
    for(str2[i];str2[i]!='\0';i++)
    {
        length2++;
    }
    for(i=0;i<length;i++)
    {
        if(str1[0]==str[i])
        {
            a=i; flag=1; break;
        }
    }
    j=0;
    for(i=a;i<a+length1;i++)
    {
        if(str1[j]!=str[i])
        {
            flag=0;
            break;
        }
        j++;
    }

    if(flag==1)
    {
        /*deletion part*/
        for(i=0;i<length1;i++)
        {
            for(j=a;j<length;j++)
            {
                str[j]=str[j+1];
            }
        }

        /*insertion part*/
        for(i=0;i<length2;i++)
        {
            for(j=length;j>=a;j--)
            {
                str[j]=str[j-1];
            }
            str[a]=str2[i];
            a++;
        }
        printf("Replaced ");
    }
    if(flag==0)
    {
        printf("entered string was not found, Original ");
    }
    printf("String = %s",str);

}
