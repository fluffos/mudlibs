// zoulang3.c 走廊
// by yuer


#include <room.h>
inherit ROOM;

void create()
{
	set("short", "走廊");
	set("long", @LONG
	你走在一条走廊上，北面通向武器库,南面是防具库，
东面是药品库。
LONG
	);

	
	set("exits", ([
		"south" : __DIR__"fangjuku",
		"north" : __DIR__"wuqiku",
	 	 "west" : __DIR__"zoulang2",
		 "east" : __DIR__"yaopinku",		     
	]));
	setup();
}


