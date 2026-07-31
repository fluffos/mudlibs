// Room: /u/dubei/u/gumu/jqg/hc10
// by dubei

#include <room.h>
inherit ROOM;
void create()
{
	set("short", "花丛");
	set("long", @LONG
这里是一片花丛，你感到已经很难辨清道路了。
LONG
	);

	set("exits", ([
		"south" : __DIR__"hc9",
		"east" : __DIR__"hc"+(random(10)+1),
		"north" : __DIR__"hc"+(random(10)+1),
		"west" : __DIR__"hc11",
		"northeast" : __DIR__"hc"+(random(10)+1),
                "southwest" : __DIR__"hc"+(random(10)+1),
	]));

      set("outdoors", "xiangyang");
    replace_program(ROOM);

	setup();

}
 
