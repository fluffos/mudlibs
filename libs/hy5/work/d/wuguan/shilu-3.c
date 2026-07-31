//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "石板路");
	set("long", @LONG
你走在一条石板路上，一直通向后院，路两旁是些普通的花草，树上
的小鸟，不停的叫着。
LONG);
	set("exits", ([
	       "north" : __DIR__"houyuan",
	       "south" : __DIR__"shilu-4",
        ]));
        set("objects", ([
           __DIR__"npc/puren1" : 1,
        ]));
	set("outdoors", "武馆");
	setup();
        replace_program(ROOM);
}

