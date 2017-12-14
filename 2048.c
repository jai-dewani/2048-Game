#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void clrscr()
{
    system("@cls||clear");
}
int main()
{
    int ar[4][4];
    int row,col,temp;
    int i,j,k;
    int score=0,hscore;
    for(row=0;row<4;row++)
        for(col=0;col<4;col++)
            ar[row][col]=0;
    FILE *ptr;
    ptr=fopen("hs.txt","r");
    if(ptr==NULL)
    {
        int x=0;
        //printf("ERROR");
        fclose(ptr);
        ptr=fopen("hs.txt","w");
        fprintf(ptr,"%d",x);
        fclose(ptr);
        ptr=fopen("hs.txt","r");
    }
    fscanf(ptr,"%d",&hscore);
    fclose(ptr);
    printf("\twelcome to 2048\nq:end game\t\tn:new game\n");
    printf("Score%4d\t\tHighScore%4d\n",score,hscore);
    for(row=0;row<4;row++)
    {   for(col=0;col<4;col++)
            printf("%4d ",ar[row][col]);
        printf("\n");
    }
    while(1){
        switch(getch()){
            case 72:
                for(col=0;col<4;col++)
                {
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(ar[j][col]==0)
                            {
                                for(temp=j;temp<3;temp++)
                                {
                                    ar[temp][col]=ar[temp+1][col];
                                }
                                ar[3][col]=0;
                            }
                        }
                    }
                    for(row=0;row<3;row++)
                    {
                        if(ar[row][col]==ar[row+1][col])
                        {
                            ar[row][col]+=ar[row+1][col];
                            score=score+ar[row][col];
                            for(temp=row+1;temp<3;temp++)
                            {
                                ar[temp][col]=ar[temp+1][col];

                            }
                            ar[3][col]=0;
                        }
                    }
                }
                ar[3][rand()%4]=2;
            break;
            case 75:
                for(row=0;row<4;row++)
                {
                    for(i=0;i<3;i++)
                    {
                        for(j=0;j<4;j++)
                        {
                            if(ar[row][j]==0)
                            {
                                for(temp=j;temp<3;temp++)
                                {
                                    ar[row][temp]=ar[row][temp+1];
                                }
                                ar[row][3]=0;
                            }
                        }
                    }
                    for(col=0;col<3;col++)
                    {
                        if(ar[row][col]==ar[row][col+1])
                        {
                            ar[row][col]*=2;
                            score=score+ar[row][col];
                            for(temp=col+1;temp<3;temp++)
                            {
                                ar[row][temp]=ar[row][temp+1];
                            }
                            ar[row][3]=0;
                        }
                    }
                }
                ar[rand()%4][3]=2;
            break;
            case 77:
                for(row=0;row<4;row++)
                {
                    for(i=3;i>0;i--)
                    {
                        for(j=3;j>=0;j--)
                        {
                            if(ar[row][j]==0)
                            {
                                for(temp=j;temp>0;temp--)
                                    ar[row][temp]=ar[row][temp-1];
                                ar[row][0]=0;
                            }

                        }
                    }
                    for(col=3;col>0;col--)
                    {
                        if(ar[row][col]==ar[row][col-1])
                        {
                            ar[row][col]*=2;
                            score=score+ar[row][col];
                            for(temp=col-1;temp>0;temp--)
                            {
                                ar[row][temp]=ar[row][temp-1];
                            }
                            ar[row][0]=0;
                        }
                    }
                }
                ar[rand()%4][0]=2;
            break;
            case 80:
                for(col=0;col<4;col++)
                {
                    for(i=3;i>0;i--)
                    {
                        for(j=3;j>0;j--)
                        {
                            if(ar[j][col]==0)
                            {
                                for(temp=j;temp>0;temp--)
                                {
                                    ar[temp][col]=ar[temp-1][col];
                                }
                                ar[0][col]=0;
                            }
                        }
                    }
                    for(row=3;row>0;row--)
                    {
                        if(ar[row][col]==ar[row-1][col])
                        {
                            ar[row][col]*=2;
                            score=score+ar[row][col];
                            for(temp=row-1;temp>0;temp--)
                            {
                                ar[temp][col]=ar[temp-1][col];
                            }
                            ar[0][col]=0;
                        }
                    }
                }
                ar[0][rand()%4]=2;
            break;
            case 113: exit(0);
            break;
            case 81: exit(0);
            break;
            case 110 :
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                        ar[i][j]=0;
                score=0;
            break;
            case 78:
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++)
                        ar[i][j]=0;
                score=0;
            break;
        }
        if(score>hscore)
        {
            ptr=fopen("hs.txt","w");
            hscore=score;
            fprintf(ptr,"%d",hscore);
            fclose(ptr);
        }
        clrscr();
        printf("\twelcome to 2048\nq:end game\t\tn:new game\n");
        printf("Score%4d\t\tHighScore%4d\n",score,hscore);
        for(row=0;row<4;row++)
        {   for(col=0;col<4;col++)
                printf("%4d ",ar[row][col]);
            printf("\n");
        }
    }
}
