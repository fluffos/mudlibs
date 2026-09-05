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
		"northwest" : __DIR__"nandigou2",
		//"southwest" : __DIR__"nandigou3",
		//"northeast" : __DIR__"wall1",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("objects", ([
		//__DIR__"npc/wujiang" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("entry_direction","northwest");
    set("migong","/d/northmountain/heishan/bailang");
    set("migong_posi","east");
    set("look_refuse_msg","白狼山上响起了恐怕的啸声，此时不宜进山。\n");
    set("enter_refuse_msg","白狼山上响起了恐怕的啸声，此时不宜进山。\n");
	setup();
}
