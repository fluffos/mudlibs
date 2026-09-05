inherit ROOM;
#include <ansi.h>
#include "/d/menggu/entry_migong.h"
void create()
{
	set("short", "山间路"+NOR);
	set("long", @LONG
这里是进入白狼山的山间小路，北面通向山海关。
LONG
	);
        set("outdoors", "heishan");

	set("exits", ([
		//"north" : __DIR__"heishane1",
		"south" : __DIR__"bailangn1",
		"northdown" : __DIR__"bailangn3",
		//"eastdown" : __DIR__"fengshu",
	]));
	set("objects", ([
		__DIR__"npc/laoliehu" : 1,
		//__DIR__"npc/songbing_y" : 2,
        ]));
	set("entry_direction","south");
    set("migong","/d/northmountain/heishan/heishan");
    set("migong_posi","north");
    set("look_refuse_msg","白狼山上响起了恐怕的啸声，此时不宜进山。\n");
    set("enter_refuse_msg","白狼山上响起了恐怕的啸声，此时不宜进山。\n");
	setup();
}
