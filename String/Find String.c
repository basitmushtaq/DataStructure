#include<stdio.h>
#include<stdlib.h>
main()
{
    char str1[30],str2[10];
    int flag1=0,j=0,i=0,a,L1=0,L2=0,c;
    printf("enter first string (max 30)\n");
    scanf("%s",str1);
    printf("enter string to find (max 10) \n");
    scanf("%s",str2);
    for(i=0;str1[i]!='\0';i++)
    {
        L1=L1+1;
    }
    for(i=0;str2[i]!='\0';i++)
    {
        L2=L2+1;
    }
    for(i=0;i<L1;i++)
    {
        if(str2[0]==str1[i])
        {

            flag1=1;
            break;
        }
    }
        if(flag1==1)
        {
            c=i+L2;
            for(i;i<c;i++)
            {
                if(str2[j]!=str1[i])
                {
                    flag1=0;
                    break;
                }
                j++;
            }
        }
        if(flag1==1)
            printf("string matched");
        else if(flag1==0)
            printf("string not found");
    }
