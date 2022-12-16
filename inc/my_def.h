/**
 * @file my_def.h
 * @author Stepan Postnov
 * @brief Defines
 * @version 0.1
 * @date 2022-12-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#ifndef ___MY_DEF___
#define ___MY_DEF___

/**
 * @brief Bool vars
 * 
 */
#define TRUE 1
#define FALSE 0

/**
 * @brief Max extensions count
 * 
 */
#define MAX_EXT_STR_LEN 1024
/**
 * @brief Max word length in file
 * 
 */
#define MAX_WORD_LEN 500

/**
 * @brief Separators
 * 
 */
#define SEPS "#{}()*\"\';\n /.<>,:@"

/**
 * @brief Command to get all project files
 * 
 */
#define GET_ALL_FILENAMES_COMMAND_FORMAT "find %s -type f %s > %s"

/**
 * @brief Tmp filename for all filenames
 * 
 */
#define TMP_FILENAME "all_filenames.tmp"
/**
 * @brief Project folder
 * 
 */
#define CUR_PROJECT_FOLDER "."

/**
 * @brief Format var
 * 
 */
#define LINE_LEN 30

/**
 * @brief Output colors
 * 
 */
#define RESET "\033[0m"
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define PURPLE "\033[1;35m"
#define BLUE "\033[1;36m"

#endif // ___MY_DEF___