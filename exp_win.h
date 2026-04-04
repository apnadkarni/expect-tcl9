/* exp_win.h - window support

Written by: Don Libes, NIST, 10/25/93

This file is in the public domain.  However, the author and NIST
would appreciate credit if you use this file or parts of it.
*/

#include <tcl.h> /* For _ANSI_ARGS_ */

int exp_window_size_set(int fd);
int exp_window_size_get(int fd);

void  exp_win_rows_set    (const char* rows);
char* exp_win_rows_get    (void);
void  exp_win_columns_set (const char* columns);
char* exp_win_columns_get (void);

void  exp_win2_rows_set    (int fd, const char* rows);
char* exp_win2_rows_get    (int fd);
void  exp_win2_columns_set (int fd, const char* columns);
char* exp_win2_columns_get (int fd);
