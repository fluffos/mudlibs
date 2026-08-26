// _reset.c , a quick hack to reset a terminal after some Evil Thing
// messed up our Good Player
// Leto jan 3rd - 95

#include <mudlib.h>
#include <ansi.h>

inherit DAEMON ;


int cmd_reset(string unused) {

   write(REF+NOR+"Your screen is normal again (hopefully).\n");
   return 1;
}

int help() {
	write ("Usage: faq\n\n"+
"This will reset your terminal if STRIP_ANSI is not set.\n"+
"If something or someone is messing around with your screen,"+
"you can use 'set STRIP_ANSI' to prevent further problems.\n"+
"You also might notify an admin , or post on the bug board\n"+
"about this.\n"
);
return 1;
}
