/*
Write   a   C   Program   to   enter   a   number   and   store   the   number   across  the following structure and print the content of each member of the structure.
Then aggregate each member of the structure to form the original number and print the same.
struct pkt{int ch1;
	int ch2;
	int ch3;
	};
*/
#include <stdio.h>
struct pkt{
    int c1;
    int c2;
    int c3;
  };
int main()
{

  struct pkt parts;
  printf("First number\n");
  scanf("%d", &parts.c1);

  printf("Second number\n");
  scanf("%d", &parts.c2);

  printf("Third number\n");
  scanf("%d", &parts.c3);
  printf("Part1:%d\n",parts.c1);
  printf("Part2:%d\n",parts.c2);
  printf("Part3:%d\n",parts.c3);
  printf("%d%d%d",parts.c1,parts.c2,parts.c3);
  return 0;
}
