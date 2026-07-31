// Room: /u/dubei/u/gumu/jqg/df
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "丹房");
	set("long", @LONG
这里是绝情谷炼制丹药的地方，屋里弥漫着一股刺鼻
的药味。
LONG
	);

	set("exits", ([
 
                "south" : __DIR__"zl2",
	]));
 

  
	setup();
	replace_program(ROOM); 
}

