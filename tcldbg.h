/* Dbg.h - Tcl Debugger include file

Written by: Don Libes, NIST, 3/23/93

Design and implementation of this program was paid for by U.S. tax
dollars.  Therefore it is public domain.  However, the author and NIST
would appreciate credit if this program or parts of it are used.

*/

/* _DEBUG or _DBG is just too likely, use something more unique */
#ifndef _NIST_DBG
#define _NIST_DBG

#include "tcl.h"

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

typedef int (Dbg_InterProc) (Tcl_Interp *interp, ClientData data);
typedef int (Dbg_IgnoreFuncsProc) (
			Tcl_Interp *interp,
			char *funcname);
typedef void (Dbg_OutputProc) (
			Tcl_Interp *interp,
			char *output,
			ClientData data);

typedef struct {
  Dbg_InterProc *func;
  ClientData data;
} Dbg_InterStruct;

typedef struct {
  Dbg_OutputProc *func;
  ClientData data;
} Dbg_OutputStruct;

EXTERN char *Dbg_VarName;
EXTERN char *Dbg_DefaultCmdName;

/* trivial interface, creates a "debug" command in your interp */
EXTERN int Tcldbg_Init (Tcl_Interp *);

EXTERN void Dbg_On (Tcl_Interp *interp,
					int immediate);
EXTERN void Dbg_Off (Tcl_Interp *interp);
EXTERN char **Dbg_ArgcArgv (int argc,char *argv[],
					int copy);
EXTERN int Dbg_Active (Tcl_Interp *interp);
EXTERN Dbg_InterStruct Dbg_Interactor (
					Tcl_Interp *interp,
					Dbg_InterProc *interactor,
					ClientData data);
EXTERN Dbg_IgnoreFuncsProc *Dbg_IgnoreFuncs (
					Tcl_Interp *interp,
					Dbg_IgnoreFuncsProc *);
EXTERN Dbg_OutputStruct Dbg_Output (
					Tcl_Interp *interp,
					Dbg_OutputProc *,
					ClientData data);

EXTERN void Dbg_StdinMode (int mode);

#endif /* _NIST_DBG */
