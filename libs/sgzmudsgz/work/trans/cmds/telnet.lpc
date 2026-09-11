// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** This file is part of the Lima distribution mudlib.  
** Do not remove this header.  Please see /USAGE for more 
** information on using this code.
**
** FILE: /trans/cmds/telnet.c
** AUTHOR: John Viega (rust@virginia.edu)
** CREATED: Jul 25 1995

** OVERVIEW
** ========
** This command is usable by anyone with valid security clearence to use sockets.
** It initiates /trans/obj/telnet_ob.
**
*/

#include <mudlib.h>
inherit CMD;

private void main()
{
    if (!check_privilege(1))
    {
        //out("Only admins may use telnet!\n");
        out("只有大神才可以用 telnet！\n");
        return;
    }
    else
    {
        //write("Type /help or /? for help on telnet.\n");
        write("在 telnet 中用 /help 或 /? 来获取对 telnet 的帮助。\n");
        new(TELNET_OB)->init_telnet();
    }
}
