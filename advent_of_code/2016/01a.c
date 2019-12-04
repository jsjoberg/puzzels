#include <stdio.h>
int main () {
  char c;
  int x = 0, y = 0, i = 0;
  enum {N,E,S,W} d = N;
  for (;;) {
    c = getchar();
    if (c >= '0' && c <= '9')
      i = i*10+c-'0';
    else if ('R' == c) d = (d+1)%4;
    else if ('L' == c) d = (d+3)%4;
    else {
      y += N==d ? i : S==d ? -i : 0;
      x += E==d ? i : W==d ? -i : 0;
      i = 0;
      if (EOF == c) break;
    } 
  }
  printf("%d\n", (x<0?-x:x) + (y<0?-y:y));
  return 0;
}
