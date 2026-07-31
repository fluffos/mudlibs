// Room: /d/shaolin/lhtang.c
// Date: by zqb

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", HIY"罗汉堂"NOR);
    set("long", @LONG
你面前是一座很大的院落，周围用高墙围住，院门匾额上写着『罗汉堂
』三个大字。这里是少林弟子练习本门基本武功的所在。有很多年轻的僧人
进进出出，院内传来阵阵呼喝练功的声音。
LONG
    );

    set("exits", ([
        "east" : __DIR__"stoneroad4",
        "west" : __DIR__"lwc",
    ]));

    set("outdoors", "shaolin");
    set("objects",([
        CLASS_D("shaolin") + "/xuan-ku" : 1,
        __DIR__"npc/xiao-ku" : 1
    ]));
      setup();
}

int valid_leave(object me, string dir)
{
	mapping myfam;
	myfam = (mapping)me->query("family");

	if ((!myfam || myfam["family_name"] != "少林派") && dir == "west" &&
            objectp(present("xuanku dashi", environment(me))))
	   return notify_fail("玄苦喝道：罗汉堂乃本派弟子习武之处，你非本派弟子，不能入内。\n");
		
        return ::valid_leave(me, dir);
}
