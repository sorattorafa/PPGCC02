
#include <stdio.h>

int main()
{
    int y;
    int x = 10;
    y = x++;
    int z = x;
    x *= 2;
    z = x++ + ++y;
    printf("%d\n", y);
    printf("%d\n", x);
    printf("%d\n", z);

    return 0;
}
