#include "stdio.h"
int main()
{
int stack[100];
int index=0;
while ( !feof(stdin) )
  {
    int c = getchar();
    int h;
    switch (c)
      {
        case ' ':
        case '\n':
        break;
        case '=':
        printf("Result = %d\n", stack[index - 1]); index--;
        break;
        case '+':
        stack[index-2] = stack[index-2] + stack[index-1]; index--;
        break;
        case '-':
        stack[index-2] = stack[index-2] - stack[index-1]; index--;
        break;
        case '*':
        stack[index-2] = stack[index-2] * stack[index-1]; index--;
        break;
        case '/':
        stack[index-2] = stack[index-2] / stack[index-1]; index--;
        break;
        default:
        ungetc (c, stdin);
        if (scanf("%d", &h)!=1)
         {
           printf("can't read integer");
           return 1;
         }
           else
            {
              stack[index]=h;
              index++;
            }
      }
   }
           printf("Result = %d\n",stack[index-1]);
           return 0;
}
