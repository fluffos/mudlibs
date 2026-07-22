// CMDS /cmds/wiz/nuke.c
// Created by waiwai@2001/06/05

#include "/doc/help.h"
#include <ansi.h>

inherit F_CLEAN_UP;

mixed query(string arg)
{
    if (arg && arg=="channel_id")
        return  WHT"清除精灵";
    return 0;
}

void create() { seteuid(getuid(this_object())); } 
 
int main(object me, string arg)
{
	object ob;
	string wiz_status;

	if (!arg) return notify_fail("指令格式: nuke <id>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("没有这个人。\n");

	if( me != this_player(1) ) return 0;
	wiz_status = SECURITY_D->get_status(me);
	if( wiz_status != "(created)" 
		&& wiz_status != "(admin)" 
		&& wiz_status != "(arch)" 
		&& wiz_status != "(wizard)" )
		return notify_fail(HIC"只有 wizard 级别以上的巫师才有权使用这个指令。\n"NOR);

	if( wiz_level(me) < wiz_level(ob) ) {
  if( ob->query("id")=="amy")
            return notify_fail(WHT"你没有将" HIR+ ob->query("id") +NOR WHT "清除出游戏的权利。\n"NOR);
	else return notify_fail("没有这个人。\n");
	}
 
	CHANNEL_D->do_channel(this_object(), "sys", me->query("id")+"将"+ob->query("id")+"清除出游戏。\n"NOR);	

	if( userp(ob) )
	log_file("wizcmds/nuke", 
	sprintf("[%s] %s将%s强制清除出游戏。\n", ctime(time()), me->query("id"), ob->query("id")));

	ob -> save();
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP

指令格式: nuke <id>

对于无法退线或别的原因需要清除在线状态的玩家
可用此指令。

HELP
   );
   return 1;
}
