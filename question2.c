#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

int checkingIfNum()
{
	int a,b,k,n=1;
    char str[20];

	while (a=0, str[a]!= '\0')
	{
		/* code */
		
		if((str[a]>='0'&&str[a]<='5')||(str[a]=='.')) {
			printf(".");
			a++;
		}
		else {
            n = 0;
			break;
		}
	}
    return 0;
	
}
int main()
{
    int t, i1, j1, i2, j2, k, l, m, n, row, col, i, j;
    double excelbook[10][10] = {0};
    char sheet[10][10][20] = {0};
    int flag[10][10] = {0};
    char input[20];

    char CellInput[4];
    char *sub;
    for (i = 0; i <= 5; i++)
        for (j = 0; j <= 5; j++)
        {
            if (i == 0 && j != 0)
                sheet[i][j][0] = 'A' + j - 1;
            else if (i != 0 && j == 0)
                sheet[i][j][0] = '0' + i;
            else if (i == 0 && j == 0)
                sheet[i][j][0] = '\0';
            else
                sheet[i][j][0] = '_';
        }
    while (1)
    {
        double sum = 0, avg = 0;
        int maxm = INT_MIN, minm = INT_MAX, cnt = 0;
        printf("Enter the cell number :  ");
        scanf("%s", CellInput);

        if (CellInput[0] >= 'A' && CellInput[0] <= 'Z')
            col = CellInput[0] - 'A' + 1;
        else
            col = CellInput[0] - 'a' + 1;
        row = CellInput[1] - '1' + 1;
        if (row > 9 || row < 0 || col > 9 || col < 0)
        {
            printf("\no cell found. Please try a new one \n");
            continue;
        }
        printf("\nEnter a new cell value to be inserted:  ");
        scanf("%s", input);

        if (checkingIfNum(input))
        {
            excelbook[row][col] = atoi(input);
            flag[row][col] = 1;
            strcpy(sheet[row][col], input);
            if (strlen(sheet[row][col]) > 6)
            {
                sheet[row][col][6] = '.';
                sheet[row][col][7] = '.';
                sheet[row][col][8] = '\0';
            }
        }
        else
        {
            strcpy(sheet[row][col], input);
            if (strlen(sheet[row][col]) > 6)
            {
                sheet[row][col][6] = '.';
                sheet[row][col][7] = '.';
                sheet[row][col][8] = '\0';
            }
        }

        for (i = 0; i <= 9; i++)
        {
            for (j = 0; j <= 9; j++)
                printf("%8s   ", sheet[i][j]);
            printf("\n");
        }

        printf("\n\n The Previous Input\nCell Value : %s\nValue : %s\n\n", CellInput, input);
    }
    return 0;
}