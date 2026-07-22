//bye enter

inherit ROOM;

void create()
{
        set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，上面雕梁画柱，飞檐琉璃，穿行其
间，心情舒畅。往西是温老三的住处。
LONG
	);
	set("exits", ([ 
//            "east" : __DIR__"houyuan",
            "north" : __DIR__"zoulang3",
            "south" : __DIR__"zoulang1",
            "west" : __DIR__"fang2",
            ]));

	setup();
	replace_program(ROOM);
}
