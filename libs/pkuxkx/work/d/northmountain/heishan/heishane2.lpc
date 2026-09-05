inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
	set("short", HIG+"入山小道"+NOR);
	set("long", @LONG
这里是进入黑山的山间小路。
LONG
	);
        set("outdoors", "heishan");

	set("exits", ([
		"westup" : __DIR__"heishane1",
		"southeast" : __DIR__"heishane3",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("entry_direction","westup");
    set("migong","/d/northmountain/heishan/heishan");
    set("migong_posi","east");
    set("look_refuse_msg","黑山上云雾笼罩，此时不宜进山。\n");
    set("enter_refuse_msg","黑山上云雾笼罩，此时不宜进山。\n");
	setup();
}
