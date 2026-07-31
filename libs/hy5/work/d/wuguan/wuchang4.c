//cool 98.4.18

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "东练武场");
	set("long", @LONG
这是露天练武场，好多人在这里辛苦的练着，你走在场中，没有人
回头看你一眼，都在聚精汇神的练着自己的功夫，地上放着几个练功用具。
LONG);
	set("exits", ([
	       "north" : __DIR__"lang4",
	       "south" : __DIR__"wuchang2",
        ]));
        set("objects", ([
           __DIR__"npc/daotong" : 1,
        ]));
        set("outdoors", "武馆");
	setup();
}

