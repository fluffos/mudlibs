//shilu1.c

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "白石路");
        set("long", @LONG
这是一条白石板铺成的小路，两边绿树成荫，不时有些仆人和丫鬟从你身
边走来走去。往北走就是后院了，菜地，菜园和柴房都在那里。南面是一条走
廊，能闻到阵阵传来的香气，你肚子不由的“咕咕”叫了起来。
LONG);

	//set("outdoors","武馆");
	set("no_fight",1);
        set("exits", ([
               "north" : __DIR__"houyuan",
               "south" : __DIR__"zoulang1",
            ]));
        
        set("objects", ([
        ]));

        setup();
}
