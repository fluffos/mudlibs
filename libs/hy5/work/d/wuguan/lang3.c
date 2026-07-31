//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，一直通向后院，南边是西练武场。
LONG);
	set("exits", ([
	       "north" : __DIR__"shilu-4",
	       "south" : __DIR__"wuchang3",
        ]));
	setup();
        replace_program(ROOM);
}

