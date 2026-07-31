// Room: /d/changle/yongdao.c
// River 2003.2.26
inherit ROOM;
#include <ansi.h>

void create()
{
	set("short", HIB"石室"NOR);
	set("long", @long
昏暗的石屋没有窗户，乃是长乐帮私设的刑堂及囚室。周围摆放着几件刑
具，墙上有些新旧不一的血痕，令人不寒而栗。室内甚是潮湿，头顶不时滴下
水珠。
long
	);

	set("exits", ([
		"west" : __DIR__"yongdao",
	]));

	set("objects", ([
		__DIR__"npc/zhan": 1,
	]));

	setup();
}
