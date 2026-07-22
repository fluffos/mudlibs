// Room: /d/putian/mf-dian.c 妙法殿
// lklv 2001.9.10

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "妙法殿");
        set("long", @LONG
这里是妙法殿，殿中香火很多，门口有一个镂刻得十分精美的大香炉，香
炉前面是一张深色的供桌，桌后面立着一个很大的屏风。从这里出去南面就是
藏经阁了。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xj3",
                "southup" : __DIR__"cjg",
                "east" : __DIR__"dmyuan",
        ]));

        set("objects",([
                __DIR__"npc/wuseng" : 4,
        ]));

        setup();
}
int valid_leave(object me, string dir)
{
	if (objectp(present("wu seng", environment(me))) && dir == "southup")
		return notify_fail("武僧道：藏经阁重地，没事请不要乱闯。\n");

	return ::valid_leave(me, dir);
}