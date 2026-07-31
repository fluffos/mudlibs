// Room: /u/dubei/u/gumu/jqg/sl2
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
                "westup" : __DIR__"sl3",
                "southdown" : __DIR__"sl1",
	]));
 

        set("outdoors", "襄阳");
	setup();
	replace_program(ROOM); 
}

