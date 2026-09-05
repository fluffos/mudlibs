// 东天目山，一座随机生成的区域。玩家副本 Zine 2014/7/14
inherit ROOM;
#include <ansi.h>
void create()
{
	set("short", WHT+"畲寨大门"+NOR);
	set("long", @LONG
这里是一座畲寨的西门，这座里聚集了几百口人。
LONG
	);
        set("outdoors", "xitianmu");

	set("exits", ([
		"southwest" : "/d/southmountain/qingliangfeng/shanlue1",
		//"northeast" : __DIR__"shanluw4",
		"enter" : __DIR__"westgc",
		//"eastdown" : __DIR__"fengshu",
	]));

	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		__DIR__"npc/shebing" : 2,
        ]));
	setup();
}
int valid_leave(object me,string dir)
{
	if (dir=="enter"&&!userp(me)) return notify_fail("");
	return ::valid_leave(me,dir);
}