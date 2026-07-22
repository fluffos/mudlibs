// semote.c
#include "/doc/help.h"
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string *e,str="\n";
	int i;
	if( me->query("gin")<1 )
		return notify_fail("你的活力不够了。\n");
	me->add("gin",-1);	
	e = sort_array(EMOTE_D->query_all_emote(), 1);
	for(i=0; i<sizeof(e); i++)
		str+=sprintf("%-15s%s", e[i], (i%5==4)?"\n": "");
	this_player()->start_more(str);
	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : semote

这个指令可以列出目前所能使用的emote.

*注：此命令将消耗1点活力
HELP
    );
    return 1;
}
