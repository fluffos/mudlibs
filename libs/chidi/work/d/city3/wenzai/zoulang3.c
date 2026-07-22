//bye enter

inherit ROOM;

void create()
{
        set("short", "走廊");
	set("long", @LONG
你走在一条长长的走廊上，上面雕梁画柱，飞檐琉璃，穿行其
间，心情舒畅。往西是有个厨房。
LONG
	);
	set("exits", ([ 
//            "east" : __DIR__"houyuan",
            "northeast" : __DIR__"zoulang4",
            "south" : __DIR__"zoulang2",
            "west" : __DIR__"chufang",
            ]));

	setup();
	replace_program(ROOM);
}
