#ifndef WC
#define WC

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <locale.h>
#include <wchar.h>
#include <wctype.h>

typedef  struct   s_count
{
   unsigned int words;
   unsigned int bytes;
   unsigned int chars;
   unsigned int lines;
} cnt ;

typedef struct s_flags
{
    char m;
    char c;
    char l;
    char w;
} t_flags;

cnt   count(FILE *file);

#endif