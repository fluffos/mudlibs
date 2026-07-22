//bye enter

inherit ROOM;

void create()
{
        set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，上面雕梁画柱，飞檐琉璃，穿行其
间，心情舒畅。往西是温老大的住处。
LONG
	);
	set("exits", ([ 
//            "east" : __DIR__"houyuan",
            "north" : __DIR__"zoulang2",
            "southeast" : __DIR__"dating",
            "west" : __DIR__"fang1",
            ]));

	setup();
	replace_program(ROOM);
}
