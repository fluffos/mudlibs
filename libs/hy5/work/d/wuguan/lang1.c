//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "长廊");
	set("long", @LONG
这是个长廊，通向西练武场，人们急冲冲的走过，不时有人被抬出来，
看样子是练功脱力昏倒的。
LONG);
	set("exits", ([
	       "west" : __DIR__"wuchang1",
	       "east" : __DIR__"dayuan",
        ]));
        set("objects", ([
           __DIR__"npc/mrdizi" : 1,
        ]));
	setup();
        replace_program(ROOM);
}

