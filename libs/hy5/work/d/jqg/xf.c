// Room: /u/dubei/u/gumu/jqg/xf
// by dubei
#include <room.h>

inherit ROOM;

void create()
{
	set("short", "绣房");
	set("long", @LONG
这里是公孙绿萼的绣房，整个房间秀雅整洁，一个少女正
坐在窗前沉思。
LONG
	);

	set("exits", ([
                "north" : __DIR__"zl2",
 
	]));
	set("objects", ([
		__DIR__"npc/gsle" : 1,
	 ]));

       setup();
   replace_program(ROOM);
}
 
