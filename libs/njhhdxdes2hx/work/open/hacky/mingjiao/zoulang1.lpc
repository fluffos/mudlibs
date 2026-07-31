// zoulang1.c 走廊
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
	你走在一条走廊上，西边是饭厅，北边是休息室。
LONG
	);

	
	set("exits", ([
	
		"north" : __DIR__"xiuxishi",
		"west" : __DIR__"fanting",
		"east" : __DIR__"zoulang",		     
	]));
	setup();
}


