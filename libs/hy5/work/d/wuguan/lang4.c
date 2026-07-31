//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，北面是武馆内的物品房，要在武馆做杂事的人都得去
物品房领工具，南边是东练武场。
LONG);
	set("exits", ([
	       "north" : __DIR__"wupinfang",
	       "south" : __DIR__"wuchang4",
        ]));
        set("objects", ([
           __DIR__"npc/thddizi" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

