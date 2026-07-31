// Room: /u/dubei/u/gumu/jqg/hc1
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
		"north" : __DIR__"hc"+(random(10)+1),
		"south" : __DIR__"hc2",
		"west" : __DIR__"hc"+(random(10)+1),
		"east" : __DIR__"hc"+(random(10)+1),
		"out" : __DIR__"wx",
	]));

      set("outdoors", "xiangyang");
          replace_program(ROOM);

	setup();

}
 
