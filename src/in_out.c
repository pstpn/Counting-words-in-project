/**
 * @file in_out.c
 * @author Stepan Postnov
 * @brief In / out functions
 * @version 0.1
 * @date 2022-12-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "tools.h"
#include "my_def.h"


/**
 * @brief Draw lines
 * 
 * @param len 
 */
void draw_line(int len)
{
    for (int i = 0; i < len; ++i)
        printf("-");

    printf("\n");
}


/**
 * @brief Print info about words count ib files
 * 
 * @param src_filenames 
 * @param seps 
 */
void print_words_count(char *src_filenames, char *seps)
{
    FILE *src_file = fopen(src_filenames, "r");

    size_t init_buf = 40;

    int all_count = 0;


    printf("\n\n");

    while (feof(src_file) == 0)
    {
        char *cur_filename = NULL;
        

        getline(&cur_filename, &init_buf, src_file);

        if (cur_filename[strlen(cur_filename) - 1] != '\n')
            break;
        else
        {
            cur_filename[strlen(cur_filename) - 1] = '\0';

            FILE *cur_file = fopen(cur_filename, "r");


            int cur_count = get_words_count_in_file(cur_file, seps);


            draw_line(LINE_LEN);
            printf("\nFilename: %s\nWords count: %d\n\n", cur_filename, cur_count);

            all_count += cur_count;

            fclose(cur_file);
        }

        free(cur_filename);
    }

    draw_line(LINE_LEN);

    printf("\n%sSUMMARY: %d%s\n\n", PURPLE, all_count, RESET);

    fclose(src_file);
}