#pragma once

#define ZNACKA_SIZE 21
#define ALBUMSIZE 20

struct t_auto
{
    char  znacka[ZNACKA_SIZE];
    char album[ALBUMSIZE];
    int   rok;
    struct t_auto* dalsi;
};

void add(char* znacka, int rok, char* album, struct t_auto** uk_prvni);
void del(int rok, struct t_auto** uk_prvni);
