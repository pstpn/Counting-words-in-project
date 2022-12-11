/**
 * @file main.c
 * @author Stepan Postnov
 * @brief                        
 * 
 * Program for counting the number of words in a project files
 * 
 * @version 0.1
 * @date 2022-12-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <stdlib.h>
#include <stdio.h>

#include "my_def.h"
#include "my_err.h"
#include "tools.h"
#include "in_out.h"


/**
 * @brief Main function
 * 
 * @return int 
 */
int main(void)
{
    get_all_filenames_in_cur_folder(TMP_FILENAME, CUR_PROJECT_FOLDER, 2,
        "h", "c");

    print_words_count(TMP_FILENAME, SEPS);

    return SUCCESS;
}
