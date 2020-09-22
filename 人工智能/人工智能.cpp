#include"stdio.h"
#define num 3 
void show(int begin[num][num]) 
{
for(int i = 0; i < num; i++)
{
for(int j = 0; j < num; j++)
printf("%d ", begin[i][j]);
printf("\n");
}
printf("\n");
}
void exchange(int begin[num][num], int row_one, int column_one, int row_two, int column_two) 
{
int temp;
temp = begin[row_two][column_two] ;
begin[row_two][column_two] = begin[row_one][column_one];
begin[row_one][column_one] = temp;
}
int judge(int begin[num][num], int end[num][num])
{
int count=0;          
for(int i = 0; i < num; i++)  
for(int j = 0; j < num; j++)
{
if(begin[i][j] == end[i][j] && end[i][j] != 0)
count++;
}
return count;         
}

int yidong(int begin[num][num], int end[num][num]
, int right, int jishu, int ji_shu[50][3][3]
, int biaoji, int row, int column) 
{
int temp_zhi;
show(begin); 
if(jishu >= 20)
return 0;
int node; 
int temp;           
for(int q=0; q<jishu; q++) 
{
node = 1;
for(int w=0; w<num && node; w++)
for(int r=0; r<num && node; r++)
if(ji_shu[q][w][r] != begin[w][r])
node = 0;
if(node == 1) 
{
return 0;
}
}
for(int i = 0; i < num; i++) 
for(int j = 0; j < num; j++)
ji_shu[jishu][i][j] = begin[i][j];
if(right == num * num - 1)  
return 1;
if(row > 0 && biaoji != 0)           
{
exchange(begin, row - 1, column, row , column);  
temp = judge(begin, end);
if(temp < right)  
exchange(begin, row - 1, column, row , column); 
else if(temp >= right)         
{
temp_zhi = yidong(begin, end, temp, jishu+1, ji_shu, 2, row-1, column);
if( temp_zhi == 1)  
return 1;
exchange(begin, row - 1, column, row , column);
}
}
if(column > 0 && biaoji != 1)
{
exchange(begin, row, column - 1, row , column); 
temp = judge(begin, end);       
if(temp < right) 
exchange(begin, row, column - 1, row , column);           
else if(temp >= right)
{
temp_zhi = yidong(begin, end, temp, jishu+1, ji_shu ,3, row, column - 1);
if(temp_zhi == 1) 
return 1;
exchange(begin, row, column - 1, row , column);
}
}
if(row < num-1 && biaoji != 2)
{
exchange(begin, row + 1, column, row , column); 
temp = judge(begin, end);   
if(temp < right)
exchange(begin, row + 1, column, row , column);
else if(temp >= right)
{
temp_zhi =yidong(begin, end, temp, jishu+1, ji_shu, 0, row+1, column);
if(temp_zhi == 1) 
return 1;
exchange(begin, row + 1, column, row , column);
}
}
if(column < num-1 && biaoji != 3)
{
exchange(begin, row, column + 1, row , column); 
temp = judge(begin, end);   
if(temp < right) 
exchange(begin, row, column + 1, row , column);       
else if(temp >= right) 
{
temp_zhi = yidong(begin, end, temp, jishu+1, ji_shu, 1, row, column+1);
if(temp_zhi == 1) 
return 1;
exchange(begin, row, column + 1, row , column);   
}
}
return 0; 
}
void shuru(int begin[][num],int blank[]) 
{
int temp, node, zero = 0;
for (int i = 0; i < num; i++)
for(int j = 0; j < num; j++)
{
node = 1;
printf("请输入第%d行，第%d列的元素的值：", i+1, j+1);
scanf("%d", &temp);
for (int q = 0; q <= i && node == 1; q++) 
for (int w = 0; w < j; w++)
if(temp == begin[q][w])
{
printf("输入重复，请重新输入\n");
node = 0;
j--;
break;
}
if(temp < 0 || temp > num*num-1)  
{
printf("请输入从%d到%d的数\n", zero, num*num-1);
node = 0;
j--;
}
if(node == 1)   
{
if(temp == 0) 
{
blank[0] = i;
blank[1] = j;
}
begin[i][j] = temp;
}
}
}
int main()
{
int jishu = 0, ji_shu[50][3][3];
int row;    
int column; 
int begin[num][num], blank[2],count=1;    
int end[num][num] = {1, 2, 3, 8, 0, 4, 7, 6, 5}; 
printf ("-------%d开始！--------\n", num);
shuru(begin, blank);  
row = blank[0];
column = blank[1];
if(yidong (begin, end,judge(begin,end),jishu,ji_shu,4,row,column) == 0) 
printf("\nTo Be Continue");
else
show(begin);
getchar();getchar();
return 0;
}
