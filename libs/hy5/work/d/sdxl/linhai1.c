// sdxl
// by dubei

#include <room.h>
inherit ROOM;


void create()
{
	set("short", "林海");
	set("long", @LONG
这里是一片一望无垠林海，每棵树木都有十来丈高，周围阡陌
交错，你进来感觉到自己迷路了
LONG
	);

	set("exits", ([
		"northeast" : __DIR__"linhai"+(random(13)+1),
		"southwest" : __DIR__"linhai2",
		"northwest" : __DIR__"linhai"+(random(13)+1),
		"southeast" : __DIR__"linhai"+(random(13)+1),
		"down" : __DIR__"conglin4",
	]));

      set("outdoors", "xiangyang");
           replace_program(ROOM);
           setup();

}
 
