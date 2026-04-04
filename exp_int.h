/* exp_int.h - private symbols common to both expect program and library

Written by: Don Libes, libes@cme.nist.gov, NIST, 12/3/90

Design and implementation of this program was paid for by U.S. tax
dollars.  Therefore it is public domain.  However, the author and NIST
would appreciate credit if this program or parts of it are used.
*/

#ifndef _EXPECT_INT_H
#define _EXPECT_INT_H

#ifndef TRUE
#define FALSE 0
#define TRUE 1
#endif

#ifndef HAVE_MEMCPY
#define memcpy(x,y,len) bcopy(y,x,len)
#endif

#include <limits.h>
#include <errno.h>

/* Check, if Tcl version supports Tcl_Size,
   which was introduced in Tcl 9.
*/
#ifndef TCL_SIZE_MAX
    #define TCL_SIZE_MAX INT_MAX

    #ifndef Tcl_Size
        typedef int Tcl_Size;
    #endif

    #define TCL_SIZE_MODIFIER ""
    #define Tcl_GetSizeIntFromObj Tcl_GetIntFromObj
#endif

void	exp_console_set     (void);
void	expDiagLogPtrSet    (void (*)(const char *));
void	expDiagLogPtr       (char *);
void	expDiagLogPtrX      (char *,int);
void	expDiagLogPtrStr    (char *,char *);
void	expDiagLogPtrStrStr (char *,char *,char *);
void	expErrnoMsgSet      (const char * (*) (int));
const char *expErrnoMsg     (int);

int	expListGetElements  (Tcl_Interp *interp, Tcl_Obj *objPtr,
			        int *objcPtr, Tcl_Obj ***objvPtr);

#ifdef NO_STDLIB_H
#  include "../compat/stdlib.h"
#else
#  include <stdlib.h>		/* for malloc */
#endif /*NO_STDLIB_H*/

#endif /* _EXPECT_INT_H */
