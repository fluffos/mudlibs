// zoulang2.c 走廊
// by yuer


#include <room.h>
inherit ROOM;   

void create()
{
	set("short", "走廊");
	set("long", @LONG
	你走在一条走廊上，东边是练功房，北边是药品库。
LONG
	);

	
	set("exits", ([
	
		"north" : __DIR__"yaoping",
		"west" : __DIR__"zoulang",
		"east" : __DIR__"liangong",		     
	]));
	setup();
}                
