// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("指令格式: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("找不到这个生物。\n");
	message_vision("$N向$n演说无上法轮妙法，$n顿觉人生无趣，剖腹取轮。\n",me,ob);
	ob -> die();
	return 1;
}
 
int help(object me)
{
   write(@HELP
指令格式: smash <生物>
 
hehehehehe...........

HELP
   );
   return 1;
}
