// shaqiu2.c 沙丘
// shamo can to shaqiu
// Ver 0.1 08/14/1998 by Freeze

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short",HIG "沙 州"NOR);
	set("long",  @LONG
这里四面是沙海边缘，沙丘起伏，可以看到有稀疏的灌木，一不溜神就可能错入沙漠地带。
这里是通向天山、抵达嘉峪关的唯一路径。
LONG
	);	
        set("outdoors", "jyguan");


	set("exits", ([
//		"west" : __DIR__"shamo1",
//		"east" : __DIR__"shamo",
//                "south" : __DIR__"shamo",
                "north" : __DIR__"shamo",
                "northwest" : __DIR__"shamo",
                "northeast" : __DIR__"shaqiu1",
//                "southwest" : __DIR__"shqiu2",
                "southeast" : __DIR__"luzhou",
	]));
	
		
	setup();
	replace_program(ROOM);
}

