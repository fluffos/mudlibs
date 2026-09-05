inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
	set("short", "南地沟"+NOR);
	set("long", @LONG
这里是黑山和白狼山之间的山间小路。
LONG
	);
        set("outdoors", "heishan");

	set("exits", ([
		"southeast" : __DIR__"nandigou1",
		//"southeast" : "/d/changbai/guandao9",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("entry_direction","southeast");
    set("migong","/d/northmountain/heishan/heishan");
    set("migong_posi","north");
    set("look_refuse_msg","黑山上云雾笼罩，此时不宜进山。\n");
    set("enter_refuse_msg","黑山上云雾笼罩，此时不宜进山。\n");
	setup();
}
