// Room: /u/dubei/u/gumu/jqg/zl1
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "回廊");
	set("long", @LONG
一条典雅的回廊，上面画满当代名人的书画。
LONG
	);

	set("exits", ([
                "southwest" : __DIR__"zl2",
                "northeast" : __DIR__"sqx",
                "north" : __DIR__"qs",
                "east" : __DIR__"hhs",
	]));
	set("objects", ([
		__DIR__"npc/puren" : 1,
	 ]));
 	setup();
	replace_program(ROOM); 
}

