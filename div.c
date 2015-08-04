#include <stdio.h>

int main()
{
    unsigned char a[30000], *ptr;
    unsigned int i;

    for(i = 0; i < 30000; i++)
        a[i] = 0;

    ptr = a;

    *ptr = fgetc(stdin);
    ++ptr;
    *ptr = fgetc(stdin);
    ++ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;

    while(*ptr) {
        --*ptr;
        --ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        --*ptr;
        ++ptr;
        ++ptr;
    }

    --ptr;
    --ptr;

    while(*ptr) {
        ++ptr;

        while(*ptr) {
            --*ptr;
            ++ptr;
            ++*ptr;
            ++ptr;
            ++*ptr;
            --ptr;
            --ptr;
        }

        ++ptr;

        while(*ptr) {
            --*ptr;
            --ptr;
            --ptr;
            --*ptr;

            while(*ptr) {
                ++ptr;
            }

            ++ptr;
            ++ptr;
            ++ptr;

            while(*ptr) {
                --ptr;

                while(*ptr) {
                    ++ptr;
                    ++ptr;
                    ++ptr;
                    --*ptr;
                    --ptr;
                    --ptr;
                    --ptr;

                    while(*ptr) {
                        --*ptr;
                    }

                }

                ++ptr;
                ++ptr;
            }

            --ptr;
            --ptr;
        }

        ++ptr;
        ++ptr;
        ++ptr;
        ++*ptr;
        --ptr;
        --ptr;

        while(*ptr) {
            --*ptr;
            --ptr;
            --ptr;
            ++*ptr;
            ++ptr;
            ++ptr;
        }

        --ptr;
        --ptr;
        --ptr;
    }

    ++ptr;

    while(*ptr) {
        --*ptr;
    }

    ++ptr;
    ++ptr;
    ++ptr;
    ++ptr;

    while(*ptr) {
        --*ptr;
        --ptr;
        --ptr;
        --ptr;
        --ptr;
        --ptr;
        ++*ptr;
        ++ptr;
        ++ptr;
        ++ptr;
        ++ptr;
        ++ptr;
    }

    --ptr;
    --ptr;
    --ptr;
    --ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;
    ++*ptr;

    while(*ptr) {
        --*ptr;
        --ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        ++*ptr;
        ++ptr;
    }

    --ptr;
    putc(*ptr, stdout);
    fflush(stdout);
    return 0;
}
