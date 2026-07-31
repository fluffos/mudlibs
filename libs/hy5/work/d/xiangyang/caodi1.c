// Room: /d/xiangyang/caodi1.c
// Date: Jan. 8 1999 by Winder

inherit ROOM;
#include <ansi.h>;

void create()
{
	set("short", "草地");
	set("long", @LONG
这是襄阳城外的草地。蒙古兵进犯以来，这里的百姓全进
城了，蒙古兵驰骋来去，以为牧场，尘土飞扬，甚是嚣张。
LONG );
        set("outdoors", "xiangyang");

	set("exits", ([
		"west"  : __DIR__"northgate2",
		"up"  : __DIR__"gaotai",
	]));
	set("objects", ([
		"quest/guojob/badjob/mengge"   : 1,
		__DIR__"npc/tuolei"   : 1,
		__DIR__"npc/menggubing" : 4,
	]));
	
	set("roomif","$botten#绑架任务|放弃任务:ask meng ge about job|ask meng ge about fangqi$#");
	setup();
	//replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
	if ( objectp(present("menggu bing", environment(me))) && 
		dir == "up")
		return notify_fail("蒙古兵拦住了你的去路。\n");

	if ( objectp(present("tuo lei", environment(me))) && 
		dir == "up")
		return notify_fail("蒙古征南大元师拦住了你的去路。\n");
	return ::valid_leave(me, dir);
}