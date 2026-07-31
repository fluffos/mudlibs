//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，通向东练武场，人来人往的，很是热闹。
LONG);
	set("exits", ([
	       "east" : __DIR__"wuchang2",
	       "west" : __DIR__"dayuan",
        ]));
        set("objects", ([
           __DIR__"npc/xiaohs" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

