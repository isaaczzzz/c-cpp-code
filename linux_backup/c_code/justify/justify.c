#include <string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void)
{
    char word[MAX_WORD_LEN + 2];
    int len;

    clear_line();
    while (1)
    {
        read_word(word, MAX_WORD_LEN + 1);
        len = strlen(word);
        if (len == 0)
        {
            flush_line();
            return 0;
        }
        if (len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (len + 1 > space_remaining())
        {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}