inherit ROOM;
#include <ansi.h>
#include <room.h>

void create()
{
	set("short", "后院");
	set("long", @LONG
这里是大理皇宫的后院，再进去就是保定帝的寝宫了，由于保定帝生性喜
静，所以这里很少有人走动，处处给人一种静谧的感觉。
LONG
	);

	set("exits", ([
		"north" : __DIR__"qingong",
		"south" : __DIR__"xiaoqiao",
	]));
	set("outdoors", "大理");
	set("coor/x",-310);
  set("coor/y",-390);
   set("coor/z",-20);
   setup();
}
