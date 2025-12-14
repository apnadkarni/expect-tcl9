/* exp_rename.h - preface globals that appear in the expect library with "exp_"
so we don't conflict with the user.  This saves me having to use exp_XXX
throughout the expect program itself, which was written well before the library
when I didn't have to worry about name conflicts.

Written by: Don Libes, NIST, 12/3/90

Design and implementation of this program was paid for by U.S. tax
dollars.  Therefore it is public domain.  However, the author and NIST
would appreciate credit if this program or parts of it are used.  */

/* Check, if Tcl version supports Tcl_Size,
   which was introduced in Tcl 8.7 and 9.
*/
#ifndef TCL_SIZE_MAX
    #include <limits.h>
    #define TCL_SIZE_MAX INT_MAX

    #ifndef Tcl_Size
        typedef int Tcl_Size;
    #endif

    #define TCL_SIZE_MODIFIER ""
    #define Tcl_GetSizeIntFromObj Tcl_GetIntFromObj
#endif
