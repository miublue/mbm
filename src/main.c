#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ncurses.h>
#include "mfile.h"

// key:path

char*
get_key(int key, char *text)
{
    char k[3] = {key, ':', 0};
    char *f = strstr(text, k);
    if (!f) return f;
    f += 2;

    char *nl = strstr(f, "\n");
    if (nl) *nl = '\0';

    return f;
}

void
main(int argc, const char *argv[])
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <file>\n", argv[0]);
        return;
    }

    initscr();

    char path[1024] = {0};
    char *home = getenv("HOME");
    sprintf(path, "%s/.mbmsel", home);

    char *text = read_file(argv[1]);

    printw("%s\n", text);
    printw("key: ");
    int key = getch();

    char *opt = get_key(key, text);
    if (!opt)
        goto fail;

    write_file(path, opt);
    endwin();
    return;
fail:
    if (text) free(text);
    endwin();
    fprintf(stderr, "could not find key %c\n", key);
    write_file(path, "NULL");
}
