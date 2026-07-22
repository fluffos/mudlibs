//bye enter

inherit ROOM;

void create()
{
        set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，上面雕梁画柱，飞檐琉璃，穿行其
间，心情舒畅。往东是温老五的住处。
LONG
	);
	set("exits", ([ 
//            "west" : __DIR__"houyuan",
            "north" : __DIR__"zoulang7",
            "south" : __DIR__"zoulang5",
            "east" : __DIR__"fang4",
            ]));

	setup();
	replace_program(ROOM);
}
