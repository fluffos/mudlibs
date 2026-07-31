// Room: /u/dubei/u/gumu/jqg/hc8
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
		"south" : __DIR__"hc"+(random(10)+1),
		"east" : __DIR__"hc"+(random(10)+1),
		"north" : __DIR__"hc7",
		"west" : __DIR__"hc"+(random(10)+1),
		"northeast" : __DIR__"hc"+(random(10)+1),
                "southwest" : __DIR__"hc9",
	]));

      set("outdoors", "襄阳");
    replace_program(ROOM);

	setup();

}
 
