/*
// _tsh.c: This file is part of the TMI Mudlib distribution.
// Please include this header if you use this code.
// Originally written by Truilkan (1992/03/11)
*/

#include <mudlib.h>

inherit DAEMON ;

int
cmd_tsh(string str)
{
        object pobj;

        pobj = previous_object();
        if (!pobj)
                return 0;
        return (int)pobj->tsh(str);
}

string
help()
{
  return("Command: tsh\nSyntax: tsh script\n"+
        "Tsh calls the command() efun on each line in the script.  The\n"+
        "effect of typing 'tsh script' is as if you had manually\n" +
                "typed each command in the script.\n");
}

/* EOF */
