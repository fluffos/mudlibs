// ghost.c
// by SPY, 23th,march 1997

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	if (!arg || arg!="-p") {
		me->set_ghost(1);
		write("你成功地变成了一只鬼！\n");
	}
	else {
		me->set_ghost(0);
		write("你又投胎做人了！\n");
	}
	return 1;
}
		
int help(object me)
{
write(@HELP
指令格式 : ghost [-p]
 
这个指令让你在人鬼之间切换！
HELP	);
	return 1;
}