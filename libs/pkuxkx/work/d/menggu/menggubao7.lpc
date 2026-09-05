// Room: menggubao.c
// created by Zine 30 Aug 2010
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIY+"金帐"+NOR);
	set("long", @LONG
这是一顶金色的帐篷，铁木真在此处的行辕。
LONG
	);

	set("exits", ([
        "enter" : __DIR__"jinzhang",
		"northwest" : __DIR__"hua_bao",
		"northeast" : __DIR__"tuo_bao",
		"south" : __DIR__"menggubao",
		"southeast" : __DIR__"menggubao5",
        "southwest" : __DIR__"shuchi_bao",
	]));
    set("valid_startroom", 1);
	set("sleep_room", "1");
	set("objects", ([
        	__DIR__"npc/weishi" : 2,
			__DIR__"npc/wanfu" : 1,
	]));
	set("no_robber",1);
	set("outdoors", "menggu_e");
    setup();
}

int valid_leave(object me,string dir)
{
    if (present("menggu yongshi",this_object())&&dir=="enter"&&!me->query("shediaoquest/zhebie"))
    {
        return notify_fail("蒙古勇士拦住了你，不许你走进大汗的行帐。\n");
    }
    return ::valid_leave(me,dir);
}
