// Copyright 2014 Jianfei Chen
#include <cstdio>
#include <cstring>

int main(int argc, char *argv[]) {
        char *config_file = argv[1];
        char *output_file = argv[2];

        FILE *inf = fopen(config_file, "r");
        FILE *ouf = fopen(output_file, "w");

        fputs("// Copyright 2014 Jianfei Chen\n", ouf);
        fputs("#ifndef MAKE_CONSTS_H_\n", ouf);
        fputs("#define MAKE_CONSTS_H_\n", ouf);

        char buff[65536];
        while (fgets(buff, 65535, inf)) {
                int n           = strlen(buff);
                buff[n-1]       = ';';
                buff[n]         = '\n';
                buff[n+1]       = '\0';

                fprintf(ouf, "const int %s", buff);
        }

        fputs("#endif  // MAKE_CONSTS_H_\n", ouf);

        fclose(inf);
        fclose(ouf);
}
