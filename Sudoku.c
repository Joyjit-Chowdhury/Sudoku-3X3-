#include<stdio.h>

int main()
{
    printf("\t\t\t\t\t\t\tWelcome\n");
    printf("\t\t\t\t\t\t\t--------\n");
    printf("\t\t\t\t\t\t*****To Sudoku Game*****\n");                               ///Ans: 6 7 2 1 5 9 8 3  4///
    system("pause");
    int l,index=0, win = 0;
    for(l=0;l<3;l++)
    {
        if(index<3)
        {
            printf("\n\t\t\t\t\t\tNOTE:(You Have Only %d Lives Left)",3-l);
        }
        win = game();
        index++;
        system("cls");
        if(win==-1 && index<3)
            {
                printf("\nNot Correct, Try Again.\n");
            }
        if(win == 1)
            break;
    }
    if(index==3 && win!=1)
        printf("\n\t\t\t\t\t\t*****GAME OVER*****\n");
    else
        printf("\nCorrect\n""\t\t\t\t\t*****Congratulation, YOU WIN*****\n");
    getch();
}
int game()
{
    int i, j, sum_r =0,sum_c =0, sum = 0,sum_cr = 0, sum_cr2=0, correct = 0, win =0;
    int a[3][3];

    printf("\nEnter The Numbers:\n\n");
    for(i=0; i<3; i++)
    {
        for(j=0; j<3;j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");
    for(i=0; i<3; i++)
    {
        printf("_|_");
        for(j=0; j<3;j++)
        {
            printf("%d_|", a[i][j]);
        }
        printf("_\n");
    }
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            sum_r = sum_r+a[i][j];
            sum_c = sum_c+a[j][i];
        }
        if(sum_r == 15 && sum_c == 15)
            correct++;
        sum_r = 0;
        sum_c = 0;
        sum_cr = sum_cr+a[i][i];
        sum_cr2 = sum_cr2+a[i][2-i];
        if(sum_cr==15 && sum_cr2 == 15)
            correct++;
    }
    if(correct == 4)
    {
        win = 1;
        getch();
        return win;
    }
    else
        getch();
        return -1;
}
