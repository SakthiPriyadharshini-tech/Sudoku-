#include<stdio.h>
int sudoku[9][9];
void solvesudoku(int,int);
int checkrow(int r,int n)
{
int c;
for(c=0;c<9;c++)
    if(sudoku[r][c]==n)
        return 0;
return 1;
}
int checkcolumn(int c,int n)
{
int r;
for(r=0;r<9;r++)
    if(sudoku[r][c]==n)
        return 0;
return 1;
}
int checkgrid(int r,int c,int n)
{
r=(r/3)*3 ;
c=(c/3)*3;
int r1,c1;
for(r1=0;r1<3;r1++)
{
    for(c1=0;c1<3;c1++)
    {
         if(sudoku[r+r1][c+c1]==n)
            return 0;
    }
return 1;
}
}
void navigate(int r,int c)
{
if(c<8)
        solvesudoku(r,c+1);
    else
       solvesudoku(r+1,0);
}
void display()
{
int r,c;
printf("THE SOLVED SUDOKU \n");
for(r=0;r<9;r++)
{
    for(c=0;c<9;c++)
    {
    printf("%d ",sudoku[r][c]);
    }
    printf("\n");
}
}
void solvesudoku(int r,int c)
{
    if(r>8)
    display();
    if(sudoku[r][c]!=0)
    navigate(r,c);
    else
    {
        int counter;
        for(counter=1;counter<=9;counter++)
        {
        if((checkrow(r,counter)==1)&&(checkcolumn(c,counter)==1)&&(checkgrid(r,c,counter)==1))
        {
            sudoku[r][c]=counter;
             navigate(r,c);
        }
        }
        sudoku[r][c]=0;
    }

}
int main()
{
int r,c;
printf("Enter the desired sudoku and enter 0 for unknown entries\n");
for(r=0;r<9;r++)
{
    for(c=0;c<9;c++)
    {
        scanf("%d",&sudoku[r][c]);
    }
}
solvesudoku(0,0);
}
