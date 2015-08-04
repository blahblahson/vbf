#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    if(argc < 3) {
        printf("Usage:\tcbfc <input.b> <output.c>\n");
        return 0;
    }

    FILE *input = fopen(argv[1], "r");

    if(!input) {
        printf("Error reading input: %s\n", strerror(errno));
        return 1;
    }

    FILE *output = fopen(argv[2], "w");

    if(!output) {
        printf("Error writing output: %s\n", strerror(errno));
        return 1;
    }
    
    char *start     = "#include <stdio.h>\n\n"
    "int main()\n"
    "{\n"
    "    unsigned char a[30000], *ptr;\n"
    "    unsigned int i;\n\n"
    "    for(i = 0; i < 30000; i++)\n"
    "        a[i] = 0;\n\n"
    "    ptr = a;\n\n";
    char *end       = "    return 0;\n"
        "}\n";
    char *incptr    = "++ptr;\n";
    char *decptr    = "--ptr;\n";
    char *incval    = "++*ptr;\n";
    char *decval    = "--*ptr;\n";
    char *putval    = "putc(*ptr, stdout);\n";
    char *fflsh     = "fflush(stdout);\n";
    char *getval    = "*ptr = fgetc(stdin);\n";
    char *loopstart = "while(*ptr) {\n";
    char *loopend   = "}\n\n";

    if(fputs(start, output) == EOF) {
        printf("Error writing output: %s\n", strerror(errno));
        return 1;
    }

    char inst;
    unsigned int indent = 1;
    int i;

    while((inst = fgetc(input))) {
        if(inst == EOF)
            break;

        switch(inst) {
            case '>':
                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(incptr, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }
                
                break;

            case '<':
                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(decptr, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }
                
                break;

            case '+':
                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(incval, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }
                
                break;

            case '-':
                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(decval, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }
                
                break;

            case '.':
                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(putval, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }

                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(fflsh, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }
                
                break;

            case ',':
                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(getval, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }
                
                break;

            case '[':
                if(fputs("\n", output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }

                for(i = 0; i < indent; i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(loopstart, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }

                indent++;
                
                break;

            case ']':
                for(i = 0; i < (indent - 1); i++) {
                    if(fputs("    ", output) == EOF) {
                        printf("Error writing output: %s\n", strerror(errno));
                        return 1;
                    }
                }

                if(fputs(loopend, output) == EOF) {
                    printf("Error writing output: %s\n", strerror(errno));
                    return 1;
                }

                indent--;
                
                break;
        }
    }

    if(fputs(end, output) == EOF) {
        printf("Error writing output: %s\n", strerror(errno));
        return 1;
    }

    fclose(output);
    fclose(input);

    return 0;
}
