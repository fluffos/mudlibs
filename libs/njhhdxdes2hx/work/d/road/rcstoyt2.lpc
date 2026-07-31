#include <ansi.h>
#include <room.h>

inherit ROOM;
int drop_him(object me);
void create()
{
	object san, sna;
	set("short", "马鞍山");
	set("long", @LONG
这是马鞍山的西面，风光秀丽。
但你似乎能听到某种动物的啸声,使人有点紧张
LONG
	);
	set("exits", ([ 
  "west"  : __DIR__"rcstoyt1",
  "eastup" : __DIR__"rcstoyt3",
]));

	set("outdoors", "road");

	setup();replace_program(ROOM);
	
}

void init()
{	
        return;
}

