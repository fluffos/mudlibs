// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>

int valid_leave(object me,string dir)
{
	if (me->query_skill("dodge",1)>200)
	return ::valid_leave(me,dir);
	else if (random(100)>70)
	{
		me->add_busy(1);
		return notify_fail("山路难行，你不小心给拌了一跤。\n");
	}
	else
	return ::valid_leave(me,dir);
}
