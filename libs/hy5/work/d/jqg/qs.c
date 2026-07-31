// Room: /u/dubei/u/gumu/jqg/qs
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "寝室");
	set("long", @LONG
这是公孙止的睡房，里面的床上绫罗绸缎，床边站着一名丫鬟，
窗户半开，屋内光线不太明亮。
LONG
	);

	set("exits", ([
                "south" : __DIR__"zl1",
	]));

        set("objects", ([
		__DIR__"npc/yahuan" : 1,
	 ]));
	setup();
	replace_program(ROOM); 
}

