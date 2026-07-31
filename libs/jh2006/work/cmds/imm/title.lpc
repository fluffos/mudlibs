// title.c (Mon  09-04-95)
// last modify by-SPY. 8th, April 1997. for wizard set self title. 

#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	if( !arg ) {
		write(sprintf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(me), me->short(1)));
		return 1;
	}
	if( arg == "none") {
		me->delete("title");
		write("您的title已经被删除了。\n");
		write(sprintf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(me), me->short(1)));
		return 1;
	}
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	if( strlen(strip(arg)) > 40 )
		return notify_fail("你的title太长了，想一个短一点的、响亮一点的。\n");
	me->set("title", arg + NOR);
	write(sprintf(BOLD "%s" NOR "%s\n", RANK_D->query_rank(me), me->short(1)));
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式: title
 
显示你目前的阶级和头衔。

HELP );
	return 1;
}
