//wizgroup.c   ☆侠客☆(Xkxmud)所做的显示★侠客梦★目前巫师分组情况的指令！！
//☆侠客☆(Xkxmud)
//     /cmds/usr/wizgroup.c
//Time:001_2002-10-21

inherit F_CLEAN_UP;
#include <ansi.h>
int main(object me)
{
	seteuid(getuid());
	RWM_D->long();
	return notify_fail(HIW"有任何问题请找相关巫师或高级巫师联系，或请其他组别巫师代为转告！\n"HIG"亮绿色显示为在线的巫师！\n"NOR);
}
int help(object me)
{
	write(HIC"指令格式：wizgroup\n\n"HIR"★侠客梦★"HIC"目前巫师分组情况！\n"NOR);
	return 1;
}