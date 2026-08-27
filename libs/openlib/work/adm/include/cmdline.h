/*  -*- LPC -*-  */
#ifndef _COMMAND_H
#define _COMMAND_H
// cmdline.h:  A replacement for command.h which provides facilities for
//             stripping flags from the command line. (see cmdline.c)
//
// written by: Tim McIntosh (astasia@iastate.edu)
//
// This file is part of the UltraLib distribution mudlib.
// It may be used and modified as long as this header remains intact.
// The UltraLib mudlib is available via FTP at knapp38.res.iastate.edu
//
// #include this and write main() as declared below for your main function.
//
// int main(string *argv, string *argv2);
//
// arguments passed:
//          argv:  an array of all the words passed to the command with nothing
//                 removed.  argv[0] is always the verb.
//          argv2: an array of all the words passed to the command with flags
//                 removed--the verb is not included in this array
//
//          flag(string str) tells you if the flag 'str' is present.
//                           Flags that are more than 1 char. must be passed
//                           with 2 leading dashes. e.g. --help
//
// NOTE: --help is a special flag which will cause help info to be printed
// as returned by help() in the command object.

#include "mudlib.h"
#include "dirs.h"
#include "modules.h"

inherit DAEMON;

inherit M_CLEAN_UP;
inherit INHERIT_DIR "/cmdline";

#endif /* _COMMAND_H */
