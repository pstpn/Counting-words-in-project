/**
 * @file tools.h
 * @author Stepan Postnov
 * @brief Library for tools.c
 * @version 0.1
 * @date 2022-12-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ___MY_TOOLS___
#define ___MY_TOOLS___


void get_all_filenames_in_cur_folder(char *out_filename, char *folder, int count, ...);
int is_sep_sym(char *seps, char ch);
int get_words_count_in_file(FILE *f, char *seps);

#endif // ___MY_TOOLS___