#include <stdio.h>
#include <stdlib.h>

char* input_str(void);

int main()
{
    char *str;
    printf("Enter your name - > ");

    str = input_str();
    printf("%s", str);

    free(str);
    return 0;
}

char* input_str()
{
    char *p, *q, ch;
    int size = 1, i;

    p = (char*) malloc(sizeof(char) * size);
    ch = getche();
    *p = ch;

    for(i = 0; i < size; i++)
    {
        q = (char*) malloc(sizeof(char) * (size + 1));

        *q = *(p + i);
        *(q + i + 1) = NULL;

        free(p);

        size++;

        p = (char*) malloc(sizeof(char) * size);

        *p = *(q + i);

        free(q);

        ch = getche();

        *(p + i + 1) = ch;

        if(ch == 13)
        {
            return p;
        }

    }
}
