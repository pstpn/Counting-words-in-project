/**
 * @file tools.c
 * @author Stepan Postnov
 * @brief Tools
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
#include <stdarg.h>

#include "my_def.h"


/**
 * @brief Get the all filenames in current folder
 * 
 * @param out_filename 
 * @param folder 
 * @param count 
 * @param ... // File extensions
 */
void get_all_filenames_in_cur_folder(char *out_filename, char *folder, int count, ...)
{
    char *command;
    char desired_extensions[MAX_EXT_STR_LEN + 1] = "\0";

    va_list cur_param;

    va_start(cur_param, count);


    for (int i = 0; i < count - 1; ++i)
    {
        strcat(desired_extensions, "-name \"*.");
        strcat(desired_extensions, va_arg(cur_param, char *));
        strcat(desired_extensions, "\" -o ");
    }
    strcat(desired_extensions, "-name \"*.");
    strcat(desired_extensions, va_arg(cur_param, char *));
    strcat(desired_extensions, "\"");

    va_end(cur_param);

    asprintf(&command, GET_ALL_FILENAMES_COMMAND_FORMAT,
            folder, desired_extensions, out_filename);

    system(command);

    free(command);
}


/**
 * @brief Checking if a character is a separator
 * 
 * @param seps 
 * @param ch 
 * @return int 
 */
int is_sep_sym(char *seps, char ch)
{
    for (int i = 0; seps[i]; ++i)
        if (ch == seps[i])
            return TRUE;

    return FALSE;
}


/**
 * @brief Get the words count in file
 * 
 * @param f 
 * @param seps 
 * @return int 
 */
int get_words_count_in_file(FILE *f, char *seps)
{
    int all_words_count = 0;

    char buf_word[MAX_WORD_LEN + 1];
    char buf_sym;


    while (feof(f) == 0)
    {
        int i = 0;


        memset(buf_word, '\0', MAX_WORD_LEN + 1);

        do
        {
            if (fscanf(f, "%c", &buf_sym) != 1)
                break;
            
            if (!is_sep_sym(seps, buf_sym))
                buf_word[i++] = buf_sym;
            else
                break;
        } while (buf_sym != EOF);
        

        all_words_count += (buf_word[0]) ? 1 : 0;
    }

    return all_words_count;
}