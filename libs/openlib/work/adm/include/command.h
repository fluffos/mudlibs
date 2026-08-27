/*  -*- LPC -*-  */
#ifndef _COMMAND_H
#define _COMMAND_H
// command.h   File included by all commands
//
//   This ensures that command objects are destructed after being idle, and
// the euid gets set right.
//

#pragma save_binary

#include "mudlib.h"
#include "dirs.h"
#include "modules.h"

inherit DAEMON;
inherit M_CLEAN_UP;
inherit INHERIT_DIR "/command";

#endif /* _COMMAND_H */
