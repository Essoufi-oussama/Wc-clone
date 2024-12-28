#include "word_count.h"

cnt   count(FILE *file)
{
   cnt   count_elements = {0};
   wint_t wc;
   char c[MB_CUR_MAX];
   wint_t prev_c = ' ';
   while((wc = getwc(file)) != WEOF)
   {
      count_elements.bytes +=  wctomb(c, wc);
      count_elements.chars += 1;
      if (wc == '\n')
         count_elements.lines += 1;
      if (iswspace(prev_c) && !iswspace(wc))
         count_elements.words += 1;
      prev_c = wc;
   }
   return (count_elements);
}

int main(int argc, char **argv)
{
   int opt;
   t_flags flags = {0};
   cnt result;
   FILE *file = NULL;
   setlocale(LC_ALL, "");

   while((opt = getopt(argc, argv, "lcwm")) != -1)
   {
      switch(opt)
      {
         case 'l':
            flags.l = 1;
            break;
         case 'm':
            flags.m = 1;
            break;
         case 'c':
            flags.c = 1;
            break;
         case 'w':
            flags.w = 1;
            break; 
         default:
            fprintf(stderr, "Usage: %s  -[l/c/w/m] [File name]\n", argv[0]);
            exit(EXIT_FAILURE);
      }
   }
   
    if (optind < argc) {
        file = fopen(argv[optind], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    } else {
        file = stdin;
    }
    if (argc == 1 && file == stdin)
    {
         flags.l = 1;
         flags.w = 1;
         flags.c = 1;
    }
    else if (argc <= 2 && file != stdin) 
    {
        flags.l = 1;
        flags.w = 1;
        flags.c = 1;
    }
    result = count(file);

    if (file != stdin) {
        fclose(file);
    }

    if (flags.l) printf("  %d", result.lines);
    if (flags.m) printf("  %d", result.chars);
    if (flags.w) printf("  %d", result.words);
    if (flags.c) printf("  %d", result.bytes);
    if (file != stdin) {
        printf("  %s", argv[optind]);
    }
    printf("\n");

    return 0;
}
