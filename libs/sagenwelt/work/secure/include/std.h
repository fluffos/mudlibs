/// @file std.h
/// @brief standard macros
///
/// This file is automatically included in _every_ *.c
/// @author Gwenhwyvar
/// @version 0.1.0
/// @date 2016-04-03

#ifndef __STD_H
#define __STD_H

#include "simul_efun.h"
#include <driver/runtime_config.h>
#include "config.h"

#define     __LIB_VERSION   "0.0.0"

// standard booleans
#define     FALSE           0
#define     TRUE            1

// screen settings
#define     DFLT_SCR_WIDTH  79
#define     DFLT_SCR_HEIGHT 24
#define     DFLT_SCR_INDENT 4

// save_object flags
#define     SO_NONE         0
#define     SO_SAVE_ZERO    1
#define     SO_SAVE_GZ      2

// input_to flags
#define     I_NONE          0
#define     I_NO_ECHO       1
#define     I_NO_ESC        2
#define     I_SINGLE_CHAR   4

// save_object flags
#define     SO_NONE         0
#define     SO_SAVE_ZERO    1
#define     SO_SAVE_GZ      2

// function short-cuts
#define     TO              this_object
#define     PO(x)           previous_object(x)
#define     TI              this_interactive
#define     TP(x)           this_player(x)

// paths
#define     TMPDIR          "/tmp"

// standard error messages
#define     TYPE_ERROR(func, arg, got, expected) \
    "illigale type to argument " arg " of " func " got <" got "> expected <" expected ">!"

#endif // __STD_H
