// /d/wizard/guest_room.c
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
	set("short", "巫师公告室");
	set("long", @LONG
这里是巫师和玩家交流的地方，张贴的是巫师工会的最新公告；如果
你有问题应该到巫师会客室去(POST)。
LONG );

	set("exits", ([
		"east": __DIR__"guest_room",
        ]));
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("valid_startroom", 1);
	setup();
	call_other("/clone/board/wiz2_b", "???");
}


