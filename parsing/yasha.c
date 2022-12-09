#include <stdio.h>

int main() {
    int one;
    int two;
    int three;
    char* qwe = "v 123 123 123";
    sscanf(qwe, "v %d %d %d", &one, &two, &three);
    printf("%d %d %d", one, two, three);
}