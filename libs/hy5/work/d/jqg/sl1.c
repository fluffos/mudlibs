// Room: /u/dubei/u/gumu/jqg/sl1
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
着是一条陡峭的山路，向后山蜿蜒而去。
LONG
	);

	set("exits", ([
                "northup" : __DIR__"sl2",
                "southdown" : __DIR__"st",
	]));
 

        set("outdoors", "襄阳");
	setup();
	replace_program(ROOM); 
}

